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

        class FastTravelHCButton : A3A_ShortcutButton
        {
          idc = -1;
          textureNoShortcut = A3A_Icon_FastTravel;
          onLoad = "_this # 0 ctrlEnable false; _this # 0 ctrlSetFade 0.5; _this # 0 ctrlCommit 0";
          onButtonClick = "hint ""FT button clicked"";";
          x = 42 * GRID_W;
          y = 16 * GRID_H;
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

        class TestShortcutButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Test";
          onLoad = "_this # 0 ctrlEnable false;";
          onButtonClick = "hint ""FT button clicked"";";
          x = 64 * GRID_W;
          y = 16 * GRID_H;
          w = 10 * GRID_W;
          h = 6 * GRID_H;

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
