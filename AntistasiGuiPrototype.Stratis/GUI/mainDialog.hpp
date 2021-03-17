/*
  Main Dialog - aka the Y-menu
*/

#include "ids.inc"

class A3A_MainDialog : A3A_TabbedDialog
{
  idd = A3A_IDD_MainDialog;
  onLoad = "[""onLoad""] spawn A3A_fnc_mainDialog";
  onUnload = "[""onUnload""] call A3A_fnc_mainDialog";

  class Controls
  {
    class TitlebarText : A3A_Text
    {
      idc = A3A_IDC_MainDialogTitleBar;
      text = "Main Menu";
      x = DIALOG_X;
      y = DIALOG_Y - 8 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 4 * GRID_H;
    };

    class TabButtons : A3A_ControlsGroupNoScrollbars
    {
      idc = A3A_IDC_MainDialogTabButtons;
      x = DIALOG_X;
      y = DIALOG_Y - 4 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 4 * GRID_H;

      class Controls
      {
        class PlayerTabButton : A3A_Button
        {
          idc = A3A_IDC_PlayerTabButton;
          text = "Player";
          onButtonClick = "[""switchTab"", [""player""]] call A3A_fnc_mainDialog;";
          x = 0;
          y = 0;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class CommanderTabButton : A3A_Button
        {
          idc = A3A_IDC_CommanderTabButton;
          text = "Commander";
          onButtonClick = "[""switchTab"", [""commander""]] call A3A_fnc_mainDialog;";
          x = 30 * GRID_W;
          y = 0;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class AdminTabButton : A3A_Button
        {
          idc = A3A_IDC_AdminTabButton;
          text = "Admin";
          onButtonClick = "[""switchTab"", [""admin""]] call A3A_fnc_mainDialog;";
          x = 60 * GRID_W;
          y = 0;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };
      };
    };


    ///////////////
    // MAIN TABS //
    ///////////////

    class PlayerTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_PlayerTab;
      show = false;

      class Controls
      {
        // Left side button column

