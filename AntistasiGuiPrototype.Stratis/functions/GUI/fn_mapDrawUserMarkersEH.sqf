/*
Maintainer: DoomMetal
    Draws user markers to map controls
    Used for cases where we want only user created markers, not editor placed ones

Arguments:
    None

Return Value:
    None

Scope: Internal
Environment: Unscheduled
Public: No
Dependencies:
    None

Example:
    _commanderMap ctrlAddEventHandler ["Draw","_this call A3A_fnc_mapDrawUserMarkersEH"];
*/

#include "..\..\GUI\textures.inc"
// Logging
#define Log_Debug true
#define Log_Error true
#define Log_Trace true
#include "..\..\LogMacros.inc"

params ["_map"];

private _markersPath = "\A3\Ui_f\data\Map\Markers\Military\";

// Loop through all map markers
{
  // Check for user markers
  if ("_USER_DEFINED" in _x) then {
    // Check for line markers
    if ((markerPolyline _x) isEqualTo []) then {

      // Get marker data
      // TODO: Fix paths, flag things are wrong
      Debug_1("Drawing user marker: %1", _x);
      _markerType = _markersPath + ((getMarkerType _x) select [3, (count getMarkerType _x) - 3]) + "_CA.paa";
      Debug_1("Marker type: %1", _markerType);
      _markerColor = (configfile >> "CfgMarkerColors" >> getMarkerColor _x >> "color") call BIS_fnc_colorConfigToRGBA;
      Debug_1("Marker color: %1", _markerColor);
      _markerPos = getMarkerPos _x;
      Debug_1("Marker pos: %1", _markerPos);
      _markerText = markerText _x;
      Debug_1("Marker text: %1", _markerText);

      // Draw marker
      _map drawIcon [
        _markerType, // texture
         _markerColor,
        _markerPos,
        32, // width
        32, // height
        0, // angle
        _markerText, // text
        0 // shadow (outline if 2)
      ];
    } else {
      // Marker is a line marker
      // Do some special shits here
      Debug("Line marker");
    };
  };

} forEach allMapMarkers;
