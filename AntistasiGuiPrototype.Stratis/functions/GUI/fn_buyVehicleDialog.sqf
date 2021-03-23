/*
Maintainer: DoomMetal
    Handles the initialization and updating of the Buy Vehicle dialog.
    This function should only be called from BuyVehicle onLoad and control activation EHs.

Arguments:
    <STRING> Mode, only possible value for this dialog is "onLoad"
    <ARRAY<ANY>> Array of params for the mode when applicable. Params for specific modes are documented in the modes.

Return Value:
    Nothing

Scope: Clients, Local Arguments, Local Effect
Environment: Scheduled for onLoad mode / Unscheduled for everything else unless specified
Public: No
Dependencies:
    None

Example:
    ["onLoad"] spawn A3A_fnc_mainDialog; // initialization
*/

// disableSerialization; // TODO: Remove when merging
#include "..\..\GUI\ids.inc"
#include "..\..\GUI\defines.hpp"
#include "..\..\GUI\textures.inc"

// Logging
#define Log_Debug true
#define Log_Error true
#include "..\..\LogMacros.inc"

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do
{
  case ("onLoad"):
  {
    Debug("BuyVehicleDialog onLoad starting...");

    private _display = findDisplay A3A_IDD_BuyVehicleDialog;

    // Add the stuff to the construct list
    private _vehiclesControlsGroup = _display displayCtrl A3A_IDC_VEHICLESGROUP;

    private _added = 0;
    {
      private _className = _x select 0;
      private _price = _x select 1;
      private _canGoUndercover = _x select 2;
      private _crewCount = [_className] call A3A_fnc_getVehicleCrewCount;
      private _driver = _crewCount select 0;
      private _coPilot = _crewCount select 1;
      private _commander = _crewCount select 2;
      private _gunners = _crewCount select 3;
      private _passengers = _crewCount select 4;
      private _passengersFFV = _crewCount select 5;
      private _configClass = configFile >> "CfgVehicles" >> _className;
      private _displayName = getText (_configClass >> "displayName");
      private _editorPreview = getText (_configClass >> "editorPreview");

      // Add some extra padding to the top if there are 2 rows or less
      private _topPadding = if (count buyableVehiclesList < 7) then {5 * GRID_H} else {0};

      private _itemXpos = 7 * GRID_W + ((7 * GRID_W + 44 * GRID_W) * (_added mod 3));
      private _itemYpos = (floor (_added / 3)) * (44 * GRID_H) + _topPadding;

      private _itemControlsGroup = _display ctrlCreate ["A3A_ControlsGroupNoScrollbars", -1, _vehiclesControlsGroup];
      _itemControlsGroup ctrlSetPosition[_itemXpos, _itemYpos, 44 * GRID_W, 37 * GRID_H];
      _itemControlsGroup ctrlSetFade 1;
      _itemControlsGroup ctrlCommit 0;

      private _previewPicture = _display ctrlCreate ["A3A_Picture", -1, _itemControlsGroup];
      _previewPicture ctrlSetPosition [0, 0, 44 * GRID_W, 25 * GRID_H];
      _previewPicture ctrlSetText _editorPreview;
      _previewPicture ctrlCommit 0;

      private _button = _display ctrlCreate ["A3A_ShortcutButton", -1, _itemControlsGroup];
      _button ctrlSetPosition [0, 25 * GRID_H, 44 * GRID_W, 12 * GRID_H];
      _button ctrlSetText _displayName;
      _button buttonSetAction "hint ""Imagine just buying stuff.""";
      _button ctrlCommit 0;

      private _priceText = _display ctrlCreate ["A3A_InfoTextRight", -1, _itemControlsGroup];
      _priceText ctrlSetPosition[23 * GRID_W, 21 * GRID_H, 20 * GRID_W, 3 * GRID_H];
      _priceText ctrlSetText format ["%1 €",_price];
      _priceText ctrlCommit 0;

      // Undercover icon
      if (_canGoUndercover) then {
        private _undercoverIcon = _display ctrlCreate ["A3A_PictureStroke", -1, _itemControlsGroup];
        _undercoverIcon ctrlSetPosition [1 * GRID_W, 1 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _undercoverIcon ctrlSetText A3A_Tex_Icon_HideVic;
        _underCoverIcon ctrlSetTooltip "This vehicle can go undercover"; // TODO: localize
        _undercoverIcon ctrlCommit 0;
      };

      // Crew icons and counts
      private _hasGunners = if (_gunners > 0) then {1} else {0}; // Is there a better way to just return all positive numbers as 1?
      private _hasPassengers = if (_passengers > 0) then {1} else {0}; // Too sleepy to think of one right now...
      private _numberOfCrewTypes = (_driver + _commander + _hasGunners + _hasPassengers);
      private _crewCountHeight = _numberOfCrewTypes * 4.5 * GRID_H;
      private _crewCountYpos = 24 * GRID_H - _crewCountHeight;

      // Using an inner controlsGroup here so the coordinate calculations don't get completely unreadable
      private _crewControlsGroup = _display ctrlCreate ["A3A_ControlsGroupNoScrollbars", -1, _itemControlsGroup];
      _crewControlsGroup ctrlSetPosition[1 * GRID_W, _crewCountYpos, 20 * GRID_W, _crewCountHeight];
      _crewControlsGroup ctrlCommit 0;

      private _crewInfoAdded = 0;
      if (_driver > 0) then
      {
        private _driverIcon = _display ctrlCreate ["A3A_PictureStroke", -1, _crewControlsGroup];
        _driverIcon ctrlSetPosition [0, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _driverIcon ctrlSetText A3A_Tex_Icon_Driver;
        _driverIcon ctrlSetTooltip "Driver / Pilot"; // TODO: localize
        _driverIcon ctrlCommit 0;

        if (_coPilot > 0) then
        {
          private _coPilotIcon = _display ctrlCreate ["A3A_PictureStroke", -1, _crewControlsGroup];
          _coPilotIcon ctrlSetPosition [5 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
          _coPilotIcon ctrlSetText A3A_Tex_Icon_Driver;
          _coPilotIcon ctrlSetTextColor [0.8,0.8,0.8,1];
          _coPilotIcon ctrlSetTooltip "Co-Pilot"; // TODO: localize
          _coPilotIcon ctrlCommit 0;
        };
        _crewInfoAdded = _crewInfoAdded + 1;
      };

      if (_commander > 0) then
      {
        private _commanderIcon = _display ctrlCreate ["A3A_PictureStroke", -1, _crewControlsGroup];
        _commanderIcon ctrlSetPosition [0, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _commanderIcon ctrlSetText A3A_Tex_Icon_Commander;
        _commanderIcon ctrlSetTooltip "Commander"; // TODO: localize
        _commanderIcon ctrlCommit 0;

        _crewInfoAdded = _crewInfoAdded + 1;
      };

      if (_gunners > 0) then
      {
        private _gunnerIcon = _display ctrlCreate ["A3A_PictureStroke", -1, _crewControlsGroup];
        _gunnerIcon ctrlSetPosition [0, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _gunnerIcon ctrlSetText A3A_Tex_Icon_Gunner;
        _gunnerIcon ctrlSetTooltip "Gunner"; // TODO: localize
        _gunnerIcon ctrlCommit 0;

        if (_gunners > 1) then
        {
          private _gunnersText = _display ctrlCreate ["A3A_InfoTextLeft", -1, _crewControlsGroup];
          _gunnersText ctrlSetPosition [3 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 3 * GRID_H];
          _gunnersText ctrlSetText str _gunners;
          _gunnersText ctrlCommit 0;
        };
        _crewInfoAdded = _crewInfoAdded + 1;
      };

      if (_passengers > 0) then
      {
        private _passengerIcon = _display ctrlCreate ["A3A_PictureStroke", -1, _crewControlsGroup];
        _passengerIcon ctrlSetPosition [0, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _passengerIcon ctrlSetText A3A_Tex_Icon_Cargo;
        _passengerIcon ctrlSetTooltip "Passenger seats"; // TODO: localize
        _passengerIcon ctrlCommit 0;

        if (_passengers > 1) then
        {
          private _passengersText = _display ctrlCreate ["A3A_InfoTextLeft", -1, _crewControlsGroup];
          _passengersText ctrlSetPosition [3 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 3 * GRID_H];
          _passengersText ctrlSetText str _passengers;
          _passengersText ctrlCommit 0;
        };

        if (_passengersFFV > 0) then
        {
          private _ffvIcon = _display ctrlCreate ["A3A_PictureStroke", -1, _crewControlsGroup];
          _ffvIcon ctrlSetPosition [7 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 4 * GRID_H];
          _ffvIcon ctrlSetText A3A_Tex_Icon_FFV;
          _ffvIcon ctrlSetTextColor [0.8,0.8,0.8,1];
          _ffvIcon ctrlSetTooltip "FFV seats"; // TODO: localize
          _ffvIcon ctrlCommit 0;

          if (_passengersFFV > 1) then
          {
            private _ffvText = _display ctrlCreate ["A3A_InfoTextLeft", -1, _crewControlsGroup];
            _ffvText ctrlSetPosition [10 * GRID_W, _crewInfoAdded * 4.5 * GRID_H, 4 * GRID_W, 3 * GRID_H];
            _ffvText ctrlSetText str _passengersFFV;
            _ffvText ctrlSetTextColor [0.8,0.8,0.8,1];
            _ffvText ctrlCommit 0;
          };
        };

        _crewInfoAdded = _crewInfoAdded + 1;
      };
      // Show item
      _itemControlsGroup ctrlSetFade 0;
      _itemControlsGroup ctrlCommit 0.1;

      _added = _added + 1;
    } forEach buyableVehiclesList;

    Debug("BuyVehicleDialog onLoad complete.");
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("BuyVehicleDialog mode does not exist: %1", _mode);
  };
};
