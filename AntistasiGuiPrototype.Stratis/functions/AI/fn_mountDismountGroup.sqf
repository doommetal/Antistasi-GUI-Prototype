/*
Maintainer: DoomMetal
    Mounts / Dismounts high command groups

Arguments:
    <GROUP> A high command group

Return Value:
    None

Scope: Any, Local Arguments, Global Effect
Environment: Any
Public: Yes
Dependencies:
    None

Example:
    [_someGroup] call A3A_fnc_mountdismountGroup;
*/

// This function was part of A3A_fnc_vehStats

#include "..\..\Includes\common.inc"
FIX_LINE_NUMBERS()

params [["_groupX",grpNull]];


if !((typeName _groupX) isEqualTo "GROUP") exitWith {
  Error_1("%1 is not a group", _groupX);
};

if (isNull _groupX) exitWith {
  Error("Group is null");
};

_textX = "";

_veh = objNull;
{
  _owner = _x getVariable "owner";
  if (!isNil "_owner") then {if (_owner == _groupX) exitWith {_veh = _x}};
} forEach vehicles;

if !(isNull _veh) then {
  // If the vehicle has 1 or more non-FFV turrets then it's not a transport
  _isTransport = true;
  if (count allTurrets [_veh, false] > 0) then {_isTransport = false};

  if (_isTransport) then {
    if (leader _groupX in _veh) then {
      _textX = format ["%2%1 dismounting<br/>",groupID _groupX,_textX];
      {[_x] orderGetIn false; [_x] allowGetIn false} forEach units _groupX;
    } else {
      _textX = format ["%2%1 boarding<br/>",groupID _groupX,_textX];
      {[_x] orderGetIn true; [_x] allowGetIn true} forEach units _groupX;
    };

  } else {
    if (leader _groupX in _veh) then {
      _textX = format ["%2%1 dismounting<br/>",groupID _groupX,_textX];
      if (canMove _veh) then {
        {[_x] orderGetIn false; [_x] allowGetIn false} forEach assignedCargo _veh;
      } else {
        _veh allowCrewInImmobile false;
        {[_x] orderGetIn false; [_x] allowGetIn false} forEach units _groupX;
      }
    } else {
      _textX = format ["%2%1 boarding<br/>",groupID _groupX,_textX];
      {[_x] orderGetIn true; [_x] allowGetIn true} forEach units _groupX;
    };
  };
};

if (_textX != "") then {["Vehicle Info", format ["%1",_textX]] call A3A_fnc_customHint;};
