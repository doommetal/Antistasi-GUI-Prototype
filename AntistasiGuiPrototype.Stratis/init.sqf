// Needed to get custom textures on map icons
MISSION_ROOT = call {
    private "_arr";
    _arr = toArray __FILE__;
    _arr resize (count _arr - 8);
    toString _arr
};

// Stupid hack to force group icons to load
/* [] spawn {
  setGroupIconsVisible [true, true];
  sleep 1;
  setGroupIconsVisible [false, false];
}; */

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
    if (!dialog) then {createDialog "A3A_TestDefaultDialog";};
  };
}];

// U (cursorTarget)
/* eventHandlerU = findDisplay 46 displayAddEventHandler ["KeyDown", {
  if (_this select 1 == 22) then {[typeOf cursorTarget] execVM "functions\GUI\fn_getVehicleCrewCount.sqf";};
}]; */

// State variables
canGoUndercover = false;
canFastTravel = true;
canConstruct = true;
canManageAI = true;
factionMoney = 10000;
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

totalPopulation = 500;
rebelPopulation = 100;
deadPopulation = 75;

// Template stuff
// Needed for AI/A3A_fn_typeOfSoldier.sqf to work
// Most left empty as it shouldn't matter for the GUI testing
allMachineGuns = [];
allSniperRifles = [];

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
  _x setVariable ["money", floor random 2000];
} forEach fakePlayers;
p1 setVariable ["isMember", true]; // player starts as member


// Fake map places
// markerName (str), type (str), garrison (array<int>)
// TODO: D'oh, forgot to add side
outposts = [
  ["marker_outpost1", "outpost", [0,0,0,0,0,0,0,0]],
  ["marker_outpost2", "outpost", [0,0,0,0,0,0,0,0]],
  ["marker_outpost3", "outpost", [0,0,0,0,0,0,0,0]],
  ["marker_outpost4", "outpost", [0,0,0,0,0,0,0,0]],
  ["marker_outpost5", "outpost", [0,0,0,0,0,0,0,0]],
  ["marker_HQ", "hq", [0,0,0,0,0,0,0,0]]
];

// markerName (str), type (str), mines (array<obj>)
/* minefields = [
  ["minefield1", "ap", [] ];
]; */


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
