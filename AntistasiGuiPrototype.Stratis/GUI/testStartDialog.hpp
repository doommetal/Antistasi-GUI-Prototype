class A3A_TestStartDialog : A3A_DefaultDialog
{
  idd = 7000;
  onLoad = "[""onLoad""] spawn A3A_fnc_testStartDialog";

  class Controls
  {
    class TitlebarText : A3A_TitlebarText
    {
      idc = 7001;
      text = "STARTUP OPTIONS";
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
        class TemplateSelectionLabel : A3A_Text
        {
          idc = -1;
          text = "Template selection";
					x = 8 * GRID_W;
					y = 3 * GRID_H;
					w = 42 * GRID_W;
					h = 4 * GRID_H;
        };

        class RebelsLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Rebels";
          x = 7 * GRID_W;
					y = 8 * GRID_H;
					w = 35 * GRID_W;
					h = 4 * GRID_H;
        };

        class RebelsListBox : A3A_Listbox
        {
          idc = 7102;
          // onLoad = "_this#0 lbAdd ""FIA (Vanilla)"";_this#0 lbAdd ""NAPA (RHS)"";_this#0 lbAdd ""SDK (RHS)"";_this#0 lbAdd ""Takistan Militia (3CB Factions)"";_this#0 lbAdd ""Armia Krajowa (IFA)"";_this#0 lbAdd ""FIA (CUP)"";";
          sizeEx = GUI_TEXT_SIZE_SMALL;
          rowHeight = GUI_TEXT_SIZE_SMALL;
          x = 7 * GRID_W;
					y = 12 * GRID_H;
					w = 35 * GRID_W;
					h = 48 * GRID_H;
        };

        class OccupantsLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Occupants";
          x = 44 * GRID_W;
					y = 8 * GRID_H;
					w = 35 * GRID_W;
					h = 4 * GRID_H;
        };

        class OccupantsListBox : RebelsListBox
        {
          idc = 7103;
          // onLoad = "_this#0 lbAdd ""NATO, arid (Vanilla)"";_this#0 lbAdd "" NATO, jungle (Vanilla)"";_this#0 lbAdd ""US Army, Temperate (RHS)"";_this#0 lbAdd ""British Army, Arid (3CB BAF)"";_this#0 lbAdd ""CDF (RHS)"";_this#0 lbAdd ""US Army (CUP)"";_this#0 lbAdd ""CDF (CUP)"";";
          x = 44 * GRID_W;
					y = 12 * GRID_H;
					w = 35 * GRID_W;
					h = 48 * GRID_H;
        };

        class InvadersLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Invaders";
          x = 81 * GRID_W;
					y = 8 * GRID_H;
					w = 35 * GRID_W;
					h = 4 * GRID_H;
        };

        class InvadersListBox : RebelsListBox
        {
          idc = 7104;
          // onLoad = "_this#0 lbAdd ""CSAT, arid (Vanilla)"";_this#0 lbAdd "" CSAT, jungle (Vanilla)"";_this#0 lbAdd ""VDV, Temperate (RHS)"";_this#0 lbAdd ""Takistan Army, Arid (3CB BAF)"";_this#0 lbAdd ""CDF (RHS)"";_this#0 lbAdd ""US Army (CUP)"";_this#0 lbAdd ""CDF (CUP)"";";
          x = 81 * GRID_W;
					y = 12 * GRID_H;
					w = 35 * GRID_W;
					h = 48 * GRID_H;
        };

        class CiviliansLabel : A3A_SectionLabelRight
        {
          idc = -1;
          text = "Civilians";
          x = 118 * GRID_W;
					y = 8 * GRID_H;
					w = 35 * GRID_W;
					h = 4 * GRID_H;
        };

        class CiviliansListBox : RebelsListBox
        {
          idc = 7105;
          // onLoad = "_this#0 lbAdd ""CSAT, arid (Vanilla)"";_this#0 lbAdd "" CSAT, jungle (Vanilla)"";_this#0 lbAdd ""VDV, Temperate (RHS)"";_this#0 lbAdd ""Takistan Army, Arid (3CB BAF)"";_this#0 lbAdd ""CDF (RHS)"";_this#0 lbAdd ""US Army (CUP)"";_this#0 lbAdd ""CDF (CUP)"";";
          x = 118 * GRID_W;
					y = 12 * GRID_H;
					w = 35 * GRID_W;
					h = 48 * GRID_H;
        };

        class StartButton : A3A_Button
        {
          idc = -1;
          text = "Start";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 118 * GRID_W;
					y = 77 * GRID_H;
					w = 35 * GRID_W;
					h = 16 * GRID_H;
        };
      };
    };

    // Close button

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = DIALOG_X + DIALOG_W * GRID_W - 5 * GRID_W;
      y = DIALOG_Y - 5 * GRID_H;
    };
  };
};
