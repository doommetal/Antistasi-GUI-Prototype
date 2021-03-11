class A3A_TestDefaultDialog : A3A_DefaultDialog
{
  idd = 7000;
  // onLoad = "[""onLoad""] spawn A3A_fnc_testDefaultDialog";

  class Controls
  {
    class TitlebarText : A3A_Text
    {
      idc = 7001;
      text = "Test Default Dialog";
      x = DIALOG_X;
      y = DIALOG_Y - 4 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 4 * GRID_H;
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
      };
    };

    // Close and Back buttons
    class BackButton : A3A_BackButton
    {
      idc = -1;
      onMouseButtonClick = "hint ""Back"";";
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
