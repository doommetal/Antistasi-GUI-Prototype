#include "..\..\GUI\GUI_IDS.inc";
disableSerialization;

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do {
  case ("onLoad"): {
    while {dialog} do {closeDialog 2;}; // Make sure all other dialogs are closed
    createDialog "A3A_SandboxDialog";
    waitUntil {dialog}; // Wait until the dialog is actually created

    _display = findDisplay A3A_IDD_SANDBOXDIALOG;
    systemChat str _display;
};
