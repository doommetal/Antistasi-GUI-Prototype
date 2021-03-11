class A3A_RecruitDialog : A3A_DefaultDialog
{
  idd = A3A_IDD_RecruitDialog;
  // onLoad = "[""onLoad""] spawn A3A_fnc_buyVehicleDialog";

  class Controls
  {
    class TitlebarText : A3A_Text
    {
      idc = -1;
      text = "Recruit Units";
      x = DIALOG_X;
      y = DIALOG_Y - 4 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 4 * GRID_H;
    };

    // Main content
    class MainContent : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_RECRUITMAIN;

      class Controls
      {
        class RiflemanIcon : A3A_Picture
        {
          idc = -1;
          colorText[]= {0.7,0.7,0.7,1};
          text = A3A_Tex_Icon_Rifleman;
          x = 24 * GRID_W;
          y = 13 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class RiflemanPriceText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          shadow = 2;
          x = 24 * GRID_W;
          y = 19 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class RiflemanButton : A3A_Button
        {
          idc = -1;
          text = "Rifleman";
          sizeEx = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 11 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class AutoriflemanIcon : A3A_Picture
        {
          idc = -1;
          colorText[]= {0.7,0.7,0.7,1};
          text = A3A_Tex_Icon_Autorifleman;
          x = 24 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AutoriflemanPriceText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          shadow = 2;
          x = 24 * GRID_W;
          y = 40 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class AutoriflemanButton : A3A_Button
        {
          idc = -1;
          text = "Autorifleman";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 32 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class GrenadierIcon : A3A_Picture
        {
          idc = -1;
          colorText[]= {0.7,0.7,0.7,1};
          text = A3A_Tex_Icon_Grenadier;
          x = 24 * GRID_W;
          y = 55 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class GrenadierPriceText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          shadow = 2;
          x = 24 * GRID_W;
          y = 61 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class GrenadierButton : A3A_Button
        {
          idc = -1;
          text = "Grenadier";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 53 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class AtIcon : A3A_Picture
        {
          idc = -1;
          colorText[]= {0.7,0.7,0.7,1};
          text = A3A_Tex_Icon_AT;
          x = 24 * GRID_W;
          y = 76 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class AtPriceText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          shadow = 2;
          x = 24 * GRID_W;
          y = 82 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class AtButton : A3A_Button
        {
          idc = -1;
          text = "AT";
          size = GUI_TEXT_SIZE_LARGE;
          x = 36 * GRID_W;
          y = 74 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class MedicIcon : A3A_Picture
        {
          idc = -1;
          colorText[]= {0.7,0.7,0.7,1};
          text = A3A_Tex_Icon_Heal;
          x = 128 * GRID_W;
          y = 13 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class MedicPriceText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          shadow = 2;
          x = 128 * GRID_W;
          y = 19 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class MedicButton : A3A_Button
        {
          idc = -1;
          text = "Medic";
          size = GUI_TEXT_SIZE_LARGE;
          x = 88 * GRID_W;
          y = 11 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class MarksmanIcon : A3A_Picture
        {
          idc = -1;
          colorText[]= {0.7,0.7,0.7,1};
          text = A3A_Tex_Icon_Sniper;
          x = 128 * GRID_W;
          y = 34 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class MarksmanPriceText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          shadow = 2;
          x = 128 * GRID_W;
          y = 40 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class MarksmanButton : A3A_Button
        {
          idc = -1;
          text = "Marksman";
          size = GUI_TEXT_SIZE_LARGE;
          x = 88 * GRID_W;
          y = 32 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class EngineerIcon : A3A_Picture
        {
          idc = -1;
          colorText[]= {0.7,0.7,0.7,1};
          text = A3A_Tex_Icon_Construct;
          x = 128 * GRID_W;
          y = 55 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class EngineerPriceText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          shadow = 2;
          x = 128 * GRID_W;
          y = 61 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class EngineerButton : A3A_Button
        {
          idc = -1;
          text = "Engineer";
          size = GUI_TEXT_SIZE_LARGE;
          x = 88 * GRID_W;
          y = 53 * GRID_H;
          w = 36 * GRID_W;
          h = 12 * GRID_H;
        };

        class BombSpecialistIcon : A3A_Picture
        {
          idc = -1;
          colorText[]= {0.7,0.7,0.7,1};
          text = A3A_Tex_Icon_Bomb_Specialist;
          x = 128 * GRID_W;
          y = 76 * GRID_H;
          w = 8 * GRID_W;
          h = 8 * GRID_H;
        };

        class BombSpecialistPriceText : A3A_Text
        {
          idc = -1;
          style = ST_CENTER;
          text = "€ 5000";
          shadow = 2;
          x = 128 * GRID_W;
          y = 82 * GRID_H;
          w = 8 * GRID_W;
          h = 4 * GRID_H;
        };

        class BombSpecialistButton : A3A_Button
        {
          idc = -1;
          text = "Bomb Specialist";
          size = GUI_TEXT_SIZE_LARGE;
          x = 88 * GRID_W;
          y = 74 * GRID_H;
          w = 36 * GRID_W;
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
