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
  };

  case ("mapClicked"): {

    // Find closest marker to the clicked position
    _clickedPosition = [_params select 0, _params select 1];
    _selectedMarker = [allMapMarkers, _clickedPosition] call BIS_fnc_nearestPosition;
    _position = getMarkerPos _selectedMarker;

    // Get the data from the marker
    _garrisonName = markerText _selectedMarker;

    // TODO: Get the actual data when merging
    _rifleman = 0;
    _squadleader = 0;
    _autorifleman = 0;
    _grenadier = 0;
    _medic = 0;
    _mortar = 0;
    _marksman = 0;
    _at = 0;

    systemChat ("Map clicked: " + str _clickedPosition);
    systemChat (_garrisonName + ": " + str _position);

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

    systemChat format["Display:%1 MapControl: %2", str _display, str _map];

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
    _map ctrlRemoveAllEventHandlers "Draw";
    _map ctrlAddEventHandler ["Draw",{

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

    // Pan to location
    _map ctrlMapAnimAdd [0.2, ctrlMapScale _map, _position];
    systemChat format["Map scale %1", ctrlMapScale _map];
    ctrlMapAnimCommit _map;
  };

  case ("garrisonAdd"): {
    _type = _params select 0;
    _num = _params select 1;

    _display = findDisplay A3A_IDD_GARRISONDIALOG;
    _text = "";
    switch (_type) do
    {
      case ("rifleman"): {
        _text = _display displayCtrl A3A_IDC_RIFLEMANNUMBER;
      };
      case ("squadleader"): {
          _text = _display displayCtrl A3A_IDC_SQUADLEADERNUMBER;
      };
      case ("autorifleman"): {
          _text = _display displayCtrl A3A_IDC_AUTORIFLEMANNUMBER;
      };
      case ("grenadier"): {
          _text = _display displayCtrl A3A_IDC_GRENADIERNUMBER;
      };
      case ("medic"): {
          _text = _display displayCtrl A3A_IDC_MEDICNUMBER;
      };
      case ("mortar"): {
          _text = _display displayCtrl A3A_IDC_MORTARNUMBER;
      };
      case ("marksman"): {
          _text = _display displayCtrl A3A_IDC_MARKSMANNUMBER;
      };
      case ("at"): {
          _text = _display displayCtrl A3A_IDC_ATNUMBER;
      };
    };

    _val = parseNumber (ctrlText _text);
    _newVal = _val + _num;
    _newVal = 0 max _newVal;
    _text ctrlSetText str _newVal;
    systemChat format["Type: %1, Num: %2, Text: %3, Val: %4 NewVal: %5", _type, _num, _text, _val, _newVal];
  };
};
