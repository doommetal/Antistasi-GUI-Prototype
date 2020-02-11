// Add event handler for keys
waituntil {!isnull (finddisplay 46)};

// Y
eventHandlerY = findDisplay 46 displayAddEventHandler ["KeyDown",{
  if (_this select 1 == 21) then {[] spawn A3A_fnc_playerDialog;};
}];

// U
eventHandlerU = findDisplay 46 displayAddEventHandler ["KeyDown", {
  if (_this select 1 == 22) then {[] spawn A3A_fnc_openSandboxDialog;};
}];

// State variables
canGoUndercover = false;
canFastTravel = true;
canConstruct = true;
canManageAI = true;
playerMoney = 1500;
