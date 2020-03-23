class A3A_GarageDialog
{
  idd = A3A_IDD_GARAGEDIALOG;

  #define DIALOG_W 104
  #define DIALOG_H 28

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "GARAGE VEHICLE";
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
        class PersonalGarageButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_PERSONALGARAGEBUTTON;
          text = "Personal Garage";
          action = "closeDialog 2";
          size = GUI_TEXT_SIZE_LARGE;
          x = 8 * GRID_W;
          y = 8 * GRID_H;
          w = 40 * GRID_W;
          h = 12 * GRID_H;

          class TextPos
          {
            left = 2 * GRID_W;
            right = 2 * GRID_W;
            top = 3 * GRID_H;
            bottom = 3 * GRID_W;
          };
        };

        class FactionGarageButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_FACTIONGARAGEBUTTON;
          text = "Faction Garage";
          action = "closeDialog 2";
          size = GUI_TEXT_SIZE_LARGE;
          x = 56 * GRID_W;
          y = 8 * GRID_H;
          w = 40 * GRID_W;
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
      action = "[] spawn A3A_fnc_playerDialog";
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
