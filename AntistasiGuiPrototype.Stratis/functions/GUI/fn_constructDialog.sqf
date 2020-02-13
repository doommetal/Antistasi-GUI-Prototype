#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_ConstructDialog";
    waitUntil {dialog}; // Wait until the dialog is actually created

    _display = findDisplay A3A_IDD_CONSTRUCTDIALOG;

    // Pixel grid
    // TODO: MOVE THIS
    #define pixelScale	0.50
    #define GRID_W (pixelW * pixelGrid * pixelScale)
    #define GRID_H (pixelH * pixelGrid * pixelScale)

    // Add the stuff to the construct list
    _constructControlsGroup = _display displayCtrl A3A_IDC_CONSTRUCTGROUP;

    // Hide the group initially to let things get into place
    _constructControlsGroup ctrlSetFade 1;
    _constructControlsGroup ctrlCommit 0;

    _added = 0;
    {
      _className = _x select 0;
      _price = _x select 1;
      _buildTime = _x select 2;
      _configClass = configFile >> "CfgVehicles" >> _className;
      _displayName = getText (_configClass >> "displayName");
      _editorPreview = getText (_configClass >> "editorPreview");
      // Add some extra padding to the top if there are 2 rows or less
      _topPadding = if (count constructionsList < 7) then {5 * GRID_H} else {0};
      _itemXpos = 7 * GRID_W + ((7 * GRID_W + 44 * GRID_W) * (_added mod 3));
      _itemYpos = (floor (_added / 3)) * (44 * GRID_H) + _topPadding;
      _previewPicture = _display ctrlCreate ["RscPicture", -1, _constructControlsGroup];
      _previewPicture ctrlSetPosition [_itemXpos, _itemYpos, 44 * GRID_W, 25 * GRID_H];
      _previewPicture ctrlSetText _editorPreview;
      _previewPicture ctrlCommit 0;
      _button = _display ctrlCreate ["A3A_ShortcutButton", -1, _constructControlsGroup];
      _button ctrlSetPosition [_itemXpos, _itemYpos + (25 * GRID_H), 44 * GRID_W, 12 * GRID_H];
      _button ctrlSetText _displayName;
      _button ctrlCommit 0;
      _timeText = _display ctrlCreate ["A3A_InfoTextRight", -1, _constructControlsGroup];
      _timeText ctrlSetPosition[_itemXpos + 23 * GRID_W, _itemYpos + 18 * GRID_H, 20 * GRID_W, 3 * GRID_H];
      _timeText ctrlSetText format ["%1 s",_buildTime];
      _timeText ctrlCommit 0;
      _priceText = _display ctrlCreate ["A3A_InfoTextRight", -1, _constructControlsGroup];
      _priceText ctrlSetPosition[_itemXpos + 23 * GRID_W, _itemYpos + 21 * GRID_H, 20 * GRID_W, 3 * GRID_H];
      _priceText ctrlSetText format ["%1 €",_price];
      _priceText ctrlCommit 0;

      _added = _added + 1;
    } forEach constructionsList;

    // Adds padding to the bottom, allowing the scroll to go a little past the items
    // Might look better on some configurations?
    /* _paddingBottom = _display ctrlCreate ["RscText", -1, _constructControlsGroup];
    _fullRow = if (_added % 3 == 0) then {0} else {1};
    _paddingBottom ctrlSetPosition [0, (floor (_added / 3)) * (44 * GRID_H) + _fullRow * (44 * GRID_H), 1 * GRID_W, 7 * GRID_H];
    _paddingBottom ctrlSetText "";
    _paddingBottom ctrlCommit 0; */

    // Show group again
    _constructControlsGroup ctrlSetFade 0;
    _constructControlsGroup ctrlCommit 0.1;
  };
};
