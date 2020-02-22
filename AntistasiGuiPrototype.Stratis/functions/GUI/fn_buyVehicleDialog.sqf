#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_BuyVehicleDialog";
    waitUntil {dialog}; // Wait until the dialog is actually created

    _display = findDisplay A3A_IDD_BUYVEHICLEDIALOG;

    // Pixel grid
    // TODO: MOVE THIS
    #define pixelScale	0.50
    #define GRID_W (pixelW * pixelGrid * pixelScale)
    #define GRID_H (pixelH * pixelGrid * pixelScale)

    // Add the stuff to the construct list
    _vehiclesControlsGroup = _display displayCtrl A3A_IDC_VEHICLESGROUP;
    // Hide group initially to let all the things get to the right place
    _vehiclesControlsGroup ctrlSetFade 1;
    _vehiclesControlsGroup ctrlCommit 0;
    _added = 0;
    {
      _className = _x select 0;
      _price = _x select 1;
      _canGoUndercover = _x select 2;
      _crewCount = [_className] call A3A_fnc_getVehicleCrewCount;
      _driver = _crewCount select 0;
      _coPilot = _crewCount select 1;
      _commander = _crewCount select 2;
      _gunners = _crewCount select 3;
      _passengers = _crewCount select 4;
      _passengersFFV = _crewCount select 5;
      _configClass = configFile >> "CfgVehicles" >> _className;
      _displayName = getText (_configClass >> "displayName");
      _editorPreview = getText (_configClass >> "editorPreview");

      // Add some extra padding to the top if there are 2 rows or less
      _topPadding = if (count buyableVehiclesList < 7) then {5 * GRID_H} else {0};

      _itemXpos = 7 * GRID_W + ((7 * GRID_W + 44 * GRID_W) * (_added mod 3));
      _itemYpos = (floor (_added / 3)) * (44 * GRID_H) + _topPadding;

      _previewPicture = _display ctrlCreate ["RscPicture", -1, _vehiclesControlsGroup];
      _previewPicture ctrlSetPosition [_itemXpos, _itemYpos, 44 * GRID_W, 25 * GRID_H];
      _previewPicture ctrlSetText _editorPreview;
      _previewPicture ctrlCommit 0;

      _button = _display ctrlCreate ["A3A_ShortcutButton", -1, _vehiclesControlsGroup];
      _button ctrlSetPosition [_itemXpos, _itemYpos + (25 * GRID_H), 44 * GRID_W, 12 * GRID_H];
      _button ctrlSetText _displayName;
      _button ctrlCommit 0;

      _priceText = _display ctrlCreate ["A3A_InfoTextRight", -1, _vehiclesControlsGroup];
      _priceText ctrlSetPosition[_itemXpos + 23 * GRID_W, _itemYpos + 21 * GRID_H, 20 * GRID_W, 3 * GRID_H];
      _priceText ctrlSetText format ["%1 €",_price];
      _priceText ctrlCommit 0;

      // Undercover icon
      if (_canGoUndercover) then {
        _undercoverIcon = _display ctrlCreate ["RscPicture", -1, _vehiclesControlsGroup];
        _undercoverIcon ctrlSetPosition [_itemXpos + 1 * GRID_W, _itemYpos + 1 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _undercoverIcon ctrlSetText "GUI\textures\icon_hidevic.paa";
        _undercoverIcon ctrlCommit 0;
      };

      // Crew icons and counts
      _hasGunners = if (_gunners > 0) then {1} else {0}; // Is there a better way to just return all positive numbers as 1?
      _hasPassengers = if (_passengers > 0) then {1} else {0}; // Too sleepy to think of one right now...
      _numberOfCrewTypes = (_driver + _commander + _hasGunners + _hasPassengers);
      _crewCountHeight = _numberOfCrewTypes * 4.5 * GRID_H;
      _crewCountYpos = _itemYpos + 24 * GRID_H - _crewCountHeight;

      // Using an inner controlsGroup here so the coordinate calculations don't get completely unreadable
      _crewControlsGroup = _display ctrlCreate ["RscControlsGroupNoScrollbars", -1, _vehiclesControlsGroup];
      _crewControlsGroup ctrlSetPosition[_itemXpos + 1 * GRID_W, _crewCountYpos, 20 * GRID_W, _crewCountHeight];
      _crewControlsGroup ctrlCommit 0;

      _crewInfoAdded = 0;
      if (_driver > 0) then
      {
        _driverIcon = _display ctrlCreate ["RscPicture", -1, _crewControlsGroup];
        _driverIcon ctrlSetPosition [0, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _driverIcon ctrlSetText "GUI\textures\icon_driver.paa";
        _driverIcon ctrlCommit 0;

        // Only one driver so we don't need the text for it
        /* _driverText = _display ctrlCreate ["A3A_InfoText", -1, _crewControlsGroup];
        _driverText ctrlSetPosition [2 * GRID_W, _crewInfoAdded * 3 * GRID_H, 4 * GRID_W, 3 * GRID_H];
        _driverText ctrlSetText str _driver;
        _driverText ctrlCommit 0; */

        if (_coPilot > 0) then
        {
          _coPilotIcon = _display ctrlCreate ["RscPicture", -1, _crewControlsGroup];
          _coPilotIcon ctrlSetPosition [5 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
          _coPilotIcon ctrlSetText "GUI\textures\icon_driver.paa";
          _coPilotIcon ctrlSetTextColor [0.7,0.7,0.7,1];
          _coPilotIcon ctrlCommit 0;
        };
        _crewInfoAdded = _crewInfoAdded + 1;
      };

      if (_commander > 0) then
      {
        _commanderIcon = _display ctrlCreate ["RscPicture", -1, _crewControlsGroup];
        _commanderIcon ctrlSetPosition [0, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _commanderIcon ctrlSetText "GUI\textures\icon_commander.paa";
        _commanderIcon ctrlCommit 0;

        // Same with commander
        /* _commanderText = _display ctrlCreate ["A3A_InfoText", -1, _crewControlsGroup];
        _commanderText ctrlSetPosition [2 * GRID_W, _crewInfoAdded * 3 * GRID_H, 4 * GRID_W, 3 * GRID_H];
        _commanderText ctrlSetText str _commander;
        _commanderText ctrlCommit 0; */
        _crewInfoAdded = _crewInfoAdded + 1;
      };

      if (_gunners > 0) then
      {
        _gunnerIcon = _display ctrlCreate ["RscPicture", -1, _crewControlsGroup];
        _gunnerIcon ctrlSetPosition [0, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _gunnerIcon ctrlSetText "GUI\textures\icon_gunner.paa";
        _gunnerIcon ctrlCommit 0;

        if (_gunners > 1) then
        {
          _gunnersText = _display ctrlCreate ["A3A_InfoText", -1, _crewControlsGroup];
          _gunnersText ctrlSetPosition [3 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 3 * GRID_H];
          _gunnersText ctrlSetText str _gunners;
          _gunnersText ctrlCommit 0;
        };
        _crewInfoAdded = _crewInfoAdded + 1;
      };

      if (_passengers > 0) then
      {
        _passengerIcon = _display ctrlCreate ["RscPicture", -1, _crewControlsGroup];
        _passengerIcon ctrlSetPosition [0, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _passengerIcon ctrlSetText "GUI\textures\icon_cargo.paa";
        _passengerIcon ctrlCommit 0;

        if (_passengers > 1) then
        {
          _passengersText = _display ctrlCreate ["A3A_InfoText", -1, _crewControlsGroup];
          _passengersText ctrlSetPosition [3 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 3 * GRID_H];
          _passengersText ctrlSetText str _passengers;
          _passengersText ctrlCommit 0;
        };

        if (_passengersFFV > 0) then
        {
          _ffvIcon = _display ctrlCreate ["RscPicture", -1, _crewControlsGroup];
          _ffvIcon ctrlSetPosition [7 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
          _ffvIcon ctrlSetText "GUI\textures\icon_ffv.paa";
          _ffvIcon ctrlSetTextColor [0.7,0.7,0.7,1];
          /* _ffvIcon ctrlSetFade 0.3; */
          _ffvIcon ctrlCommit 0;

          if (_passengersFFV > 1) then
          {
            _ffvText = _display ctrlCreate ["A3A_InfoText", -1, _crewControlsGroup];
            _ffvText ctrlSetPosition [10 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 3 * GRID_H];
            _ffvText ctrlSetText str _passengersFFV;
            _ffvText ctrlSetTextColor [0.7,0.7,0.7,1];
            _ffvText ctrlCommit 0;
          };
        };

        _crewInfoAdded = _crewInfoAdded + 1;
      };

      _added = _added + 1;
    } forEach buyableVehiclesList;

    // Adds padding to the bottom, allowing the scroll to go a little past the items
    // Might look better on some configurations?
    /* _paddingBottom = _display ctrlCreate ["RscText", -1, _vehiclesControlsGroup];
    _fullRow = if (_added % 3 == 0) then {0} else {1};
    _paddingBottom ctrlSetPosition [0, (floor (_added / 3)) * (44 * GRID_H) + _fullRow * (44 * GRID_H), 1 * GRID_W, 7 * GRID_H];
    _paddingBottom ctrlSetText "";
    _paddingBottom ctrlCommit 0; */

    // Show list
    _vehiclesControlsGroup ctrlSetFade 0;
    _vehiclesControlsGroup ctrlCommit 0.1;
  };
};
