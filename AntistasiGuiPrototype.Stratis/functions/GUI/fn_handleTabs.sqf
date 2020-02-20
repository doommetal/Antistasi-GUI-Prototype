#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params [["_activeTab", "NONE"]];

private "_display";

// Disable the button for the tab we're on
switch (_activeTab) do {
  case ("playerDialog"): {
    _display = findDisplay A3A_IDD_PLAYERDIALOG;
    _playerButton = _display displayCtrl A3A_IDC_PLAYERTABBUTTON;
    _playerButton ctrlSetBackgroundColor [0.1,0.1,0.1,1];
    ctrlEnable [A3A_IDC_PLAYERTABBUTTON, false];
  };

  case ("commanderDialog"): {
    _display = findDisplay A3A_IDD_COMMANDERDIALOG;
    _commanderButton = _display displayCtrl A3A_IDC_COMMANDERTABBUTTON;
    _commanderButton ctrlSetBackgroundColor [0.1,0.1,0.1,1];
    ctrlEnable [A3A_IDC_COMMANDERTABBUTTON, false];
  };

  case ("adminDialog"): {
  _display = findDisplay A3A_IDD_ADMINDIALOG;
  _adminButton = _display displayCtrl A3A_IDC_ADMINTABBUTTON;
  _adminButton ctrlSetBackgroundColor [0.1,0.1,0.1,1];
  ctrlEnable [A3A_IDC_ADMINTABBUTTON, false];
  };
};

// Disable Commander and Admin tabs if the player isn't either
if !(playerIsCommander) then
{
  _commanderButton = _display displayCtrl A3A_IDC_COMMANDERTABBUTTON;
  ctrlEnable [A3A_IDC_COMMANDERTABBUTTON, false];
};

if !(playerIsAdmin) then
{
  _adminButton = _display displayCtrl A3A_IDC_ADMINTABBUTTON;
  ctrlEnable [A3A_IDC_ADMINTABBUTTON, false];
};