        // Undercover
        class UndercoverIcon : A3A_Picture
        {
          idc = A3A_IDC_UNDERCOVERICON;
          text = A3A_Tex_Icon_Undercover;
          x = 8 * GRID_W;
          y = 13 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class UndercoverButton : A3A_Button
        {
          idc = A3A_IDC_UNDERCOVERBUTTON;
          text = "Go Undercover"; // TODO: localize
          onButtonClick = "closeDialog 2"; // TODO: undercover function
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
          y = 11 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        // Fast Travel
        class FastTravelIcon : A3A_Picture
        {
          idc = A3A_IDC_FASTTRAVELICON;
          text = A3A_Tex_Icon_FastTravel;
          x = 8 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class FastTravelButton : A3A_Button
        {
          idc = A3A_IDC_FASTTRAVELBUTTON;
          text = "Fast Travel"; // TODO: localize
          onButtonClick = "closeDialog 2"; // TODO: fasttravel function
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
          y = 32 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        // Construct
        class ConstructIcon : A3A_Picture
        {
          idc = A3A_IDC_CONSTRUCTICON;
          text = A3A_Tex_Icon_Construct;
          x = 8 * GRID_W;
          y = 55 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class ConstructButton : A3A_Button
        {
          idc = A3A_IDC_CONSTRUCTBUTTON;
          text = "Construct"; // TODO: localize
          onButtonClick = "[""switchTab"", [""construct""]] call A3A_fnc_mainDialog;";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
          y = 53 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        // AI Management
        class AIManagementIcon : A3A_Picture
        {
          idc = A3A_IDC_AIMANAGEMENTICON;
          text = A3A_Tex_Icon_AI_Management;
          x = 8 * GRID_W;
          y = 76 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AIManagementButton : A3A_Button
        {
          idc = A3A_IDC_AIMANAGEMENTBUTTON;
          text = "AI Management"; // TODO: localize
          onButtonClick = "[""switchTab"", [""aimanagement""]] call A3A_fnc_mainDialog;";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
          y = 74 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };


        // Right side content

        // Player info area
        class PlayerNameText : A3A_Text
        {
          idc = A3A_IDC_PLAYERNAMETEXT;
          text = "";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          colorBackground[] = {0,0,0,1};
          x = 70 * GRID_W;
          y = 7 * GRID_H;
          w = 90 * GRID_W;
          h = 6 * GRID_H;
        };

        class PlayerRankText : A3A_Text
        {
          idc = A3A_IDC_PLAYERRANKTEXT;
          text = "";
          colorText[] = {0.7,0.7,0.7}; // TODO: Use colors from defines.hpp
          style = ST_RIGHT;
          x = 117 * GRID_W;
          y = 8 * GRID_H;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class PlayerRankPicture : A3A_Picture
        {
          idc = A3A_IDC_PLAYERRANKPICTURE;
          colorBackground[] = {0,0,0,0};
          colorText[] = {0.7,0.7,0.7}; // TODO: Use colors from defines.hpp
          text = "";
          x = 147 * GRID_W;
          y = 8 * GRID_H;
          w = 4 * GRID_W;
          h = 4 * GRID_H;
        };

        class AliveLabel : A3A_Text
        {
          idc = -1;
          text = "Time alive:"; // TODO: localize
          x = 98 * GRID_W;
          y = 17 * GRID_H;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class AliveText : A3A_Text
        {
          idc = A3A_IDC_ALIVETEXT;
          style = ST_RIGHT;
          text = "";
          x = 130 * GRID_W;
          y = 17 * GRID_H;
          w = 22 * GRID_W;
          h = 4 * GRID_H;
        };

        class MissionsLabel : A3A_Text
        {
          idc = -1;
          text = "Missions:"; // TODO: localize
          x = 98 * GRID_W;
          y = 22 * GRID_H;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class MissionsText : A3A_Text
        {
          idc = A3A_IDC_MISSIONSTEXT;
          style = ST_RIGHT;
          text = "";
          x = 130 * GRID_W;
          y = 22 * GRID_H;
          w = 22 * GRID_W;
          h = 4 * GRID_H;
        };

        class KillsLabel : A3A_Text
        {
          idc = -1;
          text = "Kills:"; // TODO: localize
          x = 98 * GRID_W;
          y = 27 * GRID_H;
          w = 30 * GRID_W;
          h = 4 * GRID_H;
        };

        class KillsText : A3A_Text
        {
          idc = A3A_IDC_KILLSTEXT;
          style = ST_RIGHT;
          text = "";
          x = 130 * GRID_W;
          y = 27 * GRID_H;
          w = 22 * GRID_W;
          h = 4 * GRID_H;
        };

        class CommanderBackground : A3A_Background
        {
          idc = -1;
          x = 74 * GRID_W;
          y = 17 * GRID_H;
          w = 22 * GRID_W;
          h = 14 * GRID_H;
        };

        class CommanderPicture : A3A_Picture
        {
          idc = A3A_IDC_COMMANDERPICTURE;
          colorText[] = {1,0.9,0.5,1};
          colorShadow[] = {0,0,0,1};
          shadow = 2;
          text = "\A3\Ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa";
          x = 79 * GRID_W;
          y = 16 * GRID_H;
          w = 12 * GRID_W;
          h = 12 * GRID_H;
        };

        class CommanderText : A3A_Text
        {
          text = "Commander";
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

        class CommanderButton : A3A_Button
        {
          idc = A3A_IDC_COMMANDERBUTTON;
          text = "Resign";
          x = 74 * GRID_W;
          y = 34 * GRID_H;
          w = 22 * GRID_W;
          h = 12 * GRID_H;
        };

        class MoneyText : A3A_TextMulti
        {
          idc = A3A_IDC_MONEYTEXT;
          text = "Current money:\n€ 0";
          // font = "PuristaLight";
          colorBackground[] = {0,0,0,0.5};
          x = 98 * GRID_W;
          y = 34 * GRID_H;
          w = 30 * GRID_W;
          h = 12 * GRID_H;
        };

        class DonateButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_DONATEBUTTON;
          text = "Donate Money";
          onButtonClick = "[""switchTab"", [""donate""]] call A3A_fnc_mainDialog;";
          x = 130 * GRID_W;
          y = 34 * GRID_H;
          w = 22 * GRID_W;
          h = 12 * GRID_H;
        };

        // Vehicle section
        class VehicleSectionLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Vehicles"; // TODO: localize
          x = 70 * GRID_W;
          y = 53 * GRID_H;
          w = 90 * GRID_W;
          h = 4 * GRID_H;
        };

        class NoVehicleGroup : A3A_ControlsGroupNoScrollbars
        {
          idc = A3A_IDC_NOVEHICLEGROUP;
          x = 74 * GRID_W;
          y = 64 * GRID_H;
          w = 78 * GRID_W;
          h = 36 * GRID_H;

          class controls {
            class NoVehicleText : A3A_Text
            {
              idc = A3A_IDC_NOVEHICLETEXT;
              style = ST_CENTER;
              text = "No vehicle detected"; // TODO: localize
              colorText[] = {0.7,0.7,0.7,1};
              colorBackground[] = {0,0,0,0.5};
              x = 0;
              y = 0;
              w = 78 * GRID_W;
              h = 26 * GRID_H;
            };
          };
        };

        class VehicleGroup : A3A_ControlsGroupNoScrollbars
        {
          idc = A3A_IDC_PLAYERVEHICLEGROUP;
          x = 74 * GRID_W;
          y = 64 * GRID_H;
          w = 78 * GRID_W;
          h = 36 * GRID_H;

          class controls
          {
            class VehiclePicture : A3A_Picture
            {
              idc = A3A_IDC_VEHICLEPICTURE;
              x = 0 * GRID_W;
              y = 0 * GRID_H;
              w = 30 * GRID_W;
              h = 17 * GRID_H;
            };

            class VehicleNameBackground : A3A_Background
            {
              idc = -1;
              x = 0;
              y = 17 * GRID_H;
              w = 30 * GRID_W;
              h = 9 * GRID_H;
            };

            class VehicleNameLabel : A3A_TextMulti
            {
              idc = A3A_IDC_VEHICLENAMELABEL;
              style = ST_MULTI + ST_CENTER + ST_NO_RECT;
              x = 1 * GRID_W;
              // Sub-grid position works here because it's only text with transparent background:
              y = 17.5 * GRID_H;
              w = 28 * GRID_W;
              h = 8 * GRID_H;
            };

            class GarageVehicleButton : A3A_Button
            {
              idc = A3A_IDC_GARAGEVEHICLEBUTTON;
              text = "Garage";
              onButtonClick = ""; // TODO: garage this shit
              x = 32 * GRID_W;
              y = 0 * GRID_H;
              w = 22 * GRID_W;
              h = 12 * GRID_H;
            };

            class UnlockVehicleButton : A3A_Button
            {
              idc = A3A_IDC_UNLOCKVEHICLEBUTTON;
              text = "Unlock";
              x = 32 * GRID_W;
              y = 14 * GRID_H;
              w = 22 * GRID_W;
              h = 12 * GRID_H;
            };

            class SellVehicleButton : A3A_Button
            {
              idc = A3A_IDC_SELLVEHICLEBUTTON;
              text = "Sell";
              x = 56 * GRID_W;
              y = 0 * GRID_H;
              w = 22 * GRID_W;
              h = 12 * GRID_H;
            };

            class AddToAirSuportButton : A3A_ShortcutButton
            {
              idc = A3A_IDC_ADDTOAIRSUPPORTBUTTON;
              text = "Add to Air Support";
              x = 56 * GRID_W;
              y = 14 * GRID_H;
              w = 22 * GRID_W;
              h = 12 * GRID_H;
            };
          };
        };
        // End of playerTab controlsGroup content
      };
    };

    // Map misbehaves inside controlsGroups, hence this is placed outside
    // See controls.hpp for details
    class CommanderMap : A3A_MapControl
    {
      idc = A3A_IDC_COMMANDERMAP;
      onMouseButtonClick = "[""commanderMapClicked"", _this select 0 ctrlMapScreenToWorld [_this select 2, _this select 3]] call A3A_fnc_mainDialog";
      x = CENTER_X(DIALOG_W) + 68 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 8 * GRID_H;
      w = 84 * GRID_W;
      h = 84 * GRID_H;

      // Fade satellite texture a bit
      maxSatelliteAlpha = 0.75;
      alphaFadeStartScale = 3.0;
      alphaFadeEndScale = 3.0;

      // Set zoom levels
      scaleMin = 0.2; // 0.2 = Smallest scale showing the 100m grid
      scaleDefault = 0.325; // 0.325 = Largest scale forests still are visible
      scaleMax = 2; // 2 = Max zoom level
    };

    class CommanderTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_CommanderTab;
      // Width set to smaller than usual to avoid an issue where
      // pressing anything other than the map would (invisibly) cover up the
      // map control, making it unclickable
      w = 68 * GRID_W;
      show = false;

      class Controls
      {
        // Main group list
        class MultipleGroupsBackground : A3A_Background
        {
          idc = A3A_HCMULTIPLEGROUPSBACKGROUND;
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 68 * GRID_H;
        };

        class MultipleGroupsView : A3A_ControlsGroupNoHScrollbars
        {
          idc = A3A_IDC_HCMULTIPLEGROUPSVIEW;
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 58 * GRID_W;
          h = 68 * GRID_H;

          class controls {}; // Intentionally empty, controls generated by script
        };

        // Viewing a single group
        class SingleGroupView : A3A_ControlsGroupNoScrollbars
        {
          idc = A3A_IDC_HCSINGLEGROUPVIEW;
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 68 * GRID_H;

          class controls {
            class GroupNameLabel : A3A_Button_Left
            {
              idc = A3A_IDC_HCGROUPNAME;
              text = "";
              // TODO: Get rid of hardcoded IDCS here
              onButtonClick = "(findDisplay 7000 displayCtrl 7201) setVariable [""selectedGroup"", grpNull]; [""updateCommanderTab""] call A3A_fnc_mainDialog";
              x = 0;
              y = 0;
              w = 48 * GRID_W;
              h = 6 * GRID_H;
            };

            class RemoteControlHCButton : A3A_ShortcutButton
            {
              idc = -1;
              textureNoShortcut = A3A_Tex_Icon_Remotecontrol;
              tooltip = "Remote control group leader";
              onButtonClick = "hint ""Totally controlling this dude now""";
              x = 48 * GRID_W;
              y = 0 * GRID_H;
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

            class GroupBackground : A3A_Background
            {
              idc = -1;
              x = 0;
              y = 6 * GRID_H;
              w = 54 * GRID_W;
              h = 62 * GRID_H;
            };

            class IconsControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = A3A_IDC_HCGROUPSTATUSICONS;
              x = 22 * GRID_W;
              y = 8 * GRID_H;
              w = 30 * GRID_W;
              h = 6 * GRID_H;

              class controls {}; // Intentionally empty, controls generated by script
            };

            class GroupUnitCountIcon : A3A_Picture
            {
              idc = -1;
              text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa";
              tooltip = "Number of units in the group\nAble to combat / Total number of units";
              x = 2 * GRID_W;
              y = 8 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };

            class GroupUnitCountText : A3A_Text
            {
              idc = A3A_IDC_HCGROUPCOUNT;
              text = "10 / 10";
              tooltip = "Number of units in the group\nAble to combat / Total number of units";
              x = 6 * GRID_W;
              y = 8 * GRID_H;
              w = 16 * GRID_W;
              h = 4 * GRID_H;
            };

            class GroupTaskLabel : A3A_Text
            {
              idc = -1;
              text = "Current task:";
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 0;
              y = 14 * GRID_H;
              w = 24 * GRID_W;
              h = 4 * GRID_H;
            };

            class GroupTaskText : A3A_Text
            {
              idc = A3A_IDC_HCGROUPTASK;
              style = ST_RIGHT;
              text = "";
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 28 * GRID_W;
              y = 14 * GRID_H;
              w = 24 * GRID_W;
              h = 4 * GRID_H;
            };

            class GroupCombatModeLabel : A3A_Text
            {
              idc = -1;
              text = "Combat mode:";
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 0;
              y = 20 * GRID_H;
              w = 24 * GRID_W;
              h = 4 * GRID_H;
            };

            class GroupCombatModeText : A3A_Text
            {
              idc = A3A_IDC_HCGROUPCOMBATMODE;
              style = ST_RIGHT;
              text = "";
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 28 * GRID_W;
              y = 20 * GRID_H;
              w = 24 * GRID_W;
              h = 4 * GRID_H;
            };

            class FireMissionButton : A3A_ShortcutButton
            {
              idc = A3A_IDC_HCFIREMISSIONBUTTON;
              text = "Fire Mission";
              onButtonClick = "[""updateFireMissionView""] call A3A_fnc_mainDialog;";
              // onButtonClick = "findDisplay 7000 displayCtrl 7203 ctrlShow false; findDisplay 7000 displayCtrl 7210 ctrlShow true;";
              x = 28 * GRID_W;
              y = 28 * GRID_H;
              w = 24 * GRID_W;
              h = 8 * GRID_H;
            };

            class MountButton : A3A_ShortcutButton
            {
              idc = -1;
              text = "Mount / Dismount";
              x = 2 * GRID_H;
              y = 40 * GRID_H;
              w = 24 * GRID_W;
              h = 12 * GRID_H;
            };

            class AddVehicleButton : A3A_Button
            {
              idc = -1;
              text = "Add Vehicle";
              x = 2 * GRID_H;
              y = 54 * GRID_H;
              w = 24 * GRID_W;
              h = 12 * GRID_H;
            };

            class GarrisonButton : A3A_Button
            {
              idc = -1;
              text = "Garrison";
              x = 28 * GRID_W;
              y = 40 * GRID_H;
              w = 24 * GRID_W;
              h = 12 * GRID_H;
            };

            class DismissButton : A3A_Button
            {
              idc = -1;
              text = "Dismiss";
              x = 28 * GRID_W;
              y = 54 * GRID_H;
              w = 24 * GRID_W;
              h = 12 * GRID_H;
            };
          }; // End of SingleGroupView controls
        };


        // Fire mission view
        class FireMissionControlsGroup : A3A_ControlsGroupNoScrollbars
        {
          idc = A3A_IDC_FIREMISSONCONTROLSGROUP;
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 68 * GRID_H;

          class controls
          {
            // TODO: Replace placeholder values

            // Label also works as a back button
            class FireMissionLabel : A3A_Button_Left
            {
              idc = -1;
              text = "Fire mission";
              onButtonClick = "[""updateCommanderTab""] call A3A_fnc_mainDialog;";
              x = 0;
              y = 0;
              w = 54 * GRID_W;
              h = 6 * GRID_H;
            };

            class FireMissionBackground : A3A_Background
            {
              idc = -1;
              x = 0;
              y = 6 * GRID_H;
              w = 54 * GRID_W;
              h = 62 * GRID_H;
            };

            class AmmoLabel : A3A_SectionLabelRight
            {
              idc = -1;
              text = "Ammo";
              x = 2 * GRID_W;
              y = 8 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;
            };

            class HeRoundsCountLabel : A3A_Text
            {
              idc = -1;
              text = "HE:";
              colorBackground[] = A3A_COLOR_BACKGROUND;
              x = 2 * GRID_W;
              y = 13 * GRID_H;
              w = 25 * GRID_W;
              h = 4 * GRID_H;
            };

            class HeRoundsCountText : A3A_Text
            {
              idc = A3A_IDC_HEROUNDSTEXT;
              text = "32";
              colorBackground[] = A3A_COLOR_BACKGROUND;
              style = ST_RIGHT;
              x = 27 * GRID_W;
              y = 13 * GRID_H;
              w = 25 * GRID_W;
              h = 4 * GRID_H;
            };

            class SmokeRoundsCountLabel : A3A_Text
            {
              idc = -1;
              text = "Smoke:";
              colorBackground[] = A3A_COLOR_BACKGROUND;
              x = 2 * GRID_W;
              y = 18 * GRID_H;
              w = 25 * GRID_W;
              h = 4 * GRID_H;
            };

            class SmokeRoundsCountText : A3A_Text
            {
              idc = A3A_IDC_SMOKEROUNDSTEXT;
              text = "16";
              colorBackground[] = A3A_COLOR_BACKGROUND;
              style = ST_RIGHT;
              x = 27 * GRID_W;
              y = 18 * GRID_H;
              w = 25 * GRID_W;
              h = 4 * GRID_H;
            };

            class ShellTypeControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = -1;
              x = 2 * GRID_W;
              y = 27 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class ShellTypeLabel : A3A_Text
                {
                  idc = -1;
                  text = "Shell type:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class HeButton : A3A_Button
                {
                  idc = A3A_IDC_HEBUTTON;
                  text = "HE";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  onButtonClick = "[""fireMissionSelectionChanged"",[""he""]] call A3A_fnc_mainDialog;";
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 15 * GRID_W;
                  h = 4 * GRID_H;

                  // Colors are a bit different on these because we use them as radio buttons
                  // We disable them to show that they are active
                  colorDisabled[] = A3A_COLOR_BUTTON_TEXT;
                  colorBackgroundDisabled[] = A3A_COLOR_BUTTON_ACTIVE;
                };

                class SmokeButton : A3A_Button
                {
                  idc = A3A_IDC_SMOKEBUTTON;
                  text = "Smoke";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  onButtonClick = "[""fireMissionSelectionChanged"",[""smoke""]] call A3A_fnc_mainDialog;";
                  x = 35 * GRID_W;
                  y = 0 * GRID_H;
                  w = 15 * GRID_W;
                  h = 4 * GRID_H;

                  // Colors, see HE button for clarification
                  colorDisabled[] = A3A_COLOR_BUTTON_TEXT;
                  colorBackgroundDisabled[] = A3A_COLOR_BUTTON_ACTIVE;
                };
              };
            };

            class MissionTypeControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = -1;
              x = 2 * GRID_W;
              y = 32 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class MissionTypeLabel : A3A_Text
                {
                  idc = -1;
                  text = "Mission type:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class PointStrikeButton : A3A_Button
                {
                  idc = A3A_IDC_POINTSTRIKEBUTTON;
                  text = "Point";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  onButtonClick = "[""fireMissionSelectionChanged"",[""point""]] call A3A_fnc_mainDialog;";
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 15 * GRID_W;
                  h = 4 * GRID_H;

                  // Colors, see HE button for clarification
                  colorDisabled[] = A3A_COLOR_BUTTON_TEXT;
                  colorBackgroundDisabled[] = A3A_COLOR_BUTTON_ACTIVE;
                };

                class BarrageButton : A3A_Button
                {
                  idc = A3A_IDC_BARRAGEBUTTON;
                  text = "Barrage";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  onButtonClick = "[""fireMissionSelectionChanged"",[""barrage""]] call A3A_fnc_mainDialog;";
                  x = 35 * GRID_W;
                  y = 0 * GRID_H;
                  w = 15 * GRID_W;
                  h = 4 * GRID_H;

                  // Colors, see HE button for clarification
                  colorDisabled[] = A3A_COLOR_BUTTON_TEXT;
                  colorBackgroundDisabled[] = A3A_COLOR_BUTTON_ACTIVE;
                };
              };
            };


            class RoundsControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = A3A_IDC_ROUNDSCONTROLSGROUP;
              x = 2 * GRID_W;
              y = 37 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class RoundsLabel : A3A_Text
                {
                  idc = -1;
                  text = "Rounds:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class RoundsEditbox : A3A_Edit
                {
                  idc = A3A_IDC_ROUNDSEDITBOX;
                  text = "0";
                  style = ST_RIGHT + ST_NO_RECT;
                  onLoad = "_this#0 ctrlEnable false";
                  colorBackground[] = A3A_COLOR_BLACK;
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 22 * GRID_W;
                  h = 4 * GRID_H;
                };

                class AddRoundsButton : A3A_Button
                {
                  idc = A3A_IDC_ADDROUNDSBUTTON;
                  text = "+";
                  // sizeEx = GUI_TEXT_SIZE_SMALL;
                  onButtonClick = "[""fireMissionSelectionChanged"",[""addround""]] call A3A_fnc_mainDialog;";
                  x = 42 * GRID_W;
                  y = 0 * GRID_H;
                  w = 4 * GRID_W;
                  h = 4 * GRID_H;
                };

                class SubRoundsButton : A3A_Button
                {
                  idc = A3A_IDC_SUBROUNDSBUTTON;
                  text = "-";
                  // sizeEx = GUI_TEXT_SIZE_SMALL;
                  onButtonClick = "[""fireMissionSelectionChanged"",[""subround""]] call A3A_fnc_mainDialog;";
                  x = 46 * GRID_W;
                  y = 0 * GRID_H;
                  w = 4 * GRID_W;
                  h = 4 * GRID_H;
                };
              };
            };


            class StartPositionControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = A3A_IDC_STARTPOSITIONCONTROLSGROUP;
              x = 2 * GRID_W;
              y = 42 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class StartPositionLabel : A3A_Text
                {
                  idc = A3A_IDC_STARTPOSITIONLABEL;
                  text = "Position:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class StartPositionEditbox : A3A_Edit
                {
                  idc = A3A_IDC_STARTPOSITIONEDITBOX;
                  text = "039 047";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  style = ST_RIGHT + ST_NO_RECT;
                  onLoad = "_this#0 ctrlEnable false";
                  colorBackground[] = A3A_COLOR_BLACK;
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 22 * GRID_W;
                  h = 4 * GRID_H;
                };

                class SetStartPositionButton : A3A_Button
                {
                  idc = -1;
                  text = "Set";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  onButtonClick = "[""fireMissionSelectionChanged"",[""setstart""]] call A3A_fnc_mainDialog;";
                  x = 42 * GRID_W;
                  y = 0 * GRID_H;
                  w = 8 * GRID_W;
                  h = 4 * GRID_H;
                };
              };
            };


            class EndPositionControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = A3A_IDC_ENDPOSITIONCONTROLSGROUP;
              x = 2 * GRID_W;
              y = 47 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class EndPositionLabel : A3A_Text
                {
                  idc = A3A_IDC_ENDPOSITIONLABEL;
                  text = "End:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class EndPositionEditbox : A3A_Edit
                {
                  idc = A3A_IDC_ENDPOSITIONEDITBOX;
                  text = "039 047";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  style = ST_RIGHT + ST_NO_RECT;
                  onLoad = "_this#0 ctrlEnable false";
                  colorBackground[] = A3A_COLOR_BLACK;
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 22 * GRID_W;
                  h = 4 * GRID_H;
                };

                class SetEndPositionButton : A3A_Button
                {
                  idc = -1;
                  text = "Set";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  onButtonClick = "[""fireMissionSelectionChanged"",[""setend""]] call A3A_fnc_mainDialog;";
                  x = 42 * GRID_W;
                  y = 0 * GRID_H;
                  w = 8 * GRID_W;
                  h = 4 * GRID_H;
                };
              };
            };


            class FireButton : A3A_Button
            {
              idc = A3A_IDC_FIREBUTTON;
              text = "Fire";
              x = 17 * GRID_W;
              y = 56 * GRID_H;
              w = 20 * GRID_W;
              h = 8 * GRID_H;
            };


          };
        };


        // Bottom buttons

        class AirSupportButton : A3A_Button
        {
          idc = -1; // TODO: idc
          text = "Air Support";
          onButtonClick = "[""switchTab"", [""airsupport""]] call A3A_fnc_mainDialog;";
          x = 10 * GRID_W;
          y = 80 * GRID_H;
          w = 24 * GRID_W;
          h = 12 * GRID_H;
        };

        class GarbageCleanButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Garbage Clean";
          x = 36 * GRID_W;
          y = 80 * GRID_H;
          w = 24 * GRID_W;
          h = 12 * GRID_H;
        };
      };
    };

