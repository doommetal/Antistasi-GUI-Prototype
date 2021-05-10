class A3A_TestTabbedDialog : A3A_TabbedDialog
{
  idd = 7000;
  onLoad = "[""onLoad""] spawn A3A_fnc_testTabbedDialog";

  class Controls
  {
    class TitlebarText : A3A_TitlebarText
    {
      idc = 7001;
      text = "TABBED DIALOG";
      x = DIALOG_X;
      y = DIALOG_Y - 10 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 5 * GRID_H;
    };

    class TabButtons : A3A_ControlsGroupNoScrollbars
    {
      idc = 7002;
      x = DIALOG_X;
      y = DIALOG_Y - 5 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 5 * GRID_H;

      class Controls
      {
        class TabButton1 : A3A_Button
        {
          idc = 7003;
          text = "Tab 1";
          onButtonClick = "ctrlShow [7100, true]; ctrlShow [7200, false]";
          x = 0;
          y = 0;
          w = 20 * GRID_W;
          h = 4 * GRID_H;
        };

        class TabButton2 : A3A_Button
        {
          idc = 7004;
          text = "Tab 2";
          onButtonClick = "ctrlShow [7200, true]; ctrlShow [7100, false]";
          x = 20 * GRID_W;
          y = 0;
          w = 20 * GRID_W;
          h = 4 * GRID_H;
        };
      };
    };


    class Tab1 : A3A_DefaultControlsGroup
    {
      idc = 7100;
      show = true;

      class Controls
      {
        class TestText : A3A_Text
        {
          idc = 7101;
          text = "This is a test of the first tab.";
					x = 2 * GRID_W;
					y = 2 * GRID_H;
					w = 56 * GRID_W;
					h = 4 * GRID_H;
        };

        class TestPicture : A3A_Picture
        {
          idc = -1;
          text = "#(argb,8,8,3)color(0.13,0.54,0.21,0.8)";
          x = 2 * GRID_W;
          y = 8 * GRID_H;
          w = 12 * GRID_W;
          h = 8 * GRID_H;
        };

        class TestBox : A3A_Background
        {
          idc = -1;
          colorBackground[] = {0.13,0.54,0.21,0.8};
          x = 16 * GRID_W;
          y = 8 * GRID_H;
          w = 12 * GRID_W;
          h = 8 * GRID_H;
        };

        class TestButton : A3A_Button
        {
          idc = -1;
          text = "TEST";
          x = 2 * GRID_W;
          y = 18 * GRID_H;
          w = 12 * GRID_W;
          h = 8 * GRID_H;
        };

        class TestShortcutButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "TEST";
          x = 16 * GRID_W;
          y = 18 * GRID_H;
          w = 12 * GRID_W;
          h = 8 * GRID_H;
        };

        class TestButtonDisabled : A3A_Button
        {
          idc = 9000;
          text = "TEST";
          x = 2 * GRID_W;
          y = 32 * GRID_H;
          w = 12 * GRID_W;
          h = 8 * GRID_H;
        };

        class TestShortcutButtonDisabled : A3A_ShortcutButton
        {
          idc = 9001;
          text = "TEST";
          x = 16 * GRID_W;
          y = 32 * GRID_H;
          w = 12 * GRID_W;
          h = 8 * GRID_H;
        };

				/* class TestButton1 : A3A_ShortcutButton
        {
					text = "Test";
          x = 2 * GRID_W;
          y = 8 * GRID_H;
        };

				class TestButton2 : A3A_ShortcutButton
        {
					text = "Test Test Test Test";
          x = 2 * GRID_W;
          y = 16 * GRID_H;
					h = 12 * GRID_H;
        };

        class TestNewButton : A3A_Button
        {
          text = "Test";
          x = 2 * GRID_W;
          y = 30 * GRID_H;
        };

        class TestNewButtonDisabled : A3A_Button
        {
          text = "Test";
          x = 32 * GRID_W;
          y = 30 * GRID_H;
          onLoad = "(_this # 0) ctrlEnable false;";
        };

        class TestEdit : A3A_Edit
        {
          x = 88 * GRID_W;
          y = 2 * GRID_H;
          w = 50 * GRID_W;
          h = 4 * GRID_H;
        };

				class TestSlider : A3A_Slider
				{
					idc = 5001;
					x = 88 * GRID_W;
          y = 8 * GRID_H;
          w = 50 * GRID_W;
          h = 4 * GRID_H;
				};

        class TestListbox : A3A_Listbox
        {
          x = 88 * GRID_W;
          y = 16 * GRID_H;
          w = 35 * GRID_W;
          h = 20 * GRID_H;
          onLoad = "(_this # 0) lbAdd ""Listbox test""; (_this # 0) lbAdd ""Thing 2""; (_this # 0) lbAdd ""Thing 3""; (_this # 0) lbAdd ""Thing 4""; (_this # 0) lbAdd ""Thing 5""; (_this # 0) lbAdd ""Thing 6""; (_this # 0) lbAdd ""Thing 7""; (_this # 0) lbAdd ""Thing 8""; (_this # 0) lbAdd ""Thing 9""; (_this # 0) lbAdd ""Thing 10"";"
        };

        class TestListNBox : A3A_ListNBox
        {
          x = 125 * GRID_W;
          y = 16 * GRID_H;
          w = 35 * GRID_W;
          h = 20 * GRID_H;
          onLoad = "(_this # 0) lbAdd ""ListNBox test""; (_this # 0) lbAdd ""Thing 2""; (_this # 0) lbAdd ""Thing 3""; (_this # 0) lbAdd ""Thing 4""; (_this # 0) lbAdd ""Thing 5""; (_this # 0) lbAdd ""Thing 6""; (_this # 0) lbAdd ""Thing 7""; (_this # 0) lbAdd ""Thing 8""; (_this # 0) lbAdd ""Thing 9""; (_this # 0) lbAdd ""Thing 10"";"
        };

        class TestStructuredText : A3A_StructuredText
        {
          x = 2 * GRID_W;
          y = 50 * GRID_H;
          w = 80 * GRID_W;
          h = 46 * GRID_H;
          onLoad = "(_this # 0) ctrlSetStructuredText parseText ""<t size='0.5'>Testing testing structured text etc</t><br />More text without any tag and stuff."";";
        }; */
      };
    };

    class Tab2 : A3A_DefaultControlsGroup
    {
      idc = 7200;
      show = false;

      class Controls
      {
        class TestText : A3A_Text
        {
          idc = 7201;
          text = "This is a test of the second tab.";
					x = 2 * GRID_W;
					y = 2 * GRID_H;
					w = 56 * GRID_W;
					h = 4 * GRID_H;
        };

        class TestEdit : A3A_Edit
        {
          idc = 7202;
          x = 88 * GRID_W;
          y = 2 * GRID_H;
          w = 50 * GRID_W;
          h = 4 * GRID_H;
          onKeyDown = "[""editBoxChanged""] call A3A_fnc_testTabbedDialog";
        };

				class TestSlider : A3A_Slider
				{
					idc = 7203;
					x = 88 * GRID_W;
          y = 8 * GRID_H;
          w = 50 * GRID_W;
          h = 4 * GRID_H;
          onSliderPosChanged = "[""sliderChanged""] call A3A_fnc_testTabbedDialog";
				};

        class TestActiveText : A3A_ActiveText
        {
          idc = -1;
          text = "Testing ActiveText";
          x = 2 * GRID_W;
          y = 16 * GRID_H;
          w = 20 * GRID_W;
          h = 4 * GRID_H;
        };

        class TestActivePicture : A3A_ActivePicture
        {
          idc = -1;
          text = A3A_Icon_Destroy;
          x = 2 * GRID_W;
          y = 22 * GRID_H;
          w = 4 * GRID_W;
          h = 4 * GRID_H;
        };
      };
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = DIALOG_X + DIALOG_W * GRID_W - 5 * GRID_W;
      y = DIALOG_Y - 10 * GRID_H;
    };
  };
};
