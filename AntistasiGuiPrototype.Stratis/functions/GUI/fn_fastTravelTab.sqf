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
    private _fastTravelMap = _display displayCtrl A3A_IDC_FASTTRAVELMAP;
    private _hcMode = _fastTravelMap getVariable ["hcMode", false];
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    if (_hcMode) then {
      _backButton ctrlAddEventHandler ["MouseButtonClick", {
        ["switchTab", ["commander"]] call A3A_fnc_mainDialog;
      }];
    } else {
      _backButton ctrlAddEventHandler ["MouseButtonClick", {
        ["switchTab", ["player"]] call A3A_fnc_mainDialog;
      }];
    };
    _backButton ctrlShow true;

    // TODO: Update title bar

    // Show map
    _fastTravelMap ctrlShow true;
    private _selectedMarker = _fastTravelMap getVariable ["selectedMarker", ""];
    private _markerName = markerText _selectedMarker;

    // Format info text
    private _infoText = "";

    // Player/Group name + location name
    if (_hcMode) then {
      private _hcGroup = _fastTravelMap getVariable "hcGroup";
      private _groupName = groupId _hcGroup;
      _infoText = _infoText + _groupName + " will travel to:<br/>" + _markerName + "<br/><br/>"; // TODO: localize
    } else {
      _infoText = _infoText + "You will travel to:<br/>" + _markerName + "<br/><br/>"; // TODO: localize
    };

    // Time
    _infoText = _infoText + "This will take 1m 5s.<br/><br/>"; // TODO: localize

    // Vehicle
    if (!_hcMode && vehicle player != player) then {
      _infoText = _infoText + "You will bring your vehicle along as well as any cargo and passengers along with you."; // TODO: localize
    };


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
      _fastTravelInfoText ctrlSetStructuredText parseText _infoText;
      // Pan to location
      private _position = (_fastTravelMap getVariable "selectMarkerData") # 0;
      _fastTravelMap ctrlMapAnimAdd [0.2, ctrlMapScale _fastTravelMap, _position];
      ctrlMapAnimCommit _fastTravelMap;
    } else {
      // Disable button
      _fastTravelCommitButton ctrlEnable false;
      // Enable select location text
      _fastTravelSelectText ctrlShow true;
      // Set select hint text
      _selectText = "";
      if (_hcMode) then {
        private _hcGroup = _fastTravelMap getVariable "hcGroup";
        private _groupName = groupId _hcGroup;
        _selectText = format ["Click the map to select the location you want %1 to fast travel to.", _groupName]; // TODO: localize
      } else {
        _selectText = "Click the map to select the location you want to fast travel to."; // TODO: localize
      };
      _fastTravelSelectText ctrlSetText _selectText;
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
    private _maxDistance = 8 * GRID_W; // TODO: Move somewhere else?
    private _distance = _clickedPosition distance _markerMapPosition;
    if (_distance > _maxDistance) exitWith
    {
      Debug("Distance too large, deselecting");
      ["clearSelectedLocation"] call A3A_fnc_fastTravelTab;
      ["update"] call A3A_fnc_fastTravelTab;
    };

    _fastTravelMap setVariable ["selectedMarker", _selectedMarker];
    private _position = getMarkerPos _selectedMarker;
    _fastTravelMap setVariable ["selectMarkerData", [_position, 48, 0]];

    ["update"] call A3A_fnc_fastTravelTab;
  };

  case ("clearSelectedLocation"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _fastTravelMap = _display displayCtrl A3A_IDC_FASTTRAVELMAP;
    _fastTravelMap setVariable ["selectedMarker", ""];
    _fastTravelMap setVariable ["selectMarkerData", []];
  };

  case ("setHcMode"):
  {
    _params params [["_enableHcMode", false], ["_hcGroup", grpNull]];
    private _display = findDisplay A3A_IDD_MainDialog;
    private _fastTravelMap = _display displayCtrl A3A_IDC_FASTTRAVELMAP;
    Trace_2("Set high command mode: %1, group: %2", _enableHcMode, _hcGroup);
    _fastTravelMap setVariable ["hcMode", _enableHcMode];
    _fastTravelMap setVariable ["hcGroup", _hcGroup];
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
