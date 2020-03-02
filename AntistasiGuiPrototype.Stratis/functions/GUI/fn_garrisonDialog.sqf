#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_GarrisonDialog";
    waitUntil {dialog}; // Wait until the dialog is actually created

    /* _display = findDisplay A3A_IDD_GARRISONDIALOG;
    _display displayAddEventHandler ["KeyDown",{
      _display = findDisplay A3A_IDD_GARRISONDIALOG;
      _map = _display displayCtrl A3A_IDC_GARRISONMAP;
      systemChat format ["Map zoom: ", ctrlMapScale _maps];
    }]; */

    ["mapClicked", [getPos player select 0, getPos player select 1]] spawn A3A_fnc_garrisonDialog;

    _display = findDisplay A3A_IDD_GARRISONDIALOG;

    // We don't show map markers on the garrison map to avoid clutter,
    // so we only show the ones relevant to the garrisons

    _outpostIconData = [];

    _map = _display displayCtrl A3A_IDC_GARRISONMAP;
    {
      _x params ["_marker", "_type", "_garrison"];
      _name = markerText _marker;
      _pos = getMarkerPos _marker;
      _color = [0.1,0.7,0.1,1];

      _icon = switch (_type) do {
        case ("hq"): {
          "\A3\ui_f\data\Map\Markers\Military\flag_CA.paa";
        };

        case ("outpost"): {
          "\A3\ui_f\data\Map\MapControl\bunker_CA.paa";
        };

        default {
          "\A3\ui_f\data\Map\MapControl\ruin_CA.paa.paa";
        };
      };

      _outpostIconData pushBack [_name, _pos, _icon, _color];
    } forEach outposts;

    _map setVariable ["outpostIconData", _outpostIconData];

    _map ctrlAddEventHandler ["Draw",{
      _display = findDisplay A3A_IDD_GARRISONDIALOG;
      _map = _display displayCtrl A3A_IDC_GARRISONMAP;
      _outpostIconData = _map getVariable "outpostIconData";
      {
        _x params ["_name", "_pos", "_icon", "_color"];
        _map drawIcon [
          _icon, // texture
          _color,
          _pos,
          32, // width
          32, // height
          0, // angle
          _name, // text
          2 // shadow (outline if 2)
        ];
      } forEach _outpostIconData;
    }];
  };

  case ("mapClicked"): {

    // Find closest marker to the clicked position
    _clickedPosition = [_params select 0, _params select 1];
    _selectedMarker = [allMapMarkers, _clickedPosition] call BIS_fnc_nearestPosition;
    _position = getMarkerPos _selectedMarker;

    // Get the data from the marker
    _garrisonName = markerText _selectedMarker;
    _outpostData = [_selectedMarker] call A3A_fnc_getOutpostByMarkerName;
    _type = _outpostData select 1;
    _garrison = _outpostData select 2;
    _garrison params [
      "_rifleman",
      "_squadLeader",
      "_autorifleman",
      "_grenadier",
      "_medic",
      "_mortar",
      "_marksman",
      "_at"];

    /* _rifleman = _garrisonNumbers select 0;
    _squadleader = _garrisonNumbers select 1;
    _autorifleman = _garrisonNumbers select 2;
    _grenadier = _garrisonNumbers select 3;
    _medic = _garrisonNumbers select 4;
    _mortar = _garrisonNumbers select 5;
    _marksman = _garrisonNumbers select 6;
    _at = _garrisonNumbers select 7; */

    /* systemChat ("Map clicked: " + str _clickedPosition);
    systemChat (_garrisonName + ": " + str _position); */

    // Get the controls
    _display = findDisplay A3A_IDD_GARRISONDIALOG;
    _garrisonTitle = _display displayCtrl A3A_IDC_GARRISONTITLE;
    _riflemanNumber = _display displayCtrl A3A_IDC_RIFLEMANNUMBER;
    _squadleaderNumber = _display displayCtrl A3A_IDC_SQUADLEADERNUMBER;
    _autoriflemanNumber = _display displayCtrl A3A_IDC_AUTORIFLEMANNUMBER;
    _grenadierNumber = _display displayCtrl A3A_IDC_GRENADIERNUMBER;
    _medicNumber = _display displayCtrl A3A_IDC_MEDICNUMBER;
    _mortarNumber = _display displayCtrl A3A_IDC_MORTARNUMBER;
    _marksmanNumber = _display displayCtrl A3A_IDC_MARKSMANNUMBER;
    _atNumber = _display displayCtrl A3A_IDC_ATNUMBER;
    _map = _display displayCtrl A3A_IDC_GARRISONMAP;

    /* systemChat format["Display:%1 MapControl: %2", str _display, str _map]; */

    // Add currently selected marker to map, we need it later for... stuff...
    _map setVariable ["selectedOutpost", _selectedMarker];

    // Update controls
    _garrisonTitle ctrlSetText _garrisonName;
    _riflemanNumber ctrlSetText str _rifleman;
    _squadleaderNumber ctrlSetText str _squadleader;
    _autoriflemanNumber ctrlSetText str _autorifleman;
    _grenadierNumber ctrlSetText str _grenadier;
    _medicNumber ctrlSetText str _medic;
    _mortarNumber ctrlSetText str _mortar;
    _marksmanNumber ctrlSetText str _marksman;
    _atNumber ctrlSetText str _at;

    // Draw selection marker
    _radius = 85;
    _dir = 0;
    _map setVariable["data", [_position, _radius, _dir]];
    // TODO: Change to remove only the selection marker
    // we need another one to draw the outposts themselves
    /* _map ctrlRemoveAllEventHandlers "Draw"; */
    _selectEH = _map getVariable "selectEH";
    if !(isNil "_selectEH") then {
      _map ctrlRemoveEventHandler ["Draw", _selectEH];
    };
    _selectEH = _map ctrlAddEventHandler ["Draw",{

      _map = _this select 0;
      _data = _map getVariable "data";
      _data params ["_position", "_radius", "_dir"];
      if (_dir == 0) then {
        _radius = _radius - 0.5;
        if (_radius < 75) then {
          _dir = 1; // Reverse direction
        };
      } else {
        _radius = _radius + 0.5;
        if (_radius > 85) then {
          _dir = 0;
        };
      };
      _map setVariable["data", [_position, _radius, _dir]];
      _map drawIcon [
         "\A3\ui_f\data\IGUI\Cfg\Cursors\selectOver_ca.paa",
        [1,1,1,1],
        _position,
        _radius,
        _radius,
        0
      ];
      /* _map drawEllipse [_position, _radius, _radius, 0, [1,1,1,1], _texture]; */
    }];

    _map setVariable ["selectEH", _selectEH];

    // Pan to location
    _map ctrlMapAnimAdd [0.2, ctrlMapScale _map, _position];
    /* systemChat format["Map scale %1", ctrlMapScale _map]; */
    ctrlMapAnimCommit _map;
  };

