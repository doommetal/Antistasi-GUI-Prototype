class A3A_CommanderDialog
{
  idd = A3A_IDD_COMMANDERDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "COMMANDER OPTIONS";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class Tabs : A3A_Tabs {
      idc = -1;
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
        class HcList : A3A_ShortcutButton
        {
          idc = -1;
          text = "Squad list placeholder";
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 64 * GRID_W;
          h = 54 * GRID_H;
        };

        class HcButton1 : A3A_ShortcutButton
        {
          idc = -1;
          text = "SITREP";
          x = 8 * GRID_W;
          y = 66 * GRID_H;
          w = 20 * GRID_W;
          h = 12 * GRID_H;
        };

        class HcButton2 : A3A_ShortcutButton
        {
          idc = -1;
          text = "Recruit";
          x = 30 * GRID_W;
          y = 66 * GRID_H;
          w = 20 * GRID_W;
          h = 12 * GRID_H;
        };

        class HcButton3 : A3A_ShortcutButton
        {
          idc = -1;
          text = "Dismiss";
          x = 52 * GRID_W;
          y = 66 * GRID_H;
          w = 20 * GRID_W;
          h = 12 * GRID_H;
        };

        class HcButton4 : A3A_ShortcutButton
        {
          idc = -1;
          text = "Garrison";
          x = 8 * GRID_W;
          y = 80 * GRID_H;
          w = 20 * GRID_W;
          h = 12 * GRID_H;
        };

        class HcButton5 : A3A_ShortcutButton
        {
          idc = -1;
          text = "Add Vehicle";
          x = 30 * GRID_W;
          y = 80 * GRID_H;
          w = 20 * GRID_W;
          h = 12 * GRID_H;
        };

        class HcButton6 : A3A_ShortcutButton
        {
          idc = -1;
          text = "Mount / Dismount";
          x = 52 * GRID_W;
          y = 80 * GRID_H;
          w = 20 * GRID_W;
          h = 12 * GRID_H;
        };
      };
    };
  };

  class controlsBackground
  {
    class TitleBackground : A3A_TitleBackground
    {
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class TabsBackground : A3A_TabsBackground
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
