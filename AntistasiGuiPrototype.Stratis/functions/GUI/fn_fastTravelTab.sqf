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

params[["_mode","onLoad"], ["_params",[]]];

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

    private _fastTravelMap = _display displayCtrl A3A_IDC_FASTTRAVELMAP;
    _fastTravelMap ctrlShow true;

    // TODO: Check if location is set.
    // Enable select location text if location is not set
    _fastTravelSelectText = _display displayCtrl A3A_IDC_FASTTRAVELSELECTTEXT;
    _fastTravelSelectText ctrlShow false;

    // Disable button if location is not set
    // _fastTravelCommitButton = _display displayCtrl A3A_IDC_FASTTRAVELCOMMITBUTTON;
    // _fastTravelCommitButton ctrlEnable false;

    // Update info text
    _fastTravelInfoText = _display displayCtrl A3A_IDC_FASTTRAVELLOCATIONGROUP;
    _fastTravelInfoText ctrlSetStructuredText parseText "You will travel to:<br/>Placeholder Outpost<br/><br/>This will take 1m 5s.<br/><br/>You will bring your vehicle along as well as any cargo and passengers along with you.";
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("Fast Travel tab mode does not exist: %1", _mode);
  };
};
