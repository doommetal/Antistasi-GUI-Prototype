class A3A_RecruitSquadDialog
{
  idd = A3A_IDD_RECRUITSQUADDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "RECRUIT SQUADS";
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
        class InfSquadIcon : RscPicture
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

        class InfSquadPriceText : RscText
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

        class InfSquadButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Inf. Squad";
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

        class InfTeamIcon : RscPicture
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

        class InfTeamPriceText : RscText
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

        class InfTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Inf. Team";
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

        class MgTeamIcon : RscPicture
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

        class MgTeamPriceText : RscText
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

        class MgTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "MG Team";
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

        class AtTeamIcon : RscPicture
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

        class AtTeamPriceText : RscText
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

        class AtTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AT Team";
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

        class MortarTeamIcon : RscPicture
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

        class MortarTeamPriceText : RscText
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

        class MortarTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Mortar Team";
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

        class SniperTeamIcon : RscPicture
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

        class SniperTeamPriceText : RscText
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

        class SniperTeamButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Sniper Team";
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

        class AtCarIcon : RscPicture
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

        class AtCarPriceText : RscText
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

        class AtCarButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AT Car";
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

        class AaTruckIcon : RscPicture
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

        class AaTruckPriceText : RscText
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

        class AaTruckButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AA Truck";
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

    class BackButton : A3A_BackButton
    {
      idc = -1;
      action = "[] spawn A3A_fnc_hqDialog";
      x = CENTER_X(DIALOG_W) + PX_W(DIALOG_W) - 9 * GRID_W;
      y = CENTER_Y(DIALOG_H) - 4 * GRID_H;
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
