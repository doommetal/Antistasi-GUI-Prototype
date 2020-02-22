class A3A_RecruitDialog
{
  idd = A3A_IDD_RECRUITDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "RECRUIT UNITS";
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
        class RiflemanButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Rifleman";
          x = 16 * GRID_W;
          y = 13 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class AutoriflemanButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Autorifleman";
          x = 16 * GRID_W;
          y = 34 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class GrenadierButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Grenadier";
          x = 16 * GRID_W;
          y = 55 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class AtButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AT";
          x = 16 * GRID_W;
          y = 76 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class MedicButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Medic";
          x = 112 * GRID_W;
          y = 13 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class MarksmanButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Marksman";
          x = 112 * GRID_W;
          y = 34 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class EngineerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Engineer";
          x = 112 * GRID_W;
          y = 55 * GRID_H;
          w = 32 * GRID_W;
          h = 8 * GRID_H;
        };

        class BombSpecialistButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Bomb Specialist";
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
