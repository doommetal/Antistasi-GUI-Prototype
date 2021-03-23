/*
Maintainer: DoomMetal
    Handles updating and controls on the AI Management tab of the Main dialog.

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
    ["update"] call A3A_fnc_aiManagementTab;
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
    Trace("Updating AI Management Tab");
    // Show back button
    private _display = findDisplay A3A_IDD_MainDialog;
    private _backButton = _display displayCtrl A3A_IDC_MainDialogBackButton;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["player"]] call A3A_fnc_mainDialog;
    }];
    _backButton ctrlShow true;

    // Get list of AI group members
    _aisInGroup = [];
    {
      if (!isPlayer _x) then {_aisInGroup pushBackUnique _x};
    } forEach units group player;

    // Update AI listBox
    private _aiListBox = _display displayCtrl A3A_IDC_AILISTBOX;
    lbClear _aiListBox;

    // If there are no AI just add a message and disable the listBox
    if (count _aisInGroup < 1) then
    {
      _aiListBox ctrlEnable false;
      _aiListBox lbAdd "No AIs in group. You can recruit them at the flag.";
    } else {
      // Else add units to the listbox
      _aiListBox ctrlEnable true;
      {
        _index = _aiListBox lbAdd name _x;
        _netId = _x call BIS_fnc_netId; // TODO: can be only netId command instead of function in MP-only
        Trace_1("Adding unit: %1", _netId);
        _aiListBox lbSetData [_index, _netId];
      } forEach _aisInGroup;
    };

    // If any units are selected on the command bar select those in the list
    {
      _netId = _x call BIS_fnc_netId; // TODO: can be only netId command instead of function in MP-only
      Trace_1("Selecting unit: %1", _netId);
      _lbSize = lbSize _aiListBox;
      for "_i" from 0 to (_lbSize - 1) do
      {
        _listNetId = _aiListBox lbData _i;
        Trace_2("LB netID: %1, Sel netId: %2", _listNetId, _netId);
        if (_listNetId isEqualTo _netId) then
        {
          _aiListBox lbSetSelected [_i, true];
        };
      };
    } forEach groupSelectedUnits player;

    ["aiListBoxSelectionChanged"] call A3A_fnc_aiManagementTab;
  };

  case ("clearAIListboxSelection"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _aiListBox = _display displayCtrl A3A_IDC_AILISTBOX;
    _lbSize = lbSize _aiListBox;
    for "_i" from 0 to _lbSize - 1 do
    {
      _aiListBox lbSetSelected [_i, false];
    };

    // Update Selection
    ["aiListBoxSelectionChanged"] spawn A3A_fnc_aiManagementTab;
  };

  case ("aiListBoxSelectionChanged"):
  {
    // Needs scheduled environment

    private _display = findDisplay A3A_IDD_MainDialog;
    private _aiListBox = _display displayCtrl A3A_IDC_AILISTBOX;

    // Disable remote control button if more than 1 AI is selected
    private _aiControlButton = _display displayCtrl A3A_IDC_AICONTROLBUTTON;
    private _aiControlIcon = _display displayCtrl A3A_IDC_AICONTROLICON;
    _lbSelection = lbSelection _aiListBox;
    Trace_1("AI LB selection changed: %1", _lbSelection);
    if (count _lbSelection == 1) then
    {
      _aiControlButton ctrlEnable true;
      _aiControlButton ctrlSetTooltip "";
      _aiControlIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
    } else {
      _aiControlButton ctrlEnable false;
      _aiControlButton ctrlSetTooltip "You can only remote control single units\nSelect exactly one AI in the list";
      _aiControlIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
    };

    // If none are selected, disable all the other buttons
    private _aiDismissButton = _display displayCtrl A3A_IDC_AIDISMISSBUTTON;
    private _aiDismissIcon = _display displayCtrl A3A_IDC_AIDISMISSICON;
    private _aiAutoLootButton = _display displayCtrl A3A_IDC_AIAUTOLOOTBUTTON;
    private _aiAutoLootIcon = _display displayCtrl A3A_IDC_AIAUTOLOOTICON;
    private _aiAutoHealButton = _display displayCtrl A3A_IDC_AIAUTOHEALBUTTON;
    private _aiAutoHealIcon = _display displayCtrl A3A_IDC_AIAUTOHEALICON;
    if (count _lbSelection > 0) then
    {
      _aiDismissButton ctrlEnable true;
      _aiDismissButton ctrlSetTooltip "";
      _aiDismissIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
      _aiAutoLootButton ctrlEnable true;
      _aiAutoLootButton ctrlSetTooltip "";
      _aiAutoLootIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
      _aiAutoHealButton ctrlEnable true;
      _aiAutoHealButton ctrlSetTooltip "";
      _aiAutoHealIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
    } else {
      _aiDismissButton ctrlEnable false;
      _aiDismissButton ctrlSetTooltip "Select AI in the list";
      _aiDismissIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
      _aiAutoLootButton ctrlEnable false;
      _aiAutoLootButton ctrlSetTooltip "Select AI in the list";
      _aiAutoLootIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
      _aiAutoHealButton ctrlEnable false;
      _aiAutoHealButton ctrlSetTooltip "Select AI in the list";
      _aiAutoHealIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
    };
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("AI Management tab mode does not exist: %1", _mode);
  };
};
