// Returns info about a group
// Group name, position, alive/combat ready counts, vehicle status etc.
// Mostly rewritten stuff from REINF/fn_vehStats.sqf
// TODO: This might be a good idea to split up into multiple functions

/* Current return layout:
  [
  0: The group itself, object
  1: groupID, i.e. the display name, string
  2: group leader, object
  3: units, array
  4: leader position, position
  5: alive units count, number
  6: combat-ready units count, number
  7: current task (will be implemented when merging), string
  8: combat mode ("behaviour"), string
  9: has medic, bool
  10: has AT, bool
  11: has AA, bool
  12: has mortar, bool
  13: mortar deployed, bool
  14: has static weapon, bool
  15: static deployed, bool
  16: vehicle (not yet implemented)
  ]
*/

params[["_group", grpNull]];

if (_group == grpNull) exitWith {
  diag_log ["fn_getGroupInfo: No group specified"];
};

_groupID = groupID _group;
_groupLeader = leader _group;
_units = units _group;
_position = position _groupLeader;
_aliveUnits = {alive _x} count _units;
_ableToCombat = {[_x] call A3A_fnc_canFight} count _units;
_task = "N/A"; // TODO: Update when merging: _x getVariable ["taskX","Patrol"]
_combatMode = behaviour _groupLeader;
_hasOperativeMedic = {[_x] call A3A_fnc_isMedic} count _units > 0;
_hasAt = {_x call A3A_fnc_typeOfSoldier == "ATMan"} count _units > 0;
_hasAa = {_x call A3A_fnc_typeOfSoldier == "AAMan"} count _units > 0;

// Mortars and statics
_hasMortar = false;
_mortarDeployed = false;
_hasStatic = false;
_staticDeployed = false;

// If the group has variable mortarsX OR if any of the units has a mortar
if (!(isNull(_group getVariable ["mortarsX",objNull])) or ({_x call A3A_fnc_typeOfSoldier == "StaticMortar"} count _units > 0)) then {
  _hasMortar = true;
	if ({vehicle _x isKindOf "StaticWeapon"} count _units > 0) then {
    _mortarDeployed = true;
  };
} else {
  // Check for static weapons
	if ({_x call A3A_fnc_typeOfSoldier == "StaticGunner"} count _units > 0) then {
    _hasStatic = true;
		if ({vehicle _x isKindOf "StaticWeapon"} count _units > 0) then {
			_staticDeployed = true;
		};
	};
};

// TODO: Get group vehicle
_groupVehicle = false;

[_group, _groupID, _groupLeader, _units, _position, _aliveUnits, _ableToCombat, _task, _combatMode, _hasOperativeMedic, _hasAt, _hasAa, _hasMortar, _mortarDeployed, _hasStatic, _staticDeployed, _groupVehicle];
