/*
Maintainer: DoomMetal
    Handles updating and controls on the Commander tab of the Main dialog.

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
    ["update"] call A3A_fnc_commanderTab;
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
    Trace("Updating Commander tab");
    private _display = findDisplay A3A_IDD_MainDialog;

    // Show map if not already visible
    private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
    if (!ctrlShown _commanderMap) then {_commanderMap ctrlShow true;};

    // Hide both group views initially
    private _multipleGroupsView = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSVIEW;
    private _multipleGroupsBackground = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSBACKGROUND;
    private _multipleGroupsLabel = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSLABEL;
    private _singleGroupView = _display displayCtrl A3A_IDC_HCSINGLEGROUPVIEW;
    _multipleGroupsView ctrlShow false;
    _multipleGroupsBackground ctrlShow false;
    _multipleGroupsView ctrlShow false;
    _singleGroupView ctrlShow false;

    // Hide fire mission controlsGroup initially
    private _fireMissionControlsGroup = _display displayCtrl A3A_IDC_FIREMISSONCONTROLSGROUP;
    _fireMissionControlsGroup ctrlShow false;

    // Initialize fire mission vars
    _fireMissionControlsGroup setVariable ["heSelected", true];
    _fireMissionControlsGroup setVariable ["pointSelected", true];
    _fireMissionControlsGroup setVariable ["roundsNumber", 1];

    // TODO: This should be moved to where we select a group, here atm for debugging purposes
    _fireMissionControlsGroup setVariable ["availableHeRounds", 0];
    _fireMissionControlsGroup setVariable ["availableSmokeRounds", 0];

    // Initialize position to nil
    _fireMissionControlsGroup setVariable ["startPos", nil];
    _fireMissionControlsGroup setVariable ["endPos", nil];

    // Make sure commander map is in group selection mode
    _commanderMap setVariable ["selectFireMissionPos", false];
    _commanderMap setVariable ["selectFireMissionEndPos", false];


    // Check for selected groups
    private _selectedGroup = _commanderMap getVariable ["selectedGroup", grpNull];
    if !(_selectedGroup isEqualTo grpNull) then
    {
      // If exactly 1 HC group is selected show the single group view
      _multipleGroupsView ctrlShow false;
      _multipleGroupsBackground ctrlShow false;
      _multipleGroupsLabel ctrlShow false;
      _singleGroupView ctrlShow true;

      // Hide fire mission button initially
      private _fireMissionButton = _display displayCtrl A3A_IDC_HCFIREMISSIONBUTTON;
      _fireMissionButton ctrlShow false;

      private _groupInfo = [_selectedGroup] call A3A_fnc_getGroupInfo;
      _groupInfo params [
        "_group",
        "_groupID",
        "_groupLeader",
        "_units",
        "_aliveUnits",
        "_ableToCombat",
        "_task",
        "_combatMode",
        "_hasOperativeMedic",
        "_hasAt",
        "_hasAa",
        "_hasMortar",
        "_mortarDeployed",
        "_hasStatic",
        "_staticDeployed",
        "_groupVehicle",
        "_groupIcon",
        "_groupIconColor"
      ];

      private _position = getPos leader _group;

      // Update controls
      private _controlsGroup = _display displayCtrl A3A_IDC_HCSINGLEGROUPVIEW;
      private _groupNameText = _display displayCtrl A3A_IDC_HCGROUPNAME;
      private _groupCountText = _display displayCtrl A3A_IDC_HCGROUPCOUNT;
      private _groupTaskText = _display displayCtrl A3A_IDC_HCGROUPTASK;
      private _groupCombatModeText = _display displayCtrl A3A_IDC_HCGROUPCOMBATMODE;

      _groupNameText ctrlSetText _groupID;
      _groupCountText ctrlSetText format ["%1 / %2", _ableToCombat, _aliveUnits];

      // Delete any previous status icons
      private _iconsControlsGroup = _display displayCtrl A3A_IDC_HCGROUPSTATUSICONS;
      {
        if (ctrlParentControlsGroup _x isEqualTo _iconsControlsGroup) then {ctrlDelete _x};
      } forEach allControls _display;

      // Get the status icons to display
      private _statusIcons = [];
      if _hasOperativeMedic then {_statusIcons pushBack "medic"};
      if _hasAt then {_statusIcons pushBack "at"};
      if _hasAa then {_statusIcons pushBack "aa"};
      if _hasMortar then {
        if _mortarDeployed then {
          _statusIcons pushBack "mortarDeployed";

          // also show fire mission button
          _fireMissionButton ctrlShow true;
        } else {
          _statusIcons pushBack "mortar";

          // show fire mission button, disable and show tooltip
          _fireMissionButton ctrlShow true;
          _fireMissionButton ctrlEnable false;
          _fireMissionButton ctrlSetTooltip "Unable to fire. Mortar is not deployed."; // TODO: localize
        };
      };
      if _hasStatic then {
        if _staticDeployed then {
          _statusIcons pushBack "staticDeployed";
        } else {
          _statusIcons pushBack "static";
        };
      };

      // Create icons, right justified
      {
        private _iconXpos = (30 * GRID_W) - ((count _statusIcons) * 5 * GRID_W) + (_forEachIndex * 5 * GRID_W);
        private _iconPath = "";
        private _toolTipText = "";
        switch (_x) do {
          // TODO: fade undeployed weapon icons a bit
          case ("medic"): {
            _iconPath = "\A3\ui_f\data\igui\cfg\actions\heal_ca.paa";
            _toolTipText = "Has operative medic"; // TODO: localize
          };

          case ("at"): {
            _iconPath = "GUI\textures\icon_has_at.paa";
            _toolTipText = "Has AT capability"; // TODO: localize
          };

          case ("aa"): {
            _iconPath = "GUI\textures\icon_has_aa.paa";
            _toolTipText = "Has AA capability"; // TODO: localize
          };

          case ("mortarDeployed"): {
            _iconPath = "GUI\textures\icon_has_mortar.paa";
            _toolTipText = "Mortar is deployed"; // TODO: localize
          };

          case ("mortar"): {
            _iconPath = "GUI\textures\icon_has_mortar.paa";
            _toolTipText = "Mortar is not deployed"; // TODO: localize
          };

          case ("staticDeployed"): {
            _iconPath = "GUI\textures\icon_has_static.paa";
            _toolTipText = "Static weapon is deployed"; // TODO: localize
          };

          case ("static"): {
            _iconPath = "GUI\textures\icon_has_static.paa";
            _toolTipText = "Static weapon is not deployed"; // TODO: localize
          };
        };

        private _icon = _display ctrlCreate ["A3A_Picture", -1, _iconsControlsGroup];
        _icon ctrlSetPosition [_iconXpos, 0, 4 * GRID_W, 4 * GRID_H];
        _icon ctrlSetText _iconPath;
        _icon ctrlSetTooltip _toolTipText;
        _icon ctrlCommit 0;
      } forEach _statusIcons;

      _groupTaskText ctrlSetText _task;
      _groupCombatModeText ctrlSetText _combatMode;

      // Pan to group location
      private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
      _commanderMap ctrlMapAnimAdd [0.2, ctrlMapScale _commanderMap, getPos _groupLeader];
      ctrlMapAnimCommit _commanderMap;

    } else {
      // If 0 or multiple groups are selected show the multiple groups view
      _singleGroupView ctrlShow false;
      _multipleGroupsView ctrlShow true;
      _multipleGroupsBackground ctrlShow true;
      _multipleGroupsLabel ctrlShow true;

      // Get data
      private _hcGroupData = _commanderMap getVariable "hcGroupData";

      // Generate list
      private _multipleGroupsView = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSVIEW;

      // Clear controlsGroup first
      {
        if (ctrlParentControlsGroup _x isEqualTo _multipleGroupsView) then {ctrlDelete _x};
      } forEach allControls _display;

      {
        // Get group info
        _x params [
          "_group",
          "_groupID",
          "_groupLeader",
          "_units",
          "_aliveUnits",
          "_ableToCombat",
          "_task",
          "_combatMode",
          "_hasOperativeMedic",
          "_hasAt",
          "_hasAa",
          "_hasMortar",
          "_mortarDeployed",
          "_hasStatic",
          "_staticDeployed",
          "_groupVehicle",
          "_groupIcon",
          "_groupIconColor"
        ];

        private _position = getPos leader _group;

        // Set up controls
        private _itemYpos = 16 * _forEachIndex * GRID_H;
        private _itemControlsGroup = _display ctrlCreate ["A3A_ControlsGroupNoScrollbars", -1, _multipleGroupsView];
        _itemControlsGroup ctrlSetPosition [0, _itemYpos, 54 * GRID_W, 14 * GRID_H];
        _itemControlsGroup ctrlCommit 0;

        // background
        private _itemBackground = _display ctrlCreate ["A3A_Background", -1, _itemControlsGroup];
        _itemBackground ctrlSetPosition [0, 0, 54 * GRID_W, 14 * GRID_H];
        _itemBackground ctrlCommit 0;

        // Name label / back button
        // private _groupNameLabel = _display ctrlCreate ["A3A_Button_Left", -1, _itemControlsGroup];
        private _groupNameLabel = _display ctrlCreate ["A3A_Button", -1, _itemControlsGroup];
        _groupNameLabel setVariable ["groupToSelect", _group];
        _groupNameLabel ctrlAddEventHandler ["ButtonClick", {
          params ["_control"];
          private _display = findDisplay A3A_IDD_MainDialog;
          private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
          _commanderMap setVariable ["selectedGroup", _control getVariable "groupToSelect"];
          ["update"] call A3A_fnc_commanderTab;
        }];
        _groupNameLabel ctrlSetPosition [0, 0, 54 * GRID_W, 6 * GRID_H];
        _groupNameLabel ctrlSetBackgroundColor [0,0,0,1];
        _groupNameLabel ctrlSetText _groupID;
        _groupNameLabel ctrlCommit 0;

        // Group icon
        private _ctrlGroupIcon = _display ctrlCreate ["A3A_Picture", -1, _itemControlsGroup];
        _ctrlGroupIcon ctrlSetPosition [0,0, 6 * GRID_W, 6 * GRID_H];
        _ctrlGroupIcon ctrlSetText ("\A3\ui_f\data\Map\Markers\NATO\" + _groupIcon);
        _ctrlGroupIcon ctrlSetTextColor _groupIconColor;
        _ctrlGroupIcon ctrlCommit 0;

        // Group count, able to combat / alive
        private _groupCountIcon = _display ctrlCreate ["A3A_Picture", -1, _itemControlsGroup];
        _groupCountIcon ctrlSetPosition [2 * GRID_W, 8 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _groupCountIcon ctrlSetText "\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa";
        _groupCountIcon ctrlSetTooltip "Number of units in the group\nAble to combat / Total number of units"; // TODO: localize
        _groupCountIcon ctrlCommit 0;

        private _groupCountText = _display ctrlCreate ["A3A_Text", -1, _itemControlsGroup];
        _groupCountText ctrlSetPosition [6 * GRID_W, 8 * GRID_H, 16 * GRID_W, 4 * GRID_H];
        _groupCountText ctrlSetText format["%1 / %2", _aliveUnits, count _units];
        _groupCountText ctrlSetTooltip "Number of units in the group\nAble to combat / Total number of units"; // TODO: localize
        _groupCountText ctrlCommit 0;

        // Subgroup for status icons
        private _iconsControlsGroup = _display ctrlCreate ["A3A_ControlsGroupNoScrollbars", -1, _itemControlsGroup];
        _iconsControlsGroup ctrlSetPosition [22 * GRID_W, 8 * GRID_H, 30 * GRID_W, 6 * GRID_H];
        _iconsControlsGroup ctrlCommit 0;

        // Get the status icons to display
        private _statusIcons = [];
        if _hasOperativeMedic then {_statusIcons pushBack "medic"};
        if _hasAt then {_statusIcons pushBack "at"};
        if _hasAa then {_statusIcons pushBack "aa"};
        if _hasMortar then {
          if _mortarDeployed then {
            _statusIcons pushBack "mortarDeployed";
          } else {
            _statusIcons pushBack "mortar";
          };
        };
        if _hasStatic then {
          if _staticDeployed then {
            _statusIcons pushBack "staticDeployed";
          } else {
            _statusIcons pushBack "static";
          };
        };

        // Create icons, right justified
        {
          private _iconXpos = (30 * GRID_W) - ((count _statusIcons) * 5 * GRID_W) + (_forEachIndex * 5 * GRID_W);
          private _iconPath = "";
          private _toolTipText = "";
          switch (_x) do {
            case ("medic"): {
              _iconPath = "\A3\ui_f\data\igui\cfg\actions\heal_ca.paa";
              _toolTipText = "Has operative medic"; // TODO: localize
            };

            case ("at"): {
              _iconPath = "GUI\textures\icon_has_at.paa";
              _toolTipText = "Has AT capability"; // TODO: localize
            };

            case ("aa"): {
              _iconPath = "GUI\textures\icon_has_aa.paa";
              _toolTipText = "Has AA capability"; // TODO: localize
            };

            case ("mortarDeployed"): {
              _iconPath = "GUI\textures\icon_has_mortar.paa";
              _toolTipText = "Mortar is deployed"; // TODO: localize
            };

            case ("mortar"): {
              _iconPath = "GUI\textures\icon_has_mortar.paa";
              _toolTipText = "Mortar is not deployed"; // TODO: localize
            };

            case ("staticDeployed"): {
              _iconPath = "GUI\textures\icon_has_static.paa";
              _toolTipText = "Static weapon is deployed"; // TODO: localize
            };

            case ("static"): {
              _iconPath = "GUI\textures\icon_has_static.paa";
              _toolTipText = "Static weapon is not deployed"; // TODO: localize
            };
          };

          private _icon = _display ctrlCreate ["A3A_Picture", -1, _iconsControlsGroup];
          _icon ctrlSetPosition [_iconXpos, 0, 4 * GRID_W, 4 * GRID_H];
          _icon ctrlSetText _iconPath;
          _icon ctrlSetTooltip _toolTipText;
          _icon ctrlCommit 0;
        } forEach _statusIcons;

      } forEach _hcGroupData;

      // If no high command groups show how to get them
      if (count _hcGroupData < 1) then
      {
        private _noHcGroupsText = _display ctrlCreate ["A3A_StructuredText", -1, _multipleGroupsView];
        _noHcGroupsText ctrlSetPosition [0, 10 * GRID_H, 54 * GRID_W, 14 * GRID_H];
        _noHcGroupsText ctrlSetStructuredText parseText "<t align='center'>You have no high command groups.</t><br /><t align='center'>You can recruit them at the flag.</t>"; // TODO: localize
        _noHcGroupsText ctrlCommit 0;
      };

    };

    // Hide garbage clean controlsGroup group initially
    _garbageCleanControlsGroup = _display displayCtrl A3A_IDC_GARBAGECLEANCONTROLSGROUP;
    _garbageCleanControlsGroup ctrlShow false;
  };

  case ("updateFireMissionView"):
  {
    Trace("Updating Fire Mission View");
    private _display = findDisplay A3A_IDD_MainDialog;

    // Hide group views
    private _multipleGroupsView = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSVIEW;
    private _singleGroupView = _display displayCtrl A3A_IDC_HCSINGLEGROUPVIEW;
    _multipleGroupsView ctrlShow false;
    _singleGroupView ctrlShow false;

    // Show fire mission view if not already shown
    private _fireMissionControlsGroup = _display displayCtrl A3A_IDC_FIREMISSONCONTROLSGROUP;
    if !(ctrlShown _fireMissionControlsGroup) then {
      _fireMissionControlsGroup ctrlShow true;
    };


    // Update rounds count
    // TODO: Actually get rounds count from squad
    private _heRoundsCount = 40;
    private _smokeRoundsCount = 24;
    _fireMissionControlsGroup setVariable ["availableHeRounds", _heRoundsCount];
    _fireMissionControlsGroup setVariable ["availableSmokeRounds", _smokeRoundsCount];

    private _heRoundsText = _display displayCtrl A3A_IDC_HEROUNDSTEXT;
    private _smokeRoundsText = _display displayCtrl A3A_IDC_SMOKEROUNDSTEXT;

    _heRoundsText ctrlSetText str _heRoundsCount;
    _smokeRoundsText ctrlSetText str _smokeRoundsCount;


    // States for selecting shell type, mission type and round counts are initialized
    // in update, we get them here
    private _heShell = _fireMissionControlsGroup getVariable ["heSelected", true];
    private _pointStrike = _fireMissionControlsGroup getVariable ["pointSelected", true];
    private _roundsCount = _fireMissionControlsGroup getVariable ["roundsNumber", 1];
    private _startPos = _fireMissionControlsGroup getVariable ["startPos", nil];
    private _endPos = _fireMissionControlsGroup getVariable ["endPos", nil];


    // Update controls based on what is selected
    private _heButton = _display displayCtrl A3A_IDC_HEBUTTON;
    private _smokeButton = _display displayCtrl A3A_IDC_SMOKEBUTTON;
    private _pointStrikeButton = _display displayCtrl A3A_IDC_POINTSTRIKEBUTTON;
    private _barrageButton = _display displayCtrl A3A_IDC_BARRAGEBUTTON;
    private _roundsControlsGroup = _display displayCtrl A3A_IDC_ROUNDSCONTROLSGROUP;
    private _roundsEditBox = _display displayCtrl A3A_IDC_ROUNDSEDITBOX;
    private _addRoundsButton = _display displayCtrl A3A_IDC_ADDROUNDSBUTTON;
    private _subRoundsButton = _display displayCtrl A3A_IDC_SUBROUNDSBUTTON;

    private _startPosControlsGroup = _display displayCtrl A3A_IDC_STARTPOSITIONCONTROLSGROUP;
    private _startPosLabel = _display displayCtrl A3A_IDC_STARTPOSITIONLABEL;
    private _startPosEditBox = _display displayCtrl A3A_IDC_STARTPOSITIONEDITBOX;

    private _endPosControlsGroup = _display displayCtrl A3A_IDC_ENDPOSITIONCONTROLSGROUP;
    private _endPosLabel = _display displayCtrl A3A_IDC_ENDPOSITIONLABEL;
    private _endPosEditBox = _display displayCtrl A3A_IDC_ENDPOSITIONEDITBOX;

    private _fireButton = _display displayCtrl A3A_IDC_FIREBUTTON;

    // Disable fire button initially
    _fireButton ctrlEnable false;

    if (_heShell) then
    {
      // HE
      _heButton ctrlEnable false;
      _smokeButton ctrlEnable true;

    } else {
      // Smoke
      _smokeButton ctrlEnable false;
      _heButton ctrlEnable true;
    };

    if (_pointStrike) then
    {
      // Point strike

      _pointStrikeButton ctrlEnable false;
      _barrageButton ctrlEnable true;

      // Change text on start position label
      _startPosLabel ctrlSetText "Position:";

      // Hide endPos controlsGroup
      _endPosControlsGroup ctrlShow false;

      // Enable rounds buttons, remove tooltips
      _addRoundsButton ctrlEnable true;
      _addRoundsButton ctrlSetTooltip "";
      _subRoundsButton ctrlEnable true;
      _subRoundsButton ctrlSetTooltip "";
      _roundsEditBox ctrlSetTooltip "";


    } else {
      // Barrage

      _barrageButton ctrlEnable false;
      _pointStrikeButton ctrlEnable true;

      // Show endPos controlsGroup
      _endPosControlsGroup ctrlShow true;

      // Change text on start position label
      _startPosLabel ctrlSetText "Start:"; // TODO: localize

      // Disable rounds buttons and editBox, show tooltip
      _tooltipText = "Number of rounds set by barrage length"; // TODO: localize
      _addRoundsButton ctrlEnable false;
      _addRoundsButton ctrlSetTooltip _tooltipText;
      _subRoundsButton ctrlEnable false;
      _subRoundsButton ctrlSetTooltip _tooltipText;
      _roundsEditBox ctrlSetTooltip _tooltipText;

      // If mission type is barrage and both positions are set, calculate number of rounds
      // One round per 10m
      // _rounds = round (_positionTel distance _positionTel2) / 10; // <- from antistasi
      if (!isNil "_startPos" && !isNil "_endPos") then
      {
        _roundsCount = round ((_startPos distance _endPos) / 10);
      };
    };

    _roundsEditBox ctrlSetText str _roundsCount;

    // Update position editBoxes
    Trace("Updating fire mission position edit box...");
    private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
    _selectFireMissionPos = _commanderMap getVariable ["selectFireMissionPos", false];
    _selectFireMissionEndPos = _commanderMap getVariable ["selectFireMissionEndPos", false];

    // Start pos
    switch (true) do
    {
      // Selecting position on map
      case (_selectFireMissionPos):
      {
        _startPosEditBox ctrlSetText "CLICK MAP"; // TODO: localize
      };

      // Position is already set
      case (!isNil "_startPos"):
      {
        private _gridPos = mapGridPosition _startPos;
        _startPosEditBox ctrlSetText _gridPos;
      };

      // No position set
      default
      {
        _startPosEditBox ctrlSetText "NOT SET"; // TODO: localize
      };
    };

    // End pos
    switch (true) do
    {
      case (_selectFireMissionEndPos):
      {
        _endPosEditBox ctrlSetText "CLICK MAP"; // TODO: localize
      };

      case (!isNil "_endPos"):
      {
        private _gridPos = mapGridPosition _endPos;
        _endPosEditBox ctrlSetText _gridPos;
      };

      default
      {
        _endPosEditBox ctrlSetText "NOT SET"; // TODO: localize
      };
    };

    // Add tooltip to fire button when unable to fire
    private _firebuttonTooltipText = "";
    private _availableRounds = [_smokeRoundsCount, _heRoundsCount] select _heShell;
    switch (true) do
    {
      case (isNil "_startPos" || (!_pointStrike && isNil "_endPos")): {_firebuttonTooltipText = _firebuttonTooltipText + "Strike position not set\n"}; // TODO: localize
      case (_roundsCount > _availableRounds): {_firebuttonTooltipText = _firebuttonTooltipText + "Not enough ammo\n"}; // TODO: localize
    };

    _fireButton ctrlSetTooltip _firebuttonTooltipText;

    // Enable fire button when able to fire
    if (_firebuttonTooltipText isEqualTo "") then
    {
      _fireButton ctrlEnable true;
    };
  };

  case ("commanderMapClicked"):
  {
    // Get display and map control
    private _display = findDisplay A3A_IDD_MainDialog;
    private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
    private _clickedPosition = [_params select 0, _params select 1];

    // Special cases for selecting fire mission position(s)
    private _selectFireMissionPos = _commanderMap getVariable ["selectFireMissionPos", false];
    if (_selectFireMissionPos) exitWith
    {
      private _fireMissionControlsGroup = _display displayCtrl A3A_IDC_FIREMISSONCONTROLSGROUP;
      _fireMissionControlsGroup setVariable ["startPos", _clickedPosition];
      _commanderMap setVariable ["selectFireMissionPos", false];
      ["updateFireMissionView"] call A3A_fnc_commanderTab;
      Trace_1("Set fire mission startPos: %1", _clickedPosition);
    };

    private _selectFireMissionEndPos = _commanderMap getVariable ["selectFireMissionEndPos", false];
    if (_selectFireMissionEndPos) exitWith
    {
      private _fireMissionControlsGroup = _display displayCtrl A3A_IDC_FIREMISSONCONTROLSGROUP;
      _fireMissionControlsGroup setVariable ["endPos", _clickedPosition];
      _commanderMap setVariable ["selectFireMissionEndPos", false];
      ["updateFireMissionView"] call A3A_fnc_commanderTab;
      Trace_1("Set fire mission endPos: %1", _clickedPosition);
    };

    if (count hcAllGroups player < 1) exitWith {
      Debug("CommanderMap clicked but there are no HC groups to select.");
    };

    // Find closest HC squad to the clicked position
    private _selectedGroup = [hcAllGroups player, _clickedPosition] call BIS_fnc_nearestPosition;

    // If clicked position is nowhere near any hc groups, deselect all units
    // and show list view
    if (leader _selectedGroup distance _clickedPosition > 100) exitWith {
      _commanderMap setVariable ["selectedGroup", grpNull];
      ["update"] call A3A_fnc_commanderTab;
    };

    // Save selected group to map
    _commanderMap setVariable ["selectedGroup", _selectedGroup];

    // Update single group view
    ["update"] call A3A_fnc_commanderTab;
  };

  case ("fireMissionSelectionChanged"):
  {
    private _selection = _params select 0;
    Trace_1("Fire Mission selection changed: %1", _selection);

    _display = findDisplay A3A_IDD_MainDialog;
    _fireMissionControlsGroup = _display displayCtrl A3A_IDC_FIREMISSONCONTROLSGROUP;


    switch (_selection) do
    {
      case ("he"):
      {
        _fireMissionControlsGroup setVariable ["heSelected", true];
        // Set rounds number back to 1 or 0 depending on point/barrage mode
        if (_fireMissionControlsGroup getVariable ["pointSelected", false]) then
        {
          _fireMissionControlsGroup setVariable ["roundsNumber", 1];
        } else {
          _fireMissionControlsGroup setVariable ["roundsNumber", 0];
        };
      };

      case ("smoke"):
      {
        _fireMissionControlsGroup setVariable ["heSelected", false];
        // Set rounds number back to 1 or 0 depending on point/barrage mode
        if (_fireMissionControlsGroup getVariable ["pointSelected", false]) then
        {
          _fireMissionControlsGroup setVariable ["roundsNumber", 1];
        } else {
          _fireMissionControlsGroup setVariable ["roundsNumber", 0];
        };
      };

      case ("point"):
      {
        _fireMissionControlsGroup setVariable ["pointSelected", true];
        // Set rounds number back to 1
        _fireMissionControlsGroup setVariable ["roundsNumber", 1];
      };

      case ("barrage"):
      {
        _fireMissionControlsGroup setVariable ["pointSelected", false];
        // Set rounds number to 0, nubmer decided by barrage length
        _fireMissionControlsGroup setVariable ["roundsNumber", 0];
      };

      case ("addround"):
      {
        // Check for available ammo
        private _availableAmmo = 0;
        if (_fireMissionControlsGroup getVariable ["heSelected", true]) then {
          _availableAmmo = _fireMissionControlsGroup getVariable ["availableHeRounds", 0];
        } else {
          _availableAmmo = _fireMissionControlsGroup getVariable ["availableSmokeRounds", 0];
        };

        Trace_1("Available ammo: %1", _availableAmmo);

        // Add 1
        private _previousNumber = _fireMissionControlsGroup getVariable ["roundsNumber", 1];
        private _newNumber = _previousNumber + 1;

        // Check if num exceeds available ammo
        if (_newNumber > _availableAmmo) then {_newNumber = _availableAmmo};

        // Set new rounds count
        _fireMissionControlsGroup setVariable ["roundsNumber", _newNumber];

        Trace_1("Rounds count now at %1", _newNumber);
      };

      case ("subround"):
      {
        // Subtract 1
        private _previousNumber = _fireMissionControlsGroup getVariable ["roundsNumber", 1];
        private _newNumber = _previousNumber - 1;

        // Check if number is at least 1
        // We clamp it to 1 here and then check if we actually have that 1 round in updateFireMissionView
        if (_newNumber < 1) then {_newNumber = 1};

        // Set new rounds count
        _fireMissionControlsGroup setVariable ["roundsNumber", _newNumber];

        Trace_1("Rounds count now at %1", _newNumber);
      };

      case ("setstart"):
      {
        private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
        _commanderMap setVariable ["selectFireMissionPos", true];
      };

      case ("setend"):
      {
        private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
        _commanderMap setVariable ["selectFireMissionEndPos", true];
      };
    };

    // Update fire mission view to show changes
    ["updateFireMissionView"] call A3A_fnc_commanderTab;
  };

  case ("showGarbageCleanOptions"):
  {
    Trace("Showing garbage clean options");
    _display = findDisplay A3A_IDD_MainDialog;

    // Hide overlapping buttons
    _airSupportButton = _display displayCtrl A3A_IDC_AIRSUPPORTBUTTON;
    _garbageCleanButton = _display displayCtrl A3A_IDC_GARBAGECLEANBUTTON;
    _airSupportButton ctrlShow false;
    _garbageCleanButton ctrlShow false;
    // Show garbage clean controlsGroup
    _garbageCleanControlsGroup = _display displayCtrl A3A_IDC_GARBAGECLEANCONTROLSGROUP;
    _garbageCleanControlsGroup ctrlShow true;
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("Commander tab mode does not exist: %1", _mode);
  };
};