    class AdminTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_AdminTab;
      show = false;

      class Controls
      {
        class DebugSectionLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Debug info";
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 48 * GRID_W;
          h = 4 * GRID_H;
        };

        class DebugInfoPlaceholder : A3A_StructuredText
        {
          idc = A3A_IDC_DEBUGINFO;
          colorBackground[] = A3A_COLOR_BACKGROUND;
          // font = "EtelkaMonospacePro"; // Maybe this dont work with structured text?
          x = 8 * GRID_W;
          y = 12 * GRID_H;
          w = 48 * GRID_W;
          h = 44 * GRID_H;
        };

        class PlayerManagementButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_PLAYERMANAGEMENTBUTTON;
          text = "Player Management";
          onButtonClick = "[""switchTab"", [""playermanagement""]] call A3A_fnc_mainDialog;";
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

        class CivLimitLabel : A3A_Text
        {
          idc = -1;
          text = "Civ Limit";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 74 * GRID_W;
          y = 16 * GRID_H;
          w = 24 * GRID_W;
          h = 4 * GRID_H;
        };

        class CivLimitSlider : A3A_Slider
        {
          idc = A3A_IDC_CIVLIMITSLIDER;
          x = 98 * GRID_W;
          y = 16 * GRID_H;
          w = 40 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""civLimitSliderChanged""] call A3A_fnc_mainDialog";
        };

