class A3A
{
  class GUI
  {
    // Utility
    class handleTabs{};
    class sandboxDialog{};
    class getVehicleCrewCount {}; // Should probably be somewhere else when merging
    class getOutpostByMarkerName {};

    // Open dialogs
    class playerDialog {};
    class constructDialog {};
    class commanderDialog {};
    class adminDialog {};
    class playerManagementDialog{};
    class buyVehicleDialog {};
    class hqDialog {};
    class garageDialog {};
    class garrisonDialog {};
    class recruitDialog {};
    class recruitSquadDialog {};
    class requestMissionDialog {};
    class minefieldDialog {};
    class aiManagementDialog {};
    class airSupportDialog {};
    class donateDialog{};
  };

  class AI
  {
    class getGroupInfo {};
    class typeOfSoldier {}; // Already in antistasi, don't merge
    class canFight {}; // Already in antistasi, don't merge
  };

  class Revive
  {
    class isMedic {}; // Already in antistasi, don't merge
  };
};
