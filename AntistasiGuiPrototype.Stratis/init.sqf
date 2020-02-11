// Add event handler for keys
waituntil {!isnull (finddisplay 46)};

// Y
eventHandlerY = findDisplay 46 displayAddEventHandler ["KeyDown",{
  if (_this select 1 == 21) then {[] spawn A3A_fnc_playerDialog;};
}];

// U
eventHandlerU = findDisplay 46 displayAddEventHandler ["KeyDown", {
  if (_this select 1 == 22) then {[] spawn A3A_fnc_sandboxDialog;};
}];

// State variables
canGoUndercover = false;
canFastTravel = true;
canConstruct = true;
canManageAI = true;
playerMoney = 1500;
playerIsCommander = true;
playerIsAdmin = true;

civLimit = 40;
civLimitMin = 0;
civLimitMax = 200;
spawnDistance = 1000;
spawnDistanceMin = 100;
spawnDistanceMax = 12000;
aiLimiter = 100;
aiLimiterMin = 0;
aiLimiterMax = 200;
