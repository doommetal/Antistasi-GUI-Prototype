#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params [["_activeTab", "NONE"]];

// Disable the button for the tab we're on
switch (_activeTab) do {
    case ("playerDialog"): {
        _display = findDisplay A3A_IDD_PLAYERDIALOG;
        _playerButton = _display displayCtrl A3A_IDC_PLAYERTABBUTTON;
        /* _playerButton ctrlEnable false; */
        ctrlEnable [A3A_IDC_PLAYERTABBUTTON, false];
    };

    case ("commanderDialog"): {
        _display = findDisplay A3A_IDD_COMMANDERDIALOG;
        _commanderButton = _display displayCtrl A3A_IDC_COMMANDERTABBUTTON;
        /* _commanderButton ctrlEnable false; */
        ctrlEnable [A3A_IDC_COMMANDERTABBUTTON, false];
    };

    case ("adminDialog"): {
      _display = findDisplay A3A_IDD_ADMINDIALOG;
      _adminButton = _display displayCtrl A3A_IDC_ADMINTABBUTTON;
      /* _adminButton ctrlEnable false; */
      ctrlEnable [A3A_IDC_ADMINTABBUTTON, false];
    };
};

//TODO: Check if player is commander or admin
