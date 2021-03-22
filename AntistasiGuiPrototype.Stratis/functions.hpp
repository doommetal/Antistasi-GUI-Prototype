class A3A
{
  class GUI
  {
    // Dialog functions
    class mainDialog {};
    class hqDialog {};
    class buyVehicleDialog {};

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
    class typeOfSoldier {}; // TODO: Already in antistasi, don't merge
    class canFight {}; // TODO: Already in antistasi, don't merge
  };

  class Revive
  {
    class isMedic {}; // TODO: Already in antistasi, don't merge
  };
};
