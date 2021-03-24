class A3A_RequestMissionDialog : A3A_DefaultDialog
{
  idd = A3A_IDD_RequestMissionDialog;

  class Controls
  {
    class TitlebarText : A3A_Text
    {
      idc = -1;
      text = $STR_antistasi_dialogs_mission_request_titlebar;
      x = DIALOG_X;
      y = DIALOG_Y - 4 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 4 * GRID_H;
    };

    // Main content
    class MainContent : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_REQUESTMISSIONMAIN;

      class Controls
      {
        // Conquest
        class ConquestIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Conquest;
          x = 15 * GRID_W;
          y = 14 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class ConquestButton : A3A_Button
        {
          idc = -1;
          text = $STR_antistasi_dialogs_mission_request_conquest;
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 7 * GRID_W;
          y = 34 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        // Destroy
        class DestroyIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Destroy;
          x = 53 * GRID_W;
          y = 14 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class DestroyButton : A3A_Button
        {
          idc = -1;
          text = $STR_antistasi_dialogs_mission_request_destroy;
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 45 * GRID_W;
          y = 34 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        // Assasination
        class AssassinationIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Assassination;
          x = 91 * GRID_W;
          y = 14 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class AssassinationButton : A3A_Button
        {
          idc = -1;
          text = $STR_antistasi_dialogs_mission_request_assassination;
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 83 * GRID_W;
          y = 34 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        // Convoy
        class ConvoyIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Convoy_Ambush;
          x = 129 * GRID_W;
          y = 14 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class ConvoyButton : A3A_Button
        {
          idc = -1;
          text = $STR_antistasi_dialogs_mission_request_convoy;
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 121 * GRID_W;
          y = 34 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        // Rescue
        class RescueIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Rescue;
          x = 34 * GRID_W;
          y = 56 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class RescueButton : A3A_Button
        {
          idc = -1;
          text = $STR_antistasi_dialogs_mission_request_rescue;
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 26 * GRID_W;
          y = 76 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        // Logistics
        class LogisticsIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Logistics;
          x = 72 * GRID_W;
          y = 56 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class LogisticsButton : A3A_Button
        {
          idc = -1;
          text = $STR_antistasi_dialogs_mission_request_logistics;
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 64 * GRID_W;
          y = 76 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        // Support
        class SupportIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Logistics; // TODO: Make new icon
          x = 110 * GRID_W;
          y = 56 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class SupportButton : A3A_Button
        {
          idc = -1;
          text = $STR_antistasi_dialogs_mission_request_support;
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 102 * GRID_W;
          y = 76 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

      };
    };

    class CloseButton : A3A_CloseButton
    {
      idc = -1;
      x = DIALOG_X + DIALOG_W * GRID_W - 4 * GRID_W;
      y = DIALOG_Y - 4 * GRID_H;
    };
  };
};