        class CivLimitEditBox : A3A_Edit
        {
          idc = A3A_IDC_CIVLIMITEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 140 * GRID_W;
          y = 16 * GRID_H;
          w = 12 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""civLimitEditBoxChanged""] call A3A_fnc_mainDialog";
        };

        class SpawnDistanceLabel : A3A_Text
        {
          idc = -1;
          text = "Spawn Distance";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 74 * GRID_W;
          y = 22 * GRID_H;
          w = 24 * GRID_W;
          h = 4 * GRID_H;
        };

        class SpawnDistanceSlider : A3A_Slider
        {
          idc = A3A_IDC_SPAWNDISTANCESLIDER;
          x = 98 * GRID_W;
          y = 22 * GRID_H;
          w = 40 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""spawnDistanceSliderChanged""] call A3A_fnc_mainDialog";
        };

        class SpawnDistanceEditBox : A3A_Edit
        {
          idc = A3A_IDC_SPAWNDISTANCEEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 140 * GRID_W;
          y = 22 * GRID_H;
          w = 12 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""spawnDistanceEditBoxChanged""] call A3A_fnc_mainDialog";
        };

        class AiLimiterLabel : A3A_Text
        {
          idc = -1;
          text = "AI Limiter";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 74 * GRID_W;
          y = 28 * GRID_H;
          w = 24 * GRID_W;
          h = 4 * GRID_H;
        };

