// disableSerialization; // TODO UI-update: Test without this to see if it's actually needed

#include "..\..\GUI\ids.inc"
#include "..\..\GUI\defines.hpp"
#include "..\..\Includes\common.inc"
FIX_LINE_NUMBERS()

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do
{
  case ("onLoad"):
  {
    private _display = findDisplay 7000;
    Trace_1("testStartDialog onLoad display: ", _display);
    private _rebelsListbox = _display displayCtrl 7102;
    Trace_1("testStartDialog rebelsListbox: ", _rebelsListbox);
    private _occupantsListbox = _display displayCtrl 7103;
    private _invadersListbox = _display displayCtrl 7104;
    private _civiliansListbox = _display displayCtrl 7105;

    private _rebelsList = [
      "Vanilla FIA, Arid",
      "Vanilla FIA, Enoch",
      "Vanilla SDK, Tanoa",
      "RHS NAPA, Arid",
      "RHS NAPA, Temperate"
    ];

    private _aiList = [
      "Vanilla AAF, Arid",
      "Vanilla CSAT, Arid",
      "Vanilla CSAT, Tropical",
      "Vanilla LDF, Enoch",
      "Vanilla NATO, Arid",
      "Vanilla NATO, Temperate",
      "Vanilla NATO, Tropical",
      "Vanilla CSAT, Enoch",
      "RHS USAF Marines , Temperate",
      "RHS AFRF, Arid",
      "RHS AFRF, Temperate",
      "RHS CDF, Temperate",
      "RHS USAF Army, Arid",
      "RHS USAF Army, Temperate",
      "RHS USAF Marines, Arid"
    ];

    private _civiliansList = [
      "Vanilla Civilians",
      "RHS, Civilians"
    ];

    {
      _rebelsListbox lbAdd _x;
    } forEach _rebelsList;

    {
      _occupantsListbox lbAdd _x;
      _invadersListbox lbAdd _x;
    } forEach _aiList;

    {
      _civiliansListbox lbAdd _x;
    } forEach _civiliansList;
  };
};
