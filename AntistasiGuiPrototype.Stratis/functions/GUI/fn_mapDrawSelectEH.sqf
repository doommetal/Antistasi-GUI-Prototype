/*
Maintainer: DoomMetal
    Event Handler for drawing select markers to maps.

Arguments:
    None

Return Value:
    None

Scope: Internal
Environment: Unscheduled
Public: No
Dependencies:
    Dialog with map must be open

Example:
    _commanderMap ctrlAddEventHandler ["Draw","_this call A3A_fnc_mapDrawSelectEH"];
*/

params ["_map"];

// Get select marker data
private _data = _map getVariable ["selectMarkerData", []];
// Exit if no data
if (count _data != 3) exitWith {nil}; // TODO: Might need to be changed?
_data params ["_position", "_radius", "_dir"];

// Update "pulsing"
private _minRadius = 48; // TODO: add optional parameters for these
private _maxRadius = 64;
private _pulseSpeed = 0.5;
if (_dir == 0) then {
  _radius = _radius - _pulseSpeed;
  if (_radius < _minRadius) then {
    _dir = 1; // Reverse direction
  };
} else {
  _radius = _radius + _pulseSpeed;
  if (_radius > _maxRadius) then {
    _dir = 0;
  };
};
_map setVariable ["selectMarkerData", [_position, _radius, _dir]];

_map drawIcon [
  "\A3\ui_f\data\IGUI\Cfg\Cursors\selectOver_ca.paa", // TODO: Replace hardcoded texture
  [1,1,1,0.75], // TODO: Replace hardcoded color
  _position,
  _radius,
  _radius,
  0
];
