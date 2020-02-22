class A3A_RecruitSquadDialog
{
  idd = A3A_IDD_RECRUITSQUADDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "RECRUIT SQUADS";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 4 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class MainContent : RscControlsGroupNoScrollbars
    {
      idc = -1;
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H);
      w = PX_W(DIALOG_W);
      h = PX_H(DIALOG_H);

      class controls
      {
        class InfSquadButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Inf. Squad";
          x = 16 * GRID_W;
          y = 13 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class InfTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Inf. Team";
          x = 16 * GRID_W;
          y = 34 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class AtTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AT Team";
          x = 16 * GRID_W;
          y = 55 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class SniperTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Sniper Team";
          x = 16 * GRID_W;
          y = 76 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class MgTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "MG Team";
          x = 112 * GRID_W;
          y = 13 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class MortarTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Mortar Team";
          x = 112 * GRID_W;
          y = 34 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class AtCarButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AT Car";
          x = 112 * GRID_W;
          y = 55 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class AaTruckButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AA Truck";
          x = 112 * GRID_W;
          y = 76 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };
      };
    };
  };

  class controlsBackground
  {
    class TitleBackground : A3A_TitleBackground
    {
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 4 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class MainBackground : A3A_MainBackground
    {
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H);
      w = PX_W(DIALOG_W);
      h = PX_H(DIALOG_H);
    };
  };
};
