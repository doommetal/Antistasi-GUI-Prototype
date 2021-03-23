/*
Maintainer: DoomMetal
    Handles the initialization and tab switching on the Main Dialog (aka the Y-Menu).
    This function should only be called from MainDialog onLoad and control activation EHs.

Arguments:
    <STRING> Mode, e.g. "onLoad", "switchTab"
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
    ["switchTab", ["player"]] call A3A_fnc_mainDialog; // switching to the player tab
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
  case ("onLoad"):
  {
    Debug("MainDialog onLoad starting...");

    private _display = findDisplay A3A_IDD_MainDialog;

    // Disable/hide unavailable tab buttons
    if (!playerIsCommander) then {
      private _commanderTabButton = _display displayCtrl A3A_IDC_CommanderTabButton;
      _commanderTabButton ctrlEnable false;
      _commanderTabButton ctrlSetTooltip "Only the commander can access the commander tab";
    };

    if (!playerIsAdmin) then {
      private _adminTabButton = _display displayCtrl A3A_IDC_AdminTabButton;
      _adminTabButton ctrlEnable false;
      _adminTabButton ctrlshow false;
    };

    // Hide HC group icons to stop them from interfering with map controls
    _display setVariable ["HCgroupIcons", groupIconsVisible];
    setGroupIconsVisible [false, false];
    setGroupIconsSelectable false;

    // Show player tab content
    ["switchTab", ["player"]] call A3A_fnc_mainDialog;

    // Cache group info in map control
    Debug("Caching group info");

    private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
    private _hcGroupData = [];
    if (playerIsCommander) then
    {
      {
        private _groupData = [_x] call A3A_fnc_getGroupInfo;
        _hcGroupData pushBack _groupData;
      } forEach hcallGroups player;
    };
    _commanderMap setVariable ["hcGroupData", _hcGroupData];
    Debug_1("%1 Groups cached", count (_commanderMap getVariable "hcGroupData"));

    // Init selected group
    private _selectedGroup = grpNull;
    if (count (hcSelected player) == 1) then
    {
      _selectedGroup = (hcSelected player) # 0;
    };
    _commanderMap setVariable ["selectedGroup", _selectedGroup];


    // Fire mission marker event handler
    private _fireMissionEH = _commanderMap ctrlAddEventHandler ["Draw",{
      private _display = findDisplay A3A_IDD_MainDialog;
      private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
      private _fireMissionControlsGroup = _display displayCtrl A3A_IDC_FIREMISSONCONTROLSGROUP;

      private _startPos = _fireMissionControlsGroup getVariable ["startPos", nil];
      private _endPos = _fireMissionControlsGroup getVariable ["endPos", nil];
      private _pointStrike = _fireMissionControlsGroup getVariable ["pointSelected", true];

      if (_pointStrike && !isNil "_startPos") then {
        // Draw icon
        _commanderMap drawIcon [
          "\A3\ui_f\data\Map\Markers\Military\destroy_CA.paa", // icon path
          [0.8,0,0,1], // color
          _startPos, // position
          32, // width
          32, // height
          0, // angle
          "", // text
          2 // shadow, outline if 2
        ];
      };

      if (!_pointStrike) then {
        if (!isNil "_startPos") then {
          // Draw start pos marker
          _commanderMap drawIcon [
            "\A3\ui_f\data\Map\Markers\Military\destroy_CA.paa", // icon path
            [0.8,0,0,1], // color
            _startPos, // position
            32, // width
            32, // height
            0, // angle
            "Barrage start", // text
            2 // shadow, outline if 2
          ];
        };

        if (!isNil "_endPos") then {
          // Draw end pos marker
          _commanderMap drawIcon [
            "\A3\ui_f\data\Map\Markers\Military\destroy_CA.paa", // icon path
            [0.8,0,0,1], // color
            _endPos, // position
            32, // width
            32, // height
            0, // angle
            "Barrage end", // text
            2 // shadow, outline if 2
          ];
        };

        if (!isNil "_startPos" && !isNil "_endPos") then {
          // If both markers are present draw a line between them
          _commanderMap drawLine [_startPos, _endPos, [0.8,0,0,1]];
        };

      };
    }];

    Debug_1("Adding Fire Mission Draw EH to commander map: %1", _fireMissionEH);


    // EH for drawing HC groups on the commander map
    private _eh = _commanderMap ctrlAddEventHandler ["Draw",{
      private _display = findDisplay A3A_IDD_MainDialog;
      private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;

      // Update HC group data
      private _oldHcGroupData = _commanderMap getVariable "hcGroupData";

      private _hcGroupData = [];
      {
        private _groupData = [_x] call A3A_fnc_getGroupInfo;
        _hcGroupData pushBack _groupData;
      } forEach hcallGroups player;

      _commanderMap setVariable ["hcGroupData", _hcGroupData];

      // Update commander tab when data changes
      if !(_oldHcGroupData isEqualTo _hcGroupData) then {
        ["update"] call A3A_fnc_commanderTab;
      };

      {
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

        // Shorten group name if it's over 16 characters
        if (count _groupID > 16) then
        {
          _groupID = (_groupId select [0, 15]) + "...";
        };

        // Draw group type icon
        _commanderMap drawIcon [
          "\A3\ui_f\data\Map\Markers\NATO\" + _groupIcon, // icon type
          _groupIconColor, // colour
          _position, // position
          32, // width
          32, // height
          0, // angle
          "", // text, no text for this
          0 // shadow (outline if 2)
        ];

        // Draw size indicator
        private _size = 0;
        switch (true) do
        {
          case (_aliveUnits < 4): {_size = 0};
          case (_aliveUnits >= 4 && _aliveUnits < 8): {_size = 1};
          case (_aliveUnits >= 12 && _aliveUnits < 25): {_size = 2};
          case (_aliveUnits >= 25 && _aliveUnits < 60): {_size = 3};
          case (_aliveUnits >= 60 && _aliveUnits < 240): {_size = 4};
        };
        private _sizeIcon = "\A3\ui_f\data\Map\Markers\NATO\group_" + str _size;
        _commanderMap drawIcon [
          _sizeIcon, // icon type
          [0,0,0,1], // colour
          _position, // position
          38, // width
          38, // height
          0, // angle
          "", // text, no text for this
          0 // shadow (outline if 2)
        ];


        // Draw group name text
        _commanderMap drawIcon [
          "#(rgb,1,1,1)color(0,0,0,0)", // transparent
          _groupIconColor, // colour
          _position, // position
          32, // width
          32, // height
          0, // angle
          _groupID, // text
          2 // shadow (outline if 2)
        ];
      } forEach _hcGroupData;
    }];

    Debug_1("Adding HC group marker Draw EH to commander map: %1", _eh);

    // Selection marker event handler
    private _radius = 64;
    private _dir = 0;
    _commanderMap setVariable ["selectMarker", [_radius, _dir]];

    private _selectEH = _commanderMap ctrlAddEventHandler ["Draw",{
      private _display = findDisplay A3A_IDD_MainDialog;
      private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
      private _data = _commanderMap getVariable "selectMarker";
      _data params ["_radius", "_dir"];
      if (_dir == 0) then {
        _radius = _radius - 0.5;
        if (_radius < 48) then {
          _dir = 1; // Reverse direction
        };
      } else {
        _radius = _radius + 0.5;
        if (_radius > 64) then {
          _dir = 0;
        };
      };

      _commanderMap setVariable ["selectMarker", [_radius, _dir]];
      private _selectedGroup = _commanderMap getVariable "selectedGroup";

      if !(_selectedGroup isEqualTo grpNull) then {
        private _position = getPos leader _selectedGroup;
        _commanderMap drawIcon [
        "\A3\ui_f\data\IGUI\Cfg\Cursors\selectOver_ca.paa",
        [1,1,1,0.75],
        _position,
        _radius,
        _radius,
        0
        ];
      };
    }];

    Debug_1("Adding HC group selection Draw EH to commander map: %1", _selectEH);


    // Admin tab

    // AI options section setup
    _civLimitSlider = _display displayCtrl A3A_IDC_CIVLIMITSLIDER;
    _civLimitSlider sliderSetRange [civLimitMin,civLimitMax];
    _civLimitSlider sliderSetSpeed [10, 10];
    _civLimitSlider sliderSetPosition civLimit;
    ctrlSetText [A3A_IDC_CIVLIMITEDITBOX, str civLimit];

    _spawnDistanceSlider = _display displayCtrl A3A_IDC_SPAWNDISTANCESLIDER;
    _spawnDistanceSlider sliderSetRange [spawnDistanceMin,spawnDistanceMax];
    _spawnDistanceSlider sliderSetSpeed [100, 100];
    _spawnDistanceSlider sliderSetPosition spawnDistance;
    ctrlSetText [A3A_IDC_SPAWNDISTANCEEDITBOX, str spawnDistance];

    _aiLimiterSlider = _display displayCtrl A3A_IDC_AILIMITERSLIDER;
    _aiLimiterSlider sliderSetRange [civLimitMin,civLimitMax];
    _aiLimiterSlider sliderSetSpeed [10, 10];
    _aiLimiterSlider sliderSetPosition aiLimiter;
    ctrlSetText [A3A_IDC_AILIMITEREDITBOX, str aiLimiter];

    Debug("MainDialog onLoad complete.");
  };

  case ("onUnload"):
  {
    Debug("MainDialog onUnload starting...");
    private _display = findDisplay A3A_IDD_MainDialog;

    // Remove map drawing EH
    _commanderMap ctrlRemoveAllEventHandlers "Draw";

    // Restore HC group icons state
    private _groupIcons = _display getVariable ["HCgroupIcons", [false,false]];
    setGroupIconsVisible _groupIcons;
    setGroupIconsSelectable true;

    Debug("MainDialog onUnload complete.");
  };

  case ("switchTab"):
  {
    // Get selected tab
    private _selectedTab = _params select 0;

    Debug_1("MainDialog switching tab to %1.", _selectedTab);

    // Get IDC for selected tab if user has permission to use it
    private _selectedTabIDC = -1;
    switch (_selectedTab) do
    {
      case ("player"):
      {
        // No permission check needed
        _selectedTabIDC = A3A_IDC_PlayerTab;
      };

      case ("commander"):
      {
        if (playerIsCommander) then {
          _selectedTabIDC = A3A_IDC_CommanderTab;
        };
      };

      case ("admin"):
      {
        if (playerIsAdmin) then {
          _selectedTabIDC = A3A_IDC_AdminTab;
        };
      };

      case ("construct"):
      {
        _selectedTabIDC = A3A_IDC_ConstructTab;
      };

      case ("aimanagement"):
      {
        _selectedTabIDC = A3A_IDC_AIManagementTab;
      };

      case ("donate"):
      {
        _selectedTabIDC = A3A_IDC_DonateTab;
      };

      case ("airsupport"):
      {
        _selectedTabIDC = A3A_IDC_AirSupportTab;
      };

      case ("playermanagement"):
      {
        _selectedTabIDC = A3A_IDC_PlayerManagementTab;
      };
    };

    // Log attempt at accessing tab without permission
    if (_selectedTabIDC == -1) exitWith {
      Error("Attempted to acces tab without permission : %1", _selectedTab);
    };

    // Get display
    private _display = findDisplay A3A_IDD_MainDialog;

    // Array of IDCs for all the tabs, including subtabs (like AI & player management)
    // Commander map is also hidden here, and shown again in updateCommanderTab
    private _allTabs = [
      A3A_IDC_PlayerTab,
      A3A_IDC_CommanderTab,
      A3A_IDC_COMMANDERMAP,
      A3A_IDC_AdminTab,
      A3A_IDC_ConstructTab,
      A3A_IDC_AIManagementTab,
      A3A_IDC_DonateTab,
      A3A_IDC_AirSupportTab,
      A3A_IDC_PlayerManagementTab
      ];

    // Hide all tabs
    {
      private _ctrl = _display displayCtrl _x;
      _ctrl ctrlShow false;
    } forEach _allTabs;

    // Hide back button, enable in update tab mode when/if needed
    private _backButton = _display displayCtrl A3A_IDC_MainDialogBackButton;
    _backButton ctrlShow false;

    // Show selected tab
    private _selectedTabCtrl = _display displayCtrl _selectedTabIDC;
    _selectedTabCtrl ctrlShow true;

    switch (_selectedTab) do
    {
      case ("player"):
      {
        ["update"] call A3A_fnc_playerTab;
      };

      case ("commander"):
      {
        ["update"] call A3A_fnc_commanderTab;
      };

      case ("admin"):
      {
        ["update"] call A3A_fnc_adminTab;
      };

      case ("construct"):
      {
        ["update"] call A3A_fnc_constructTab;
      };

      case ("aimanagement"):
      {
        ["update"] call A3A_fnc_aiManagementTab;
      };

      case ("donate"):
      {
        ["update"] call A3A_fnc_donateTab;
      };

      case ("airsupport"):
      {
        ["update"] call A3A_fnc_airSupportTab;
      };

      case ("playermanagement"):
      {
        ["update"] call A3A_fnc_playerManagementTab;
      };
    };
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("Main Dialog mode does not exist: %1", _mode);
  };
};
