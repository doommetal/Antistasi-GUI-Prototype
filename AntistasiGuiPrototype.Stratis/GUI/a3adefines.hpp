/*
This file contains all Antistasi-specific GUI definitions.
The default defines.hpp is loaded first in description.ext for fallback.
*/

#include "GUI_IDS.inc"

// Input pixel grid units, output dimension in Proprietary Arma Units™
#define PX_W(n) n*GRID_W
#define PX_H(n) n*GRID_H


// Input dimension of box in pixel grid units, output the top left corner coords
// in Proprietary Arma Units™
// Used to center elements on the screen and then add units in pixelGrid to it for layout
#define CENTER_X(n) ((getResolution select 2) * 0.5 * pixelW) - (0.5 * (PX_W(n)))
#define CENTER_Y(n) ((getResolution select 3) * 0.5 * pixelH) - (0.5 * (PX_H(n)))


// Colors
#define COLOR_TITLEBAR\
  "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",\
  "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",\
  "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",\
  "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
#define COLOR_TITLEBAR_TEXT {0.95,0.95,0.95,1}
#define COLOR_ERROR_TEXT {0.5,0,0,1}


// Overriding the default text sizes because we're using pixelGrid
// Might change these to use antistasi specific names if this proves troublesome
// Still, *nothing* should use text sizes not based on pixelGrid
#define GUI_TEXT_SIZE_SMALL (GRID_H * 3.2) // Fits inside 3*GRID_H
#define GUI_TEXT_SIZE_MEDIUM (GRID_H * 4.2)  // Fits inside 4*GRID_H
#define GUI_TEXT_SIZE_LARGE (GRID_H * 5) // Fits inside 6*GRID_H


// Background boxes

class A3A_MainBackground
{
  idc = -1;
  type = CT_STATIC;
  style = 0;
  colorBackground[] = {0.1,0.1,0.1,0.7};
  colorShadow[] = {0,0,0,0.5};
  colorText[] = {1,1,1,1};
  shadow = 1;
  SizeEx = "0";
  font = "RobotoCondensed";
  text = "";
};

class A3A_TitleBackground
{
  idc = -1;
  type = CT_STATIC;
  style = 0;
  colorBackground[] = {COLOR_TITLEBAR};
  colorShadow[] = {0,0,0,0.5};
  colorText[] = {1,1,1,1};
  shadow = 1;
  SizeEx = "0";
  font = "RobotoCondensed";
  text = "";
};

class A3A_TabsBackground
{
  idc = -1;
  type = CT_STATIC;
  style = 0;
  colorBackground[] = {0,0,0,1};
  colorShadow[] = {0,0,0,0.5};
  colorText[] = {1,1,1,1};
  shadow = 1;
  SizeEx = "0";
  font = "RobotoCondensed";
  text = "";
};


// Title bar text

class A3A_TitleText : RscText
{
  idc = -1;
  style = ST_UPPERCASE;
  font = "PuristaMedium";
  sizeEx = GUI_TEXT_SIZE_MEDIUM;
  colorText[] = COLOR_TITLEBAR_TEXT;
};


// Buttons

class A3A_ShortcutButton : RscShortcutButton
{
  idc = -1;
  style = "0x02 + 0xC0"; // ST_CENTER + ST_UPPERCASE

  animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
  animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
  animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
  animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
  animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
  animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
  textureNoShortcut = "#(argb,8,8,3)color(0,0,0,0)";

  color[] = {1,1,1,1};
  color2[] = {0,0,0,1};
  color2Secondary[] = {0,0,0,1};
  colorBackground[] = {0,0,0,0.8};
  colorBackground2[] = {0.75,0.75,0.75,1};
  colorBackgroundFocused[] = {1,1,1,1};
  colorDisabled[] = {1,1,1,0.25};
  colorDisabledSecondary[] = {1,1,1,0.25};
  colorFocused[] = {0,0,0,1};
  colorFocusedSecondary[] = {0,0,0,1};
  colorSecondary[] = {1,1,1,1};
  colorText[] = {1,1,1,1};

  period = 1.2;
  periodFocus = 1.2;
  periodOver = 1.2;
  shadow = 0;

  size = GUI_TEXT_SIZE_MEDIUM;
  sizeEx = GUI_TEXT_SIZE_MEDIUM;
  sizeExSecondary = GUI_TEXT_SIZE_MEDIUM;

  class Attributes
  {
    align = "left";
    color = "#E5E5E5"; // TODO: Replace
    font = "PuristaLight";
    shadow = "false";
  };

