#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_DonateDialog"; // Create the actual dialog
    waitUntil {dialog}; // Wait until the dialog is actually created
    // ^ This method might be a bit heavy handed, but it *** works ***

    _display = findDisplay A3A_IDD_DONATEDIALOG;

    // Money section setup
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneySlider sliderSetRange [0,playerMoney];
    _moneySlider sliderSetSpeed [100, 100];
    _moneySlider sliderSetPosition 0;
  };

  case ("moneySliderChanged"): {
    _display = findDisplay A3A_IDD_DONATEDIALOG;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _sliderValue = sliderPosition _moneySlider;
    _moneyEditBox ctrlSetText str floor _sliderValue;
  };

  case ("moneyEditBoxChanged"): {
    _display = findDisplay A3A_IDD_DONATEDIALOG;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBoxValue = floor parseNumber ctrlText _moneyEditBox;
    _moneySlider sliderSetPosition _moneyEditBoxValue;
    if (_moneyEditBoxValue < 0) then {_moneyEditBox ctrlSetText str 0};
    if (_moneyEditBoxValue > playerMoney) then {_moneyEditBox ctrlSetText str playerMoney};
  };
};
