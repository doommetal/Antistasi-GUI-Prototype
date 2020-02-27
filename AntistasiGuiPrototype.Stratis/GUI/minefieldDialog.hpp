class A3A_MinefieldDialog
{
  idd = A3A_IDD_MINEFIELDDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "HQ MANAGEMENT > MINEFIELD MANAGEMENT";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 4 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
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

    // MapControl needs to be placed here to avoid problems
    // with map clicks when it's placed within a controlsGroup
    class GarrisonMap : RscMapControl
    {
      idc = A3A_IDC_MINEFIELDMAP;
      onMouseButtonClick = "[""mapClicked"", _this] spawn A3A_fnc_minefieldDialog";
      x = CENTER_X(DIALOG_W) + 68 * GRID_W;
      y = CENTER_Y(DIALOG_H) + 8 * GRID_H;
      // x = 68 * GRID_W;
      // y = 8 * GRID_H;
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
      // Width set to smaller than usual to avoid an issue where
      // pressing anything other than the map would (invisibly) cover up the
      // map control, making it not get click events
      w = 68 * GRID_W;
      h = PX_H(DIALOG_H);

      class controls
      {
        // Start of controls
        class MinefieldList : A3A_ShortcutButton
        {
          idc = -1;
          text = "Placeholder List / Info";
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 56 * GRID_W;
          h = 32 * GRID_H;
        };

        class RemoveMinefieldButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Remove Minefield";
          x = 8 * GRID_W;
          y = 48 * GRID_H;
          w = 56 * GRID_W;
          h = 8 * GRID_H;
        };

        class DeploySectionLabel : A3A_SectionLabelLeft
        {
          idc = -1;
          text = "Deploy minefield";
          x = 0;
          y = 64 * GRID_H;
          w = 64 * GRID_W;
          h = 4 * GRID_H;
        };

        class DeployApersMinefieldButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "APERS Mines";
          x = 16 * GRID_W;
          y = 74 * GRID_H;
          w = 40 * GRID_W;
          h = 8 * GRID_H;
        };

        class DeployAtMinefieldButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "AT Mines";
          x = 16 * GRID_W;
          y = 84 * GRID_H;
          w = 40 * GRID_W;
          h = 8 * GRID_H;
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
