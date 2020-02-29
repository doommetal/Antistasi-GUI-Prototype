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
    _money = player getVariable "money";
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneySlider sliderSetRange [0,_money];
    _moneySlider sliderSetSpeed [10, 10];
    _moneySlider sliderSetPosition 0;
    _target = cursorTarget;

    _moneyText = _display displayCtrl A3A_IDC_DONATIONMONEYTEXT;
    _moneyText ctrlSetText format ["%1 €", _money];

    _playerList = _display displayCtrl A3A_IDC_DONATEPLAYERLIST;
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

  case ("moneySliderChanged"): {
    _display = findDisplay A3A_IDD_DONATEDIALOG;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _sliderValue = sliderPosition _moneySlider;
    _moneyEditBox ctrlSetText str floor _sliderValue;
  };

  case ("moneyEditBoxChanged"): {
    _money = player getVariable "money";
    _display = findDisplay A3A_IDD_DONATEDIALOG;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBoxValue = floor parseNumber ctrlText _moneyEditBox;
    if (_moneyEditBoxValue < 0) then {_moneyEditBox ctrlSetText str 0};
    if (_moneyEditBoxValue > _money) then {_moneyEditBox ctrlSetText str _money};
    _moneySlider sliderSetPosition _moneyEditBoxValue;
  };

  case ("add"): {
    _moneyToAdd = _params select 0;
    _money = player getVariable "money";
    _display = findDisplay A3A_IDD_DONATEDIALOG;
    _moneyEditBox = _display displayCtrl A3A_IDC_MONEYEDITBOX;
    _moneySlider = _display displayCtrl A3A_IDC_MONEYSLIDER;
    _moneyEditBoxValue = floor parseNumber ctrlText _moneyEditBox;
    _newValue = _moneyEditBoxValue + _moneyToAdd;
    if (_newValue < 0) then {_newValue = 0};
    if (_newValue > _money) then {_newValue = _money};
    _moneyEditBox ctrlSetText str _newValue;
    _moneySlider sliderSetPosition _newValue;
  };
};
