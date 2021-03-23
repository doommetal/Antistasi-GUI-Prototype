// TODO: Add header
#include "..\..\GUI\ids.inc"

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