// TODO: this needs to be generalized a bit for garrison update compatibility
  case ("garrisonAdd"): {
    _type = _params select 0;
    _num = _params select 1;

    _display = findDisplay A3A_IDD_GARRISONDIALOG;
    _text = "";
    _typeIndex = -1;
    switch (_type) do
    {
      case ("rifleman"): {
        _text = _display displayCtrl A3A_IDC_RIFLEMANNUMBER;
        _typeIndex = 0;
      };
      case ("squadleader"): {
          _text = _display displayCtrl A3A_IDC_SQUADLEADERNUMBER;
          _typeIndex = 1;
      };
      case ("autorifleman"): {
          _text = _display displayCtrl A3A_IDC_AUTORIFLEMANNUMBER;
          _typeIndex = 2;
      };
      case ("grenadier"): {
          _text = _display displayCtrl A3A_IDC_GRENADIERNUMBER;
          _typeIndex = 3;
      };
      case ("medic"): {
          _text = _display displayCtrl A3A_IDC_MEDICNUMBER;
          _typeIndex = 4;
      };
      case ("mortar"): {
          _text = _display displayCtrl A3A_IDC_MORTARNUMBER;
          _typeIndex = 5;
      };
      case ("marksman"): {
          _text = _display displayCtrl A3A_IDC_MARKSMANNUMBER;
          _typeIndex = 6;
      };
      case ("at"): {
          _text = _display displayCtrl A3A_IDC_ATNUMBER;
          _typeIndex = 7;
      };
    };

    _val = parseNumber (ctrlText _text);
    _newVal = _val + _num;
    _newVal = 0 max _newVal;
    _map = _display displayCtrl A3A_IDC_GARRISONMAP;

    // Update garrison in outpost array
    _selectedMarker = _map getVariable "selectedOutpost";
    if (_typeIndex != -1) then {
      {
        if ((_x select 0) == _selectedMarker) then {
          /* systemChat format ["Trying to add garrison to %1", _x]; */

          ((outposts select _forEachIndex) select 2) set [_typeIndex, _newVal];
        };
      } forEach outposts;
    };

    _text ctrlSetText str _newVal;
    /* systemChat format["Type: %1, Num: %2, Text: %3, Val: %4 NewVal: %5", _type, _num, _text, _val, _newVal]; */
  };
};
