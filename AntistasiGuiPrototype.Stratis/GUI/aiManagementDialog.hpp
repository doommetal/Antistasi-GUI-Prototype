class A3A_AiManagementDialog
{
  idd = A3A_IDD_AIMANAGEMENTDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "PLAYER OPTIONS > AI MANAGEMENT";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class BackButton : A3A_BackButton
    {
      idc = -1;
      action = "[] spawn A3A_fnc_playerDialog";
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
        class AiControlIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 24 * GRID_W;
          y = 24 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AiControlButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Temp. AI Control";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 22 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class AutoLootIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 24 * GRID_W;
          y = 46 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AutoLootButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Auto Rearm / Loot";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 44 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class AutoHealIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 24 * GRID_W;
          y = 68 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AutoHealButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Auto Heal";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 66 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class GarrisonIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 128 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class GarrisonButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Garrison Unit(s)";
          size = GUI_TEXT_SIZE_LARGE;
          x = 92 * GRID_W;
          y = 32 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class DismissIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 128 * GRID_W;
          y = 60 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class DismissButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Dismiss Unit(s)";
          size = GUI_TEXT_SIZE_LARGE;
          x = 92 * GRID_W;
          y = 58 * GRID_H;
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
  };
};
