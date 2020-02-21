#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_GarrisonDialog";
    waitUntil {dialog}; // Wait until the dialog is actually created

    _display = findDisplay A3A_IDD_GARRISONDIALOG;
  };

  case ("mapClicked"): {

    // Find closest marker to the clicked position
    _clickedPosition = _params select 0 ctrlMapScreenToWorld [ (_params select 2), (_params select 3) ];
    _selectedMarker = [allMapMarkers, _clickedPosition] call BIS_fnc_nearestPosition;
    _position = getMarkerPos _selectedMarker;

    // Get the data from the marker
    _garrisonName = markerText _selectedMarker;
    /* _garrisonData = _selectedMarker getVariable ["garrisonData"];
    _rifleman = _garrisonData select 0;
    _squadleader = _garrisonData select 1;
    _autorifleman = _garrisonData select 2;
    _grenadier = _garrisonData select 3;
    _medic = _garrisonData select 4;
    _mortar = _garrisonData select 5;
    _marksman = _garrisonData select 6;
    _at = _garrisonData select 7; */

    systemChat ("Map clicked: " + str _clickedPosition);
    systemChat (_garrisonName + ": " + str _position);

    // Get the controls
    _display = findDisplay A3A_IDD_GARRISONDIALOG;
    _garrisonTitle = _display displayCtrl A3A_IDC_GARRISONTITLE;
    /* _riflemanNumber = _display displayCtrl A3A_IDC_RIFLEMANNUMBER;
    _squadleaderNumber = _display displayCtrl A3A_IDC_SQUADLEADERNUMBER;
    _autoriflemanNumber = _display displayCtrl A3A_IDC_AUTORIFLEMANNUMBER;
    _grenadierNumber = _display displayCtrl A3A_IDC_GRENADIERNUMBER;
    _medicNumber = _display displayCtrl A3A_IDC_MEDICNUMBER;
    _mortarNumber = _display displayCtrl A3A_IDC_MORTARNUMBER;
    _marksmanNumber = _display displayCtrl A3A_IDC_MARKSMANNUMBER;
    _atNumber = _display displayCtrl A3A_IDC_ATNUMBER; */
    _map = _display displayCtrl A3A_IDC_GARRISONMAP;

    // Update controls
    _garrisonTitle ctrlSetText _garrisonName;
    /* _riflemanNumber ctrlSetText str _rifleman;
    _squadleaderNumber ctrlSetText str _squadleader;
    _autoriflemanNumber ctrlSetText str _autorifleman;
    _grenadierNumber ctrlSetText str _grenadier;
    _medicNumber ctrlSetText str _medic;
    _mortarNumber ctrlSetText str _mortar;
    _marksmanNumber ctrlSetText str _marksman;
    _atNumber ctrlSetText str _at; */

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
         MISSION_ROOT + "GUI\textures\icon_driver.paa",
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
    ctrlMapAnimCommit _map;
  };
};
