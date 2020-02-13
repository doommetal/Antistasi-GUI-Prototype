#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_PlayerManagementDialog";
    waitUntil {dialog}; // Wait until the dialog is actually created

    _display = findDisplay A3A_IDD_PLAYERMANAGEMENTDIALOG;

    _listBox = _display displayCtrl A3A_IDC_PLAYERLIST;
    {
      _name = name _x;
      _isMember = _x getVariable "isMember";

      _index = _listBox lbAdd _name;
      if (_isMember) then {
        _listBox lbSetColor [_index, [0.2,0.6,0.2,1]];
      } else {
        _listBox lbSetColor [_index, [0.7,0.7,0.7,1]];
      };
    } forEach fakePlayers;

    _listBox lbSetCurSel 0;
    ["listBoxSelectionChanged"] spawn A3A_fnc_playerManagementDialog;
  };

  case ("listBoxSelectionChanged"): {
    _display = findDisplay A3A_IDD_PLAYERMANAGEMENTDIALOG;
    _listBox = _display displayCtrl A3A_IDC_PLAYERLIST;
    _index = lbCurSel _listBox;
    _addButton = _display displayCtrl A3A_IDC_ADDMEMBERBUTTON;
    _removeButton = _display displayCtrl A3A_IDC_REMOVEMEMBERBUTTON;
    _player = fakePlayers select _index;
    if (_player getVariable "isMember") then {
      _addButton ctrlShow false;
      _removeButton ctrlShow true;
    } else {
      _addButton ctrlShow true;
      _removeButton ctrlShow false;
    };
  };

  // Debug cases, to be removed/changed when merging
  case ("addMember"): {
    _display = findDisplay A3A_IDD_PLAYERMANAGEMENTDIALOG;
    _listBox = _display displayCtrl A3A_IDC_PLAYERLIST;
    _index = lbCurSel _listBox;
    _listBox lbSetColor [_index, [0.2,0.6,0.2,1]];
    fakePlayers select _index setVariable ["isMember", true];
    ["listBoxSelectionChanged"] spawn A3A_fnc_playerManagementDialog;
  };

  case ("removeMember"): {
    _display = findDisplay A3A_IDD_PLAYERMANAGEMENTDIALOG;
    _listBox = _display displayCtrl A3A_IDC_PLAYERLIST;
    _index = lbCurSel _listBox;
    _listBox lbSetColor [_index, [0.7,0.7,0.7,1]];
    fakePlayers select _index setVariable ["isMember", false];
    ["listBoxSelectionChanged"] spawn A3A_fnc_playerManagementDialog;
  };
};
