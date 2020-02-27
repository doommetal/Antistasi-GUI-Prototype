class A3A_PlayerDialog
{
  idd = A3A_IDD_PLAYERDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls
  {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "PLAYER OPTIONS";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = CENTER_X(DIALOG_W) + PX_W(DIALOG_W) - 4 * GRID_W;
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
    };

    class Tabs : A3A_Tabs
    {
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
          action = "[] spawn A3A_fnc_constructDialog";
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
          action = "[] spawn A3A_fnc_aiManagementDialog";
          show = false;
          size = GUI_TEXT_SIZE_LARGE;
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

        class PlayerNameText : RscText
        {
          idc = A3A_IDC_PLAYERNAMETEXT;
          // text = "Player McPlayerface";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          colorBackground[] = {0,0,0,1};
          x = 70 * GRID_W;
          y = 7 * GRID_H;
          w = 90 * GRID_W;
          h = 6 * GRID_H;
        };

        class PlayerRankText : RscText
        {
          idc = A3A_IDC_PLAYERRANKTEXT;
          // text = "Major";
          colorText[] = {0.7,0.7,0.7};
          style = ST_RIGHT;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 117 * GRID_W;
          y = 8 * GRID_H;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class PlayerRankPicture : RscPicture
        {
          idc = A3A_IDC_PLAYERRANKPICTURE;
          colorBackground[] = {0,0,0,0};
          colorText[] = {0.7,0.7,0.7};
          // text = "\A3\Ui_f\data\GUI\Cfg\Ranks\major_gs.paa";
          x = 147 * GRID_W;
          y = 8 * GRID_H;
          w = 4 * GRID_W;
          h = 4 * GRID_H;
        };

        class AliveLabel : RscText
        {
          idc = -1;
          text = "Time alive:";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 98 * GRID_W;
          y = 17 * GRID_H;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class AliveText : RscText
        {
          idc = A3A_IDC_ALIVETEXT;
          style = ST_RIGHT;
          text = "";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 130 * GRID_W;
          y = 17 * GRID_H;
          w = 22 * GRID_W;
          h = 4 * GRID_H;
        };

        class MissionsLabel : RscText
        {
          idc = -1;
          text = "Missions:";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 98 * GRID_W;
          y = 22 * GRID_H;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class MissionsText : RscText
        {
          idc = A3A_IDC_MISSIONSTEXT;
          style = ST_RIGHT;
          text = "";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 130 * GRID_W;
          y = 22 * GRID_H;
          w = 22 * GRID_W;
          h = 4 * GRID_H;
        };

        class KillsLabel : RscText
        {
          idc = -1;
          text = "Kills:";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 98 * GRID_W;
          y = 27 * GRID_H;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class KillsText : RscText
        {
          idc = A3A_IDC_KILLSTEXT;
          style = ST_RIGHT;
          text = "";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 130 * GRID_W;
          y = 27 * GRID_H;
          w = 22 * GRID_W;
          h = 4 * GRID_H;
        };

        class CommanderPicture : RscPicture
        {
          idc = A3A_IDC_COMMANDERPICTURE;
          colorBackground[] = {0,0,0,0};
          colorText[] = {0,0,0,0};
          colorShadow[] = {0,0,0,1};
          shadow = 2;
          text = "\A3\Ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa";
          x = 79 * GRID_W;
          y = 16 * GRID_H;
          w = 12 * GRID_W;
          h = 12 * GRID_H;
        };

        class CommanderText : RscText
        {
          // text = "Commander";
          idc = A3A_IDC_COMMANDERTEXT;
          style = ST_CENTER;
          colorText[] = {1,0.9,0.5,1};
          colorShadow[] = {0,0,0,1};
          shadow = 2;
          x = 74 * GRID_W;
          y = 25 * GRID_H;
          w = 22 * GRID_W;
          h = 4 * GRID_H;
        }

        class CommanderButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_COMMANDERBUTTON;
          text = "Resign";
          x = 74 * GRID_W;
          y = 34 * GRID_H;
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

        class MoneyText : RscTextMulti
        {
          idc = A3A_IDC_MONEYTEXT;
          text = "Current money:\nALL THE MONEY";
          // font = "PuristaLight";
          colorBackground[] = {0,0,0,0.5};
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 98 * GRID_W;
          y = 34 * GRID_H;
          w = 30 * GRID_W;
          h = 12 * GRID_H;
        };

        class DonateButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Donate Money";
          action = "[] spawn A3A_fnc_donateDialog";
          x = 130 * GRID_W;
          y = 34 * GRID_H;
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

        class VehicleSectionLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Vehicles";
          x = 70 * GRID_W;
          y = 53 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class NoVehicleGroup : RscControlsGroupNoScrollbars
        {
          idc = A3A_IDC_NOVEHICLEGROUP;
          x = 74 * GRID_W;
          y = 64 * GRID_H;
          w = 78 * GRID_W;
          h = 36 * GRID_H;

          class controls {
            class NoVehicleText : RscText
            {
              idc = A3A_IDC_NOVEHICLETEXT;
              style = ST_CENTER;
              text = "No vehicle";
              colorText[] = {0.7,0.7,0.7,1};
              colorBackground[] = {0,0,0,0.5};
              shadow = 0;
              x = 0;
              y = 0;
              w = 78 * GRID_W;
              h = 26 * GRID_H;
            };
          };
        };

        class VehicleGroup : RscControlsGroupNoScrollbars
        {
          idc = A3A_IDC_PLAYERVEHICLEGROUP;
          x = 74 * GRID_W;
          y = 64 * GRID_H;
          w = 78 * GRID_W;
          h = 36 * GRID_H;
          show = false;

          class controls
          {
            class VehiclePicture : RscPicture
            {
              idc = A3A_IDC_VEHICLEPICTURE;
              text = "";
              colorBackground[] = {0,0,0,0};
              x = 0 * GRID_W;
              y = 0 * GRID_H;
              w = 30 * GRID_W;
              h = 17 * GRID_H;
            };

            class VehicleNameLabel : RscTextMulti
            {
              idc = A3A_IDC_VEHICLENAMELABEL;
              style = ST_MULTI + ST_CENTER;
              enabled = false;
              text = "";
              colorBackground[] = {0,0,0,0.5};
              colorShadow[] = {0,0,0,0};
              shadow = 0;
              x = 0;
              y = 17 * GRID_H;
              w = 30 * GRID_W;
              h = 9 * GRID_H;
            };

            class GarageVehicleButton : A3A_ShortcutButton
            {
              idc = A3A_IDC_GARAGEVEHICLEBUTTON;
              text = "Garage Vehicle";
              action = "[] spawn A3A_fnc_garageDialog";
              x = 32 * GRID_W;
              y = 0 * GRID_H;
              w = 22 * GRID_W;
              h = 12 * GRID_H;

              class TextPos
              {
                left = 2 * GRID_W;
                right = 2 * GRID_W;
                top = 1 * GRID_H;
                bottom = 1 * GRID_H;
              };
            };

            class UnlockVehicleButton : A3A_ShortcutButton
            {
              idc = A3A_IDC_UNLOCKVEHICLEBUTTON;
              text = "Unlock Vehicle";
              x = 32 * GRID_W;
              y = 14 * GRID_H;
              w = 22 * GRID_W;
              h = 12 * GRID_H;

              class TextPos
              {
                left = 2 * GRID_W;
                right = 2 * GRID_W;
                top = 1 * GRID_H;
                bottom = 1 * GRID_H;
              };
            };

            class SellVehicleButton : A3A_ShortcutButton
            {
              idc = A3A_IDC_SELLVEHICLEBUTTON;
              text = "Sell Vehicle";
              x = 56 * GRID_W;
              y = 0 * GRID_H;
              w = 22 * GRID_W;
              h = 12 * GRID_H;

              class TextPos
              {
                left = 2 * GRID_W;
                right = 2 * GRID_W;
                top = 1 * GRID_H;
                bottom = 1 * GRID_H;
              };
            };

            class AddToAirSuportButton : A3A_ShortcutButton
            {
              idc = A3A_IDC_ADDTOAIRSUPPORTBUTTON;
              text = "Add to Air Support";
              x = 56 * GRID_W;
              y = 14 * GRID_H;
              w = 22 * GRID_W;
              h = 12 * GRID_H;

              class TextPos
              {
                left = 2 * GRID_W;
                right = 2 * GRID_W;
                top = 1 * GRID_H;
                bottom = 1 * GRID_H;
              };
            };
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

    class RankPictureBackground : A3A_MainBackground
    {
      colorBackground[] = {0,0,0,0.5};
      x = CENTER_X(DIALOG_W) + 74 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 17 * GRID_H;
      w = 22 * GRID_W;
      h = 14 * GRID_H;
    };
  };
};
