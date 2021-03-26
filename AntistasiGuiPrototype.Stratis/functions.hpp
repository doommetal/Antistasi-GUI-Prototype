class A3A
{
  class GUI
  {
    // Dialog functions
    class mainDialog {};
    class playerTab {};
    class commanderTab {};
    class adminTab {};
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
    class hcGroupsEH {};
    class hcSelectEH {};
    class outpostMarkersEH {};
    class outpostSelectEH {};

    // Utility functions
    class configColorToArray {};
    class getVehicleCrewCount {};
    class getOutpostByMarkerName {};

    // TODO: Test stuff, remove when merging
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
    class typeOfSoldier {}; // Already in antistasi, don't merge
    class canFight {}; // Already in antistasi, don't merge
    class hasRadio {}; // Already in antistasi, don't merge
  };

  class Revive
  {
    class isMedic {}; // Already in antistasi, don't merge
  };

  class Utility
  {
    class formatTime {};
  };
};
