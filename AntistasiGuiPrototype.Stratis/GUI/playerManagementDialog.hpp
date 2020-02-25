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
          y = 8 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class DistanceLabel : RscText
        {
          text = "Distance";
          x = 74 * GRID_W;
          y = 8 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class UIDLabel : RscText
        {
          text = "PlayerUID";
          x = 89 * GRID_W;
          y = 8 * GRID_H;
          w = 16 * GRID_W;
          h = 4 * GRID_W;
          sizeEx = GUI_TEXT_SIZE_MEDIUM;
        };

        class PlayerList : ctrlListNbox
        {
          idc = A3A_IDC_PLAYERLIST;
          x = 8 * GRID_W;
          y = 12 * GRID_H;
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
          y = 7 * GRID_H;
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
          y = 7 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class TeleportToPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Teleport to Player";
          x = 120 * GRID_W;
          y = 22 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class TeleportPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Teleport Player to Me";
          x = 120 * GRID_W;
          y = 37 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class KickPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Kick Player";
          x = 120 * GRID_W;
          y = 52 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class BanPlayerButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Ban Player";
          x = 120 * GRID_W;
          y = 67 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class CopyIdButton : A3A_ShortcutButton
        {
          idc = -1;
          text = "Copy UID to Clipboard";
          x = 120 * GRID_W;
          y = 82 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
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
      y = CENTER_Y(DIALOG_H) +  12 * GRID_H;
      w = 106 * GRID_W;
      h = 82 * GRID_H;
    };
  };
};
