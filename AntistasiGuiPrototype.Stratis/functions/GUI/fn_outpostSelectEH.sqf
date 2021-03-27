/*
Maintainer: DoomMetal
    Event Handler for drawing outpost select markers to the commander map

Arguments:
    None

Return Value:
    None

Scope: Internal
Environment: Unscheduled
Public: No
Dependencies:
    HQ Dialog must be open

Example:
    _garrisonMap ctrlAddEventHandler ["Draw","_this call A3A_fnc_outpostSelectEH"];
*/

private _garrisonMap = _this select 0;
private _data = _garrisonMap getVariable "data";
_data params ["_position", "_radius", "_dir"];
if (_dir == 0) then {
  _radius = _radius - 0.5;
  if (_radius < 48) then {
    _dir = 1; // Reverse direction
  };
} else {
  _radius = _radius + 0.5;
  if (_radius > 64) then {
    _dir = 0;
  };
};
_garrisonMap setVariable["data", [_position, _radius, _dir]];
_garrisonMap drawIcon [
   "\A3\ui_f\data\IGUI\Cfg\Cursors\selectOver_ca.paa",
  [1,1,1,0.75],
  _position,
  _radius,
  _radius,
  0
];
