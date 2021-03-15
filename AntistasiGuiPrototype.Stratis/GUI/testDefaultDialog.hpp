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

        class FireMissionControlsGroup : A3A_ControlsGroupNoScrollbars
        {
          idc = -1;
          x = 80 * GRID_W;
          y = 8 * GRID_H;
          w = 54 * GRID_W;
          h = 68 * GRID_H;

          class controls
          {
            class FireMissionLabel : A3A_Button_Left
            {
              idc = -1;
              text = "Fire mission";
              x = 0;
              y = 0;
              w = 54 * GRID_W;
              h = 6 * GRID_H;
            };

            class FireMissionBackground : A3A_Background
            {
              idc = -1;
              x = 0;
              y = 6 * GRID_H;
              w = 54 * GRID_W;
              h = 62 * GRID_H;
            };

            class RoundsCountLabel : A3A_SectionLabelRight
            {
              idc = -1;
              text = "Ammo";
              x = 2 * GRID_W;
              y = 10 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;
            };

            class HeRoundsCountLabel : A3A_Text
            {
              idc = -1;
              text = "HE:";
              x = 2 * GRID_W;
              y = 15 * GRID_H;
              w = 25 * GRID_W;
              h = 4 * GRID_H;
            };

            class HeRoundsCountText : A3A_Text
            {
              idc = -1;
              text = "32";
              style = ST_RIGHT;
              x = 27 * GRID_W;
              y = 15 * GRID_H;
              w = 25 * GRID_W;
              h = 4 * GRID_H;
            };

            class SmokeRoundsCountLabel : A3A_Text
            {
              idc = -1;
              text = "Smoke:";
              x = 2 * GRID_W;
              y = 20 * GRID_H;
              w = 25 * GRID_W;
              h = 4 * GRID_H;
            };

            class SmokeRoundsCountText : A3A_Text
            {
              idc = -1;
              text = "32";
              style = ST_RIGHT;
              x = 27 * GRID_W;
              y = 20 * GRID_H;
              w = 25 * GRID_W;
              h = 4 * GRID_H;
            };

            class ShellTypeControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = -1;
              x = 2 * GRID_W;
              y = 30 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class ShellTypeLabel : A3A_Text
                {
                  idc = -1;
                  text = "Shell type:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class HeButton : A3A_Button
                {
                  idc = -1;
                  text = "HE";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 15 * GRID_W;
                  h = 4 * GRID_H;
                };

                class SmokeButton : A3A_Button
                {
                  idc = -1;
                  text = "Smoke";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  x = 35 * GRID_W;
                  y = 0 * GRID_H;
                  w = 15 * GRID_W;
                  h = 4 * GRID_H;
                };
              };
            };

            class MissionTypeControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = -1;
              x = 2 * GRID_W;
              y = 35 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class MissionTypeLabel : A3A_Text
                {
                  idc = -1;
                  text = "Mission type:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class PointButton : A3A_Button
                {
                  idc = -1;
                  text = "Point";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 15 * GRID_W;
                  h = 4 * GRID_H;
                };

                class BarrageButton : A3A_Button
                {
                  idc = -1;
                  text = "Barrage";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  x = 35 * GRID_W;
                  y = 0 * GRID_H;
                  w = 15 * GRID_W;
                  h = 4 * GRID_H;
                };
              };
            };


            class RoundsControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = -1;
              x = 2 * GRID_W;
              y = 40 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class MissionTypeLabel : A3A_Text
                {
                  idc = -1;
                  text = "Rounds:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class RoundsEditbox : A3A_Edit
                {
                  idc = -1;
                  text = "0";
                  style = ST_RIGHT + ST_NO_RECT;
                  onLoad = "_this#0 ctrlEnable false";
                  colorBackground[] = A3A_COLOR_BLACK;
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 22 * GRID_W;
                  h = 4 * GRID_H;
                };

                class AddRoundsButton : A3A_Button
                {
                  idc = -1;
                  text = "+";
                  // sizeEx = GUI_TEXT_SIZE_SMALL;
                  x = 42 * GRID_W;
                  y = 0 * GRID_H;
                  w = 4 * GRID_W;
                  h = 4 * GRID_H;
                };

                class RemoveRoundsButton : A3A_Button
                {
                  idc = -1;
                  text = "-";
                  // sizeEx = GUI_TEXT_SIZE_SMALL;
                  x = 46 * GRID_W;
                  y = 0 * GRID_H;
                  w = 4 * GRID_W;
                  h = 4 * GRID_H;
                };
              };
            };


            class EndPositionControlsGroup : A3A_ControlsGroupNoScrollbars
            {
              idc = -1;
              x = 2 * GRID_W;
              y = 45 * GRID_H;
              w = 50 * GRID_W;
              h = 4 * GRID_H;

              class controls
              {
                class EndPositionLabel : A3A_Text
                {
                  idc = -1;
                  text = "Rounds:";
                  colorBackground[] = A3A_COLOR_BACKGROUND;
                  x = 0 * GRID_W;
                  y = 0 * GRID_H;
                  w = 20 * GRID_W;
                  h = 4 * GRID_H;
                };

                class EndPositionEditbox : A3A_Edit
                {
                  idc = -1;
                  text = "039 047";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  style = ST_RIGHT + ST_NO_RECT;
                  onLoad = "_this#0 ctrlEnable false";
                  colorBackground[] = A3A_COLOR_BLACK;
                  x = 20 * GRID_W;
                  y = 0 * GRID_H;
                  w = 22 * GRID_W;
                  h = 4 * GRID_H;
                };

                class SetEndPositionButton : A3A_Button
                {
                  idc = -1;
                  text = "Set";
                  sizeEx = GUI_TEXT_SIZE_SMALL;
                  x = 42 * GRID_W;
                  y = 0 * GRID_H;
                  w = 8 * GRID_W;
                  h = 4 * GRID_H;
                };
              };
            };


            class FireButton : A3A_Button
            {
              idc = -1;
              text = "Fire";
              x = 17 * GRID_W;
              y = 56 * GRID_H;
              w = 20 * GRID_W;
              h = 8 * GRID_H;
            };


          };
        };

        // class ShellTypeControlsGroup : A3A_ControlsGroupNoScrollbars
        // {
        //   idc = -1;
        //   x = 38 * GRID_W;
        //   y = 18 * GRID_H;
        //   w = 82 * GRID_W;
        //   h = 8 * GRID_H;
        //
        //   class controls
        //   {
        //     class ShellTypeBackground : A3A_Background
        //     {
        //       idc = -1;
        //       x = 0 * GRID_W;
        //       y = 0 * GRID_H;
        //       w = 82 * GRID_W;
        //       h = 8 * GRID_H;
        //     };
        //
        //     class ShellTypeLabel : A3A_Text
        //     {
        //       idc = -1;
        //       text = "Shell type:";
        //       sizeEx = GUI_TEXT_SIZE_LARGE;
        //       x = 1 * GRID_W;
        //       y = 2 * GRID_H;
        //       w = 40 * GRID_W;
        //       h = 4 * GRID_H;
        //     };
        //
        //     class HeButton : A3A_Button
        //     {
        //       idc = -1;
        //       text = "HE";
        //       x = 41 * GRID_W;
        //       y = 1 * GRID_H;
        //       w = 20 * GRID_W;
        //       h = 6 * GRID_H;
        //     };
        //
        //     class SmokeButton : A3A_Button
        //     {
        //       idc = -1;
        //       text = "Smoke";
        //       x = 61 * GRID_W;
        //       y = 1 * GRID_H;
        //       w = 20 * GRID_W;
        //       h = 6 * GRID_H;
        //     };
        //   };
        // };
        //
        // class MissionTypeControlsGroup : A3A_ControlsGroupNoScrollbars
        // {
        //   idc = -1;
        //   x = 38 * GRID_W;
        //   y = 28 * GRID_H;
        //   w = 82 * GRID_W;
        //   h = 8 * GRID_H;
        //
        //   class controls
        //   {
        //     class MissionTypeBackground : A3A_Background
        //     {
        //       idc = -1;
        //       x = 0 * GRID_W;
        //       y = 0 * GRID_H;
        //       w = 82 * GRID_W;
        //       h = 8 * GRID_H;
        //     };
        //
        //     class MissionTypeLabel : A3A_Text
        //     {
        //       idc = -1;
        //       text = "Fire mission type:";
        //       sizeEx = GUI_TEXT_SIZE_LARGE;
        //       x = 1 * GRID_W;
        //       y = 2 * GRID_H;
        //       w = 40 * GRID_W;
        //       h = 4 * GRID_H;
        //     };
        //
        //     class PointStrikeButton : A3A_Button
        //     {
        //       idc = -1;
        //       text = "Point";
        //       sizeEx = GUI_TEXT_SIZE_MEDIUM;
        //       x = 41 * GRID_W;
        //       y = 1 * GRID_H;
        //       w = 20 * GRID_W;
        //       h = 6 * GRID_H;
        //     };
        //
        //     class BarrageButton : A3A_Button
        //     {
        //       idc = -1;
        //       text = "Barrage";
        //       sizeEx = GUI_TEXT_SIZE_SMALL;
        //       x = 61 * GRID_W;
        //       y = 1 * GRID_H;
        //       w = 20 * GRID_W;
        //       h = 6 * GRID_H;
        //     };
        //   };
        // };
        //
        // class FireButton : A3A_Button
        // {
        //   idc = -1;
        //   text = "Fire";
        //   sizeEx = GUI_TEXT_SIZE_LARGE;
        //   x = 65 * GRID_W;
        //   y = 56 * GRID_H;
        //   w = 30 * GRID_W;
        //   h = 12 * GRID_H;
        // };


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
