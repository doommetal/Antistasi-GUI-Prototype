#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_MinefieldDialog";
    waitUntil {dialog}; // Wait until the dialog is actually created

    _display = findDisplay A3A_IDD_MINEFIELDDIALOG;
  };

  case ("mapClicked"): {

    // Find closest marker to the clicked position
    _clickedPosition = _params select 0 ctrlMapScreenToWorld [ (_params select 2), (_params select 3) ];
    _selectedMarker = [allMapMarkers, _clickedPosition] call BIS_fnc_nearestPosition;
    _position = getMarkerPos _selectedMarker;

    // Get the data from the marker
    _minefieldName = markerText _selectedMarker;

    systemChat ("Map clicked: " + str _clickedPosition);

    // Get the controls
    _display = findDisplay A3A_IDD_MINEFIELDDIALOG;
    _map = _display displayCtrl A3A_IDC_MINEFIELDMAP;

    systemChat format["Display:%1 MapControl: %2", str _display, str _map];

    // Update controls

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
    ctrlMapAnimCommit _map;
  };
};
