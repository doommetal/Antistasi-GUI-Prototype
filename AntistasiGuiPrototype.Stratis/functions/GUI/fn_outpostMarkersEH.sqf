// TODO: Add header
#include "..\..\GUI\ids.inc"

private _display = findDisplay A3A_IDD_HqDialog;
private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;
private _outpostIconData = _garrisonMap getVariable "outpostIconData";
{
  _x params ["_name", "_pos", "_icon", "_color"];
  _garrisonMap drawIcon [
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
