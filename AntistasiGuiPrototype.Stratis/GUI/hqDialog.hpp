class A3A_HqDialog
{
  idd = A3A_IDD_HQDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "HQ MANAGEMENT";
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
        class  GarrisonManagementButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Garrison Management";
          action = "[] spawn A3A_fnc_garrisonDialog";
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class  MinefieldManagementButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Minefield Management";
          x = 8 * GRID_W;
          y = 24 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class  TrainTroopsButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Train FIA Troops";
          x = 8 * GRID_W;
          y = 40 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class  MoveHqButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Move HQ";
          x = 8 * GRID_W;
          y = 56 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class  RebuildAssetsButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Rebuild Assets";
          x = 8 * GRID_W;
          y = 72 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class  RecruitSquadButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Recruit Squad";
          action = "[] spawn A3A_fnc_recruitSquadDialog";
          x = 8 * GRID_W;
          y = 84 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class FactionMoneyLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Faction money";
          x = 70 * GRID_W;
          y = 11 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class FactionMoneySlider : ctrlXSliderH
        {
          idc = A3A_IDC_FACTIONMONEYSLIDER;
          x = 74 * GRID_W;
          y = 23 * GRID_H;
          w = 60 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""factionMoneySliderChanged""] spawn A3A_fnc_hqDialog";
        };

        class FactionMoneyEditBox : ctrlEdit
        {
          idc = A3A_IDC_FACTIONMONEYEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 136 * GRID_W;
          y = 23 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""factionMoneyEditBoxChanged""] spawn A3A_fnc_hqDialog";
        };

        class FactionMoneyButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_FACTIONMONEYBUTTON;
          text = "Take money";
          x = 132 * GRID_W;
          y = 31 * GRID_H;
          w = 16 * GRID_H;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 1 * GRID_H;
            bottom = 1 * GRID_W;
          };
        };

        class SkipTimeLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Skip time";
          x = 70 * GRID_W;
          y = 50 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class SkipTimeSlider : ctrlXSliderH
        {
          idc = A3A_IDC_FACTIONMONEYSLIDER;
          x = 74 * GRID_W;
          y = 62 * GRID_H;
          w = 60 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""moneySliderChanged""] spawn A3A_fnc_playerDialog";
        };

        class SkipTimeEditBox : ctrlEdit
        {
          idc = A3A_IDC_FACTIONMONEYEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 136 * GRID_W;
          y = 62 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""moneyEditBoxChanged""] spawn A3A_fnc_playerDialog";
        };

        class SkipTimeButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_FACTIONMONEYBUTTON;
          text = "Take money";
          x = 132 * GRID_W;
          y = 70 * GRID_H;
          w = 16 * GRID_H;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 1 * GRID_H;
            bottom = 1 * GRID_W;
          };
        };

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
