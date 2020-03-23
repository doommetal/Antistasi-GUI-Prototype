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
        class RiflemanIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          colorText[]= {0.7,0.7,0.7,1};
          text = "GUI\textures\icon_none.paa";
          x = 24 * GRID_W;
          y = 13 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class RiflemanPriceText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          shadow = 2;
          x = 24 * GRID_W;
          y = 19 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class RiflemanButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Rifleman";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 11 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class AutoriflemanIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          colorText[]= {0.7,0.7,0.7,1};
          text = "GUI\textures\icon_none.paa";
          x = 24 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AutoriflemanPriceText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          shadow = 2;
          x = 24 * GRID_W;
          y = 40 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class AutoriflemanButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Autorifleman";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 32 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class GrenadierIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          colorText[]= {0.7,0.7,0.7,1};
          text = "GUI\textures\icon_none.paa";
          x = 24 * GRID_W;
          y = 55 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class GrenadierPriceText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          shadow = 2;
          x = 24 * GRID_W;
          y = 61 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class GrenadierButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Grenadier";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 53 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class AtIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          colorText[]= {0.7,0.7,0.7,1};
          text = "GUI\textures\icon_none.paa";
          x = 24 * GRID_W;
          y = 76 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AtPriceText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          shadow = 2;
          x = 24 * GRID_W;
          y = 82 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class AtButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AT";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 74 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class MedicIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          colorText[]= {0.7,0.7,0.7,1};
          text = "GUI\textures\icon_none.paa";
          x = 128 * GRID_W;
          y = 13 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class MedicPriceText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          shadow = 2;
          x = 128 * GRID_W;
          y = 19 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class MedicButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Medic";
          size = GUI_TEXT_SIZE_LARGE;
          x = 88 * GRID_W;
          y = 11 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class MarksmanIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          colorText[]= {0.7,0.7,0.7,1};
          text = "GUI\textures\icon_none.paa";
          x = 128 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class MarksmanPriceText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          shadow = 2;
          x = 128 * GRID_W;
          y = 40 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class MarksmanButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Marksman";
          size = GUI_TEXT_SIZE_LARGE;
          x = 88 * GRID_W;
          y = 32 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class EngineerIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          colorText[]= {0.7,0.7,0.7,1};
          text = "GUI\textures\icon_none.paa";
          x = 128 * GRID_W;
          y = 55 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class EngineerPriceText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          shadow = 2;
          x = 128 * GRID_W;
          y = 61 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class EngineerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Engineer";
          size = GUI_TEXT_SIZE_LARGE;
          x = 88 * GRID_W;
          y = 53 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class BombSpecialistIcon : RscPicture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          colorText[]= {0.7,0.7,0.7,1};
          text = "GUI\textures\icon_none.paa";
          x = 128 * GRID_W;
          y = 76 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class BombSpecialistPriceText : RscText
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          shadow = 2;
          x = 128 * GRID_W;
          y = 82 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class BombSpecialistButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Bomb Specialist";
          size = GUI_TEXT_SIZE_LARGE;
          x = 88 * GRID_W;
          y = 74 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;

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
