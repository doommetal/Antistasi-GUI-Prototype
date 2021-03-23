class A3A_HqDialog : A3A_DefaultDialog
{
  idd = A3A_IDD_HqDialog;
  onLoad = "[""onLoad""] spawn A3A_fnc_hqDialog";

  class Controls
  {
    class TitlebarText : A3A_Text
    {
      idc = A3A_IDC_HQDIALOGTITLEBAR;
      text = "HQ Management";
      x = DIALOG_X;
      y = DIALOG_Y - 4 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 4 * GRID_H;
    };

    // Main content
    class MainTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_HQDIALOGMAINTAB;

      class controls
      {
        // Left side buttons

        class GarrisonsIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Garrison;
          x = 8 * GRID_W;
          y = 13 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class GarrisonManagementButton : A3A_Button
        {
          idc = -1;
          text = "Garrisons";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          onButtonClick = "[""switchTab"",[""garrison""]] call A3A_fnc_hqDialog";
          x = 20 * GRID_W;
          y = 11 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class MinefieldsIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Minefield;
          x = 8 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class MinefieldsButton : A3A_Button
        {
          idc = -1;
          text = "Minefields";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          onButtonClick = "[""switchTab"",[""minefields""]] call A3A_fnc_hqDialog";
          x = 20 * GRID_W;
          y = 32 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class MoveHqIcon : A3A_Picture
        {
          idc = A3A_IDC_MOVEHQICON;
          text = A3A_Tex_Icon_Move_HQ;
          x = 8 * GRID_W;
          y = 55 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class MoveHqButton : A3A_Button
        {
          idc = A3A_IDC_MOVEHQBUTTON;
          text = "Move HQ";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
          y = 53 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class ClearTreesIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Clear_Trees;
          x = 8 * GRID_W;
          y = 76 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class ClearTreesButton : A3A_Button
        {
          idc = -1;
          text = "Clear Trees";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 20 * GRID_W;
          y = 74 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        // Campaign status section
        class CampaignStatusControlsGroup : A3A_ControlsGroupNoScrollbars
        {
          idc = -1;
          x = 70 * GRID_W;
          y = 7 * GRID_H;
          w = 90 * GRID_W;
          h = 23 * GRID_H;

          class controls
          {
            class CampaignStatusLabel : A3A_SectionLabelRight
            {
              idc = -1;
              text = "Campaign status";
              x = 0 * GRID_W;
              y = 0 * GRID_H;
              w = 90 * GRID_W;
              h = 4 * GRID_H;
            };

            class WarLevelLabel : A3A_Text
            {
              idc = -1;
              text = "War level:";
              x = 0 * GRID_W;
              y = 6 * GRID_H;
              w = 14 * GRID_W;
              h = 4 * GRID_H;
            };

            class WarLevelText : A3A_Text
            {
              idc = A3A_IDC_WARLEVELTEXT;
              style = ST_RIGHT;
              text = "5";
              x = 14 * GRID_W;
              y = 6 * GRID_H;
              w = 14 * GRID_W;
              h = 4 * GRID_H;
            };

            class AggressionLabel : A3A_Text
            {
              idc = -1;
              text = "Aggression:";
              x = 0 * GRID_W;
              y = 11 * GRID_H;
              w = 28 * GRID_W;
              h = 4 * GRID_H;
            };

            class OccFlagPicture : A3A_Picture
            {
              idc = A3A_IDC_OCCFLAGPICTURE;
              text = "\A3\Data_F\Flags\flag_nato_co.paa"; // TODO: Replace with actual faction flag
              tooltip = "Occupants aggression"; // TODO: Update with faction name
              x = 1 * GRID_W;
              y = 16 * GRID_H;
              w = 12 * GRID_W;
              h = 6 * GRID_H;
            };

            class OccAggroText : A3A_Text
            {
              idc = A3A_IDC_OCCAGGROTEXT;
              style = ST_CENTER;
              text = "MEDIUM";
              tooltip = "Occupants aggression"; // TODO: Update with faction name
              colorBackground[] = A3A_COLOR_BACKGROUND;
              shadow = 2;
              x = 1 * GRID_W;
              y = 16 * GRID_H;
              w = 12 * GRID_W;
              h = 6 * GRID_H;
            };

            class InvFlagPicture : A3A_Picture
            {
              idc = A3A_IDC_INVFLAGPICTURE;
              text = "\A3\Data_F\Flags\flag_CSAT_co.paa"; // TODO: Replace with actual faction flag
              tooltip = "Invader aggression"; // TODO: Update with faction name
              x = 16 * GRID_W;
              y = 16 * GRID_H;
              w = 12 * GRID_W;
              h = 6 * GRID_H;
            };

            class InvAggroText : A3A_Text
            {
              idc = A3A_IDC_INVAGGROTEXT;
              style = ST_CENTER;
              text = "HIGH";
              tooltip = "Invader aggression"; // TODO: Update with faction name
              colorBackground[] = A3A_COLOR_BACKGROUND;
              shadow = 2;
              x = 16 * GRID_W;
              y = 16 * GRID_H;
              w = 12 * GRID_W;
              h = 6 * GRID_H;
            };


            // Controlled sites

            class ControlledCitiesIcon : A3A_Picture
            {
              idc = A3A_IDC_CONTROLLEDCITIESICON;
              text = A3A_Tex_Icon_Town;
              tooltip = "Controlled cities";
              x = 32 * GRID_W;
              y = 6 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledCitiesText : A3A_Text
            {
              idc = A3A_IDC_CONTROLLEDCITIESTEXT;
              text = "3/48";
              tooltip = "Controlled cities";
              x = 36 * GRID_W;
              y = 6 * GRID_H;
              w = 12 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledOutpostsIcon : A3A_Picture
            {
              idc = A3A_IDC_CONTROLLEDOUTPOSTSICON;
              text = A3A_Tex_Icon_Outpost;
              tooltip = "Controlled outposts";
              x = 49 * GRID_W;
              y = 6 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledOutpostsText : A3A_Text
            {
              idc = A3A_IDC_CONTROLLEDOUTPOSTSTEXT;
              text = "15/44";
              tooltip = "Controlled outposts";
              x = 53 * GRID_W;
              y = 6 * GRID_H;
              w = 12 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledAirBasesIcon : A3A_Picture
            {
              idc = A3A_IDC_CONTROLLEDAIRBASESICON;
              text = A3A_Tex_Icon_Airbase;
              tooltip = "Controlled airbases";
              x = 66 * GRID_W;
              y = 6 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledAirBasesText : A3A_Text
            {
              idc = A3A_IDC_CONTROLLEDAIRBASESTEXT;
              text = "0/6";
              tooltip = "Controlled airbases";
              x = 70 * GRID_W;
              y = 6 * GRID_H;
              w = 12 * GRID_W;
              h = 4 * GRID_H;
            };

            ////////////////////////////

            class ControlledResourcesIcon : A3A_Picture
            {
              idc = A3A_IDC_CONTROLLEDRESOURCESICON;
              text = A3A_Tex_Icon_Resource;
              tooltip = "Controlled resources";
              x = 32 * GRID_W;
              y = 11 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledResourcesText : A3A_Text
            {
              idc = A3A_IDC_CONTROLLEDRESOURCESTEXT;
              text = "1/8";
              tooltip = "Controlled resources";
              x = 36 * GRID_W;
              y = 11 * GRID_H;
              w = 12 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledFactoriesIcon : A3A_Picture
            {
              idc = A3A_IDC_CONTROLLEDFACTORIESICON;
              text = A3A_Tex_Icon_Factory;
              tooltip = "Controlled factories";
              x = 49 * GRID_W;
              y = 11 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledFactoriesText : A3A_Text
            {
              idc = A3A_IDC_CONTROLLEDFACTORIESTEXT;
              text = "2/12";
              tooltip = "Controlled factories";
              x = 53 * GRID_W;
              y = 11 * GRID_H;
              w = 12 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledPortsIcon : A3A_Picture
            {
              idc = A3A_IDC_CONTROLLEDPORTSICON;
              text = A3A_Tex_Icon_Seaport;
              tooltip = "Controlled ports";
              x = 66 * GRID_W;
              y = 11 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };

            class ControlledPortsText : A3A_Text
            {
              idc = A3A_IDC_CONTROLLEDPORTSTEXT;
              text = "1/5";
              tooltip = "Controlled ports";
              x = 70 * GRID_W;
              y = 11 * GRID_H;
              w = 12 * GRID_W;
              h = 4 * GRID_H;
            };

            // Stupid hack frame because armas normal frames gets off by 1 pixel errors
            class PopStatusBarFrame : A3A_Background
            {
              idc = -1;
              colorBackground[]= A3A_COLOR_BLACK;
              x = 31 * GRID_W - 1 * pixelW;
              y = 16 * GRID_H - 1 * pixelH;
              w = 50 * GRID_W + 2 * pixelW;
              h = 6 * GRID_H + 2 * pixelH;
            };

            class PopStatusBarControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = -1;
              x = 31 * GRID_W;
              y = 16 * GRID_H;
              w = 50 * GRID_W;
              h = 6 * GRID_H;

              class controls
              {
                class PopStatusBarBackground : A3A_Background
                {
                  idc = -1;
                  colorBackground[] = {0.3,0.3,0.3,1}; // TODO: Hardcoded color
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 50 * GRID_W;
                  h = 6 * GRID_H;
                };

                class PopStatusBarReb : A3A_Picture
                {
                  idc = A3A_IDC_POPSTATUSBARREB;
                  text = "#(argb,1,1,1)color(0.9,0.9,0.9,1)";
                  tooltip = "Popular support\nYou need 50% to win";
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 16 * GRID_W;
                  h = 6 * GRID_H;
                };

                class PopStatusBarDead : A3A_Picture
                {
                  idc = A3A_IDC_POPSTATUSBARDEAD;
                  text = "#(argb,1,1,1)color(0.15,0.15,0.15,1)";
                  tooltip = "Dead population\nYou lose when this hits 33%";
                  x = 48 * GRID_W;
                  y = 0 * GRID_H;
                  w = 2 * GRID_W;
                  h = 6 * GRID_H;
                };

                // Line for win condition
                class WinLine : A3A_Text
                {
                  idc = -1;
                	style = ST_MULTI + ST_TITLE_BAR + ST_HUD_BACKGROUND;
                  text = "";
                  colorText[] = {0,0,0,1};
                  colorBackground[] = A3A_COLOR_TRANSPARENT;
                	x = 25 * GRID_W;
                	y = 0;
                	w = 0;
                	h = 6 * GRID_H;
                };

                class LoseLine : A3A_Text
                {
                  idc = -1;
                	style = ST_MULTI + ST_TITLE_BAR + ST_HUD_BACKGROUND;
                  text = "";
                  colorText[] = {0,0,0,1};
                  colorBackground[] = A3A_COLOR_TRANSPARENT;
                	x = 33.33333 * GRID_W;
                	y = 0;
                	w = 0;
                	h = 6 * GRID_H;
                };

                class PopStatusRebText : A3A_Text
                {
                  idc = A3A_IDC_POPSTATUSREBTEXT;
                  text = ""; // Updated from script
                  tooltip = "Popular support\nYou need 50% to win";
                  colorShadow[] = {0,0,0,0.5};
                  shadow = 2;
                  x = 0 * GRID_W;
                  y = 1 * GRID_H;
                  w = 10 * GRID_W;
                  h = 4 * GRID_H;
                };

                class PopStatusDeadText : A3A_Text
                {
                  idc = A3A_IDC_POPSTATUSDEADTEXT;
                  style = ST_RIGHT;
                  text = ""; // Updated from script
                  tooltip = "Dead population\nYou lose when this hits 33%";
                  colorShadow[] = {0,0,0,0.5};
                  shadow = 2;
                  x = 40 * GRID_W;
                  y = 1 * GRID_H;
                  w = 10 * GRID_W;
                  h = 4 * GRID_H;
                };

              };
            };

          };
        };


        // Faction resources section

        class FactionResourcesControlsGroup : A3A_ControlsGroupNoScrollbars
        {
          idc = -1;
          x = 70 * GRID_W;
          y = 33 * GRID_H;
          w = 90 * GRID_W;
          h = 28 * GRID_H;

          class controls
          {
            class FactionResourcesLabel : A3A_SectionLabelRight
            {
              idc = -1;
              text = "Faction Resources";
              x = 0 * GRID_W;
              y = 0 * GRID_H;
              w = 90 * GRID_W;
              h = 4 * GRID_H;
            };

            /* class FactionHRBackground : A3A_Background
            {
              idc = -1;
              x = 0 * GRID_W;
              y = 7 * GRID_H;
              w = 60 * GRID_W;
              h = 9 * GRID_H;
            }; */

            class FactionHRLabel : A3A_Text
            {
              idc = -1;
              text = "HR:";
              x = 0 * GRID_W;
              y = 7 * GRID_H;
              w = 39 * GRID_W;
              h = 4 * GRID_H;
            };

            class FactionHRText : A3A_Text
            {
              idc = A3A_IDC_FACTIONHRTEXT;
              style = ST_RIGHT;
              text = "0";
              x = 41 * GRID_W;
              y = 7 * GRID_H;
              w = 16 * GRID_W;
              h = 4 * GRID_H;
            };

            class FactionTrainingLabel : A3A_Text
            {
              idc = -1;
              text = "Training level:";
              x = 0 * GRID_W;
              y = 12 * GRID_H;
              w = 39 * GRID_W;
              h = 4 * GRID_H;
            };

            class FactionTrainingText : A3A_Text
            {
              idc = A3A_IDC_FACTIONTRAININGTEXT;
              style = ST_RIGHT;
              text = "0 / 20";
              x = 41 * GRID_W;
              y = 12 * GRID_H;
              w = 16 * GRID_W;
              h = 4 * GRID_H;
            };

            class TrainTroopsButton : A3A_Button
            {
              idc = -1;
              text = "Train";
              x = 60 * GRID_W;
              y = 7 * GRID_H;
              w = 22 * GRID_W;
              h = 9 * GRID_H;
            };

            /* class  FactionMoneyBackground : A3A_Background
            {
              idc = -1;
              x = 0 * GRID_W;
              y = 19 * GRID_H;
              w = 60 * GRID_W;
              h = 9 * GRID_H;
            }; */

            class FactionMoneyLabel : A3A_Text
            {
              idc = -1;
              text = "Faction money:";
              x = 0 * GRID_W;
              y = 19 * GRID_H;
              w = 39 * GRID_W;
              h = 4 * GRID_H;
            };

            class FactionMoneyText : A3A_Text
            {
              idc = A3A_IDC_FACTIONMONEYTEXT;
              style = ST_RIGHT;
              text = "0";
              x = 41 * GRID_W;
              y = 19 * GRID_H;
              w = 16 * GRID_W;
              h = 4 * GRID_H;
            };

            class FactionMoneySlider : A3A_Slider
            {
              idc = A3A_IDC_FACTIONMONEYSLIDER;
              x = 0 * GRID_W;
              y = 24 * GRID_H;
              w = 39 * GRID_W;
              h = 4 * GRID_H;
              onSliderPosChanged = "[""factionMoneySliderChanged""] spawn A3A_fnc_hqDialog";
            };

            class FactionMoneyEditBox : A3A_Edit
            {
              idc = A3A_IDC_FACTIONMONEYEDITBOX;
              style = ST_RIGHT;
              text = "0";
              x = 41 * GRID_W;
              y = 24 * GRID_H;
              w = 16 * GRID_W;
              h = 4 * GRID_H;
              onKeyDown = "[""factionMoneyEditBoxChanged""] spawn A3A_fnc_hqDialog";
            };

            class FactionMoneyButton : A3A_Button
            {
              idc = A3A_IDC_FACTIONMONEYBUTTON;
              text = "Take";
              x = 60 * GRID_W;
              y = 19 * GRID_H;
              w = 22 * GRID_W;
              h = 9 * GRID_H;
            };

          };
        };


        // Rest & environment section

        class RestSectionControlsGroup : A3A_ControlsGroupNoScrollbars
        {
          idc = -1;
          x = 70 * GRID_W;
          y = 65 * GRID_H;
          w = 90 * GRID_W;
          h = 26 * GRID_H;

          class controls {
            class RestLabel : A3A_SectionLabelRight
            {
              idc = -1;
              text = "Rest & Environment";
              x = 0 * GRID_W;
              y = 0 * GRID_H;
              w = 90 * GRID_W;
              h = 4 * GRID_H;
            };

            class RestText : A3A_StructuredText
            {
              idc = A3A_IDC_RESTTEXT;
              text = "";
              x = 0 * GRID_W;
              y = 7 * GRID_H;
              w = 57 * GRID_W;
              h = 10 * GRID_H;
              // colorBackground[] = A3A_COLOR_BACKGROUND; // {0,0,0,0.5};
            };

            /* class RestBackground : A3A_Background
            {
              idc = -1;
              x = 0 * GRID_W;
              y = 17 * GRID_H;
              w = 57 * GRID_W;
              h = 9 * GRID_H;
            }; */

            class RestSlider : A3A_Slider
            {
              idc = A3A_IDC_RESTSLIDER;
              x = 0 * GRID_W;
              y = 21 * GRID_H;
              w = 39 * GRID_W;
              h = 4 * GRID_H;
              onSliderPosChanged = "[""restSliderChanged""] spawn A3A_fnc_hqDialog";
            };

            class RestButton : A3A_Button
            {
              idc = -1;
              text = "Rest";
              onButtonClick = "[""debugChangeTime""] spawn A3A_fnc_hqDialog;";
              x = 41 * GRID_W; // 108
              y = 20 * GRID_H;
              w = 16 * GRID_W;
              h = 6 * GRID_H;
            };

            class ClearFogButton : A3A_Button
            {
              idc = -1;
              text = "Clear Fog";
              x = 60 * GRID_W;
              y = 7 * GRID_H;
              w = 22 * GRID_W;
              h = 8 * GRID_H;
            };

            class StopRainButton : A3A_Button
            {
              idc = -1;
              onButtonClick = "[] call A3A_fnc_stopRain";
              text = "Stop Rain";
              x = 60 * GRID_W;
              y = 18 * GRID_H;
              w = 22 * GRID_W;
              h = 8 * GRID_H;
            };

          };
        };

      };
    };

    // Map misbehaves inside controlsGroups, hence this is placed outside
    // See controls.hpp for details
    class GarrisonMap : A3A_MapControl
    {
      idc = A3A_IDC_GARRISONMAP;
      onMouseButtonClick = "[""garrisonMapClicked"", _this select 0 ctrlMapScreenToWorld [_this select 2, _this select 3]] call A3A_fnc_hqDialog";
      x = CENTER_X(DIALOG_W) + 68 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 8 * GRID_H;
      w = 84 * GRID_W;
      h = 84 * GRID_H;

      // Hide map markers
      showMarkers = false;

      // Fade satellite texture a bit
      maxSatelliteAlpha = 0.75;
      alphaFadeStartScale = 3.0;
      alphaFadeEndScale = 3.0;

      // Set zoom levels
      scaleMin = 0.2; // 0.2 = Smallest scale showing the 100m grid
      scaleDefault = 0.325; // 0.325 = Largest scale forests still are visible
      scaleMax = 2; // 2 = Max zoom level
    };

    class GarrisonTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_HQDIALOGGARRISONTAB;
      // Width set to smaller than usual to avoid an issue where
      // pressing anything other than the map would (invisibly) cover up the
      // map control, making it unclickable
      w = 68 * GRID_W;

      class controls
      {
        class GarrisonTitle : A3A_Text
        {
          text = "HQ";
          idc = A3A_IDC_GARRISONTITLE;
          shadow = 2;
          colorShadow[] = {0,0,0,1};
          colorBackground[] = {0,0,0,0.5};
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 6 * GRID_H;
          sizeEx = GUI_TEXT_SIZE_LARGE;
        };

        class GarrisonControlsGroup : A3A_ControlsGroupNoScrollbars
        {
          idc = -1;
          x = 14 * GRID_W;
          y = 18 * GRID_H;
          w = 46 * GRID_W;
          h = 41 * GRID_H;

          class controls
          {
            class RiflemanLabel : A3A_Text
            {
              idc = -1;
              text = "Rifleman";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 0 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class RiflemanNumber : A3A_Text
            {
              idc = A3A_IDC_RIFLEMANNUMBER;
              text = "0";
              style = ST_RIGHT;
              font = "RobotoCondensedLight";
              x = 30 * GRID_W;
              y = 0 * GRID_H;
              w = 6 * GRID_W;
              h = 4 * GRID_H;
            };

            class RiflemanRemove : A3A_ShortcutButton
            {
              idc = -1;
              text = "-";
              onButtonClick = "[""garrisonAdd"",[""rifleman"",-1]] spawn A3A_fnc_hqDialog";
              x = 37 * GRID_W;
              y = 0 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class RiflemanAdd : A3A_ShortcutButton
            {
              idc = -1;
              text = "+";
              onButtonClick = "[""garrisonAdd"",[""rifleman"",1]] spawn A3A_fnc_hqDialog";
              x = 42 * GRID_W;
              y = 0 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class SquadleaderLabel : A3A_Text
            {
              idc = -1;
              text = "SquadLeader";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 5 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class SquadleaderNumber : A3A_Text
            {
              idc = A3A_IDC_SQUADLEADERNUMBER;
              text = "0";
              style = ST_RIGHT;
              font = "RobotoCondensedLight";
              x = 30 * GRID_W;
              y = 5 * GRID_H;
              w = 6 * GRID_W;
              h = 4 * GRID_H;
            };

            class SquadleaderRemove : A3A_ShortcutButton
            {
              idc = -1;
              text = "-";
              onButtonClick = "[""garrisonAdd"",[""squadleader"",-1]] spawn A3A_fnc_hqDialog";
              x = 37 * GRID_W;
              y = 5 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class SquadleaderAdd : A3A_ShortcutButton
            {
              idc = -1;
              text = "+";
              onButtonClick = "[""garrisonAdd"",[""squadleader"",1]] spawn A3A_fnc_hqDialog";
              x = 42 * GRID_W;
              y = 5 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class AutoriflemanLabel : A3A_Text
            {
              idc = -1;
              text = "Autorifleman";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 10 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class AutoriflemanNumber : A3A_Text
            {
              idc = A3A_IDC_AUTORIFLEMANNUMBER;
              text = "0";
              style = ST_RIGHT;
              font = "RobotoCondensedLight";
              x = 30 * GRID_W;
              y = 10 * GRID_H;
              w = 6 * GRID_W;
              h = 4 * GRID_H;
            };

            class AutoriflemanRemove : A3A_ShortcutButton
            {
              idc = -1;
              text = "-";
              onButtonClick = "[""garrisonAdd"",[""autorifleman"",-1]] spawn A3A_fnc_hqDialog";
              x = 37 * GRID_W;
              y = 10 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class AutoriflemanAdd : A3A_ShortcutButton
            {
              idc = -1;
              text = "+";
              onButtonClick = "[""garrisonAdd"",[""autorifleman"",1]] spawn A3A_fnc_hqDialog";
              x = 42 * GRID_W;
              y = 10 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class GrenadierLabel : A3A_Text
            {
              idc = -1;
              text = "Grenadier";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 15 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class GrenadierNumber : A3A_Text
            {
              idc = A3A_IDC_GRENADIERNUMBER;
              text = "0";
              style = ST_RIGHT;
              font = "RobotoCondensedLight";
              x = 30 * GRID_W;
              y = 15 * GRID_H;
              w = 6 * GRID_W;
              h = 4 * GRID_H;
            };

            class GrenadierRemove : A3A_ShortcutButton
            {
              idc = -1;
              text = "-";
              onButtonClick = "[""garrisonAdd"",[""grenadier"",-1]] spawn A3A_fnc_hqDialog";
              x = 37 * GRID_W;
              y = 15 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class GrenadierAdd : A3A_ShortcutButton
            {
              idc = -1;
              text = "+";
              onButtonClick = "[""garrisonAdd"",[""grenadier"",1]] spawn A3A_fnc_hqDialog";
              x = 42 * GRID_W;
              y = 15 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class MedicLabel : A3A_Text
            {
              idc = -1;
              text = "Medic";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 20 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class MedicNumber : A3A_Text
            {
              idc = A3A_IDC_MEDICNUMBER;
              text = "0";
              style = ST_RIGHT;
              font = "RobotoCondensedLight";
              x = 30 * GRID_W;
              y = 20 * GRID_H;
              w = 6 * GRID_W;
              h = 4 * GRID_H;
            };

            class MedicRemove : A3A_ShortcutButton
            {
              idc = -1;
              text = "-";
              onButtonClick = "[""garrisonAdd"",[""medic"",-1]] spawn A3A_fnc_hqDialog";
              x = 37 * GRID_W;
              y = 20 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class MedicAdd : A3A_ShortcutButton
            {
              idc = -1;
              text = "+";
              onButtonClick = "[""garrisonAdd"",[""medic"",1]] spawn A3A_fnc_hqDialog";
              x = 42 * GRID_W;
              y = 20 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class MortarLabel : A3A_Text
            {
              idc = -1;
              text = "Mortar";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 25 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class MortarNumber : A3A_Text
            {
              idc = A3A_IDC_MORTARNUMBER;
              text = "0";
              style = ST_RIGHT;
              font = "RobotoCondensedLight";
              x = 30 * GRID_W;
              y = 25 * GRID_H;
              w = 6 * GRID_W;
              h = 4 * GRID_H;
            };

            class MortarRemove : A3A_ShortcutButton
            {
              idc = -1;
              text = "-";
              onButtonClick = "[""garrisonAdd"",[""mortar"",-1]] spawn A3A_fnc_hqDialog";
              x = 37 * GRID_W;
              y = 25 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class MortarAdd : A3A_ShortcutButton
            {
              idc = -1;
              text = "+";
              onButtonClick = "[""garrisonAdd"",[""mortar"",1]] spawn A3A_fnc_hqDialog";
              x = 42 * GRID_W;
              y = 25 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class MarksmanLabel : A3A_Text
            {
              idc = -1;
              text = "Marksman";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 30 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class MarksmanNumber : A3A_Text
            {
              idc = A3A_IDC_MARKSMANNUMBER;
              text = "0";
              style = ST_RIGHT;
              font = "RobotoCondensedLight";
              x = 30 * GRID_W;
              y = 30 * GRID_H;
              w = 6 * GRID_W;
              h = 4 * GRID_H;
            };

            class MarksmanRemove : A3A_ShortcutButton
            {
              idc = -1;
              text = "-";
              onButtonClick = "[""garrisonAdd"",[""marksman"",-1]] spawn A3A_fnc_hqDialog";
              x = 37 * GRID_W;
              y = 30 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class MarksmanAdd : A3A_ShortcutButton
            {
              idc = -1;
              text = "+";
              onButtonClick = "[""garrisonAdd"",[""marksman"",1]] spawn A3A_fnc_hqDialog";
              x = 42 * GRID_W;
              y = 30 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class AtLabel : A3A_Text
            {
              idc = -1;
              text = "AT";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 35 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class AtNumber : A3A_Text
            {
              idc = A3A_IDC_ATNUMBER;
              text = "0";
              style = ST_RIGHT;
              font = "RobotoCondensedLight";
              x = 30 * GRID_W;
              y = 35 * GRID_H;
              w = 6 * GRID_W;
              h = 4 * GRID_H;
            };

            class AtRemove : A3A_ShortcutButton
            {
              idc = -1;
              text = "-";
              onButtonClick = "[""garrisonAdd"",[""at"",-1]] spawn A3A_fnc_hqDialog";
              x = 37 * GRID_W;
              y = 35 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };

            class AtAdd : A3A_ShortcutButton
            {
              idc = -1;
              text = "+";
              onButtonClick = "[""garrisonAdd"",[""at"",1]] spawn A3A_fnc_hqDialog";
              x = 42 * GRID_W;
              y = 35 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
              size = GUI_TEXT_SIZE_LARGE;
              class textPos
              {
                left = 1.5 * GRID_W;
                right = 0;
                top = -1 * GRID_H;
                bottom = 0;
              };
            };
          };
        };

        class RebuildButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Rebuild Assets";
          x = 14 * GRID_W;
          y = 60 * GRID_H;
          w = 22 * GRID_W;
          h = 12 * GRID_H;
        };

        class DismissGarrisonButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Dismiss Garrison";
          x = 38 * GRID_W;
          y = 60 * GRID_H;
          w = 22 * GRID_W;
          h = 12 * GRID_H;
        };

        class BuildOutpostButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Build Outpost";
          x = 14 * GRID_W;
          y = 78 * GRID_H;
          w = 22 * GRID_W;
          h = 12 * GRID_H;
        };

        class RemoveOutpostButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Remove Outpost";
          x = 38 * GRID_W;
          y = 78 * GRID_H;
          w = 22 * GRID_W;
          h = 12 * GRID_H;
        };
      };
    };

    class MinefieldsTab : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_HQDIALOGMINEFIELDSTAB;

      class controls
      {
        class DeployMinefieldText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "Deploy Minefield:";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 50 * GRID_W;
          y = 16 * GRID_H;
          w = 60 * GRID_W;
          h = 6 * GRID_H;
        }

        class ApersMinefieldIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_AP_Minefield;
          x = 42 * GRID_W;
          y = 24 * GRID_H;
          w = 28 * GRID_W;
          h = 28 * GRID_H;
        };

        class DeployApersMinefieldButton : A3A_Button
        {
          idc = -1;
          text = "APERS Mines";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 54 * GRID_H;
          w = 40 * GRID_W;
          h = 12 * GRID_H;
        };

        class AtMinefieldIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_AT_Minefield;
          x = 90 * GRID_W;
          y = 24 * GRID_H;
          w = 28 * GRID_W;
          h = 28 * GRID_H;
        };


        class DeployAtMinefieldButton : A3A_Button
        {
          idc = -1;
          text = "AT Mines";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 84 * GRID_W;
          y = 54 * GRID_H;
          w = 40 * GRID_W;
          h = 12 * GRID_H;
        };

        class RemoveMinefieldButton : A3A_Button
        {
          idc = -1;
          text = "Remove Minefield";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 52 * GRID_W;
          y = 80 * GRID_H;
          w = 56 * GRID_W;
          h = 12 * GRID_H;
        };

      };
    };

    class BackButton : A3A_BackButton
    {
      idc = A3A_IDC_HQDIALOGBACKBUTTON;
      x = DIALOG_X + DIALOG_W * GRID_W - 10 * GRID_W;
      y = DIALOG_Y - 4 * GRID_H;
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = DIALOG_X + DIALOG_W * GRID_W - 4 * GRID_W;
      y = DIALOG_Y - 4 * GRID_H;
    };
  };
};
