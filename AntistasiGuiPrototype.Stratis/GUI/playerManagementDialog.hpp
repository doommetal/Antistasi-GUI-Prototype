class A3A_PlayerManagementDialog
{
  idd = A3A_IDD_PLAYERMANAGEMENTDIALOG;

  #define DIALOG_W 160
  #define DIALOG_H 100

  class controls {
    class TitleText : A3A_TitleText
    {
      idc = -1;
      text = "ADMIN OPTIONS > PLAYER MANAGEMENT";
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
      w = PX_W(DIALOG_W);
      h = 4 * GRID_H;
    };

    class BackButton : A3A_BackButton
    {
      idc = -1;
      action = "[] spawn A3A_fnc_adminDialog";
      x = CENTER_X(DIALOG_W) + PX_W(DIALOG_W) - 9 * GRID_W;
      y = CENTER_Y(DIALOG_H) - 8 * GRID_H;
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

    class MainContent : RscControlsGroupNoScrollbars
    {
      idc = -1;
      x = CENTER_X(DIALOG_W);
      y = CENTER_Y(DIALOG_H);
      w = PX_W(DIALOG_W);
      h = PX_H(DIALOG_H);

      class controls
      {
        // Start of controls
        class NameLabel : RscText
        {
          text = "Name";
          x = 9 * GRID_W;
          y = 8 * GRID_W;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class DistanceLabel : RscText
        {
          text = "Distance";
          x = 74 * GRID_W;
          y = 8 * GRID_W;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class UIDLabel : RscText
        {
          text = "PlayerUID";
          x = 89 * GRID_W;
          y = 8 * GRID_W;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class PlayerList : ctrlListNbox
        {
          idc = A3A_IDC_PLAYERLIST;
          x = 8 * GRID_W;
          y = 12 * GRID_W;
          w = 106 * GRID_W;
          h = 82 * GRID_H;
          onLBSelChanged = "[""listBoxSelectionChanged""] spawn A3A_fnc_playerManagementDialog";

          sizeEx = GUI_TEXT_SIZE_MEDIUM;
          rowHeight = 4 * GRID_H;
          columns[] = {0,0.615,0.755};
        };

        class AddMemberButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_ADDMEMBERBUTTON;
          text = "Add Member";
          action = "[""addMember""] spawn A3A_fnc_playerManagementDialog";
          show = false;
          x = 120 * GRID_W;
          y = 8 * GRID_W;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class RemoveMemberButton : A3A_ShortcutButton
        {
          idc = A3A_IDC_REMOVEMEMBERBUTTON;
          text = "Remove Member";
          action = "[""removeMember""] spawn A3A_fnc_playerManagementDialog";
          show = false;
          x = 120 * GRID_W;
          y = 8 * GRID_W;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class TeleportToPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Teleport to Player";
          x = 120 * GRID_W;
          y = 28 * GRID_W;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class TeleportPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Teleport Player to Me";
          x = 120 * GRID_W;
          y = 48 * GRID_W;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class KickPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Kick Player";
          x = 120 * GRID_W;
          y = 68 * GRID_W;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class BanPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Ban Player";
          x = 120 * GRID_W;
          y = 88 * GRID_W;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };



        class SizeTestGroup : RscControlsGroupNoScrollbars
        {
          x = 0;
          y = 0;
          w = PX_W(DIALOG_W);
          h = PX_H(DIALOG_H);
          show = false;

          class controls
          {
            class TestText1 : RscText
            {
              text = "GUI_TEXT_SIZE_SMALL -  Goes in a box with 3xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_SMALL;
              x = 0;
              y = 0;
              w = 80 * GRID_W;
              h = 3 * GRID_H;
            };

            class TestText2 : RscText
            {
              idc = 22001;
              text = "GUI_TEXT_SIZE_MEDIUM - Goes in a box with 4xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_MEDIUM;
              x = 0;
              y = 9 * GRID_H;
              w = 80 * GRID_W;
              h = 4 * GRID_H;
            };

            class TestText3 : RscText
            {
              text = "GUI_TEXT_SIZE_LARGE - Goes in a box with 6xGRID_H";
              colorBackground[] = {0,0,0,0.5};
              sizeEx = GUI_TEXT_SIZE_LARGE;
              x = 0;
              y = 18 * GRID_H;
              w = 80 * GRID_W;
              h = 6 * GRID_H;
            };

            class GridBox1 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 8 * GRID_H;
              w = GRID_W;
              h = GRID_H;
            };

            class GridBox2 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 16 * GRID_H;
              w = 2 * GRID_W;
              h = 2 * GRID_H;
            };

            class GridBox4 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 24 * GRID_H;
              w = 4 * GRID_W;
              h = 4 * GRID_H;
            };
            class GridBox8 : RscText
            {
              text = "";
              colorBackground[] = {0,0,0,0.5};
              x = 84 * GRID_W;
              y = 32 * GRID_H;
              w = 8 * GRID_W;
              h = 8 * GRID_H;
            };

            class TestButtonSmall : A3A_ShortcutButton
            {
              text = "Small Button 1 Line";
              size = GUI_TEXT_SIZE_SMALL;
              x = 8 * GRID_W;
              y = 50 * GRID_H;
              w = 30 * GRID_W;
              h = 5 * GRID_H;

              class textPos
              {
                left = 1 * GRID_W;
                right = 1 * GRID_H;
                top = 1 * GRID_W;
                bottom = 1* GRID_H;
              };
            };

            class TestButtonSmall2 : A3A_ShortcutButton
            {
              text = "Small Button 2 Line";
              size = GUI_TEXT_SIZE_SMALL;
              x = 42 * GRID_W;
              y = 50 * GRID_H;
              w = 16 * GRID_W;
              h = 8 * GRID_H;

              class textPos
              {
                left = 1 * GRID_W;
                right = 1 * GRID_H;
                top = 1 * GRID_W;
                bottom = 1* GRID_H;
              };
            };
          };
        };

        // End of main content controls
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

    class PlayerListBackground : A3A_MainBackground
    {
      colorBackground[] = {0,0,0,0.5};
      x = CENTER_X(DIALOG_W) +  8 * GRID_W;
      y = CENTER_Y(DIALOG_H) +  12 * GRID_W;
      w = 106 * GRID_W;
      h = 82 * GRID_H;
    };
  };
};
