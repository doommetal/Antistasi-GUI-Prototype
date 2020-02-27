#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_PlayerDialog"; // Create the actual dialog
    waitUntil {dialog}; // Wait until the dialog is actually created
    // ^ This method might be a bit heavy handed, but it *** works ***

    ["playerDialog"] spawn A3A_fnc_handleTabs;
    _display = findDisplay A3A_IDD_PLAYERDIALOG;


    ///////////////////////
    // LEFT SIDE BUTTONS //
    ///////////////////////

    // Show buttons that start hidden to fix error message z-level
    ctrlShow [A3A_IDC_UNDERCOVERBUTTON, true];
    ctrlShow [A3A_IDC_FASTTRAVELBUTTON, true];
    ctrlShow [A3A_IDC_CONSTRUCTBUTTON, true];
    ctrlShow [A3A_IDC_AIMANAGEMENTBUTTON, true];

    // Hide error messages initially
    // for some reason hiding them in class definition didn't work
    ctrlShow [A3A_IDC_UNDERCOVERERROR, false];
    ctrlShow [A3A_IDC_FASTTRAVELERROR, false];
    ctrlShow [A3A_IDC_CONSTRUCTERROR, false];
    ctrlShow [A3A_IDC_AIMANAGEMENTERROR, false];

    // Disable buttons for functions that are unavailable
    if !(canGoUndercover) then
    {
      ctrlEnable [A3A_IDC_UNDERCOVERBUTTON, false];
      ctrlShow [A3A_IDC_UNDERCOVERERROR, true];
      _undercoverIcon = _display displayCtrl A3A_IDC_UNDERCOVERICON;
      _undercoverIcon ctrlSetFade 0.5;
      _undercoverIcon ctrlCommit 0;
    };

    if !(canFastTravel) then
    {
      ctrlEnable [A3A_IDC_FASTTRAVELBUTTON, false];
      ctrlShow [A3A_IDC_FASTTRAVELERROR, true];
      _fastTravelIcon = _display displayCtrl A3A_IDC_FASTTRAVELICON;
      _fastTravelIcon ctrlSetFade 0.5;
      _fastTravelIcon ctrlCommit 0;
    };

    if !(canConstruct) then
    {
      ctrlEnable [A3A_IDC_CONSTRUCTBUTTON, false];
      ctrlShow [A3A_IDC_CONSTRUCTERROR, true];
      _constructIcon = _display displayCtrl A3A_IDC_CONSTRUCTICON;
      _constructIcon ctrlSetFade 0.5;
      _constructIcon ctrlCommit 0;
    };

    if !(canManageAI) then
    {
      ctrlEnable [A3A_IDC_AIMANAGEMENTBUTTON, false];
      ctrlShow [A3A_IDC_AIMANAGEMENTERROR, true];
      _aiManagementIcon = _display displayCtrl A3A_IDC_AIMANAGEMENTICON;
      _aiManagementIcon ctrlSetFade 0.5;
      _aiManagementIcon ctrlCommit 0;
    };


    /////////////////////////
    // PLAYER INFO SECTION //
    /////////////////////////

    _playerNameText = _display displayCtrl A3A_IDC_PLAYERNAMETEXT;
    _playerRankText = _display displayCtrl A3A_IDC_PLAYERRANKTEXT;
    _playerRankPicture = _display displayCtrl A3A_IDC_PLAYERRANKPICTURE;
    _aliveText = _display displayCtrl A3A_IDC_ALIVETEXT;
    _missionsText = _display displayCtrl A3A_IDC_MISSIONSTEXT;
    _killsText = _display displayCtrl A3A_IDC_KILLSTEXT;
    _commanderPicture = _display displayCtrl A3A_IDC_COMMANDERPICTURE;
    _commanderText = _display displayCtrl A3A_IDC_COMMANDERTEXT;
    _commanderButton = _display displayCtrl A3A_IDC_COMMANDERBUTTON;
    _moneyText = _display displayCtrl A3A_IDC_MONEYTEXT;

    _playerNameText ctrlSetText name player;

    _playerRank = rank player;
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

    // TODO: Player info stats needs event handlers, and possibly saving if
    // they are to be extended beyond the current session
    _time = time;
    _days = floor (_time / 86400);
    _hours = floor ((_time - _days * 86400) / 3600);
    _minutes = floor (((_time - _days * 86400) - _hours * 3600) / 60);
    _aliveText ctrlSetText format ["%1d %2h %3m", _days, _hours, _minutes];

    _missions = player getVariable "missionsCompleted";
    _missionsText ctrlSetText str _missions;

    _kills = player getVariable "kills";
    _killsText ctrlSetText str _kills;

    if (playerIsCommander) then {
      _commanderPicture ctrlSetTextColor [1,0.9,0.5,1];
      _commanderText ctrlSetTextColor [1,0.9,0.5,1];
      _commanderText ctrlSetText "Commander";
      _commanderButton ctrlSetText "Resign";
      _commanderButton buttonSetAction "playerIsCommander = false; player setVariable [""eligibleCommander"", false]; [] spawn A3A_fnc_playerDialog";
    } else {
      if (player getVariable "eligibleCommander") then {
        _commanderPicture ctrlSetTextColor [0.7,0.7,0.7,1];
        _commanderText ctrlSetTextColor [0.7,0.7,0.7,1];
        _commanderText ctrlSetText "Eligible";
        _commanderButton ctrlSetText "Set Ineligible";
        _commanderButton buttonSetAction "player setVariable [""eligibleCommander"", false]; [] spawn A3A_fnc_playerDialog";
      } else {
        _commanderPicture ctrlSetTextColor [0.4,0.4,0.4,1];
        _commanderText ctrlSetTextColor [0.4,0.4,0.4,1];
        _commanderText ctrlSetText "Not Eligible";
        _commanderButton ctrlSetText "Set Eligible";
        _commanderButton buttonSetAction "player setVariable [""eligibleCommander"", true]; [] spawn A3A_fnc_playerDialog; [] spawn {sleep 30; playerIsCommander = true}";
      };
    };

    _money = player getVariable "money";
    _moneyText ctrlSetText format["Current money:\n€ %1", _money];


    /////////////////////
    // VEHICLE SECTION //
    /////////////////////

    _vehicleGroup = _display displayCtrl A3A_IDC_PLAYERVEHICLEGROUP;
    _noVehicleGroup = _display displayCtrl A3A_IDC_NOVEHICLEGROUP;

    // Vehicle section is only available to members
    if (player getVariable "isMember") then {

      // Attempt to get vehicle from cursortarget
      _vehicle = cursorTarget;
      // TODO: Add fallback to select the closest eligible vehicle in sight
      // TODO: Add check for distance

      if !(isNull _vehicle) then {
        // Check if vehicle is eligible for garage / sell, not a dude or house etc.
        if (_vehicle isKindOf "Air" or _vehicle isKindOf "LandVehicle") then {
          _className = typeOf _vehicle;
          _configClass = configFile >> "CfgVehicles" >> _className;
          _displayName = getText (_configClass >> "displayName");
          _editorPreview = getText (_configClass >> "editorPreview");

          _vehicleNameLabel = _display displayCtrl A3A_IDC_VEHICLENAMELABEL;
          _vehicleNameLabel ctrlSetText _displayName;
          // For some reason the text control becomes active showing an ugly
          // white border, we disable it here to avoid that
          _vehicleNameLabel ctrlEnable false;

          _vehiclePicture = _display displayCtrl A3A_IDC_VEHICLEPICTURE;
          _vehiclePicture ctrlSetText _editorPreview;

          // TODO: Disable garage, sell and add to air support buttons
          // if player is not in range of a friendly location

          if (playerIsCommander) then {
            // Disable "add to air support" button if vehicle is not eligible
            if !(_vehicle isKindOf "Air") then {
              _addToAirSupportButton = _display displayCtrl A3A_IDC_ADDTOAIRSUPPORTBUTTON;
              _addToAirSupportButton ctrlEnable false;
              _addToAirSupportButton ctrlSetTooltip "Not eligible vehicle";
            };
          } else {
            // Enable only "garage" and "lock/unlock" buttons to regular players
            _sellVehicleButton = _display displayCtrl A3A_IDC_SELLVEHICLEBUTTON;
            _sellVehicleButton ctrlEnable false;
            _sellVehicleButton ctrlSetTooltip "Commander only";
            _addToAirSupportButton = _display displayCtrl A3A_IDC_ADDTOAIRSUPPORTBUTTON;
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
      _noVehicleText = _display displayCtrl A3A_IDC_NOVEHICLETEXT;
      _noVehicleText ctrlSetText "Members only function.";
    };
  };

  case ("moneySliderChanged"): {
    _display = findDisplay A3A_IDD_PLAYERDIALOG;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _sliderValue = sliderPosition _moneySlider;
    _moneyEditBox ctrlSetText str floor _sliderValue;
  };

  case ("moneyEditBoxChanged"): {
    _money = player getVariable "money";
    _display = findDisplay A3A_IDD_PLAYERDIALOG;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBoxValue = floor parseNumber ctrlText _moneyEditBox;
    _moneySlider sliderSetPosition _moneyEditBoxValue;
    if (_moneyEditBoxValue < 0) then {_moneyEditBox ctrlSetText str 0};
    if (_moneyEditBoxValue > _money) then {_moneyEditBox ctrlSetText str _money};
  };
};
