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

        class PlayerList : ctrlListBox
        {
          idc = A3A_IDC_DONATEPLAYERLIST;
          x = 8 * GRID_H;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 84 * GRID_H;
        };

        class MoneyLabel : RscText
        {
          idc = -1;
          style = ST_LEFT;
          text = "Current money:";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 83 * GRID_W;
          y = 30 * GRID_H;
          w = 30 * GRID_W;
          h = 6 * GRID_H;
        };

        class MoneyText : RscText
        {
          idc = A3A_IDC_DONATIONMONEYTEXT;
          style = ST_RIGHT;
          text = "€ 0";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 113 * GRID_W;
          y = 30 * GRID_H;
          w = 30 * GRID_W;
          h = 6 * GRID_H;
        };

        class DonationLabel : RscText
        {
          idc = -1;
          style = ST_LEFT;
          text = "Donate:";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 83 * GRID_W;
          y = 40 * GRID_H;
          w = 30 * GRID_W;
          h = 6 * GRID_H;
        };

        class MoneyEditBox : ctrlEdit
        {
          idc = A3A_IDC_MONEYEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 123 * GRID_W;
          y = 40 * GRID_H;
          w = 16 * GRID_W;
          h = 6 * GRID_H;
          onKeyDown = "[""moneyEditBoxChanged""] spawn A3A_fnc_donateDialog";
        };

        class EuroLabel : RscText
        {
          idc = -1;
          style = ST_RIGHT;
          text = "€";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 139 * GRID_W;
          y = 40 * GRID_H;
          w = 4 * GRID_W;
          h = 6 * GRID_H;
        };

        class Sub1000Button : RscButtonMenu
        {
          idc = -1;
          // animTextureFocused = "#(argb,8,8,3)color(1,1,1,0)"; // Focused by KB, or after mouse click
          // animTextureOver = "#(argb,8,8,3)color(1,1,1,0)"; // Mouse over
          // animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)"; // Doesn't do shit ?
          textureNoShortcut = "GUI\textures\arrowEmpty_3L.paa";
          action = "[""add"", [-1000]] spawn A3A_fnc_donateDialog";
          x = 74 * GRID_W;
          y = 53 * GRID_H;
          w = 6 * GRID_W;
          h = 6 * GRID_H;

          class ShortcutPos
        	{
        		left = 0;
        		top = 0;
        		w = 6 * GRID_W;
        		h = 6 * GRID_H;
        	};
        };

        class Sub100Button : A3A_ShortcutButton
        {
          idc = -1;
          textureNoShortcut = "GUI\textures\arrowEmpty_2L.paa";
          action = "[""add"", [-100]] spawn A3A_fnc_donateDialog";
          x = 81 * GRID_W;
          y = 53 * GRID_H;
          w = 6 * GRID_W;
          h = 6 * GRID_H;

          class ShortcutPos
        	{
        		left = 0;
        		top = 0;
        		w = 6 * GRID_W;
        		h = 6 * GRID_H;
        	};
        };

        class MoneySlider : ctrlXSliderH
        {
          idc = A3A_IDC_MONEYSLIDER;
          color[] = {1,1,1,1};
          arrowEmpty = "GUI\textures\arrowEmpty_1L.paa";
          arrowFull = "GUI\textures\arrowFull_1L.paa";
          x = 88 * GRID_W;
          y = 53 * GRID_H;
          w = 50 * GRID_W;
          h = 6 * GRID_H;
          onSliderPosChanged = "[""moneySliderChanged""] spawn A3A_fnc_donateDialog";
        };

        class Add100Button : A3A_ShortcutButton
        {
          idc = -1;
          textureNoShortcut = "GUI\textures\arrowEmpty_2R.paa";
          action = "[""add"", [100]] spawn A3A_fnc_donateDialog";
          x = 139 * GRID_W;
          y = 53 * GRID_H;
          w = 6 * GRID_W;
          h = 6 * GRID_H;

          class ShortcutPos
        	{
        		left = 0;
        		top = 0;
        		w = 6 * GRID_W;
        		h = 6 * GRID_H;
        	};
        };

        class Add1000Button : A3A_ShortcutButton
        {
          idc = -1;
          textureNoShortcut = "GUI\textures\arrowEmpty_3R.paa";
          action = "[""add"", [1000]] spawn A3A_fnc_donateDialog";
          x = 146 * GRID_W;
          y = 53 * GRID_H;
          w = 6 * GRID_W;
          h = 6 * GRID_H;

          class ShortcutPos
        	{
        		left = 0;
        		top = 0;
        		w = 6 * GRID_W;
        		h = 6 * GRID_H;
        	};
        };

        class DonatePlayerButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEPLAYERBUTTON;
          text = "Donate to Player";
          x = 74 * GRID_W;
          y = 63 * GRID_H;
          w = 36 * GRID_W;
          h = 10 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class DonateFactionButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEFACTIONBUTTON;
          text = "Donate to Faction";
          x = 116 * GRID_W;
          y = 63 * GRID_H;
          w = 36 * GRID_W;
          h = 10 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
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

    class DonationBackground : A3A_MainBackground
    {
      x = CENTER_X(DIALOG_W) + 81 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 28 * GRID_H;
      w = 64 * GRID_W;
      h = 22 * GRID_H;
    }
  };
};
