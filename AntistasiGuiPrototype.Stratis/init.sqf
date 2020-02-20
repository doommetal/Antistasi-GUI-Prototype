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

// U (cursorTarget)
/* eventHandlerU = findDisplay 46 displayAddEventHandler ["KeyDown", {
  if (_this select 1 == 22) then {[typeOf cursorTarget] execVM "functions\GUI\fn_getVehicleCrewCount.sqf";};
}]; */

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

// Set member status
{
  _x setVariable ["isMember", false];
} forEach fakePlayers;
p1 setVariable ["isMember", true]; // player starts as member

// Needed to get custom textures on map icons
MISSION_ROOT = call {
    private "_arr";
    _arr = toArray __FILE__;
    _arr resize (count _arr - 8);
    toString _arr
};
