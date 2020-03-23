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

        class GarrisonManagementIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 8 * GRID_W;
          y = 13 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class GarrisonManagementButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Garrison Management";
          action = "[] spawn A3A_fnc_garrisonDialog";
          x = 20 * GRID_W;
          y = 11 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class MinefieldManagementIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 8 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class MinefieldManagementButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Minefield Management";
          action = "[] spawn A3A_fnc_minefieldDialog";
          x = 20 * GRID_W;
          y = 32 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class TrainTroopsIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          x = 8 * GRID_W;
          y = 55 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class TrainTroopsButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Train Troops";
          x = 20 * GRID_W;
          y = 53 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class MoveHqIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_none.paa";
          // text = "\A3\Ui_f\data\IGUI\Cfg\Actions\talk_ca.paa";
          x = 8 * GRID_W;
          y = 76 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class MoveHqButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Move HQ";
          x = 20 * GRID_W;
          y = 74 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class FactionMoneyLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Faction money";
          x = 70 * GRID_W;
          y = 7 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class FactionMoneySlider : ctrlXSliderH
        {
          idc = A3A_IDC_FACTIONMONEYSLIDER;
          x = 74 * GRID_W;
          y = 19 * GRID_H;
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
          y = 19 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""factionMoneyEditBoxChanged""] spawn A3A_fnc_hqDialog";
        };

        class FactionMoneyButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_FACTIONMONEYBUTTON;
          text = "Take money";
          x = 132 * GRID_W;
          y = 27 * GRID_H;
          w = 20 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 1 * GRID_H;
            bottom = 1 * GRID_W;
          };
        };

        class RestLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Rest";
          x = 70 * GRID_W;
          y = 46 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class RestText : ctrlStructuredText
        {
          idc = A3A_IDC_RESTTEXT;
          text = "";
          x = 74 * GRID_W;
          y = 52 * GRID_H;
          w = 60 * GRID_W;
          h = 10 * GRID_H;
          colorBackground[] = {0,0,0,0.5};
        };

        class RestSlider : ctrlXSliderH
        {
          idc = A3A_IDC_RESTSLIDER;
          x = 74 * GRID_W;
          y = 66 * GRID_H;
          w = 60 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""restSliderChanged""] spawn A3A_fnc_hqDialog";
        };

        class RestButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Rest";
          action = "[""debugChangeTime""] spawn A3A_fnc_hqDialog;";
          x = 136 * GRID_W;
          y = 64 * GRID_H;
          w = 16 * GRID_W;
          h = 8 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 1 * GRID_H;
            bottom = 1 * GRID_W;
          };
        };

        class ClearTreesButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Clear Trees";
          x = 74 * GRID_W;
          y = 78 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class ClearFogButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Clear Fog";
          x = 116 * GRID_W;
          y = 78 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };
        // End of main content group controls
      };
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = CENTER_X(DIALOG_W) + PX_W(DIALOG_W) - 4 * GRID_W;
      y = CENTER_Y(DIALOG_H) - 4 * GRID_H;
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
