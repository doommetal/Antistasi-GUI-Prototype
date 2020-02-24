class A3A_SandboxDialog
{
  idd = A3A_IDD_SANDBOXDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "SANDBOX";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class BackButton : A3A_BackButton
    {
      idc = -1;
      action = "[] spawn A3A_fnc_sandboxDialog";
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
        class SizeTestGroup : RscControlsGroupNoScrollbars
        {
          x = 0;
          y = 0;
          w = PX_W(DIALOG_W);
          h = PX_H(DIALOG_H);
          show = false;

          class controls
          {
            class TestText1 : RscText
            {
              text = "GUI_TEXT_SIZE_SMALL -  Goes in a box with 3xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_SMALL;
              x = 0;
              y = 0;
              w = 80 * GRID_W;
              h = 3 * GRID_H;
            };

            class TestText2 : RscText
            {
              idc = 22001;
              text = "GUI_TEXT_SIZE_MEDIUM - Goes in a box with 4xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 0;
              y = 9 * GRID_H;
              w = 80 * GRID_W;
              h = 4 * GRID_H;
            };

            class TestText3 : RscText
            {
              text = "GUI_TEXT_SIZE_LARGE - Goes in a box with 6xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_LARGE;
              x = 0;
              y = 18 * GRID_H;
              w = 80 * GRID_W;
              h = 6 * GRID_H;
            };

            class GridBox1 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 8 * GRID_H;
              w = GRID_W;
              h = GRID_H;
            };

            class GridBox2 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 16 * GRID_H;
              w = 2 * GRID_W;
              h = 2 * GRID_H;
            };

            class GridBox4 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 24 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };
            class GridBox8 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 32 * GRID_H;
              w = 8 * GRID_W;
              h = 8 * GRID_H;
            };

            class TestButtonSmall : A3A_ShortcutButton
            {
              text = "Small Button 1 Line";
              size = GUI_TEXT_SIZE_SMALL;
              x = 8 * GRID_W;
              y = 50 * GRID_H;
              w = 30 * GRID_W;
              h = 5 * GRID_H;

              class textPos
              {
                left = 1 * GRID_W;
                right = 1 * GRID_H;
                top = 1 * GRID_W;
                bottom = 1* GRID_H;
              };
            };

            class TestButtonSmall2 : A3A_ShortcutButton
            {
              text = "Small Button 2 Line";
              size = GUI_TEXT_SIZE_SMALL;
              x = 42 * GRID_W;
              y = 50 * GRID_H;
              w = 16 * GRID_W;
              h = 8 * GRID_H;

              class textPos
              {
                left = 1 * GRID_W;
                right = 1 * GRID_H;
                top = 1 * GRID_W;
                bottom = 1* GRID_H;
              };
            };
          };
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
