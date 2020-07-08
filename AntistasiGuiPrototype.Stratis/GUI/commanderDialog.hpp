class A3A_CommanderDialog
{
  idd = A3A_IDD_COMMANDERDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "COMMANDER OPTIONS";
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

    class CommanderMap : RscMapControl
    {
      idc = A3A_IDC_COMMANDERMAP;
      onMouseButtonClick = "[""mapClicked"", _this select 0 ctrlMapScreenToWorld [_this select 2, _this select 3]] spawn A3A_fnc_commanderDialog";
      x = CENTER_X(DIALOG_W) + 68 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 8 * GRID_H;
      w = 84 * GRID_W;
      h = 84 * GRID_H;

      // Fade satellite texture a bit
      maxSatelliteAlpha = 0.75;
      alphaFadeStartScale = 3.0;
      alphaFadeEndScale = 3.0;

      // Set zoom levels
      scaleMin = 0.2; // Smallest scale showing the 100m lines
      scaleDefault = 0.325; // Largest scale forests still are visible
      scaleMax = 2;
    };

    class MainContent : RscControlsGroupNoScrollbars
    {
      idc = -1;
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H);
      w = 68 * GRID_W;
      h = PX_H(DIALOG_H);

      class controls
      {
        class SingleGroupView : RscControlsGroupNoScrollbars
        {
          idc = A3A_IDC_HCSINGLEGROUPVIEW;
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 62 * GRID_H;

          class controls {
            class SquadName : RscText
            {
              idc = A3A_IDC_HCSQUADNAME;
              text = "Alpha 1-3";
              shadow = 2;
              colorShadow[] = {0,0,0,1};
              colorBackground[] = {0,0,0,0.5};
              x = 0;
              y = 0;
              w = 54 * GRID_W;
              h = 6 * GRID_H;
              sizeEx = GUI_TEXT_SIZE_LARGE;
            };

            class SquadInfoLabels : RscTextMulti
            {
              idc = -1;
              text = "Alive members:\nAble to combat:\nCurrent task:\nCombat Mode:\nOperative Medic:";
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 0;
              y = 8 * GRID_H;
              w = 24 * GRID_W;
              h = 24 * GRID_H;
            };

            class SquadInfoValues : RscTextMulti
            {
              idc = A3A_IDC_HCSQUADINFO;
              style = ST_MULTI + ST_RIGHT;
              text = "4\n2\nAssault\nCOMBAT\nYes";
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 26 * GRID_W;
              y = 8 * GRID_H;
              w = 24 * GRID_W;
              h = 24 * GRID_H;
            };

            class MountButton : A3A_ShortcutButton
            {
              idc = -1;
              text = "Mount / Dismount";
              x = 0;
              y = 36 * GRID_H;
              w = 24 * GRID_W;
              h = 12 * GRID_H;
            };

            class AddVehicleButton : A3A_ShortcutButton
            {
              idc = -1;
              text = "Add Vehicle";
              x = 0;
              y = 50 * GRID_H;
              w = 24 * GRID_W;
              h = 12 * GRID_H;
            };

            class GarrisonButtom : A3A_ShortcutButton
            {
              idc = -1;
              text = "Garrison";
              x = 26 * GRID_W;
              y = 36 * GRID_H;
              w = 24 * GRID_W;
              h = 12 * GRID_H;
            };

            class DismissButton : A3A_ShortcutButton
            {
              idc = -1;
              text = "Dismiss";
              x = 26 * GRID_W;
              y = 50 * GRID_H;
              w = 24 * GRID_W;
              h = 12 * GRID_H;
            };
          }; // End of SingleGroupView controls
        };

        class MultipleGroupsView : RscControlsGroupNoHScrollbars
        {
          idc = A3A_IDC_HCMULTIPLEGROUPSVIEW;
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 62 * GRID_H;
          show = false;

          class controls
          {
            // Controls generated via script
            /* class GroupListItem : RscControlsGroupNoScrollbars
            {
              idc = -1;
              x = 0;
              y = 0;
              w = 54 * GRID_W;
              h = 14 * GRID_H;
              class controls
              {
                class GroupListItemBackground : A3A_MainBackground
                {
                  idc = -1;
                  x = 0;
                  y = 0;
                  w = 54 * GRID_W;
                  h = 14 * GRID_H;
                };

                class GroupNameLabel : RscText
                {
                  idc = -1;
                  text = "Alpha 1-1 Big long squad name";
                  colorBackground[] = {0,0,0,1};
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 54 * GRID_W;
                  h = 6 * GRID_H;
                };

                class GroupCountIcon : RscPicture
                {
                  idc = -1;
                  text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\meet_ca.paa";
                  tooltip = "Number of units in the group\nAble to combat / Total number of units";
                  x = 2 * GRID_W;
                  y = 8 * GRID_H;
                  w = 4 * GRID_W;
                  h = 4 * GRID_H;
                };

                class GroupCountText : RscText
                {
                  idc = -1;
                  text = "900 / 900";
                  tooltip = "Number of units in the group\nAble to combat / Total number of units";
                  x = 6 * GRID_W;
                  y = 8 * GRID_H;
                  w = 16 * GRID_W;
                  h = 4 * GRID_H;
                };

                class GroupIcons : RscControlsGroupNoScrollbars
                {
                  idc = -1;
                  x = 22 * GRID_W;
                  y = 8 * GRID_H;
                  w = 30 * GRID_W;
                  h = 6 * GRID_H;
                  class controls
                  {
                    class MedicIcon : RscPicture
                    {
                      idc = -1;
                      text = "\A3\ui_f\data\igui\cfg\actions\heal_ca.paa";
                      tooltip = "Has operative medic";
                      x = 0;
                      y = 0;
                      w = 4 * GRID_W;
                      h = 4 * GRID_H;
                    };

                    class AtIcon : RscPicture
                    {
                      idc = -1;
                      text = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa"
                      tooltip = "Has AT capability";
                      x = 5 * GRID_W;
                      y = 0;
                      w = 4 * GRID_W;
                      h = 4 * GRID_H;
                    };

                    class AaIcon : RscPicture
                    {
                      idc = -1;
                      text = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa"
                      tooltip = "Has AA capability";
                      x = 10 * GRID_W;
                      y = 0;
                      w = 4 * GRID_W;
                      h = 4 * GRID_H;
                    };

                    class EngineerIcon : RscPicture
                    {
                      idc = -1;
                      text = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa"
                      tooltip = "Has engineer";
                      x = 15 * GRID_W;
                      y = 0;
                      w = 4 * GRID_W;
                      h = 4 * GRID_H;
                    };

                    class MortarIcon : RscPicture
                    {
                      idc = -1;
                      text = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa"
                      tooltip = "Has mortar";
                      x = 15 * GRID_W;
                      y = 0;
                      w = 4 * GRID_W;
                      h = 4 * GRID_H;
                    };

                    class VehicleIcon : RscPicture
                    {
                      idc = -1;
                      text = "\A3\ui_f\data\igui\cfg\weaponicons\at_ca.paa"
                      tooltip = "Has vehicle";
                      x = 20 * GRID_W;
                      y = 0;
                      w = 4 * GRID_W;
                      h = 4 * GRID_H;
                    };
                  };
                };
              };
            }; */

            // class TestText1 : RscTextMulti
            // {
            //   idc = -1;
            //   x = 0;
            //   y = 0;
            //   w = 54 * GRID_W;
            //   h = 80 * GRID_H;
            //   sizeEx = GUI_TEXT_SIZE_MEDIUM;
            //   text = "Here's a bunch of text  to test this thing\nI Really hope it works\nJust putting in some more text\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText\nText";
            // };
          };
        };

        class AirSupportButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Air Support";
          action = "[] spawn A3A_fnc_airSupportDialog";
          x = 8 * GRID_W;
          y = 80 * GRID_H;
          w = 24 * GRID_W;
          h = 12 * GRID_H;
        };

        class GarbageCleanButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Garbage Clean";
          x = 34 * GRID_W;
          y = 80 * GRID_H;
          w = 24 * GRID_W;
          h = 12 * GRID_H;
        };

        // End of main controls
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
  };
};
