/*
Maintainer: DoomMetal
    Draws map markers to map controls

Arguments:
    None

Return Value:
    None

Scope: Internal
Environment: Unscheduled
Public: No
Dependencies:
    <ARRAY> markersX // TODO: Probably needs update on merge

Example:
    _fastTravelMap ctrlAddEventHandler ["Draw","_this call A3A_fnc_mapDrawOutpostsEH"];
*/

#include "..\..\GUI\textures.inc"

params ["_map"];

// Get marker data
private _outpostIconData = [];
{
  private _marker = _x;
  private _type = _marker call A3A_fnc_getLocationMarkerType;
  private _name = markerText _marker;
  private _pos = getMarkerPos _marker;
  private _color = [0.1,0.7,0.1,1];

  private _icon = switch (_type) do {
    case ("hq"): {
      "\A3\ui_f\data\Map\Markers\Military\flag_CA.paa";
    };

    case ("city"): {
      MISSION_ROOT + A3A_Tex_Icon_Town;
    };

    case ("factory"): {
      MISSION_ROOT + A3A_Tex_Icon_Factory;
    };

    case ("resource"): {
      MISSION_ROOT + A3A_Tex_Icon_Resource;
    };

    case ("seaport"): {
      MISSION_ROOT + A3A_Tex_Icon_Seaport;
    };

    case ("airport"): {
      MISSION_ROOT + A3A_Tex_Icon_Airbase;
    };

    case ("outpost"): {
      MISSION_ROOT + A3A_Tex_Icon_Outpost;
    };

    default {
      "\A3\ui_f\data\Map\Markers\Military\flag_CA.paa";
    };
  };

  _outpostIconData pushBack [_name, _pos, _icon, _color];
} forEach markersX;

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
