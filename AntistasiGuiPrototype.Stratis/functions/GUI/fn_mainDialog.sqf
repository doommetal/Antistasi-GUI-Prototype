/*
Maintainer: DoomMetal
    Handles the initialization and updating of the Main Dialog (aka the Y-Menu).
    This function should only be called from MainDialog onLoad and control activation EHs.

Arguments:
    <STRING> Mode, possible values for this dialog are "onLoad", "switchTab"
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

// Logging
#define Log_Debug true
#define Log_Error true
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
        ["updateCommanderTab"] call A3A_fnc_mainDialog;
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
        ["updatePlayerTab"] call A3A_fnc_mainDialog;
      };

      case ("commander"):
      {
        ["updateCommanderTab"] call A3A_fnc_mainDialog;
      };

      case ("admin"):
      {
        ["updateAdminTab"] call A3A_fnc_mainDialog;
      };

      case ("construct"):
      {
        ["updateConstructTab"] call A3A_fnc_mainDialog;
      };

      case ("aimanagement"):
      {
        ["updateAIManagementTab"] call A3A_fnc_mainDialog;
      };

      case ("donate"):
      {
        ["updateDonateTab"] call A3A_fnc_mainDialog;
      };

      case ("airsupport"):
      {
        ["updateAirSupportTab"] call A3A_fnc_mainDialog;
      };

      case ("playermanagement"):
      {
        ["updatePlayerManagementTab"] call A3A_fnc_mainDialog;
      };
    };
  };

  case ("updatePlayerTab"):
  {
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
      _undercoverIcon ctrlSetFade 0;
      _undercoverIcon ctrlCommit 0;
    } else {
      _undercoverButton ctrlEnable false;
      _undercoverButton ctrlSetTooltip "Can't go undercover while wearing a clown suit";
      _undercoverIcon ctrlSetTextColor ([A3A_COLOR_ERROR] call A3A_fnc_configColorToArray);
      _undercoverIcon ctrlSetFade 0.5;
      _undercoverIcon ctrlCommit 0;
    };

    // Fasttravel
    // TODO: Get actual reason for no fast travel and display in tooltip
    private _fastTravelButton = _display displayCtrl A3A_IDC_FASTTRAVELBUTTON;
    private _fastTravelIcon = _display displayCtrl A3A_IDC_FASTTRAVELICON;
    if (canFastTravel) then
    {
      _fastTravelButton ctrlEnable true;
      _fastTravelButton ctrlSetTooltip "";
      _fastTravelIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
      _fastTravelIcon ctrlSetFade 0;
      _fastTravelIcon ctrlCommit 0;
    } else {
      _fastTravelButton ctrlEnable false;
      _fastTravelButton ctrlSetTooltip "Can't fast travel because Petros broke your leg";
      _fastTravelIcon ctrlSetTextColor ([A3A_COLOR_ERROR] call A3A_fnc_configColorToArray);
      _fastTravelIcon ctrlSetFade 0.5;
      _fastTravelIcon ctrlCommit 0;
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
      _constructIcon ctrlSetFade 0;
      _constructIcon ctrlCommit 0;
    } else {
      _constructButton ctrlEnable false;
      _constructButton ctrlSetTooltip "You need someone smart enough to use a hammer in your squad to make constructions";
      _constructIcon ctrlSetTextColor ([A3A_COLOR_ERROR] call A3A_fnc_configColorToArray);
      _constructIcon ctrlSetFade 0.5;
      _constructIcon ctrlCommit 0;
    };

    // AI Management
    // TODO: Get actual reason for no construction and display in tooltip
    private _aiManagementButton = _display displayCtrl A3A_IDC_AIMANAGEMENTBUTTON;
    private _aiManagementIcon = _display displayCtrl A3A_IDC_AIMANAGEMENTICON;
    if (canManageAI) then
    {
      _aiManagementButton ctrlEnable true;
      _aiManagementButton ctrlSetTooltip "";
      _aiManagementIcon ctrlSetTextColor ([A3A_COLOR_WHITE] call A3A_fnc_configColorToArray);
      _aiManagementIcon ctrlSetFade 0;
      _aiManagementIcon ctrlCommit 0;
    } else {
      _aiManagementButton ctrlEnable false;
      _aiManagementButton ctrlSetTooltip "Select some AI to manage them";
      _aiManagementIcon ctrlSetTextColor ([A3A_COLOR_ERROR] call A3A_fnc_configColorToArray);
      _aiManagementIcon ctrlSetFade 0.5;
      _aiManagementIcon ctrlCommit 0;
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

    private _playerRank = rank player;
    switch (_playerRank) do {
      case ("PRIVATE"): {
        _playerRankText ctrlSetText "Private";
        _playerRankPicture ctrlSetText "\A3\Ui_f\data\GUI\Cfg\Ranks\private_gs.paa";
      };

      case ("CORPORAL"): {
        _playerRankText ctrlSetText "Corporal";
        _playerRankPicture ctrlSetText "\A3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa";
      };

      case ("SERGEANT"): {
        _playerRankText ctrlSetText "Sergeant";
        _playerRankPicture ctrlSetText "\A3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa";
      };

      case ("LIEUTENANT"): {
        _playerRankText ctrlSetText "Lieutenant";
        _playerRankPicture ctrlSetText "\A3\Ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa";
      };

      case ("CAPTAIN"): {
        _playerRankText ctrlSetText "Captain";
        _playerRankPicture ctrlSetText "\A3\Ui_f\data\GUI\Cfg\Ranks\captain_gs.paa";
      };

      case ("MAJOR"): {
        _playerRankText ctrlSetText "Major";
        _playerRankPicture ctrlSetText "\A3\Ui_f\data\GUI\Cfg\Ranks\major_gs.paa";
      };

      case ("COLONEL"): {
        _playerRankText ctrlSetText "Colonel";
        _playerRankPicture ctrlSetText "\A3\Ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa";
      };
    };

    // TODO: Make function for getting time alive
    private _time = time;
    private _days = floor (_time / 86400);
    private _hours = floor ((_time - _days * 86400) / 3600);
    private _minutes = floor (((_time - _days * 86400) - _hours * 3600) / 60);
    _aliveText ctrlSetText format ["%1d %2h %3m", _days, _hours, _minutes];

    // TODO: Make function for getting num of completed missions
    private _missions = player getVariable "missionsCompleted";
    _missionsText ctrlSetText str _missions;

    // TODO: Make function for getting number of kills
    private _kills = player getVariable "kills";
    _killsText ctrlSetText str _kills;

    // TODO: Update commander icon/button

    private _money = player getVariable "money";
    _moneyText ctrlSetText format["Current money:\n€ %1", _money];

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
              _addToAirSupportButton ctrlSetTooltip "Not eligible vehicle";
            };
          } else {
            // Enable only "garage" and "lock/unlock" buttons to regular players
            private _sellVehicleButton = _display displayCtrl A3A_IDC_SELLVEHICLEBUTTON;
            _sellVehicleButton ctrlEnable false;
            _sellVehicleButton ctrlSetTooltip "Commander only";
            private _addToAirSupportButton = _display displayCtrl A3A_IDC_ADDTOAIRSUPPORTBUTTON;
            _addToAirSupportButton ctrlEnable false;
            _addToAirSupportButton ctrlSetTooltip "Commander only";
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
      _noVehicleText ctrlSetText "Members only function.";
    };
  };

  case ("updateCommanderTab"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;

    // Show map if not already visible
    private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
    if (!ctrlShown _commanderMap) then {_commanderMap ctrlShow true;};

    // TODO: Remove the placeholder things here:
    private _multipleGroupsView = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSVIEW;
    private _singleGroupView = _display displayCtrl A3A_IDC_HCSINGLEGROUPVIEW;
    _multipleGroupsView ctrlShow false;
    _singleGroupView ctrlShow false;

    // Actual commander tab update routine:

    private _selectedGroup = _commanderMap getVariable ["selectedGroup", grpNull];
    if !(_selectedGroup isEqualTo grpNull) then
    {
      // If exactly 1 HC group is selected show the single group view
      _multipleGroupsView ctrlShow false;
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
          _fireMissionButton ctrlSetTooltip "Unable to fire. Mortar is not deployed.";
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
            _toolTipText = "Has operative medic";
          };

          case ("at"): {
            _iconPath = "GUI\textures\icon_has_at.paa";
            _toolTipText = "Has AT capability";
          };

          case ("aa"): {
            _iconPath = "GUI\textures\icon_has_aa.paa";
            _toolTipText = "Has AA capability";
          };

          case ("mortarDeployed"): {
            _iconPath = "GUI\textures\icon_has_mortar.paa";
            _toolTipText = "Mortar is deployed";
          };

          case ("mortar"): {
            _iconPath = "GUI\textures\icon_has_mortar.paa";
            _toolTipText = "Mortar is not deployed";
          };

          case ("staticDeployed"): {
            _iconPath = "GUI\textures\icon_has_static.paa";
            _toolTipText = "Static weapon is deployed";
          };

          case ("static"): {
            _iconPath = "GUI\textures\icon_has_static.paa";
            _toolTipText = "Static weapon is not deployed";
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

        private _itemBackground = _display ctrlCreate ["A3A_Background", -1, _itemControlsGroup];
        _itemBackground ctrlSetPosition [0, 0, 54 * GRID_W, 14 * GRID_H];
        _itemBackground ctrlCommit 0;

        private _groupNameLabel = _display ctrlCreate ["A3A_Button_Left", -1, _itemControlsGroup];
        _groupNameLabel setVariable ["groupToSelect", _group];
        _groupNameLabel ctrlAddEventHandler ["ButtonClick", {
          params ["_control"];
          private _display = findDisplay A3A_IDD_MainDialog;
          private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;
          _commanderMap setVariable ["selectedGroup", _control getVariable "groupToSelect"];
          ["updateCommanderTab"] call A3A_fnc_mainDialog;
        }];
        _groupNameLabel ctrlSetPosition [0, 0, 54 * GRID_W, 6 * GRID_H];
        _groupNameLabel ctrlSetBackgroundColor [0,0,0,1];
        _groupNameLabel ctrlSetText _groupID;
        _groupNameLabel ctrlCommit 0;

        private _groupCountIcon = _display ctrlCreate ["A3A_Picture", -1, _itemControlsGroup];
        _groupCountIcon ctrlSetPosition [2 * GRID_W, 8 * GRID_H, 4 * GRID_W, 4 * GRID_H];
        _groupCountIcon ctrlSetText "\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa";
        _groupCountIcon ctrlSetTooltip "Number of units in the group\nAble to combat / Total number of units";
        _groupCountIcon ctrlCommit 0;

        private _groupCountText = _display ctrlCreate ["A3A_Text", -1, _itemControlsGroup];
        _groupCountText ctrlSetPosition [6 * GRID_W, 8 * GRID_H, 16 * GRID_W, 4 * GRID_H];
        _groupCountText ctrlSetText format["%1 / %2", _aliveUnits, count _units];
        _groupCountText ctrlSetTooltip "Number of units in the group\nAble to combat / Total number of units";
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
              _toolTipText = "Has operative medic";
            };

            case ("at"): {
              _iconPath = "GUI\textures\icon_has_at.paa";
              _toolTipText = "Has AT capability";
            };

            case ("aa"): {
              _iconPath = "GUI\textures\icon_has_aa.paa";
              _toolTipText = "Has AA capability";
            };

            case ("mortarDeployed"): {
              _iconPath = "GUI\textures\icon_has_mortar.paa";
              _toolTipText = "Mortar is deployed";
            };

            case ("mortar"): {
              _iconPath = "GUI\textures\icon_has_mortar.paa";
              _toolTipText = "Mortar is not deployed";
            };

            case ("staticDeployed"): {
              _iconPath = "GUI\textures\icon_has_static.paa";
              _toolTipText = "Static weapon is deployed";
            };

            case ("static"): {
              _iconPath = "GUI\textures\icon_has_static.paa";
              _toolTipText = "Static weapon is not deployed";
            };
          };

          private _icon = _display ctrlCreate ["A3A_Picture", -1, _iconsControlsGroup];
          _icon ctrlSetPosition [_iconXpos, 0, 4 * GRID_W, 4 * GRID_H];
          _icon ctrlSetText _iconPath;
          _icon ctrlSetTooltip _toolTipText;
          _icon ctrlCommit 0;
        } forEach _statusIcons;

      } forEach _hcGroupData;

    };

  };

  case ("updateAdminTab"):
  {
    // TODO: Get debug info
    // TODO: Get current AI settings
  };

  case ("updateConstructTab"):
  {
    // Show back button
    private _display = findDisplay A3A_IDD_MainDialog;
    private _backButton = _display displayCtrl A3A_IDC_MainDialogBackButton;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["player"]] call A3A_fnc_mainDialog;
    }];
    _backButton ctrlShow true;

    // Add contents to controlsGroup
    private _constructControlsGroup = _display displayCtrl A3A_IDC_CONSTRUCTGROUP;

    // Clear controlsgroup first
    {
      if (ctrlParentControlsGroup _x isEqualTo _constructControlsGroup) then {ctrlDelete _x};
    } forEach allControls _display;

    private _added = 0;
    {
      private _className = _x select 0;
      private _price = _x select 1;
      private _buildTime = _x select 2;
      private _configClass = configFile >> "CfgVehicles" >> _className;
      private _displayName = getText (_configClass >> "displayName");
      private _editorPreview = getText (_configClass >> "editorPreview");

      // Add some extra padding to the top if there are 2 rows or less
      private _topPadding = if (count constructionsList < 7) then {5 * GRID_H} else {0};
      private _itemXpos = 7 * GRID_W + ((7 * GRID_W + 44 * GRID_W) * (_added mod 3));
      private _itemYpos = (floor (_added / 3)) * (44 * GRID_H) + _topPadding;

      private _itemControlsGroup = _display ctrlCreate ["A3A_ControlsGroupNoScrollbars", -1, _constructControlsGroup];
      _itemControlsGroup ctrlSetPosition [_itemXpos, _itemYpos, 44 * GRID_W, 37 * GRID_H];

      // Hide the group initially to hide flickering when creating stuff in them
      _itemControlsGroup ctrlSetFade 1;
      _itemControlsGroup ctrlCommit 0;

      private _previewPicture = _display ctrlCreate ["A3A_Picture", -1, _itemControlsGroup];
      _previewPicture ctrlSetPosition [0, 0, 44 * GRID_W, 25 * GRID_H];
      _previewPicture ctrlSetText _editorPreview;
      _previewPicture ctrlCommit 0;
      private _button = _display ctrlCreate ["A3A_ShortcutButton", -1, _itemControlsGroup];
      _button ctrlSetPosition [0, 25 * GRID_H, 44 * GRID_W, 12 * GRID_H];
      _button ctrlSetText _displayName;
      _button buttonSetAction "hint ""Imagine just building stuff."""; // TODO: Replace with ButtonClicked EH
      _button ctrlCommit 0;
      private _timeText = _display ctrlCreate ["A3A_InfoTextRight", -1, _itemControlsGroup]; // TODO: Add icon
      _timeText ctrlSetPosition[23 * GRID_W, 18 * GRID_H, 20 * GRID_W, 3 * GRID_H];
      _timeText ctrlSetText format ["%1 s",_buildTime];
      _timeText ctrlCommit 0;
      private _priceText = _display ctrlCreate ["A3A_InfoTextRight", -1, _itemControlsGroup];
      _priceText ctrlSetPosition[23 * GRID_W, 21 * GRID_H, 20 * GRID_W, 3 * GRID_H];
      _priceText ctrlSetText format ["%1 €",_price];
      _priceText ctrlCommit 0;

      _itemControlsGroup ctrlSetFade 0;
      _itemControlsGroup ctrlCommit 0.1;

      _added = _added + 1;
    } forEach constructionsList;
  };

  case ("updateAIManagementTab"):
  {
    // Show back button
    private _display = findDisplay A3A_IDD_MainDialog;
    private _backButton = _display displayCtrl A3A_IDC_MainDialogBackButton;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["player"]] call A3A_fnc_mainDialog;
    }];
    _backButton ctrlShow true;
  };

  case ("updateDonateTab"):
  {
    // Show back button
    private _display = findDisplay A3A_IDD_MainDialog;
    private _backButton = _display displayCtrl A3A_IDC_MainDialogBackButton;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["player"]] call A3A_fnc_mainDialog;
    }];
    _backButton ctrlShow true;

    // Money section setup
    private _money = player getVariable "money";
    private _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneySlider sliderSetRange [0,_money];
    _moneySlider sliderSetSpeed [10, 10];
    _moneySlider sliderSetPosition 0;
    private _target = cursorTarget;

    private _moneyText = _display displayCtrl A3A_IDC_DONATIONMONEYTEXT;
    _moneyText ctrlSetText format ["%1 €", _money];

    private _playerList = _display displayCtrl A3A_IDC_DONATEPLAYERLIST;
    {
      if !(_x == player) then
      {
        _playerList lbAdd name _x;
        if !(_target == objNull) then
        {
          if (_target == _x) then
          {
            _playerList lbSetCurSel _forEachIndex;
          };
        };
      };
    } forEach fakePlayers;
  };

  case ("updateAirSupportTab"):
  {
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

  case ("updatePlayerManagementTab"):
  {
    // Show back button
    private _display = findDisplay A3A_IDD_MainDialog;
    private _backButton = _display displayCtrl A3A_IDC_MainDialogBackButton;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["admin"]] call A3A_fnc_mainDialog;
    }];
    _backButton ctrlShow true;

    private _listBox = _display displayCtrl A3A_IDC_ADMINPLAYERLIST;
    {
      private _name = name _x;
      private _isMember = _x getVariable "isMember";
      private _fakePlayerUID = _x getVariable "fakePlayerUID";
      private _distance = format["%1 m", floor (player distance _x)];

      private _index = _listBox lnbAddRow [_name, _distance, _fakePlayerUID];
      if (_isMember) then {
        _listBox lnbSetColor [[_index,0], [0.2,0.6,0.2,1]];
      } else {
        _listBox lnbSetColor [[_index,0], [0.7,0.7,0.7,1]];
      };
    } forEach fakePlayers;

    _listBox lnbSetCurSelRow 0;
    ["playerLbSelectionChanged"] spawn A3A_fnc_mainDialog;
  };

  // TODO: Move auxilliary modes to functions?
  // Donation Menu modes
  case ("moneySliderChanged"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    private _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _sliderValue = sliderPosition _moneySlider;
    _moneyEditBox ctrlSetText str floor _sliderValue;
  };

  case ("moneyEditBoxChanged"):
  {
    private _money = player getVariable "money";
    private _display = findDisplay A3A_IDD_MainDialog;
    private _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    private _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBoxValue = floor parseNumber ctrlText _moneyEditBox;
    if (_moneyEditBoxValue < 0) then {_moneyEditBox ctrlSetText str 0};
    if (_moneyEditBoxValue > _money) then {_moneyEditBox ctrlSetText str _money};
    _moneySlider sliderSetPosition _moneyEditBoxValue;
  };

  case ("donationAdd"):
  {
    private _moneyToAdd = _params select 0;
    private _money = player getVariable "money";
    private _display = findDisplay A3A_IDD_MainDialog;
    private _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    private _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    private _moneyEditBoxValue = floor parseNumber ctrlText _moneyEditBox;
    _newValue = _moneyEditBoxValue + _moneyToAdd;
    if (_newValue < 0) then {_newValue = 0};
    if (_newValue > _money) then {_newValue = _money};
    _moneyEditBox ctrlSetText str _newValue;
    _moneySlider sliderSetPosition _newValue;
  };

  case ("commanderMapClicked"):
  {
    // Get display and map control
    private _display = findDisplay A3A_IDD_MainDialog;
    private _commanderMap = _display displayCtrl A3A_IDC_COMMANDERMAP;

    // Find closest HC squad to the clicked position
    private _clickedPosition = [_params select 0, _params select 1];
    private _selectedGroup = [hcAllGroups player, _clickedPosition] call BIS_fnc_nearestPosition;

    // If clicked position is nowhere near any hc groups, deselect all units
    // and show list view
    if (leader _selectedGroup distance _clickedPosition > 100) exitWith {
      _commanderMap setVariable ["selectedGroup", grpNull];
      ["updateCommanderTab"] call A3A_fnc_mainDialog;
    };

    // Save selected group to map
    _commanderMap setVariable ["selectedGroup", _selectedGroup];

    // Update single group view
    ["updateCommanderTab"] call A3A_fnc_mainDialog;
  };

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
    _aiLimiterSlider sliderSetPosition _aiLimiterEditBoxValue;
    if (_aiLimiterEditBoxValue < aiLimiterMin) then {_aiLimiterEditBox ctrlSetText str aiLimiterMin};
    if (_aiLimiterEditBoxValue > aiLimiterMax) then {_aiLimiterEditBox ctrlSetText str aiLimiterMax};
  };

  case ("playerLbSelectionChanged"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _listBox = _display displayCtrl A3A_IDC_ADMINPLAYERLIST;
    private _index = lnbCurSelRow _listBox;
    private _addButton = _display displayCtrl A3A_IDC_ADDMEMBERBUTTON;
    private _removeButton = _display displayCtrl A3A_IDC_REMOVEMEMBERBUTTON;
    private _player = fakePlayers select _index;
    if (_player getVariable "isMember") then {
      _addButton ctrlShow false;
      _removeButton ctrlShow true;
    } else {
      _addButton ctrlShow true;
      _removeButton ctrlShow false;
    };
  };

  // Debug cases, to be removed/changed when merging
  case ("adminAddMember"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _listBox = _display displayCtrl A3A_IDC_ADMINPLAYERLIST;
    private _index = lbCurSel _listBox;
    _listBox lnbSetColor [[_index,0], [0.2,0.6,0.2,1]];
    fakePlayers select _index setVariable ["isMember", true];
    ["listBoxSelectionChanged"] spawn A3A_fnc_mainDialog;
  };

  case ("adminRemoveMember"):
  {
    private _display = findDisplay A3A_IDD_MainDialog;
    private _listBox = _display displayCtrl A3A_IDC_ADMINPLAYERLIST;
    private _index = lbCurSel _listBox;
    _listBox lnbSetColor [[_index,0], [0.7,0.7,0.7,1]];
    fakePlayers select _index setVariable ["isMember", false];
    ["listBoxSelectionChanged"] spawn A3A_fnc_mainDialog;
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("Main Dialog mode does not exist: %1", _mode);
  };
};
