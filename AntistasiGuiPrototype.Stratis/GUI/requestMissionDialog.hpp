class A3A_RequestMissionDialog
{
  idd = A3A_IDD_REQUESTMISSONDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "REQUEST MISSION";
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
        class AssasinationIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_assasination.paa";
          x = 24 * GRID_W;
          y = 10 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class AssasinationButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Assasination";
          size = GUI_TEXT_SIZE_LARGE;
          x = 16 * GRID_W;
          y = 30 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class LogisticsIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_logistics.paa";
          x = 72 * GRID_W;
          y = 10 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class LogisticsButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Logistics";
          size = GUI_TEXT_SIZE_LARGE;
          x = 64 * GRID_W;
          y = 30 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class ConvoyIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_convoy_ambush.paa";
          x = 120 * GRID_W;
          y = 10 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class ConvoyButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Convoy Ambush";
          size = GUI_TEXT_SIZE_LARGE;
          x = 112 * GRID_W;
          y = 30 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class ConquestIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_conquest.paa";
          x = 24 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class ConquestButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Conquest";
          size = GUI_TEXT_SIZE_LARGE;
          x = 16 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class DestroyIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_destroy.paa";
          x = 72 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class DestroyButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Destroy";
          size = GUI_TEXT_SIZE_LARGE;
          x = 64 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class RescueIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_rescue.paa";
          x = 120 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class RescueButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Rescue";
          size = GUI_TEXT_SIZE_LARGE;
          x = 112 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        ///////////////////
        /// OLD BUTTONS ///
        ///////////////////

        // class AssasinationIcon : RscPicture
        // {
        //   idc = -1;
        //   colorBackground[] = {0,0,0,0};
        //   text = "GUI\textures\icon_assasination.paa";
        //   x = 24 * GRID_W;
        //   y = 68 * GRID_H;
        //   w = 8 * GRID_W;
        //   h = 8 * GRID_H;
        // };
        //
        // class AssasinationButton : A3A_ShortcutButton
        // {
        //   idc = -1;
        //   text = "Assasination";
        //   x = 16 * GRID_W;
        //   y = 13 * GRID_H;
        //   w = 32 * GRID_W;
        //   h = 8 * GRID_H;
        // };
        //
        // class LogisticsButton : A3A_ShortcutButton
        // {
        //   idc = -1;
        //   text = "Logistics";
        //   x = 16 * GRID_W;
        //   y = 34 * GRID_H;
        //   w = 32 * GRID_W;
        //   h = 8 * GRID_H;
        // };
        //
        // class ConvoyButton : A3A_ShortcutButton
        // {
        //   idc = -1;
        //   text = "Convoy Ambush";
        //   x = 16 * GRID_W;
        //   y = 55 * GRID_H;
        //   w = 32 * GRID_W;
        //   h = 8 * GRID_H;
        // };
        //
        // class ConquestButton : A3A_ShortcutButton
        // {
        //   idc = -1;
        //   text = "Conquest";
        //   x = 112 * GRID_W;
        //   y = 13 * GRID_H;
        //   w = 32 * GRID_W;
        //   h = 8 * GRID_H;
        // };
        //
        // class DestroyButton : A3A_ShortcutButton
        // {
        //   idc = -1;
        //   text = "Destroy";
        //   x = 112 * GRID_W;
        //   y = 34 * GRID_H;
        //   w = 32 * GRID_W;
        //   h = 8 * GRID_H;
        // };
        //
        // class RescueButton : A3A_ShortcutButton
        // {
        //   idc = -1;
        //   text = "Rescue";
        //   x = 112 * GRID_W;
        //   y = 55 * GRID_H;
        //   w = 32 * GRID_W;
        //   h = 8 * GRID_H;
        // };
      };
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = CENTER_X(DIALOG_W) + PX_W(DIALOG_W) - 4 * GRID_W;
      y = CENTER_Y(DIALOG_H) - 4 * GRID_H;
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
