class A3A_DonateDialog
{
  idd = A3A_IDD_DONATEDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "PLAYER OPTIONS > DONATE MONEY";
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
      idc = A3A_IDC_PLAYERMAINCONTENT;
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H);
      w = PX_W(DIALOG_W);
      h = PX_H(DIALOG_H);

      class controls
      {

        class MoneySectionLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Donate money";
          x = 70 * GRID_W;
          y = 11 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class MoneySlider : ctrlXSliderH
        {
          idc = A3A_IDC_MONEYSLIDER;
          x = 74 * GRID_W;
          y = 23 * GRID_H;
          w = 60 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""moneySliderChanged""] spawn A3A_fnc_donateDialog";
        };

        class MoneyEditBox : ctrlEdit
        {
          idc = A3A_IDC_MONEYEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 136 * GRID_W;
          y = 23 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""moneyEditBoxChanged""] spawn A3A_fnc_donateDialog";
        };

        class DonateFactionButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEFACTIONBUTTON;
          text = "Donate to faction";
          x = 106 * GRID_W;
          y = 31 * GRID_H;
          w = 22 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 1 * GRID_H;
            bottom = 1 * GRID_W;
          };
        };

        class DonatePlayerButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEPLAYERBUTTON;
          text = "Donate to player";
          x = 130 * GRID_W;
          y = 31 * GRID_H;
          w = 22 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 1 * GRID_H;
            bottom = 1 * GRID_W;
          };
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
