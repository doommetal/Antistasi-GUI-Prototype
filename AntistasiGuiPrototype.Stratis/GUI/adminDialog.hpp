class A3A_AdminDialog
{
  idd = A3A_IDD_ADMINDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "ADMIN OPTIONS";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
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
        class DebugInfoPlaceholder : A3A_ShortcutButton
        {
          idc = -1;
          text = "Debug info placeholder";
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 48 * GRID_W;
          h = 48 * GRID_H;
        };

        class PlayerManagementButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_PLAYERMANAGEMENTBUTTON;
          text = "Player Management";
          action = "[] spawn A3A_fnc_playerManagementDialog";
          x = 8 * GRID_W;
          y = 64 * GRID_H;
          w = 48 * GRID_W;
          h = 12 * GRID_H;
          size = GUI_TEXT_SIZE_LARGE;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_H;
            top = 3 * GRID_W;
            bottom = 3 * GRID_H;
          };
        };

        class ResetHqButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_RESETHQBUTTON;
          text = "RESET HQ";
          x = 8 * GRID_W;
          y = 80 * GRID_H;
          w = 48 * GRID_W;
          h = 12 * GRID_H;
          size = GUI_TEXT_SIZE_LARGE;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_H;
            top = 3 * GRID_W;
            bottom = 3 * GRID_H;
          };
        };

        class AiSectionLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "AI Options";
          x = 70 * GRID_W;
          y = 8 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class CivLimitLabel : RscText
        {
          idc = -1;
          text = "Civ Limit";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 74 * GRID_W;
          y = 16 * GRID_H;
          w = 24 * GRID_W;
          h = 4 * GRID_H;
        };

        class CivLimitSlider : ctrlXSliderH
        {
          idc = A3A_IDC_CIVLIMITSLIDER;
          x = 98 * GRID_W;
          y = 16 * GRID_H;
          w = 40 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""civLimitSliderChanged""] spawn A3A_fnc_adminDialog";
        };

        class CivLimitEditBox : ctrlEdit
        {
          idc = A3A_IDC_CIVLIMITEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 140 * GRID_W;
          y = 16 * GRID_H;
          w = 12 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""civLimitEditBoxChanged""] spawn A3A_fnc_adminDialog";
        };

        class SpawnDistanceLabel : RscText
        {
          idc = -1;
          text = "Spawn Distance";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 74 * GRID_W;
          y = 22 * GRID_H;
          w = 24 * GRID_W;
          h = 4 * GRID_H;
        };

        class SpawnDistanceSlider : ctrlXSliderH
        {
          idc = A3A_IDC_SPAWNDISTANCESLIDER;
          x = 98 * GRID_W;
          y = 22 * GRID_H;
          w = 40 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""spawnDistanceSliderChanged""] spawn A3A_fnc_adminDialog";
        };

        class SpawnDistanceEditBox : ctrlEdit
        {
          idc = A3A_IDC_SPAWNDISTANCEEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 140 * GRID_W;
          y = 22 * GRID_H;
          w = 12 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""spawnDistanceEditBoxChanged""] spawn A3A_fnc_adminDialog";
        };

        class AiLimiterLabel : RscText
        {
          idc = -1;
          text = "AI Limiter";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 74 * GRID_W;
          y = 28 * GRID_H;
          w = 24 * GRID_W;
          h = 4 * GRID_H;
        };

        class AiLimiterSlider : ctrlXSliderH
        {
          idc = A3A_IDC_AILIMITERSLIDER;
          x = 98 * GRID_W;
          y = 28 * GRID_H;
          w = 40 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""aiLimiterSliderChanged""] spawn A3A_fnc_adminDialog";
        };

        class AiLimiterEditBox : ctrlEdit
        {
          idc = A3A_IDC_AILIMITEREDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 140 * GRID_W;
          y = 28 * GRID_H;
          w = 12 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""aiLimiterEditBoxChanged""] spawn A3A_fnc_adminDialog";
        };

        class AiSectionWarning : RscTextMulti
        {
          idc = -1;
          style = "0x02 + 0x10 + 0x0200"; // ST_CENTER + ST_MULTI
          text = "BE CAREFUL WHEN EDITING THESE SETTINGS. SETTING THEM TOO HIGH *WILL* BREAK THE GAME.";
          sizeEx = GUI_TEXT_SIZE_SMALL;
          font = "PuristaLight";
          shadow = 2;
          x = 75 * GRID_W;
          y = 37 * GRID_H;
          w = 52 * GRID_W;
          h = 10 * GRID_H;
        };

        class CommitAiButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_COMMITAIBUTTON;
          text = "Commit Changes";
          x = 132 * GRID_W;
          y = 36 * GRID_H;
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

        class TpSectionLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Teleport HQ assets to your position";
          x = 70 * GRID_W;
          y = 56 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class TpPetrosButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Petros";
          action = "petros setPos getPos player;";
          x = 74 * GRID_W;
          y = 64 * GRID_H;
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

        class TpArsenalBoxButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Arsenal Box";
          action = "boxX setPos getPos player;";
          x = 103 * GRID_W;
          y = 64 * GRID_H;
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

        class TpVehicleBoxButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Vehicle Box";
          action = "vehicleBox setPos getPos player;";
          x = 132 * GRID_W;
          y = 64 * GRID_H;
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

        class TpFlagButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Flag";
          action = "flagX setPos getPos player;";
          x = 74 * GRID_W;
          y = 80 * GRID_H;
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

        class TpTentButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Tent";
          action = "fireX setPos getPos player;";
          x = 103 * GRID_W;
          y = 80 * GRID_H;
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

        class TpMapButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Map";
          action = "mapX setPos getPos player;";
          x = 132 * GRID_W;
          y = 80 * GRID_H;
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
      };
    };
    
    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = CENTER_X(DIALOG_W) + PX_W(DIALOG_W) - 4 * GRID_W;
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
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

    class AiSectionWarningBackground : A3A_MainBackground
    {
      colorBackground[] = {0,0,0,0.5};
      x = CENTER_X(DIALOG_W) + 74 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 36 * GRID_H;
      w = 54 * GRID_W;
      h = 12 * GRID_H;
    };
  };
};
