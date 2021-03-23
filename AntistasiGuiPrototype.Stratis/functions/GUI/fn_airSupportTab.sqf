/*
Maintainer: DoomMetal
    Handles updating and controls on the Air Support tab of the Main dialog.

Arguments:
    <STRING> Mode
    <ARRAY<ANY>> Array of params for the mode when applicable. Params for specific modes are documented in the modes.

Return Value:
    Nothing

Scope: Clients, Local Arguments, Local Effect
Environment: Unscheduled
Public: No
Dependencies:
    None

Example:
    ["update"] call A3A_fnc_airSupportTab;
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
    Trace("Updating Air Support tab");
    // Show back button
    private _display = findDisplay A3A_IDD_MainDialog;
    private _backButton = _display displayCtrl A3A_IDC_MainDialogBackButton;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["commander"]] call A3A_fnc_mainDialog;
    }];
    _backButton ctrlShow true;

    // TODO: Display remaining air support points
    // TODO: Display plane used for air support
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("Air Support tab mode does not exist: %1", _mode);
  };
};
