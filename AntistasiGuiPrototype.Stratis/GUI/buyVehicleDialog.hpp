class A3A_BuyVehicleDialog : A3A_DefaultDialog
{
  idd = A3A_IDD_BuyVehicleDialog;
  onLoad = "[""onLoad""] spawn A3A_fnc_buyVehicleDialog";

  class Controls
  {
    class TitlebarText : A3A_Text
    {
      idc = -1;
      text = "Buy Vehicle"; // TODO: localize
      x = DIALOG_X;
      y = DIALOG_Y - 4 * GRID_H;
      w = DIALOG_W * GRID_W;
      h = 4 * GRID_H;
    };

    // Main content
    class MainContent : A3A_DefaultControlsGroup
    {
      idc = A3A_IDC_BUYVEHICLEMAIN;

      class Controls
      {
        class VehiclesControlsGroup : A3A_ControlsGroupNoHScrollbars
        {
          idc = A3A_IDC_VEHICLESGROUP;
          x = 0;
          y = 4 * GRID_H;
          w = PX_W(DIALOG_W);
          h = PX_H(DIALOG_H) - 8 * GRID_H;
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
