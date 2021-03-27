class A3A_TestDefaultDialog : A3A_DefaultDialog
{
  idd = 7000;
  // onLoad = "[""onLoad""] spawn A3A_fnc_testDefaultDialog";

  class Controls
  {
    class TitlebarText : A3A_TitlebarText
    {
      idc = 7001;
      text = "TEST DEFAULT DIALOG";
      x = DIALOG_X;
      y = DIALOG_Y - 5 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 5 * GRID_H;
    };

    // Main content
    class MainContent : A3A_DefaultControlsGroup
    {
      idc = 7100;

      class Controls
      {
        class TestText : A3A_Text
        {
          idc = 7101;
          text = "This is a test of A3A_DefaultDialog.";
					x = 2 * GRID_W;
					y = 2 * GRID_H;
					w = 56 * GRID_W;
					h = 4 * GRID_H;
        };

        class TestBackground : A3A_Background
        {
          idc = -1;
					x = 16 * GRID_W;
					y = 16 * GRID_H;
					w = 64 * GRID_W;
					h = 16 * GRID_H;
        };

        class TestPicture : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Napalm_Bomb;
					x = 16 * GRID_W;
					y = 16 * GRID_H;
					w = 48 * GRID_W;
					h = 16 * GRID_H;
        };

        class TestBackground2 : A3A_Background
        {
          idc = -1;
					x = 16 * GRID_W;
					y = 64 * GRID_H;
					w = 64 * GRID_W;
					h = 16 * GRID_H;
        };

        class TestPicture2 : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Napalm_Bomb;
					x = 16 * GRID_W;
					y = 64 * GRID_H;
					w = 48 * GRID_W;
					h = 16 * GRID_H;
        };

      };
    };

    // Close and Back buttons
    class BackButton : A3A_BackButton
    {
      idc = -1;
      onMouseButtonClick = "hint ""Back"";";
      x = DIALOG_X + DIALOG_W * GRID_W - 14 * GRID_W;
      y = DIALOG_Y - 5 * GRID_H;
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = DIALOG_X + DIALOG_W * GRID_W - 4 * GRID_W;
      y = DIALOG_Y - 5 * GRID_H;
    };
  };
};
