/*
Maintainer: doomMetal
Draws user markers to map controls
Used for cases where we want only user created markers, not editor placed ones

Arguments:
None

Return Value:
None

Scope: internal
Environment: Unscheduled
Public: No
Dependencies:
None

Example:
_commanderMap ctrlAddEventHandler ["Draw", "_this call A3A_fnc_mapDrawUserMarkersEH"];
*/

#include "..\..\GUI\textures.inc"
// logging
#define log_Debug true
#define log_Error true
#define log_Trace true
#include "..\..\logMacros.inc"

params ["_map"];

private _markersPath = "\A3\Ui_f\data\Map\Markers\Military\";

// Loop through all map markers
{
  // Check for user markers
  if !("_USER_DEFINED" in _x) then {continue};

  // Check marker channel, draw only global, command and side markers (0, 1, 2)
  private _channel = markerChannel _x;
  if !(_channel in [0,1,2]) then {continue};

  // Check for line markers
  if ((markerPolyline _x) isEqualto []) then {
    // not a line marker
    // Get marker data
    // todo: Fix paths, flag things are wrong
    Debug_1("Drawing user marker: %1", _x);
    _markertype = _markersPath + ((getmarkertype _x) select [3, (count getmarkertype _x) - 3]) + "_CA.paa";
    Debug_1("Marker type: %1", _markertype);
    _markerColor = (configFile >> "CfgmarkerColors" >> getmarkerColor _x >> "color") call BIS_fnc_colorConfigtorGBA;
    Debug_1("Marker color: %1", _markerColor);
    _markerPos = getmarkerPos _x;
    Debug_1("Marker pos: %1", _markerPos);
    _markertext = markertext _x;
    Debug_1("Marker text: %1", _markertext);

    // Draw marker
    _map drawIcon [
      _markertype, // texture
      _markerColor,
      _markerPos,
      32, // width
      32, // height
      0, // angle
      _markertext, // text
      0 // shadow (outline if 2)
    ];
  } else {
    // Marker is a line marker
    // do some special shits here
    Debug("Line marker");
  };
} forEach allMapMarkers;