  class TextPos // Defaults for GUI_TEXT_SIZE_MEDIUM
  {
    left = 2 * GRID_W;
    right = 2 * GRID_W;
    top = 1 * GRID_H;
    bottom = 1 * GRID_W;
  };
};

class A3A_TabButton : A3A_ShortcutButton
{
  idc = -1;
  class TextPos
  {
    left = 2 * GRID_W;
    right = 2 * GRID_W;
    top = 0;
    bottom = 0;
  };
};


// Section labels

class A3A_SectionLabelLeft : RscText
{
  style = ST_RIGHT;
  colorBackground[] = {0,0,0,1};
  colorShadow[] = {0,0,0,0.5};
  colorText[] = {1,1,1,1};
  sizeEx = GUI_TEXT_SIZE_MEDIUM;
};

class A3A_SectionLabelRight : RscText
{
  style = ST_LEFT;
  colorBackground[] = {0,0,0,1};
  colorShadow[] = {0,0,0,0.5};
  colorText[] = {1,1,1,1};
  sizeEx = GUI_TEXT_SIZE_MEDIUM;
};


// Groups / Compositions

class A3A_Tabs : RscControlsGroupNoScrollbars
{
  idc = -1;

  // Position and size needs to be specified in the dialog it's used in
  // because of it's reliance on DIALOG_W and DIALOG_H
  x = 0;
  y = 0;
  w = 0;
  h = 0;

  class controls
  {
    class PlayerTabButton : A3A_TabButton
    {
      idc = A3A_IDC_PLAYERTABBUTTON;
      text = "Player";
      action = "[] spawn A3A_fnc_playerDialog;";
      x = 0;
      y = 0;
      w = 32 * GRID_W;
      h = 4 * GRID_H;
    };

    class CommanderTabButton : A3A_TabButton
    {
      idc = A3A_IDC_COMMANDERTABBUTTON;
      text = "Commander";
      action = "[] spawn A3A_fnc_commanderDialog;";
      x = 32 * GRID_W;
      y = 0;
      w = 32 * GRID_W;
      h = 4 * GRID_H;
    };

    class AdminTabButton : A3A_TabButton
    {
      idc = A3A_IDC_ADMINTABBUTTON;
      text = "Admin";
      action = "[] spawn A3A_fnc_adminDialog;";
      x = 64 * GRID_W;
      y = 0;
      w = 32 * GRID_W;
      h = 4 * GRID_H;
    };
  };
};

class A3A_CloseButton : RscActivePicture
{
  idc = -1;
  text = "\A3\ui_f\data\GUI\RscCommon\RscButtonSearch\search_end_ca.paa";
  action = "closeDialog 2";
  shadow = 0;
  w = 4 * GRID_W;
  h = 4 * GRID_H;
};

class A3A_BackButton : A3A_CloseButton
{
  idc = -1;
  text = "\A3\ui_f\data\GUI\RscCommon\RscHTML\arrow_left_ca.paa";
  action = ""; // Must be defined in the specific dialogs
};

class A3A_InfoText : RscText
{
  sizeEx = GUI_TEXT_SIZE_SMALL;
  shadow = 2;

};

class A3A_InfoTextRight : A3A_InfoText
{
  style = ST_RIGHT; // Can't set styles from scrips so we do it here
};

class A3A_BuildButtonTemplate : RscControlsGroupNoScrollbars
{
  idc = -1;
  x = 8 * GRID_W;
  y = 8 * GRID_H;
  w = 44 * GRID_W;
  h = 37 * GRID_H;

  class controls
  {
    class Preview : RscPicture
    {
      idc = -1;
      colorBackground[] = {0,0,0,0};
      text = "\A3\EditorPreviews_F_Argo\Data\CfgVehicles\Land_Barricade_01_4m_F.jpg";
      x = 0;
      y = 0;
      w = 44 * GRID_W;
      h = 25 * GRID_H;
    };

    class CButton : A3A_ShortcutButton
    {
      idc = -1;
      // style = "0x01 + 0x04 + 0xC0"; // Adjust down right + uppercase
      text = "Barricade (4m) Long Name Is Long";
      x = 0;
      y = 25 * GRID_H;
      w = 44 * GRID_W;
      h = 12 * GRID_H;

      class TextPos
      {
        left = 2 * GRID_W;
        right = 2 * GRID_W;
        top = 1 * GRID_H;
        bottom = 1 * GRID_W;
      };
    };

    class PriceTag : RscText
    {
      text = "50000 €";
      // sizeEx = GUI_TEXT_SIZE_SMALL;
      x = 1 * GRID_W;
      y = 1 * GRID_H;
      w = 20 * GRID_W;
      h = 4 * GRID_H;
    }
  };
};
