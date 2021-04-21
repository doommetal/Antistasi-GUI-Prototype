// Needed to get custom textures on map icons
// Use MISSON_ROOT + path/to/texture.paa
MISSION_ROOT = call {
    private "_arr";
    _arr = toArray __FILE__;
    _arr resize (count _arr - 8);
    toString _arr
};

// Set log level
logLevel = 4;

///////////////////////////////////////////////////////////////////////////////
// EVERYTHING BELOW THIS POINT IS "FAKE" ANTISTASI FUNCTIONS TO TEST THE GUI //
///////////////////////////////////////////////////////////////////////////////

// Add event handler for keys
waituntil {!isnull (finddisplay 46)};

// Y
eventHandlerY = findDisplay 46 displayAddEventHandler ["KeyDown",{
  if (_this select 1 == 21) then {
    if (!dialog) then {createDialog "A3A_MainDialog";};
  };
}];


// U
eventHandlerU = findDisplay 46 displayAddEventHandler ["KeyDown", {
  if (_this select 1 == 22) then {
    if (!dialog) then {createDialog "A3A_LoadDialog";};
  };
}];

// U (cursorTarget)
/* eventHandlerU = findDisplay 46 displayAddEventHandler ["KeyDown", {
  if (_this select 1 == 22) then {[typeOf cursorTarget] execVM "functions\GUI\fn_getVehicleCrewCount.sqf";};
}]; */

// State variables
canGoUndercover = false; // TODO: Replace with A3A_fnc_canGoUndercover
// isUndercover = (captive _player) and !(_player getVariable ["incapacitated",false]);
canFastTravel = true; // TODO: Replace with A3A_fnc_canFastTravel
canConstruct = true; // check for engineer in squad

// Faction resources
skillFia = 1; // AI skill level
server setVariable ["resourcesFIA", 1000];
// factionMoney = 10000; // server getVariable "resourcesFIA"
server setVariable ["hr", 10];


playerIsCommander = true;
// theBoss == player
// player getVariable "eligible"
playerIsAdmin = true;
// if (player == A3A_admin)
// if (player == [] call A3A_fnc_getAdmin)
// call BIS_fnc_admin > 0
// (isServer && hasInterface) || {admin owner _this > 0} // <- correct way?

// Fake functions stuff
playerHasRadio = true;

// Aggro
// [aggressionLevelOccupants] call A3A_fnc_getAggroLevelString
// [aggressionLevelInvaders] call A3A_fnc_getAggroLevelString

// War level
tierWar = 5;
aggressionOccupants = 4;
aggressionInvaders = 2;

// Air Support Points
bombRuns = 3;

// TODO: Replace this with A3A_fnc_HQGameOptions
//civLimit = 40; // missionNamespace getVariable ["civPerc",0];
missionNamespace setVariable ["civPerc", 40, true];
civLimitMin = 0;
civLimitMax = 200;
// spawnDistance = 1000; // missionNamespace getVariable ["distanceSPWN",0];
missionNamespace setVariable ["distanceSPWN", 1000, true];
spawnDistanceMin = 100;
spawnDistanceMax = 12000;
// aiLimiter = 100; // missionNamespace getVariable ["maxUnits",0];
missionNamespace setVariable ["maxUnits", 100, true];
aiLimiterMin = 0;
aiLimiterMax = 200;

totalPopulation = 500;
rebelPopulation = 100;
deadPopulation = 75;

// Template stuff

// Needed for AI/A3A_fn_typeOfSoldier.sqf to work
// Most left empty as it shouldn't matter for the GUI testing
allMachineGuns = [];
allSniperRifles = [];

// Air Support aircraft
vehSDKPlane = "I_C_Plane_Civil_01_F";

// List of stuff to choose from in the Construct menu
// [classname, price, buildtime]
constructionsList = [
  ["Land_GarbageWashingMachine_F", 25, 60],
  ["Land_JunkPile_F", 25, 60],
  ["Land_Barricade_01_4m_F", 25, 60],
  ["Land_WoodPile_F", 25, 60],
  ["CraterLong_small", 25, 60],
  ["Land_Barricade_01_10m_F", 50, 60],
  ["Land_WoodPile_large_F", 50, 60],
  ["Land_BagFence_01_long_green_F", 50, 60],
  ["Land_SandbagBarricade_01_half_F", 50, 60],
  ["Land_Tyres_F", 50, 100],
  ["Land_TimberPile_01_F", 50, 100],
  ["Land_BagBunker_01_small_green_F", 100, 60],
  ["Land_PillboxBunker_01_big_F", 300, 120],
  ["Land_Anthill_01_F", 10, 500],
  ["Land_FieldToilet_F", 500, 120]
];

