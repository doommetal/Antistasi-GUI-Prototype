class A3A_PlayerDialog
{
  idd = A3A_IDD_PLAYERDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "PLAYER OPTIONS";
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
      idc = A3A_IDC_PLAYERMAINCONTENT;
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H);
      w = PX_W(DIALOG_W);
      h = PX_H(DIALOG_H);

      class controls
      {
        class UndercoverIcon : RscPicture
        {
          idc = A3A_IDC_UNDERCOVERICON;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_hide.paa";
          x = 8 * GRID_W;
          y = 13 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class UndercoverButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_UNDERCOVERBUTTON;
          text = "Undercover ON";
          action = "closeDialog 2";
          show = false; // Starts hidden to fix z-level for error text
          size = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
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

        class UndercoverErrorLabel : RscText
        {
          idc = A3A_IDC_UNDERCOVERERROR;
          text = "! Illegal gear visible";
          show = false;
          colorText[] = COLOR_ERROR_TEXT;
          sizeEx = GUI_TEXT_SIZE_SMALL;
          x = 21 * GRID_W;
          y = 19 * GRID_H;
          w = 34 * GRID_W;
          h = 3 * GRID_H;
        };

        class FastTravelIcon : RscPicture
        {
          idc = A3A_IDC_FASTTRAVELICON;
          colorBackground[] = {0,0,0,0};
          text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\run_ca.paa";
          x = 8 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class FastTravelButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_FASTTRAVELBUTTON;
          text = "Fast Travel";
          action = "closeDialog 2";
          show = false;
          size = GUI_TEXT_SIZE_LARGE;
          // sizeEx = GUI_TEXT_SIZE_LARGE;
          // sizeExSecondary = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
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

        class FastTravelErrorLabel : RscText
        {
          idc = A3A_IDC_FASTTRAVELERROR;
          text = "! Too close to enemies";
          show = false;
          colorText[] = COLOR_ERROR_TEXT;
          sizeEx = GUI_TEXT_SIZE_SMALL;
          x = 21 * GRID_W;
          y = 40 * GRID_H;
          w = 34 * GRID_W;
          h = 3 * GRID_H;
        };

        class ConstructIcon : RscPicture
        {
          idc = A3A_IDC_CONSTRUCTICON;
          colorBackground[] = {0,0,0,0};
          text = "\A3\ui_f\data\igui\cfg\cursors\iconRepairVehicle_ca.paa";
          x = 8 * GRID_W;
          y = 55 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class ConstructButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_CONSTRUCTBUTTON;
          text = "Construct";
          action = "closeDialog 2";
          show = false;
          size = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
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

        class ConstructErrorLabel : RscText
        {
          idc = A3A_IDC_CONSTRUCTERROR;
          text = "! No engineer in squad";
          show = false;
          colorText[] = COLOR_ERROR_TEXT;
          sizeEx = GUI_TEXT_SIZE_SMALL;
          x = 21 * GRID_W;
          y = 61 * GRID_H;
          w = 34 * GRID_W;
          h = 3 * GRID_H;
        };

        class AIManagementIcon : RscPicture
        {
          idc = A3A_IDC_AIMANAGEMENTICON;
          colorBackground[] = {0,0,0,0};
          text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa";
          // text = "\A3\Ui_f\data\IGUI\Cfg\Actions\talk_ca.paa";
          x = 8 * GRID_W;
          y = 76 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AIManagementButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_AIMANAGEMENTBUTTON;
          text = "AI Management";
          action = "closeDialog 2";
          show = false;
          size = GUI_TEXT_SIZE_LARGE;
          // sizeEx = GUI_TEXT_SIZE_LARGE;
          // sizeExSecondary = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
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

        class AIManagementErrorLabel : RscText
        {
          idc = A3A_IDC_AIMANAGEMENTERROR;
          text = "! No AI in squad";
          show = false;
          colorText[] = COLOR_ERROR_TEXT;
          sizeEx = GUI_TEXT_SIZE_SMALL;
          x = 21 * GRID_W;
          y = 82 * GRID_H;
          w = 34 * GRID_W;
          h = 3 * GRID_H;
        };

        class MoneySectionLabel : SectionLabelRight
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
          onSliderPosChanged = "[""moneySliderChanged""] spawn A3A_fnc_playerDialog";
        };

        class MoneyEditBox : ctrlEdit
        {
          idc = A3A_IDC_MONEYEDITBOX;
          style = ST_RIGHT;
          text = 0;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 136 * GRID_W;
          y = 23 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""moneyEditBoxChanged""] spawn A3A_fnc_playerDialog";
        };

        class DonateFactionButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEFACTIONBUTTON;
          text = "Donate to faction";
          x = 108 * GRID_W;
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

        class DonatePlayerButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEPLAYERBUTTON;
          text = "Donate to player";
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

        class VehicleSectionLabel : SectionLabelRight
        {
          idc = -1;
          text = "Vehicles";
          x = 70 * GRID_W;
          y = 53 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class VehicleInfoPlaceholder : A3A_ShortcutButton
        {
          idc = -1;
          text = "Vehicle Info Placeholder";
          x = 74 * GRID_W;
          y = 64 * GRID_H;
          w = 22 * GRID_H;
          h = 22 * GRID_H;
        };

        class GarageVehicleButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEFACTIONBUTTON;
          text = "Garage Vehicle";
          x = 108 * GRID_W;
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

        class UnlockVehicleButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEPLAYERBUTTON;
          text = "Unlock Vehicle";
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
    }
  };
};
