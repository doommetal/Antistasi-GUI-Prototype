#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_CommanderDialog"; // Create the actual dialog
    waitUntil {dialog}; // Wait until the dialog is actually created
    // ^ This method might be a bit heavy handed, but it *** works ***
    
    ["commanderDialog"] call A3A_fnc_handleTabs;

  };
};