        class AiLimiterSlider : A3A_Slider
        {
          idc = A3A_IDC_AILIMITERSLIDER;
          x = 98 * GRID_W;
          y = 28 * GRID_H;
          w = 40 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""aiLimiterSliderChanged""] call A3A_fnc_mainDialog";
        };

        class AiLimiterEditBox : A3A_Edit
        {
          idc = A3A_IDC_AILIMITEREDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          x = 140 * GRID_W;
          y = 28 * GRID_H;
          w = 12 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""aiLimiterEditBoxChanged""] call A3A_fnc_mainDialog";
        };

        class AiSectionWarningBackground : A3A_Background
        {
          idc = -1;
          x = 75 * GRID_W;
          y = 37 * GRID_H;
          w = 52 * GRID_W;
          h = 10 * GRID_H;
        };

        class AiSectionWarning : A3A_TextMulti
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
          onButtonClick = "hint ""Oh no you broke the server"";"; // TODO: Placeholder
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

        class TpPetrosButton : A3A_Button
        {
          idc = -1;
          text = "Petros";
          onButtonClick = "petros setPos getPos player;";
          x = 74 * GRID_W;
          y = 64 * GRID_H;
          w = 16 * GRID_H;
          h = 12 * GRID_H;
        };

        class TpArsenalBoxButton : A3A_Button
        {
          idc = -1;
          text = "Arsenal Box";
          onButtonClick = "boxX setPos getPos player;";
          x = 103 * GRID_W;
          y = 64 * GRID_H;
          w = 16 * GRID_H;
          h = 12 * GRID_H;
        };

        class TpVehicleBoxButton : A3A_Button
        {
          idc = -1;
          text = "Vehicle Box";
          onButtonClick = "vehicleBox setPos getPos player;";
          x = 132 * GRID_W;
          y = 64 * GRID_H;
          w = 16 * GRID_H;
          h = 12 * GRID_H;
        };

        class TpFlagButton : A3A_Button
        {
          idc = -1;
          text = "Flag";
          onButtonClick = "flagX setPos getPos player;";
          x = 74 * GRID_W;
          y = 80 * GRID_H;
          w = 16 * GRID_H;
          h = 12 * GRID_H;
        };

        class TpTentButton : A3A_Button
        {
          idc = -1;
          text = "Tent";
          onButtonClick = "fireX setPos getPos player;";
          x = 103 * GRID_W;
          y = 80 * GRID_H;
          w = 16 * GRID_H;
          h = 12 * GRID_H;
        };

        class TpMapButton : A3A_Button
        {
          idc = -1;
          text = "Map";
          onButtonClick = "mapX setPos getPos player;";
          x = 132 * GRID_W;
          y = 80 * GRID_H;
          w = 16 * GRID_H;
          h = 12 * GRID_H;
        };
      };
    };


    /////////////
    // SUBTABS //
    /////////////

    class ConstructTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_ConstructTab;
      show = false;

      class controls {

        class ConstructControlsGroup : A3A_ControlsGroupNoHScrollbars
        {
          idc = A3A_IDC_CONSTRUCTGROUP;
          x = 0;
          y = 4 * GRID_H;
          w = PX_W(DIALOG_W);
          h = PX_H(DIALOG_H) - 8 * GRID_H;
        };
      };
    };

    class AIManagementTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_AIManagementTab;
      show = false;

      class controls {

        class AiControlIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Remotecontrol;
          x = 24 * GRID_W;
          y = 24 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AiControlButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Temp. AI Control";
          x = 36 * GRID_W;
          y = 22 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class AutoLootIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Rearm;
          x = 24 * GRID_W;
          y = 46 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AutoLootButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Auto Rearm / Loot";
          x = 36 * GRID_W;
          y = 44 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class AutoHealIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Heal;
          x = 24 * GRID_W;
          y = 68 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AutoHealButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Auto Heal";
          x = 36 * GRID_W;
          y = 66 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class GarrisonIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Add_Garrison;
          x = 128 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class GarrisonButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Garrison Unit(s)";
          x = 92 * GRID_W;
          y = 32 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class DismissIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Dismiss;
          x = 128 * GRID_W;
          y = 60 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class DismissButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Dismiss Unit(s)";
          x = 92 * GRID_W;
          y = 58 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };
      };
    };

    class DonateTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_DonateTab;
      show = false;

      class controls {

        class PlayerList : A3A_Listbox
        {
          idc = A3A_IDC_DONATEPLAYERLIST;
          x = 8 * GRID_H;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 84 * GRID_H;
        };

        class MoneyLabel : A3A_Text
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

        class MoneyText : A3A_Text
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

        class DonationLabel : A3A_Text
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

        class MoneyEditBox : A3A_Edit
        {
          idc = A3A_IDC_MONEYEDITBOX;
          style = ST_RIGHT;
          text = "0";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 123 * GRID_W;
          y = 40 * GRID_H;
          w = 16 * GRID_W;
          h = 6 * GRID_H;
          onKeyDown = "[""donationEditBoxChanged""] spawn A3A_fnc_mainDialog";
        };

        class EuroLabel : A3A_Text
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

        class Sub1000Button : A3A_ShortcutButton// Was: RscButtonMenu
        {
          idc = -1;
          textureNoShortcut = A3A_Tex_ArrowEmpty_3L;
          onButtonClick = "[""donationAdd"", [-1000]] spawn A3A_fnc_mainDialog";
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
          textureNoShortcut = A3A_Tex_ArrowEmpty_2L;
          onButtonClick = "[""donationAdd"", [-100]] spawn A3A_fnc_mainDialog";
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

        class MoneySlider : A3A_Slider
        {
          idc = A3A_IDC_MONEYSLIDER;
          color[] = {1,1,1,1};
          arrowEmpty = A3A_Tex_ArrowEmpty_1L;
          arrowFull = A3A_Tex_ArrowFull_1L;
          x = 88 * GRID_W;
          y = 53 * GRID_H;
          w = 50 * GRID_W;
          h = 6 * GRID_H;
          onSliderPosChanged = "[""moneySliderChanged""] spawn A3A_fnc_mainDialog";
        };

        class Add100Button : A3A_ShortcutButton
        {
          idc = -1;
          textureNoShortcut = A3A_Tex_ArrowEmpty_2R;
          onButtonClick = "[""donationAdd"", [100]] spawn A3A_fnc_mainDialog";
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
          textureNoShortcut = A3A_Tex_ArrowEmpty_3R;
          onButtonClick = "[""donationAdd"", [1000]] spawn A3A_fnc_mainDialog";
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

        class DonatePlayerButton : A3A_Button
        {
          idc = A3A_IDC_DONATEPLAYERBUTTON;
          text = "Donate to Player";
          // TODO: Hook up to donate function
          x = 74 * GRID_W;
          y = 63 * GRID_H;
          w = 36 * GRID_W;
          h = 10 * GRID_H;
        };

        class DonateFactionButton : A3A_Button
        {
          idc = A3A_IDC_DONATEFACTIONBUTTON;
          text = "Donate to Faction";
          // TODO: Hook up to donate function
          x = 116 * GRID_W;
          y = 63 * GRID_H;
          w = 36 * GRID_W;
          h = 10 * GRID_H;
        };
      };
    };

    class AirSupportTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_AirSupportTab;
      show = false;

      class controls {
        class AirSupportText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "Remaining Air Support points: 12"; // TODO: Update in updateAirSupportTab
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 52 * GRID_W;
          y = 10 * GRID_H;
          w = 56 * GRID_W;
          h = 6 * GRID_H;
        };

        class AirSupportInfoBackground : A3A_Background
        {
          idc = -1;
          x = 38 * GRID_W;
          y = 18 * GRID_H;
          w = 84 * GRID_W;
          h = 28 * GRID_H;
        };

        class AirSupportInfoText : A3A_TextMulti
        {
          idc = -1;
          // TODO: Localize:
          text = "Aircraft used: Antonov An-2\n\nAdd aircraft to the air support pool by using the thing in the other menu and things.\nMore lines.";
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          colorText[] = {0.7,0.7,0.7,1}; // TODO: Use colors from defines
          x = 40 * GRID_W;
          y = 20 * GRID_H;
          w = 80 * GRID_W;
          h = 24 * GRID_H;
        };

        class HeBombsIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_he_bombs.paa";
          x = 24 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class HeBombsButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "HE Bombs";
          size = GUI_TEXT_SIZE_MEDIUM;
          x = 16 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class CarpetBombingIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_carpet_bombing.paa";
          x = 72 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class CarpetBombingButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Carpet Bombing";
          size = GUI_TEXT_SIZE_MEDIUM;
          x = 64 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class NapalmBombIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = "GUI\textures\icon_napalm_bomb.paa";
          x = 120 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class NapalmBombButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Napalm Bomb";
          size = GUI_TEXT_SIZE_MEDIUM;
          x = 112 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };
      };
    };

    class PlayerManagementTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_PlayerManagementTab;
      show = false;

      class controls {

        class PlayerListBackground : A3A_Background
        {
          idc = -1;
          x = 8 * GRID_W;
          y = 12 * GRID_H;
          w = 106 * GRID_W;
          h = 82 * GRID_H;
        };

        class NameLabel : A3A_Text
        {
          text = "Name";
          x = 9 * GRID_W;
          y = 8 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class DistanceLabel : A3A_Text
        {
          text = "Distance";
          x = 71 * GRID_W;
          y = 8 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class UIDLabel : A3A_Text
        {
          text = "PlayerUID";
          x = 85 * GRID_W;
          y = 8 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class PlayerList : A3A_ListNBox
        {
          idc = A3A_IDC_ADMINPLAYERLIST;
          x = 8 * GRID_W;
          y = 12 * GRID_H;
          w = 106 * GRID_W;
          h = 82 * GRID_H;
          onLBSelChanged = "[""playerLbSelectionChanged""] spawn A3A_fnc_maindialog";

          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          rowHeight = 4 * GRID_H;
          columns[] = {0,0.59,0.725};
        };

        class AddMemberButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_ADDMEMBERBUTTON;
          text = "Add Member";
          onButtonClick = "[""adminAddMember""] spawn A3A_fnc_maindialog";
          show = false;
          x = 120 * GRID_W;
          y = 7 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class RemoveMemberButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_REMOVEMEMBERBUTTON;
          text = "Remove Member";
          onButtonClick = "[""adminRemoveMember""] spawn A3A_fnc_maindialog";
          show = false;
          x = 120 * GRID_W;
          y = 7 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class TeleportToPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Teleport to Player";
          x = 120 * GRID_W;
          y = 22 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class TeleportPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Teleport Player to Me";
          x = 120 * GRID_W;
          y = 37 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class KickPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Kick Player";
          x = 120 * GRID_W;
          y = 52 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class BanPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Ban Player";
          x = 120 * GRID_W;
          y = 67 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class CopyIdButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Copy UID to Clipboard";
          x = 120 * GRID_W;
          y = 82 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };
      };
    };


    // Close and Back buttons
    class BackButton : A3A_BackButton
    {
      idc = A3A_IDC_MainDialogBackButton;
      x = DIALOG_X + DIALOG_W * GRID_W - 10 * GRID_W;
      y = DIALOG_Y - 8 * GRID_H;
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = DIALOG_X + DIALOG_W * GRID_W - 4 * GRID_W;
      y = DIALOG_Y - 8 * GRID_H;
    };
  };
};
