#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

if !(playerIsAdmin) exitWith
{
  hint "You shouldn't be in there, you sneaky bugger!";
  [] spawn A3A_fnc_playerDialog;
};

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_AdminDialog"; // Create the actual dialog
    waitUntil {dialog}; // Wait until the dialog is actually created
    // ^ This method might be a bit heavy handed, but it *** works ***

    ["adminDialog"] call A3A_fnc_handleTabs;
    _display = findDisplay A3A_IDD_ADMINDIALOG;

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
  };

  case ("civLimitSliderChanged"): {
    _display = findDisplay A3A_IDD_ADMINDIALOG;
    _civLimitSlider = _display displayCtrl A3A_IDC_CIVLIMITSLIDER;
    _civLimitEditBox = _display displayCtrl A3A_IDC_CIVLIMITEDITBOX;
    _sliderValue = sliderPosition _civLimitSlider;
    _civLimitEditBox ctrlSetText str floor _sliderValue;
  };

  case ("civLimitEditBoxChanged"): {
    _display = findDisplay A3A_IDD_ADMINDIALOG;
    _civLimitEditBox = _display displayCtrl A3A_IDC_CIVLIMITEDITBOX;
    _civLimitSlider = _display displayCtrl A3A_IDC_CIVLIMITSLIDER;
    _civLimitEditBoxValue = floor parseNumber ctrlText _civLimitEditBox;
    _civLimitSlider sliderSetPosition _civLimitEditBoxValue;
    if (_civLimitEditBoxValue < civLimitMin) then {_civLimitEditBox ctrlSetText str civLimitMin};
    if (_civLimitEditBoxValue > civLimitMax) then {_civLimitEditBox ctrlSetText str civLimitMax};
  };

  case ("spawnDistanceSliderChanged"): {
    _display = findDisplay A3A_IDD_ADMINDIALOG;
    _spawnDistanceSlider = _display displayCtrl A3A_IDC_SPAWNDISTANCESLIDER;
    _spawnDistanceEditBox = _display displayCtrl A3A_IDC_SPAWNDISTANCEEDITBOX;
    _sliderValue = sliderPosition _spawnDistanceSlider;
    _spawnDistanceEditBox ctrlSetText str floor _sliderValue;
  };

  case ("spawnDistanceEditBoxChanged"): {
    _display = findDisplay A3A_IDD_ADMINDIALOG;
    _spawnDistanceEditBox = _display displayCtrl A3A_IDC_SPAWNDISTANCEEDITBOX;
    _spawnDistanceSlider = _display displayCtrl A3A_IDC_SPAWNDISTANCESLIDER;
    _spawnDistanceEditBoxValue = floor parseNumber ctrlText _spawnDistanceEditBox;
    _spawnDistanceSlider sliderSetPosition _spawnDistanceEditBoxValue;
    if (_spawnDistanceEditBoxValue < spawnDistanceMin) then {_spawnDistanceEditBox ctrlSetText str spawnDistanceMin};
    if (_spawnDistanceEditBoxValue > spawnDistanceMax) then {_spawnDistanceEditBox ctrlSetText str spawnDistanceMax};
  };

  case ("aiLimiterSliderChanged"): {
    _display = findDisplay A3A_IDD_ADMINDIALOG;
    _aiLimiterSlider = _display displayCtrl A3A_IDC_AILIMITERSLIDER;
    _aiLimiterEditBox = _display displayCtrl A3A_IDC_AILIMITEREDITBOX;
    _sliderValue = sliderPosition _aiLimiterSlider;
    _aiLimiterEditBox ctrlSetText str floor _sliderValue;
  };

  case ("aiLimiterEditBoxChanged"): {
    _display = findDisplay A3A_IDD_ADMINDIALOG;
    _aiLimiterEditBox = _display displayCtrl A3A_IDC_AILIMITEREDITBOX;
    _aiLimiterSlider = _display displayCtrl A3A_IDC_AILIMITERSLIDER;
    _aiLimiterEditBoxValue = floor parseNumber ctrlText _aiLimiterEditBox;
    _aiLimiterSlider sliderSetPosition _aiLimiterEditBoxValue;
    if (_aiLimiterEditBoxValue < aiLimiterMin) then {_aiLimiterEditBox ctrlSetText str aiLimiterMin};
    if (_aiLimiterEditBoxValue > aiLimiterMax) then {_aiLimiterEditBox ctrlSetText str aiLimiterMax};
  };
};
