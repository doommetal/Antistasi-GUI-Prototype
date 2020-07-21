#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

// Pixel grid
// TODO: MOVE THIS
#define pixelScale	0.50
#define GRID_W (pixelW * pixelGrid * pixelScale)
#define GRID_H (pixelH * pixelGrid * pixelScale)

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_CommanderDialog"; // Create the actual dialog
    waitUntil {dialog}; // Wait until the dialog is actually created
    // ^ This method might be a bit heavy handed, but it *** works ***

    _display = findDisplay A3A_IDD_COMMANDERDIALOG;

    ["commanderDialog"] call A3A_fnc_handleTabs;



    // Init map drawing event handler
    _map = _display displayCtrl A3A_IDC_COMMANDERMAP;
    _map ctrlAddEventHandler ["Draw",{
      ["updateMapData"] call A3A_fnc_commanderDialog;
      _display = findDisplay A3A_IDD_COMMANDERDIALOG;
      _map = _display displayCtrl A3A_IDC_COMMANDERMAP;
      _hcGroupData = _map getVariable "hcGroupData";
      {
        _x params [
          "_group",
          "_groupID",
          "_groupLeader",
          "_units",
          "_position",
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
          "_groupVehicle"
        ];

        _map drawIcon [
          "\A3\ui_f\data\Map\Markers\Military\flag_CA.paa", // TODO: Change to nato markers
          [0.1,0.7,0.1,1], // colour
          _position, // position
          32, // width
          32, // height
          0, // angle
          "", // text, no text for this?
          2 // shadow (outline if 2)
        ];
      } forEach _hcGroupData;
    }];

    // Switch high command mode
    // Should probably be left off to prevent unintentional map interaction
    hcShowBar false;

    // If a single HC squad is selected show detailed view for that squad
    if (count hcSelected player == 1) then {
      ["showSingleGroup"] call A3A_fnc_commanderDialog;
    } else {
      // If none or multiple are selected show the multiple view
      ["showMultipleGroups"] call A3A_fnc_commanderDialog;
    };
  };

  case ("updateMapData"): {
    // Get display and map control
    _display = findDisplay A3A_IDD_COMMANDERDIALOG;
    _map = _display displayCtrl A3A_IDC_COMMANDERMAP;

    // Get data on all high command squads
    _hcGroupData = [];
    {
      _groupInfo = [_x] call A3A_fnc_getGroupInfo;
      _hcGroupData pushBack _groupInfo;
    } forEach hcAllGroups player;

    // Save the data to the map control to make it available in the draw EH
    _map = _display displayCtrl A3A_IDC_COMMANDERMAP;
    _map setVariable ["hcGroupData", _hcGroupData];
  };

  case ("mapClicked"): {
    // Find closest HC squad to the clicked position
    _clickedPosition = [_params select 0, _params select 1];
    _selectedSquad = [hcAllGroups player, _clickedPosition] call BIS_fnc_nearestPosition;

    // If clicked position is nowhere near any hc groups, deselect all units
    // and show list view
    if (leader _selectedSquad distance _clickedPosition > 100) exitWith {
      {
        player hcSelectGroup [_x, false];
      } forEach hcAllGroups player;
      ["showMultipleGroups"] call A3A_fnc_commanderDialog;
    };

    // Clear selection and select only the group clicked
    {
      player hcSelectGroup [_x, false];
    } forEach hcAllGroups player;
    player hcSelectGroup [_selectedSquad];

    // Update single group view
    ["showSingleGroup"] call A3A_fnc_commanderDialog;

    // Pan to location
    /* _display = findDisplay A3A_IDD_COMMANDERDIALOG;
    _map = _display displayCtrl A3A_IDC_COMMANDERMAP;
    _map ctrlMapAnimAdd [0.2, ctrlMapScale _map, _clickedPosition];
    ctrlMapAnimCommit _map; */
  };


  case ("showSingleGroup"): {
    // Hide multiple groups view
    _display = findDisplay A3A_IDD_COMMANDERDIALOG;
    _multipleGroupsView = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSVIEW;
    _multipleGroupsView ctrlShow false;
    // Show single group view
    _singleGroupView = _display displayCtrl A3A_IDC_HCSINGLEGROUPVIEW;
    _singleGroupView ctrlShow true;
    // Update view
    ["updateSingle"] call A3A_fnc_commanderDialog;
  };


  case ("updateSingle"): {
    // Get data
    _selectedSquad = hcSelected player select 0;
    _squadName = groupId _selectedSquad;
    _squadLeader = leader _selectedSquad;
    _units = units _selectedSquad;
    _aliveMembers = {alive _x} count _units;
    _ableToCombat = {[_x] call A3A_fnc_canFight} count _units;
    _task = "N/A"; // TODO: Update when merging: _x getVariable ["taskX","Patrol"]
    _combatMode = behaviour _squadLeader;
    _hasOperativeMedic = {[_x] call A3A_fnc_isMedic} count _units > 0;
    _hasAt = {_x call A3A_fnc_typeOfSoldier == "ATMan"} count _units > 0;
    _hasAa = {_x call A3A_fnc_typeOfSoldier == "AAMan"} count _units > 0;

    // Update controls
    _display = findDisplay A3A_IDD_COMMANDERDIALOG;
    _squadNameText = _display displayCtrl A3A_IDC_HCSQUADNAME;
    _squadInfoText = _display displayCtrl A3A_IDC_HCSQUADINFO;
    _squadNameText = _squadName;
    _squadInfoText ctrlSetText format ["%1\n%2\n%3\n%4\n%5",
      _aliveMembers,
      _ableToCombat,
      _task,
      _combatMode,
      _hasOperativeMedic
    ];

    // Pan to location
    _map = _display displayCtrl A3A_IDC_COMMANDERMAP;
    _map ctrlMapAnimAdd [0.2, ctrlMapScale _map, _clickedPosition];
    ctrlMapAnimCommit _map;
  };


  case ("showMultipleGroups"): {
    // Hide single group view
    _display = findDisplay A3A_IDD_COMMANDERDIALOG;
    _singleGroupView = _display displayCtrl A3A_IDC_HCSINGLEGROUPVIEW;
    _singleGroupView ctrlShow false;
    // Show multiple groups view
    _multipleGroupsView = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSVIEW;
    _multipleGroupsView ctrlShow true;
    // Update view
    ["updateMultiple"] call A3A_fnc_commanderDialog;
  };


  case ("updateMultiple"): {
    // Get data
    _hcGroups = hcAllGroups player;

    // Generate list
    _display = findDisplay A3A_IDD_COMMANDERDIALOG;
    _multipleGroupsView = _display displayCtrl A3A_IDC_HCMULTIPLEGROUPSVIEW;

    {
      // Get group info
      _groupInfo = [_x] call A3A_fnc_getGroupInfo;
      _groupInfo params [
        "_group",
        "_groupID",
        "_groupLeader",
        "_units",
        "_position",
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
        "_groupVehicle"
      ];

      // Set up controls
      _itemYpos = 16 * _forEachIndex * GRID_H;
      _itemControlsGroup = _display ctrlCreate ["RscControlsGroupNoScrollbars", -1, _multipleGroupsView];
      _itemControlsGroup ctrlSetPosition [0, _itemYpos, 54 * GRID_W, 14 * GRID_H];
      _itemControlsGroup ctrlCommit 0;

      _itemBackground = _display ctrlCreate ["A3A_MainBackground", -1, _itemControlsGroup];
      _itemBackground ctrlSetPosition [0, 0, 54 * GRID_W, 14 * GRID_H];
      _itemBackground ctrlCommit 0;

      _groupNameLabel = _display ctrlCreate ["RscText", -1, _itemControlsGroup];
      _groupNameLabel ctrlSetPosition [0, 0, 54 * GRID_W, 6 * GRID_H];
      _groupNameLabel ctrlSetBackgroundColor [0,0,0,1];
      _groupNameLabel ctrlSetText _groupID;
      _groupNameLabel ctrlCommit 0;

      _groupCountIcon = _display ctrlCreate ["RscPicture", -1, _itemControlsGroup];
      _groupCountIcon ctrlSetPosition [2 * GRID_W, 8 * GRID_H, 4 * GRID_W, 4 * GRID_H];
      _groupCountIcon ctrlSetText "\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa";
      _groupCountIcon ctrlSetTooltip "Number of units in the group\nAble to combat / Total number of units";
      _groupCountIcon ctrlCommit 0;

      _groupCountText = _display ctrlCreate ["RscText", -1, _itemControlsGroup];
      _groupCountText ctrlSetPosition [6 * GRID_W, 8 * GRID_H, 16 * GRID_W, 4 * GRID_H];
      _groupCountText ctrlSetText format["%1 / %2", _aliveUnits, count _units];
      _groupCountText ctrlSetTooltip "Number of units in the group\nAble to combat / Total number of units";
      _groupCountText ctrlCommit 0;

      // Subgroup for status icons
      _iconsControlsGroup = _display ctrlCreate ["RscControlsGroupNoScrollbars", -1, _itemControlsGroup];
      _iconsControlsGroup ctrlSetPosition [22 * GRID_W, 8 * GRID_H, 30 * GRID_W, 6 * GRID_H];
      _iconsControlsGroup ctrlCommit 0;

      // Get the status icons to display
      _statusIcons = [];
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
      // TODO: Replace icon paths
      {
        _iconXpos = (30 * GRID_W) - ((count _statusIcons) * 4 * GRID_W) + (_forEachIndex * 4 * GRID_W);
        _iconPath = "";
        _toolTipText = "";
        switch (_x) do {
          case ("medic"): {
            _iconPath = "\A3\ui_f\data\igui\cfg\actions\heal_ca.paa";
            _toolTipText = "Has operative medic";
          };

          case ("at"): {
            _iconPath = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa";
            _toolTipText = "Has AT capability";
          };

          case ("aa"): {
            _iconPath = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa";
            _toolTipText = "Has AA capability";
          };

          case ("mortarDeployed"): {
            _iconPath = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa";
            _toolTipText = "Mortar is deployed";
          };

          case ("mortar"): {
            _iconPath = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa";
            _toolTipText = "Mortar is not deployed";
          };

          case ("staticDeployed"): {
            _iconPath = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa";
            _toolTipText = "Static weapon is deployed";
          };

          case ("static"): {
            _iconPath = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa";
            _toolTipText = "Static weapon is not deployed";
          };
        };

        _icon = _display ctrlCreate ["RscPicture", -1, _iconsControlsGroup];
        _icon ctrlSetPosition [_iconXpos, 0, 4 * GRID_W, 4 * GRID_H];
        _icon ctrlSetText _iconPath;
        _icon ctrlSetTooltip _toolTipText;
        _icon ctrlCommit 0;
      } forEach _statusIcons;

    } forEach _hcGroups;
  };
};