// List of vehicles for the buy vehicle menu
// [classname, price, undercover]
buyableVehiclesList = [
  ["I_G_Quadbike_01_F", 50, false],
  ["I_G_Offroad_01_armed_F", 250, false],
  ["I_G_Offroad_01_AT_F", 300, false],
  ["O_MBT_04_Cannon_F", 4000, false],
  ["I_G_Offroad_01_F", 200, false],
  ["I_G_Van_01_transport_F", 300, false],
  ["I_C_Plane_civil_01_F", 5000, true],
  ["I_G_Boat_Transport_01_F", 500, false],
  ["I_G_Offroad_01_repair_F", 500, false],
  ["C_Offroad_01_F", 200, true],
  ["C_Van_01_transport_F", 300, true],
  ["C_Heli_Light_01_civil_F", 3000, true],
  ["O_Heli_Attack_02_dynamicLoadout_F", 10000, false],
  ["C_Boat_Transport_02_F", 800, true],
  ["I_HMG_01_high_F", 100, false],
  ["I_Static_AT_F", 150, false],
  ["I_Static_AA_F", 200, false],
  ["I_G_Mortar_01_F", 300, false]
];

// Fake "players" to use for memberlist stuff etc.
fakePlayers = [p1, p2, p3, p4];

// Set fake player variables, to be replaced the real functions when merging
{
  _x setVariable ["isMember", false];
  _x setVariable ["fakePlayerUID", str floor random [10000,50000,99999] + str floor random [10000,50000,99999] + str floor random [10000,50000,99999] + str floor random [10,50,99]];
  _x setVariable ["kills", 0];
  _x setVariable ["missionsCompleted", 0];
  _x setVariable ["eligibleCommander", true];
  _x setVariable ["moneyX", floor random 2000];
} forEach fakePlayers;
p1 setVariable ["isMember", true]; // player starts as member


// Fake map places
outposts = [
  "outpost_1",
  "outpost_2",
  "outpost_3",
  "outpost_4",
  "outpost_5"
];
airportsX = ["airport_1"];
resourcesX = ["resource_1"];
factories = ["factory_1"];
seaports = ["seaport_1"];
citiesX = ["AgiaMarina", "Girna"];
markersX = airportsX + resourcesX + factories + outposts + seaports + citiesX + ["Synd_HQ"];

// Set sides
// Loop through all markers
markersX apply {
  // Set side to GUER
  sidesX setVariable [_x, resistance];
};
// TODO: Set a few select ones to WEST or whatever

// Set garrisons
// Loop through all markers
markersX apply {
  // Set garrison to [0,0,0,0,0,0,0,0]
  garrisons setVariable [_x, [0,0,0,0,0,0,0,0]];
};


// Init addActions for HQ assets
petros addAction["HQ Management","createDialog ""A3A_HqDialog"""];
petros addAction["Request Mission","createDialog ""A3A_RequestMissionDialog"""];
flagX addAction["Recruit","createDialog ""A3A_RecruitDialog"""];
flagX addAction["Recruit Squads","createDialog ""A3A_RecruitSquadDialog"""];
mapX addAction["Map Info","hint ""Imagine opening Map Info."""];
boxX addAction["Arsenal","hint ""Imagine opening the Arsenal."""];
vehicleBox addaction["Buy Vehicle","createDialog ""A3A_BuyVehicleDialog"""];
vehicleBox addaction["Heal, Repair and Rearm","hint ""Imagine a healing light passing over you as Petros does his magic ;^)"""];
vehicleBox addaction["Unload Vehicle Cargo to Ammobox","hint ""Imagine carrying all those heavy boxes."""];
vehicleBox addaction["Personal Garage","hint ""Imagine opening the garage."""];
vehicleBox addaction["Faction Garage","hint ""Imagine opening the garage."""];
fireX addaction["Save","hint ""Imagine saving."""];
