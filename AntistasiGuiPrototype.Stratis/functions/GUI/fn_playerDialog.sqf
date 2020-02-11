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

    // Show the player menu by default
    ctrlShow [A3A_IDC_PLAYERMAINCONTENT, true];

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

    // Money section setup
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneySlider sliderSetRange [0,playerMoney];
    _moneySlider sliderSetSpeed [100, 100];
    _moneySlider sliderSetPosition 0;

    // TODO: Vehicle section setup
  };

  case ("moneySliderChanged"): {
    _display = findDisplay A3A_IDD_PLAYERDIALOG;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _sliderValue = sliderPosition _moneySlider;
    _moneyEditBox ctrlSetText str floor _sliderValue;
  };

  case ("moneyEditBoxChanged"): {
    _display = findDisplay A3A_IDD_PLAYERDIALOG;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBoxValue = floor parseNumber ctrlText _moneyEditBox;
    _moneySlider sliderSetPosition _moneyEditBoxValue;
    if (_moneyEditBoxValue < 0) then {_moneyEditBox ctrlSetText str 0};
    if (_moneyEditBoxValue > playerMoney) then {_moneyEditBox ctrlSetText str playerMoney};
  };
};
