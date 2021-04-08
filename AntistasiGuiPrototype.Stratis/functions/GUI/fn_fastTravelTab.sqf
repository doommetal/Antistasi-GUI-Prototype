/*
Maintainer: DoomMetal
    Handles updating and controls on the Fast Travel tab of the Main dialog.

Arguments:
    <STRING> Mode
    <ARRAY<ANY>> Array of params for the mode when applicable. Params for specific modes are documented in the modes.

Return Value:
    Nothing

Scope: Clients, Local Arguments, Local Effect
Environment: Scheduled for control changes / Unscheduled for update
Public: No
Dependencies:
    None

Example:
    ["update"] call A3A_fnc_fastTravelTab;
*/

// disableSerialization; // TODO: Remove when merging
#include "..\..\GUI\ids.inc"
#include "..\..\GUI\defines.hpp"
#include "..\..\GUI\textures.inc"

// Logging
#define Log_Debug true
#define Log_Error true
#define Log_Trace true
#include "..\..\LogMacros.inc"

params[["_mode","update"], ["_params",[]]];

switch (_mode) do
{
  case ("update"):
  {
    Trace("Updating Fast Travel tab");
    // Show back button
    private _display = findDisplay A3A_IDD_MainDialog;
    private _backButton = _display displayCtrl A3A_IDC_MainDialogBackButton;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["player"]] call A3A_fnc_mainDialog;
    }];
    _backButton ctrlShow true;

    // TODO: Update title bar

    // Show map
    private _fastTravelMap = _display displayCtrl A3A_IDC_FASTTRAVELMAP;
    _fastTravelMap ctrlShow true;
    private _selectedMarker = _fastTravelMap getVariable ["selectedMarker", ""];
    private _markerName = markerText _markerName;

    private _hcMode = _fastTravelMap getVariable ["hcMode", false];
    Trace_1("HC Mode active: %1", _hcMode);

    // Draw selection markers

    // Update other controls
    private _fastTravelSelectText = _display displayCtrl A3A_IDC_FASTTRAVELSELECTTEXT;
    private _fastTravelInfoText = _display displayCtrl A3A_IDC_FASTTRAVELLOCATIONGROUP;
    private _fastTravelCommitButton = _display displayCtrl A3A_IDC_FASTTRAVELCOMMITBUTTON;

    // Check if location is set.
    if !(_selectedMarker isEqualTo "") then {
      // Enable button
      _fastTravelCommitButton ctrlEnable true;
      // Hide select location text
      _fastTravelSelectText ctrlShow false;
      // Show info text
      _fastTravelInfoText ctrlShow true;
      // Update info text
      _fastTravelInfoText ctrlSetStructuredText parseText format ["You will travel to:<br/>%1<br/><br/>This will take 1m 5s.<br/><br/>You will bring your vehicle along as well as any cargo and passengers along with you.", _markerName];
    } else {
      // Disable button
      _fastTravelCommitButton ctrlEnable false;
      // Enable select location text
      _fastTravelSelectText ctrlShow true;
      // Hide info text
      _fastTravelInfoText ctrlShow false;
    };

  };

  case ("mapClicked"):
  {
    Debug_1("Fast Travel map clicked: %1", _params);
    private _display = findDisplay A3A_IDD_MainDialog;
    private _fastTravelMap = _display displayCtrl A3A_IDC_FASTTRAVELMAP;
    // Find closest marker to the clicked position
    _params params ["_clickedPosition"];
    private _clickedWorldPosition = _fastTravelMap ctrlMapScreenToWorld _clickedPosition;
    private _outposts = [];
    {
      _outposts pushBack _x # 0; // Get marker name from list
    } forEach outposts;
    private _selectedMarker = [_outposts, _clickedWorldPosition] call BIS_fnc_nearestPosition;
    Debug_1("Selected marker: %1", _selectedMarker);

    _markerMapPosition = _fastTravelMap ctrlMapWorldToScreen (getMarkerPos _selectedMarker);
    private _maxDistance = 6 * GRID_W; // TODO: Move somewhere else?
    private _distance = _clickedPosition distance _markerMapPosition;
    if (_distance > _maxDistance) exitWith
    {
      Debug("Distance too large, deselecting");
      _fastTravelMap setVariable ["selectedMarker", ""];
      _fastTravelMap setVariable ["selectMarkerData", []];
    };

    _fastTravelMap setVariable ["selectedMarker", _selectedMarker];
    private _position = getMarkerPos _selectedMarker;
    _fastTravelMap setVariable ["selectMarkerData", [_position, 48, 0]];

    ["update"] call A3A_fnc_fastTravelTab;
  };

  case ("commitButtonClicked"): // TODO: Placeholder, replace with actual FT function on merge
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _fastTravelMap = _display displayCtrl A3A_IDC_FASTTRAVELMAP;
    private _marker = _fastTravelMap getVariable ["selectedMarker", ""];
    if !(_marker isEqualTo "") then {
      player setPos getMarkerPos _marker;
      closeDialog 0;
    };
  };

  default {
    // Log error if attempting to call a mode that doesn't exist
    Error_1("Fast Travel tab mode does not exist: %1", _mode);
  };
};
