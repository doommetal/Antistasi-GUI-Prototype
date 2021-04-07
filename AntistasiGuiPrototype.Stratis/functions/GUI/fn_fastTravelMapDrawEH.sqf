/*
Maintainer: DoomMetal
    Event Handler for drawing outpost markers to the fast travel map

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
    _fastTravelMap ctrlAddEventHandler ["Draw","_this call A3A_fnc_fasttravelMapDrawEH"];
*/

#include "..\..\GUI\ids.inc"

private _display = findDisplay A3A_IDD_MainDialog;
private _fastTravelMap = _display displayCtrl A3A_IDC_FASTTRAVELMAP;

// Get outposts
private _outpostIconData = [];
{
  _x params ["_marker", "_type", "_garrison"];
  private _name = markerText _marker;
  private _pos = getMarkerPos _marker;
  private _color = [0.1,0.7,0.1,1];

  private _icon = switch (_type) do {
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

{
  _x params ["_name", "_pos", "_icon", "_color"];
  _fastTravelMap drawIcon [
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
