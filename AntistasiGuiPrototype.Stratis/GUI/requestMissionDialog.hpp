class A3A_RequestMissionDialog : A3A_DefaultDialog
{
  idd = A3A_IDD_RequestMissionDialog;

  class Controls
  {
    class TitlebarText : A3A_Text
    {
      idc = -1;
      text = "Request Mission";
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
        class AssassinationIcon : A3A_Picture
        {
          idc = -1;
          text = A3A_Tex_Icon_Assassination;
          x = 24 * GRID_W;
          y = 10 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class AssassinationButton : A3A_Button
        {
          idc = -1;
          text = "Assassination"; // TODO: localize
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 16 * GRID_W;
          y = 30 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class LogisticsIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Logistics;
          x = 72 * GRID_W;
          y = 10 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class LogisticsButton : A3A_Button
        {
          idc = -1;
          text = "Logistics"; // TODO: localize
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 64 * GRID_W;
          y = 30 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class ConvoyIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Convoy_Ambush;
          x = 120 * GRID_W;
          y = 10 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class ConvoyButton : A3A_Button
        {
          idc = -1;
          text = "Convoy Ambush"; // TODO: localize
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 112 * GRID_W;
          y = 30 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class ConquestIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Conquest;
          x = 24 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class ConquestButton : A3A_Button
        {
          idc = -1;
          text = "Conquest"; // TODO: localize
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 16 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class DestroyIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Destroy;
          x = 72 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class DestroyButton : A3A_Button
        {
          idc = -1;
          text = "Destroy"; // TODO: localize
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 64 * GRID_W;
          y = 70 * GRID_H;
          w = 32 * GRID_W;
          h = 12 * GRID_H;
        };

        class RescueIcon : A3A_Picture
        {
          idc = -1;
          colorBackground[] = {0,0,0,0};
          text = A3A_Tex_Icon_Rescue;
          x = 120 * GRID_W;
          y = 50 * GRID_H;
          w = 16 * GRID_W;
          h = 16 * GRID_H;
        };

        class RescueButton : A3A_Button
        {
          idc = -1;
          text = "Rescue"; // TODO: localize
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 112 * GRID_W;
          y = 70 * GRID_H;
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
