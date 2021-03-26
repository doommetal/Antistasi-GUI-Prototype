/*
Maintainer: DoomMetal
    Handles updating and controls on the Player tab of the Main dialog.

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
    ["update"] call A3A_fnc_playerTab;
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
    Trace ("Updating Player tab");
    private _display = findDisplay A3A_IDD_MainDialog;

    // Disable buttons for functions that are unavailable

    // Undercover
    // TODO: Get actual reason for no undercover and display in tooltip
    private _undercoverButton = _display displayCtrl A3A_IDC_UNDERCOVERBUTTON;
    private _undercoverIcon = _display displayCtrl A3A_IDC_UNDERCOVERICON;
    if (canGoUndercover) then
    {
      _undercoverButton ctrlEnable true;
      _undercoverButton ctrlSetTooltip "";
      _undercoverIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
    } else {
      _undercoverButton ctrlEnable false;
      _undercoverButton ctrlSetTooltip "Can't go undercover\n\nIllegal items visible\nYou have been reported by the enemy"; // TODO: localize later, not final yet
      _undercoverIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
    };

    // Fasttravel
    // TODO: Get actual reason for no fast travel and display in tooltip
    private _fastTravelButton = _display displayCtrl A3A_IDC_FASTTRAVELBUTTON;
    private _fastTravelIcon = _display displayCtrl A3A_IDC_FASTTRAVELICON;
    if (canFastTravel) then
    {
      _fastTravelButton ctrlEnable true;
      _fastTravelButton ctrlSetTooltip localize "STR_antistasi_dialogs_main_fast_travel_tooltip";
      _fastTravelIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
    } else {
      _fastTravelButton ctrlEnable false;
      _fastTravelButton ctrlSetTooltip "Can't fast travel\n\nEnemies nearby\nPetros broke your legs"; // TODO localize
      _fastTravelIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
    };

    // Construct
    // TODO: Get actual reason for no construction and display in tooltip
    private _constructButton = _display displayCtrl A3A_IDC_CONSTRUCTBUTTON;
    private _constructIcon = _display displayCtrl A3A_IDC_CONSTRUCTICON;
    if (canConstruct) then
    {
      _constructButton ctrlEnable true;
      _constructButton ctrlSetTooltip "";
      _constructIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
    } else {
      _constructButton ctrlEnable false;
      _constructButton ctrlSetTooltip "Can't make constructions\n\nYou need an engineer in your squad"; // TODO: localize later, not final yet
      _constructIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
    };

    // AI Management
    _aiManagementTooltipText = "";
    _canManageAi = false;

    // Check if AI Management is available
    switch (true) do
    {
      case !(leader player == player):
      {
        _aiManagementTooltipText = localize "STR_antistasi_dialogs_main_ai_management_sl_tooltip";
      };

      case ({!isPlayer _x} count units group player < 1):
      {
        _aiManagementTooltipText = localize "STR_antistasi_dialogs_main_ai_management_no_ai_tooltip";
      };

      default
      {
        _canManageAi = true;
      };
    };

    private _aiManagementButton = _display displayCtrl A3A_IDC_AIMANAGEMENTBUTTON;
    private _aiManagementIcon = _display displayCtrl A3A_IDC_AIMANAGEMENTICON;

    if (_canManageAi) then
    {
      _aiManagementButton ctrlEnable true;
      _aiManagementButton ctrlSetTooltip "";
      _aiManagementIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
    } else {
      _aiManagementButton ctrlEnable false;
      _aiManagementButton ctrlSetTooltip _aiManagementTooltipText;
      _aiManagementIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
    };


    // Player info/stats section

    private _playerNameText = _display displayCtrl A3A_IDC_PLAYERNAMETEXT;
    private _playerRankText = _display displayCtrl A3A_IDC_PLAYERRANKTEXT;
    private _playerRankPicture = _display displayCtrl A3A_IDC_PLAYERRANKPICTURE;
    private _aliveText = _display displayCtrl A3A_IDC_ALIVETEXT;
    private _missionsText = _display displayCtrl A3A_IDC_MISSIONSTEXT;
    private _killsText = _display displayCtrl A3A_IDC_KILLSTEXT;
    private _commanderPicture = _display displayCtrl A3A_IDC_COMMANDERPICTURE;
    private _commanderText = _display displayCtrl A3A_IDC_COMMANDERTEXT;
    private _commanderButton = _display displayCtrl A3A_IDC_COMMANDERBUTTON;
    private _moneyText = _display displayCtrl A3A_IDC_MONEYTEXT;

    _playerNameText ctrlSetText name player;

    _playerRankText ctrlSetText ([player, "displayName"] call BIS_fnc_rankParams);
    _playerRankPicture ctrlSetText ([player, "texture"] call BIS_fnc_rankParams);

    // TODO: Make function for getting time alive
    private _time = time;
    private _days = floor (_time / 86400);
    private _hours = floor ((_time - _days * 86400) / 3600);
    private _minutes = floor (((_time - _days * 86400) - _hours * 3600) / 60);
    _aliveText ctrlSetText format [[_time] call A3A_fnc_formatTime]; // TODO: localize later, not final yet

    // TODO: Make function for getting num of completed missions
    private _missions = player getVariable "missionsCompleted";
    _missionsText ctrlSetText str _missions;

    // TODO: Make function for getting number of kills
    private _kills = player getVariable "kills";
    _killsText ctrlSetText str _kills;

    // TODO: Update commander icon/button

    private _money = player getVariable "moneyX"; // player getVariable moneyX
    _moneyText ctrlSetText format[localize "STR_antistasi_dialogs_main_player_money_text", _money];

    // Vehicle section
    private _vehicleGroup = _display displayCtrl A3A_IDC_PLAYERVEHICLEGROUP;
    private _noVehicleGroup = _display displayCtrl A3A_IDC_NOVEHICLEGROUP;

    // Vehicle section is only available to members
    if (player getVariable "isMember") then {

      // Attempt to get vehicle from cursortarget
      _vehicle = cursorTarget;
      // TODO: Add fallback to select the closest eligible vehicle in sight
      // TODO: Add check for distance

      if !(isNull _vehicle) then {
        // Check if vehicle is eligible for garage / sell, not a dude or house etc.
        if (_vehicle isKindOf "Air" or _vehicle isKindOf "LandVehicle") then {
          private _className = typeOf _vehicle;
          private _configClass = configFile >> "CfgVehicles" >> _className;
          private _displayName = getText (_configClass >> "displayName");
          private _editorPreview = getText (_configClass >> "editorPreview");

          private _vehicleNameLabel = _display displayCtrl A3A_IDC_VEHICLENAMELABEL;
          _vehicleNameLabel ctrlSetText _displayName;
          // For some reason the text control becomes active showing an ugly
          // white border, we disable it here to avoid that
          _vehicleNameLabel ctrlEnable false;

          private _vehiclePicture = _display displayCtrl A3A_IDC_VEHICLEPICTURE;
          _vehiclePicture ctrlSetText _editorPreview;

          // TODO: Disable garage, sell and add to air support buttons
          // if player is not in range of a friendly location

          if (playerIsCommander) then {
            // Disable "add to air support" button if vehicle is not eligible
            if !(_vehicle isKindOf "Air") then {
              private _addToAirSupportButton = _display displayCtrl A3A_IDC_ADDTOAIRSUPPORTBUTTON;
              _addToAirSupportButton ctrlEnable false;
              _addToAirSupportButton ctrlSetTooltip localize "STR_antistasi_dialogs_main_not_eligible_vehicle_tooltip";
            };
          } else {
            // Enable only "garage" and "lock/unlock" buttons to regular players
            private _sellVehicleButton = _display displayCtrl A3A_IDC_SELLVEHICLEBUTTON;
            _sellVehicleButton ctrlEnable false;
            _sellVehicleButton ctrlSetTooltip localize "STR_antistasi_dialogs_main_commander_only_tooltip";
            private _addToAirSupportButton = _display displayCtrl A3A_IDC_ADDTOAIRSUPPORTBUTTON;
            _addToAirSupportButton ctrlEnable false;
            _addToAirSupportButton ctrlSetTooltip localize "STR_antistasi_dialogs_main_commander_only_tooltip";
          };
          // Show vehicle group
          _noVehicleGroup ctrlShow false;
          _vehicleGroup ctrlShow true;
        } else {
          // Show no vehicle message
          _vehicleGroup ctrlShow false;
          _noVehicleGroup ctrlShow true;
        };
      } else {
        // Show no vehicle message
        _vehicleGroup ctrlShow false;
        _noVehicleGroup ctrlShow true;
      };
    } else {
      // Show not member message
      _vehicleGroup ctrlShow false;
      _noVehicleGroup ctrlShow true;
      private _noVehicleText = _display displayCtrl A3A_IDC_NOVEHICLETEXT;
      _noVehicleText ctrlSetText localize "STR_antistasi_dialogs_main_members_only";
    };
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("Player tab mode does not exist: %1", _mode);
  };
};
