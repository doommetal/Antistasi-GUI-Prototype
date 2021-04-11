// TODO: Update header
// Gets a groups vehicle
// Split from A3A_fnc_vehStats

// Logging
#define Log_Debug true
#define Log_Error true
#include "..\..\LogMacros.inc"

params [["_groupX",grpNull]];


if !((typeName _groupX) isEqualTo "GROUP") exitWith {
  Error_1("%1 is not a group", _groupX);
  objNull;
};

if (isNull _groupX) exitWith {
  Error("Group is null");
  objNull;
};

_vehicle = objNull;
{
  _owner = _x getVariable "owner";
  if (!isNil "_owner") then {if (_owner == _groupX) exitWith {_vehicle = _x}};
} forEach vehicles;

if (isNull _vehicle) then {
  {
    if ((vehicle _x != _x) and (_x == driver _x) and !(vehicle _x isKindOf "StaticWeapon")) exitWith {_vehicle = vehicle _x};
  } forEach units _groupX;
};

_vehicle
