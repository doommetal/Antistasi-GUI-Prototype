class A3A_LoadDialog
{
  idd = A3A_IDC_LoadDialog;

  #define DIALOG_W 65 // Width of dialog in pixelGrid units
  #define DIALOG_H 26 // Height of dialog in pixelGrid units
  #define DIALOG_X CENTER_X(DIALOG_W) // Global x pos of dialog
  #define DIALOG_Y CENTER_Y(DIALOG_H) // Global y pos of dialog

  class Controls
  {
    class TitlebarText : A3A_Text
    {
      idc = 7001;
      text = "Load last save?"; // TODO: localize
      sizeEx = GUI_TEXT_SIZE_LARGE;
      x = DIALOG_X;
      y = DIALOG_Y - 6 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 6 * GRID_H;
    };

    // Main content
    class MainContent : A3A_ControlsGroupNoScrollbars
    {
      idc = -1;

      x = DIALOG_X;
      y = DIALOG_Y;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;

      class Controls
      {
        class YesButton : A3A_Button
        {
          idc = -1;
          text = "Yes"; // TODO: localize
          sizeEx = GUI_TEXT_SIZE_LARGE;
					x = 10 * GRID_W;
					y = 8 * GRID_H;
					w = 20 * GRID_W;
					h = 10 * GRID_H;
        };

        class NoButton : A3A_Button
        {
          idc = -1;
          text = "No"; // TODO: localize
          sizeEx = GUI_TEXT_SIZE_LARGE;
					x = 35 * GRID_W;
					y = 8 * GRID_H;
					w = 20 * GRID_W;
					h = 10 * GRID_H;
        };
      };
    };
  };

  class ControlsBackground
  {
    class TitleBarBackground : A3A_Background
    {
      moving = true;
      colorBackground[] = A3A_COLOR_TITLEBAR_BACKGROUND;
      x = DIALOG_X;
      y = DIALOG_Y - 6 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 6 * GRID_H;
    };

    class Background : A3A_Background
    {
      x = DIALOG_X;
      y = DIALOG_Y;
      w = DIALOG_W * GRID_W;
      h = DIALOG_H * GRID_H;
    };
  };
};
