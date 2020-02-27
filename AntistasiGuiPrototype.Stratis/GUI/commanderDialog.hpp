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

    class CommanderMap : RscMapControl
    {
      idc = A3A_IDC_COMMANDERMAP;
      onMouseButtonClick = "[""mapClicked"", _this] spawn A3A_fnc_commanderDialog";
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
        class SquadTitle : RscText
        {
          idc = -1;
          text = "Squad 1 - Alpha or whatever";
          shadow = 2;
          colorShadow[] = {0,0,0,1};
          colorBackground[] = {0,0,0,0.5};
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 6 * GRID_H;
          sizeEx = GUI_TEXT_SIZE_LARGE;
        };

        class SquadStuffPlaceholder : A3A_ShortcutButton
        {
          idc = -1;
          text = "Squad info placeholder (basically what used to be in SITREP)";
          x = 8 * GRID_W;
          y = 16 * GRID_H;
          w = 50 * GRID_W;
          h = 24 * GRID_H;
        };

        class MountButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Mount / Dismount";
          x = 8 * GRID_W;
          y = 44 * GRID_H;
          w = 24 * GRID_W;
          h = 12 * GRID_H;
        };

        class AddVehicleButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Add Vehicle";
          x = 8 * GRID_W;
          y = 58 * GRID_H;
          w = 24 * GRID_W;
          h = 12 * GRID_H;
        };

        class GarrisonButtom : A3A_ShortcutButton
        {
          idc = -1;
          text = "Garrison";
          x = 34 * GRID_W;
          y = 44 * GRID_H;
          w = 24 * GRID_W;
          h = 12 * GRID_H;
        };

        class DismissButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Dismiss";
          x = 34 * GRID_W;
          y = 58 * GRID_H;
          w = 24 * GRID_W;
          h = 12 * GRID_H;
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
