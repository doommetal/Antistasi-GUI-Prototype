class A3A
{
  class GUI
  {
    // Dialog functions
    class mainDialog {};
    class playerTab {};
    class commanderTab {};
    class adminTab {};
    class fastTravelTab {};
    class constructTab {};
    class aiManagementTab {};
    class donateTab {};
    class airSupportTab {};
    class playerManagementTab {};
    class hqDialog {};
    class buyVehicleDialog {};
    class requestMissionDialog {};

    // Map drawing event handlers
    class fireMissionEH {};
    class mapDrawOutpostsEH {};
    class mapDrawHcGroupsEH {};
    class mapDrawSelectEH {};
    class mapDrawUserMarkersEH {};

    // Utility functions
    class configColorToArray {};
    class getVehicleCrewCount {};
    class getOutpostByMarkerName {};

    // TODO UI-update: Test stuff, remove when merging
    class testTabbedDialog {};
    class testStartDialog {};
  };

  class Environment
  {
    class stopRain {};
  };

  class AI
  {
    class getGroupInfo {};
    class getGroupVehicle {};
    class mountDismountGroup {};
    class typeOfSoldier {}; // Already in antistasi, don't merge
    class canFight {}; // Already in antistasi, don't merge
    class hasRadio {}; // Already in antistasi, don't merge
  };

  class Base
  {
    class getLocationMarkerType {};
    class getAggroLevelString {}; // Already in antistasi, don't merge
    class canMoveHQ {}; // Already in antsitasi, don't merge
    class moveHQ {}; // Already in antistasi, don't merge
  };

  class Revive
  {
    class isMedic {}; // Already in antistasi, don't merge
  };

  class Utility
  {
    class formatTime {};
    class systemTime_format_S {}; // Already in antistasi, don't merge
  };

  class OrgPlayers
  {
    class theBossToggleEligibility {}; // Already in antistasi, don't merge
    class assignBossIfNone {}; // Already in antistasi, don't merge
    class isMember {}; // Already in antistasi, don't merge
  };

  class Undercover
  {
    class canGoUndercover {};
    class goUndercover {};
  };

  class FastTravel
  {
    class canFastTravel {};
    class fastTravel {};
  };

  class REINF
  {
    class canBuild {};
    class enemyNearCheck {}; // Already in antistasi, don't merge
  };
};
