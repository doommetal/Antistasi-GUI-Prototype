#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_HqDialog";
    waitUntil {dialog}; // Wait until the dialog is actually created

    _display = findDisplay A3A_IDD_HQDIALOG;

    // Faction money section setup
    _factionMoneySlider = _display displayCtrl A3A_IDC_FACTIONMONEYSLIDER;
    _factionMoneySlider sliderSetRange [0,factionMoney];
    _factionMoneySlider sliderSetSpeed [100, 100];
    _factionMoneySlider sliderSetPosition 0;

    // Rest section setup
    _restSlider = _display displayCtrl A3A_IDC_RESTSLIDER;
    _restSlider sliderSetRange [0,24];
    _restSlider sliderSetSpeed [1,1];
    _restSlider sliderSetPosition 0;
    ["restSliderChanged"] spawn A3A_fnc_hqDialog;
  };

  case ("restSliderChanged"): {
    _display = findDisplay A3A_IDD_HQDIALOG;

    _restSlider = _display displayCtrl A3A_IDC_RESTSLIDER;
    _restText = _display displayCtrl A3A_IDC_RESTTEXT;
    _time = sliderPosition _restSlider;
    _timeArray = [_time, "ARRAY"] call BIS_fnc_timeToString;
    // timeToString is 0 padded so we remove that
    _hours = parseNumber( _timeArray select 0);
    _minutes = parseNumber (_timeArray select 1);
    _restTimeString = "";
    // correct grammar up in this motherfucker
    if (_hours == 1 and _minutes == 1) then {
      _restTimeString = format ["%1 hour, %1 minute", _hours, _minutes];
    } else {
      if (_hours == 1) then {
        _restTimeString = format ["%1 hour, %2 minutes", _hours, _minutes];
      } else {
        if (_minutes == 1) then {
          _restTimeString = format ["%1 hours, %2 minute", _hours, _minutes];
        } else {
          _restTimeString = format ["%1 hours, %2 minutes", _hours, _minutes];
        };
      };
    };
    _postRestTime = daytime + _time;
    if (_postRestTime > 24) then {
      _postRestTime = _postRestTime - 24;
    };
    _postRestTimeString = [_postRestTime, "HH:MM"] call BIS_fnc_timeToString;
    _message = format ["Rest for %1.<br />Time will be %2 when you wake up.", _restTimeString, _postRestTimeString];
    _restText ctrlSetStructuredText parseText _message;
  };

  case ("factionMoneySliderChanged"): {
    _display = findDisplay A3A_IDD_HQDIALOG;
    _factionMoneySlider = _display displayCtrl A3A_IDC_FACTIONMONEYSLIDER;
    _factionMoneyEditBox = _display displayCtrl A3A_IDC_FACTIONMONEYEDITBOX;
    _sliderValue = sliderPosition _factionMoneySlider;
    _factionMoneyEditBox ctrlSetText str floor _sliderValue;
  };

  case ("factionMoneyEditBoxChanged"): {
    _display = findDisplay A3A_IDD_HQDIALOG;
    _factionMoneyEditBox = _display displayCtrl A3A_IDC_FACTIONMONEYEDITBOX;
    _factionMoneySlider = _display displayCtrl A3A_IDC_FACTIONMONEYSLIDER;
    _factionMoneyEditBoxValue = floor parseNumber ctrlText _factionMoneyEditBox;
    _factionMoneySlider sliderSetPosition _factionMoneyEditBoxValue;
    if (_factionMoneyEditBoxValue < 0) then {_factionMoneyEditBox ctrlSetText str 0};
    if (_factionMoneyEditBoxValue > factionMoney) then {_factionMoneyEditBox ctrlSetText str factionMoney};
  };

  case ("debugChangeTime"): {
    _display = findDisplay A3A_IDD_HQDIALOG;
    _restSlider = _display displayCtrl A3A_IDC_RESTSLIDER;
    _time = sliderPosition _restSlider;
    skipTime _time;
    closeDialog 1;
  };
};
