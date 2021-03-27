/*
Maintainer: DoomMetal
    Event Handler for drawing outpost markers to the commander map

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
    _garrisonMap ctrlAddEventHandler ["Draw","_this call A3A_fnc_outpostMarkersEH"];
*/

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
