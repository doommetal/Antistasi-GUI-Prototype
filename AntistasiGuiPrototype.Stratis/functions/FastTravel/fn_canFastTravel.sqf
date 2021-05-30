/*
Maintainer: DoomMetal
    Checks if the player or a high command group is able to fast travel
    and gives a reason if not

Arguments:
    <UNIT/GROUP> The unit or group to check fast travel for

Return Value:
    ARRAY<BOOL, STRING> Returns true and "" if able to FT, false and reason if not

Scope: Local
Environment: Any
Public: Yes
Dependencies:
    None

Example:
    [] call A3A_fnc_canFastTravel; // [true, ""] or [false,"Reasons"]
*/

params ["_obj"];

private _ftNonPlayerObject = false;
private _ftNonHcGroup = false;
private _invalidTypeForFT = false;
private _isHighCommandGroup = false;
private _groupX = grpNull;

if (isNil "_obj") exitWith {
    hint "Error: _obj is nil"; // TODO: use Error()
};

// Check if object is the player or a HC group
// TODO: should probably use isEqualType instead, because fasterrr
switch (typeName _obj) do
{
    case ("OBJECT"):
    {
        if !(_obj == player) then {
            _ftNonPlayerObject = true;
        } else {
            _groupX = group player;
        };
    };

    case ("GROUP"):
    {
        if !(_obj in (hcAllGroups player)) then {
            _ftNonHcGroup = true;
        } else {
            _isHighCommandGroup = true;
            _groupX = _obj;
        };
    };

    default
    {
        _invalidTypeForFT = true;
    };
};

if (_ftNonPlayerObject) exitWith {
    [false, "Trying to fast travel a single object other than the player"];
};
if (_ftNonHcGroup) exitWith {
    [false, "Can't fast travel non-high command groups"];
};
if (_invalidTypeForFT) exitWith {
    hint ("invalid type for FT: " + typeName _obj); // TODO: replace with Error()
};

// private _checkForPlayer = false;
// if ((!_isHighCommandGroup) and limitedFT) then {_checkForPlayer = true};

// if ((leader _groupX != player) and (!_isHighCommandGroup)) then {_groupX = player};

// No high command groups with players
if (({isPlayer _x} count units _groupX > 1) and (_isHighCommandGroup)) exitWith {
    [false, "You can not fast travel High Command groups with players in them"];
};

// No FT while controlling AI
if (player != player getVariable ["owner",player]) exitWith {
    [false, "You can not fast travel while you are controlling AI"];
};

// No FT while in friendly fire jail
if (!isNil "A3A_FFPun_Jailed" && {(getPlayerUID player) in A3A_FFPun_Jailed}) exitWith {
    [false, "You can not fast travel while in friendly fire punishment"];
};

// Checks needed to be done for all group members
_result = [true, ""];
private _distanceX = 500; // Distance for enemies near check

// Reduce enemies near distance if it's foggy, was commented out before refactor so didn't touch it
//_distanceX = 500 - (([leader _groupX,false] call A3A_fnc_fogCheck) * 450);

{
    // Enemies near
    if ([_x,_distanceX] call A3A_fnc_enemyNearCheck) exitWith {
        _result = [false, "You cannot fast travel with enemies near the group"];
    };

    // If unit is in a vehicle
    if (vehicle _x != _x) then {
        // No tow ropes
        if !((vehicle _x getVariable "SA_Tow_Ropes") isEqualTo objNull) exitWith {
            _result = [false, "You cannot fast travel with your tow rope out or a vehicle attached"];
        };
        // No boats
        if ((typeOf (vehicle _x)) isKindOf "Ship") exitWith {
            _result = [false, "You cannot fast travel while any group members are in a boat"];
        };
        // No static weapons
        if ((typeOf (vehicle _x)) isKindOf "StaticWeapon") exitWith {
            _result = [false, "You cannot fast travel with group members in a static weapon"];
        };
        // No vehicles without drivers
        if (isNull (driver vehicle _x)) exitWith {
            _result = [false, "You do not have a driver in all the groups vehicles"];
        };
        // No immobile vehicles
        if (!canMove vehicle _x) exitWith {
            _result = [false, "You can not fast travel if your vehicle immobile"];
        };
    };
} forEach units _groupX;

_result;
