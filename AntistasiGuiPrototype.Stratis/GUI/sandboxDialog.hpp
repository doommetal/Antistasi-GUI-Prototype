class A3A_SandboxDialog
{
  idd = A3A_IDD_SANDBOXDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "SANDBOX";
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
        // Start of controls

        class GarrisonTitle : RscText
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

        class GarrisonControlsGroup : RscControlsGroupNoScrollbars
        {
          idc = -1;
          x = 14 * GRID_W;
          y = 18 * GRID_H;
          w = 46 * GRID_W;
          h = 50 * GRID_H;

          class controls
          {
            class RiflemanLabel : RscText
            {
              idc = -1;
              text = "Rifleman";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 0 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class RiflemanNumber : RscText
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

            class SquadleaderLabel : RscText
            {
              idc = -1;
              text = "SquadLeader";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 5 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class SquadleaderNumber : RscText
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

            class AutoriflemanLabel : RscText
            {
              idc = -1;
              text = "Autorifleman";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 10 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class AutoriflemanNumber : RscText
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

            class GrenadierLabel : RscText
            {
              idc = -1;
              text = "Grenadier";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 15 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class GrenadierNumber : RscText
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

            class MedicLabel : RscText
            {
              idc = -1;
              text = "Medic";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 20 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class MedicNumber : RscText
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

            class MortarLabel : RscText
            {
              idc = -1;
              text = "Mortar";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 25 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class MortarNumber : RscText
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

            class MarksmanLabel : RscText
            {
              idc = -1;
              text = "Marksman";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 30 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class MarksmanNumber : RscText
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

            class AtLabel : RscText
            {
              idc = -1;
              text = "AT";
              font = "RobotoCondensedLight";
              x = 0 * GRID_W;
              y = 35 * GRID_H;
              w = 30 * GRID_W;
              h = 4 * GRID_H;
            };

            class AtNumber : RscText
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

            class DismissGarrisonButton : A3A_ShortcutButton
            {
              idc = -1;
              text = "Dismiss Garrison";
              x = 0 * GRID_W;
              y = 42 * GRID_H;
              w = 46 * GRID_W;
              h = 8 * GRID_H;
            };
          };
        };

        class BuildOutpostButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Build Outpost / Roadblock";
          x = 8 * GRID_W;
          y = 74 * GRID_H;
          w = 56 * GRID_W;
          h = 8 * GRID_H;
        };

        class RemoveOutpostButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Remove Outpost / Roadblock";
          x = 8 * GRID_W;
          y = 84 * GRID_H;
          w = 56 * GRID_W;
          h = 8 * GRID_H;
        };

        class SizeTestGroup : RscControlsGroupNoScrollbars
        {
          x = 0;
          y = 0;
          w = PX_W(DIALOG_W);
          h = PX_H(DIALOG_H);
          show = false;

          class controls
          {
            class TestText1 : RscText
            {
              text = "GUI_TEXT_SIZE_SMALL -  Goes in a box with 3xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_SMALL;
              x = 0;
              y = 0;
              w = 80 * GRID_W;
              h = 3 * GRID_H;
            };

            class TestText2 : RscText
            {
              idc = 22001;
              text = "GUI_TEXT_SIZE_MEDIUM - Goes in a box with 4xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 0;
              y = 9 * GRID_H;
              w = 80 * GRID_W;
              h = 4 * GRID_H;
            };

            class TestText3 : RscText
            {
              text = "GUI_TEXT_SIZE_LARGE - Goes in a box with 6xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_LARGE;
              x = 0;
              y = 18 * GRID_H;
              w = 80 * GRID_W;
              h = 6 * GRID_H;
            };

            class GridBox1 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 8 * GRID_H;
              w = GRID_W;
              h = GRID_H;
            };

            class GridBox2 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 16 * GRID_H;
              w = 2 * GRID_W;
              h = 2 * GRID_H;
            };

            class GridBox4 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 24 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };
            class GridBox8 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 32 * GRID_H;
              w = 8 * GRID_W;
              h = 8 * GRID_H;
            };

            class TestButtonSmall : A3A_ShortcutButton
            {
              text = "Small Button 1 Line";
              size = GUI_TEXT_SIZE_SMALL;
              x = 8 * GRID_W;
              y = 50 * GRID_H;
              w = 30 * GRID_W;
              h = 5 * GRID_H;

              class textPos
              {
                left = 1 * GRID_W;
                right = 1 * GRID_H;
                top = 1 * GRID_W;
                bottom = 1* GRID_H;
              };
            };

            class TestButtonSmall2 : A3A_ShortcutButton
            {
              text = "Small Button 2 Line";
              size = GUI_TEXT_SIZE_SMALL;
              x = 42 * GRID_W;
              y = 50 * GRID_H;
              w = 16 * GRID_W;
              h = 8 * GRID_H;

              class textPos
              {
                left = 1 * GRID_W;
                right = 1 * GRID_H;
                top = 1 * GRID_W;
                bottom = 1* GRID_H;
              };
            };
          };
        };
        
        // Main controlsGroup messed up the position of the map for some reason
        // Placing it here until I figure out wtf is going on with that
        class GarrisonMap : RscMapControl
        {
          idc = A3A_IDC_GARRISONMAP;
          onMouseButtonClick = "[""mapClicked"", _this] spawn A3A_fnc_sandboxDialog";
          x = CENTER_X(DIALOG_W) + 68 * GRID_W;
          y = CENTER_Y(DIALOG_H) + 8 * GRID_H;
          w = 84 * GRID_W;
          h = 84 * GRID_H;

          // Disable satellite texture
          maxSatelliteAlpha = 0.0;
          alphaFadeStartScale = 0.0;
          alphaFadeEndScale = 0.0;

          // Set zoom levels
          scaleMin = 0.2;
          scaleDefault = 0.325;
          scaleMax = 2;
        };

        // End of main content group controls
      };
    };

    // End of controls
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

    class GarrisonListBackground : A3A_MainBackground
    {
      colorBackground[] = {0,0,0,0.5};
      x = CENTER_X(DIALOG_W) + 12 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 16 * GRID_H;
      w = 50 * GRID_W;
      h = 54 * GRID_H;
    }
  };
};
