/*
Maintainer: DoomMetal
    Handles updating and controls on the Admin tab of the Main dialog.

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
    ["update"] call A3A_fnc_adminTab;
*/

#include "..\..\GUI\ids.inc"
#include "..\..\GUI\defines.hpp"
#include "..\..\GUI\textures.inc"
#include "..\..\Includes\common.inc"
FIX_LINE_NUMBERS()

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do
{
  case ("update"):
  {
    Trace("Updating admin tab");
    private _display = findDisplay A3A_IDD_MainDialog;
    // Update AI limit settings
    _civLimitSlider = _display displayCtrl A3A_IDC_CIVLIMITSLIDER;
    _civLimitSlider sliderSetRange [civLimitMin,civLimitMax];
    _civLimitSlider sliderSetSpeed [10, 10];
    _civLimit = missionNamespace getVariable ["civPerc",0];
    _civLimitSlider sliderSetPosition _civLimit;
    ctrlSetText [A3A_IDC_CIVLIMITEDITBOX, str _civLimit];

    _spawnDistanceSlider = _display displayCtrl A3A_IDC_SPAWNDISTANCESLIDER;
    _spawnDistanceSlider sliderSetRange [spawnDistanceMin,spawnDistanceMax];
    _spawnDistanceSlider sliderSetSpeed [100, 100];
    _spawnDistance = missionNamespace getVariable ["distanceSPWN",0];
    _spawnDistanceSlider sliderSetPosition _spawnDistance;
    ctrlSetText [A3A_IDC_SPAWNDISTANCEEDITBOX, str _spawnDistance];

    _aiLimiterSlider = _display displayCtrl A3A_IDC_AILIMITERSLIDER;
    _aiLimiterSlider sliderSetRange [civLimitMin,civLimitMax];
    _aiLimiterSlider sliderSetSpeed [10, 10];
    _aiLimiter = missionNamespace getVariable ["maxUnits",0];
    _aiLimiterSlider sliderSetPosition _aiLimiter;
    ctrlSetText [A3A_IDC_AILIMITEREDITBOX, str _aiLimiter];

    // Get Debug info
    // TODO UI-update: change this to get server values instead when merging
    private _debugText = _display displayCtrl A3A_IDC_DEBUGINFO;
    private _missionTime = [time] call A3A_fnc_formatTime;
    private _serverFps = (round (diag_fps * 10)) / 10;
    private _connectedHCs = 0;
    private _players = 0;
    private _allUnits = count allUnits;
    private _deadUnits = 1349;
    private _countGroups = count allGroups;
    private _countRebels = 16;
    private _countInvaders = 5;
    private _countOccupants = 37;
    private _countCiv = 4096;
    private _destroyedVehicles = 2;

    // TODO UI-update: localize later, not final yet
    private _formattedString = format [
"<t font='EtelkaMonospacePro' size='0.8'>
<t>Mission time:</t><t align='right'>%1</t><br />
<t>Server FPS:</t><t align='right'>%2</t><br />
<t>Connected HCs:</t><t align='right'>%3</t><br />
<t>Players:</t><t align='right'>%4</t><br />
<t>Groups</t><t align='right'>%5</t><br />
<t>Units:</t><t align='right'>%6</t><br />
<t>Dead units:</t><t align='right'>%7</t><br />
<t>Rebels:</t><t align='right'>%8</t><br />
<t>Invaders:</t><t align='right'>%9</t><br />
<t>Occupants:</t><t align='right'>%10</t><br />
<t>Civs:</t><t align='right'>%11</t><br />
<t>Wrecks:</t><t align='right'>%12</t>
</t>",
      _missionTime,
      _serverFps,
      _connectedHCs,
      _players,
      _countGroups,
      _allUnits,
      _deadUnits,
      _countRebels,
      _countInvaders,
      _countOccupants,
      _countCiv,
      _destroyedVehicles
    ];

    _debugText ctrlSetStructuredText parseText _formattedString;

  };

  // Admin Tab
  case ("civLimitSliderChanged"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _civLimitSlider = _display displayCtrl A3A_IDC_CIVLIMITSLIDER;
    private _civLimitEditBox = _display displayCtrl A3A_IDC_CIVLIMITEDITBOX;
    private _sliderValue = sliderPosition _civLimitSlider;
    _civLimitEditBox ctrlSetText str floor _sliderValue;
  };

  case ("civLimitEditBoxChanged"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _civLimitEditBox = _display displayCtrl A3A_IDC_CIVLIMITEDITBOX;
    private _civLimitSlider = _display displayCtrl A3A_IDC_CIVLIMITSLIDER;
    private _civLimitEditBoxValue = floor parseNumber ctrlText _civLimitEditBox;
    _civLimitEditBox ctrlSetText str _civLimitEditBoxValue;  // Strips non-numeric characters
    _civLimitSlider sliderSetPosition _civLimitEditBoxValue;
    if (_civLimitEditBoxValue < civLimitMin) then {_civLimitEditBox ctrlSetText str civLimitMin};
    if (_civLimitEditBoxValue > civLimitMax) then {_civLimitEditBox ctrlSetText str civLimitMax};
  };

  case ("spawnDistanceSliderChanged"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _spawnDistanceSlider = _display displayCtrl A3A_IDC_SPAWNDISTANCESLIDER;
    private _spawnDistanceEditBox = _display displayCtrl A3A_IDC_SPAWNDISTANCEEDITBOX;
    private _sliderValue = sliderPosition _spawnDistanceSlider;
    _spawnDistanceEditBox ctrlSetText str floor _sliderValue;
  };

  case ("spawnDistanceEditBoxChanged"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _spawnDistanceEditBox = _display displayCtrl A3A_IDC_SPAWNDISTANCEEDITBOX;
    private _spawnDistanceSlider = _display displayCtrl A3A_IDC_SPAWNDISTANCESLIDER;
    private _spawnDistanceEditBoxValue = floor parseNumber ctrlText _spawnDistanceEditBox;
    _spawnDistanceEditBox ctrlSetText str _spawnDistanceEditBoxValue; // Strips non-numeric characters
    _spawnDistanceSlider sliderSetPosition _spawnDistanceEditBoxValue;
    if (_spawnDistanceEditBoxValue < spawnDistanceMin) then {_spawnDistanceEditBox ctrlSetText str spawnDistanceMin};
    if (_spawnDistanceEditBoxValue > spawnDistanceMax) then {_spawnDistanceEditBox ctrlSetText str spawnDistanceMax};
  };

  case ("aiLimiterSliderChanged"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _aiLimiterSlider = _display displayCtrl A3A_IDC_AILIMITERSLIDER;
    private _aiLimiterEditBox = _display displayCtrl A3A_IDC_AILIMITEREDITBOX;
    private _sliderValue = sliderPosition _aiLimiterSlider;
    _aiLimiterEditBox ctrlSetText str floor _sliderValue;
  };

  case ("aiLimiterEditBoxChanged"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _aiLimiterEditBox = _display displayCtrl A3A_IDC_AILIMITEREDITBOX;
    private _aiLimiterSlider = _display displayCtrl A3A_IDC_AILIMITERSLIDER;
    private _aiLimiterEditBoxValue = floor parseNumber ctrlText _aiLimiterEditBox;
    _aiLimiterEditBox ctrlSetText str _aiLimiterEditBoxValue; // Strips non-numeric characters
    _aiLimiterSlider sliderSetPosition _aiLimiterEditBoxValue;
    if (_aiLimiterEditBoxValue < aiLimiterMin) then {_aiLimiterEditBox ctrlSetText str aiLimiterMin};
    if (_aiLimiterEditBoxValue > aiLimiterMax) then {_aiLimiterEditBox ctrlSetText str aiLimiterMax};
  };

  case ("confirmAILimit"):
  {
    Trace("Showing AI Settings confirm button");
    private _display = findDisplay A3A_IDD_MainDialog;
    private _commitAiButton = _display displayCtrl A3A_IDC_COMMITAIBUTTON;
    _commitAiButton ctrlRemoveAllEventHandlers "ButtonClick";
    _commitAiButton ctrlSetText localize "STR_antistasi_dialogs_main_admin_ai_confirm_button";
    _commitAiButton ctrlAddEventHandler ["ButtonClick", {
      Trace("Confirmed AI Settings");
      hint "Oh no you broke the server :(";

      private _display = findDisplay A3A_IDD_MainDialog;
      private _civLimitEditBox = _display displayCtrl A3A_IDC_CIVLIMITEDITBOX;
      private _civPerc = floor parseNumber ctrlText _civLimitEditBox;
      private _spawnDistanceEditBox = _display displayCtrl A3A_IDC_SPAWNDISTANCEEDITBOX;
      private _distanceSPWN = floor parseNumber ctrlText _spawnDistanceEditBox;
      private _aiLimiterEditBox = _display displayCtrl A3A_IDC_AILIMITEREDITBOX;
      private _maxUnits = floor parseNumber ctrlText _aiLimiterEditBox;

      // TODO UI-update: Change when merging. Something like this but with "set" instead of "increase"?
      // [player,"maxUnits","increase"] remoteExecCall ["A3A_fnc_HQGameOptions",2];

      // TODO UI-update: Placeholder routine, don't merge! Has no security checks whatsoever
      Trace_3("Changing AI Settings - civPerc:%1, distanceSPWN:%2, maxUnits:%3", _civPerc, _distanceSPWN, _maxUnits);
      missionNamespace setVariable ["civPerc", _civPerc];
      missionNamespace setVariable ["distanceSPWN", _distanceSPWN];
      missionNamespace setVariable ["maxUnits", _maxUnits];


      closeDialog 2;
    }];
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("Admin tab mode does not exist: %1", _mode);
  };
};
