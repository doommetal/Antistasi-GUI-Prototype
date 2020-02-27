class A3A_AirSupportDialog
{
  idd = A3A_IDD_AIRSUPPORTDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "COMMANDER OPTIONS > AIR SUPPORT";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class BackButton : A3A_BackButton
    {
      idc = -1;
      action = "[] spawn A3A_fnc_commanderDialog";
      x = CENTER_X(DIALOG_W) + PX_W(DIALOG_W) - 9 * GRID_W;
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = CENTER_X(DIALOG_W) + PX_W(DIALOG_W) - 4 * GRID_W;
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
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
        // Start of main group controls
        class AirSupportText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "Remaining Air Support points: 12";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 52 * GRID_W;
          y = 10 * GRID_H;
          w = 56 * GRID_W;
          h = 6 * GRID_H;
        };

        class AirSupportInfoText : RscTextMulti
        {
          idc = -1;
          text = "Aircraft used: Antonov An-2\n\nAdd aircraft to the air support pool by using the thing in the other menu and things.\nMore lines.";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          colorText[] = {0.7,0.7,0.7,1};
          x = 40 * GRID_W;
          y = 20 * GRID_H;
          w = 80 * GRID_W;
          h = 20 * GRID_H;
        };

        class HeBombsIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 24 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class HeBombsButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "HE Bombs";
          size = GUI_TEXT_SIZE_LARGE;
          x = 16 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class CarpetBombingIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 72 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class CarpetBombingButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Carpet Bombing";
          size = GUI_TEXT_SIZE_LARGE;
          x = 64 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class NapalmBombIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 120 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class NapalmBombButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Napalm Bomb";
          size = GUI_TEXT_SIZE_LARGE;
          x = 112 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };
        // End of main content group controls
      };
    };

    // End of controls
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

    class InfoBackground : A3A_MainBackground
    {
      colorBackground[] = {0,0,0,0.5};
      x = CENTER_X(DIALOG_W) + 38 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 8 * GRID_H;
      w = 94 * GRID_W;
      h = 34 * GRID_H;
    };
  };
};
