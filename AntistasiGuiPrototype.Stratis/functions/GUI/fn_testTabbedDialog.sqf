// disableSerialization; // TODO UI-update: Test without this to see if it's actually needed

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do
{
  case ("onLoad"):
  {
    diag_log "onLoad: testTabbedDialog";
    _display = findDisplay 7000;
    diag_log format ["_display: %1", _display];
    _editBox = _display displayCtrl 7202;
    diag_log format ["_editBox: %1", _editBox];
    _slider = _display displayCtrl 7203;
    diag_log format ["_slider: %1", _slider];

    _slider sliderSetRange [0,1000];
    diag_log format ["%1 set range 0-1000", _slider];
    _slider sliderSetSpeed [1,1];
    diag_log format ["%1 set speed 1-1", _slider];
    _slider sliderSetPosition 0;
    diag_log format ["%1 set position 0", _slider];

    _editBox ctrlSetText str 0;
    diag_log format ["%1 set text 0", _editBox];

    // Disable test buttons
    _testButtonDisabled = _display displayCtrl 9000;
    _testButtonDisabled ctrlEnable false;
    _testShortcutButtonDisabled = _display displayCtrl 9001;
    _testShortcutButtonDisabled ctrlEnable false;
  };

  case ("sliderChanged"):
  {
    diag_log "Slider changed";
    _display = findDisplay 7000;
    _editBox = _display displayCtrl 7202;
    _slider = _display displayCtrl 7203;
    _sliderValue = sliderPosition _slider;
    _editBox ctrlSetText str _sliderValue;
  };

  case ("editBoxChanged"):
  {
    diag_log "Editbox changed";
    _display = findDisplay 7000;
    _editBox = _display displayCtrl 7202;
    _slider = _display displayCtrl 7203;
    _editBoxValue = parseNumber ctrlText _editBox;
    if (_editBoxValue < 0) then {_editBox ctrlSetText str 0};
    if (_editBoxValue > 1000) then {_editBox ctrlSetText str 1000};
    _slider sliderSetPosition _editBoxValue;
  };
};
