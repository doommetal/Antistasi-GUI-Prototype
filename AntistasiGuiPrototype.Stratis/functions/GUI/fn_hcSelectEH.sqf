// TODO: Add header
#include "..\..\GUI\ids.inc"

private _display = findDisplay A3A_IDD_MainDialog;
private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
private _data = _commanderMap getVariable "selectMarker";
_data params ["_radius", "_dir"];
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

_commanderMap setVariable ["selectMarker", [_radius, _dir]];
private _selectedGroup = _commanderMap getVariable "selectedGroup";

if !(_selectedGroup isEqualTo grpNull) then {
  private _position = getPos leader _selectedGroup;
  _commanderMap drawIcon [
  "\A3\ui_f\data\IGUI\Cfg\Cursors\selectOver_ca.paa",
  [1,1,1,0.75],
  _position,
  _radius,
  _radius,
  0
  ];
};
