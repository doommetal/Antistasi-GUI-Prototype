/*
  Returns an array with numbers of vehicle positions

  Params:
    0 : String - classname of vehicle

  Returns
    Array :
      0 - driver
      1 - commander
      2 - gunners
      3 - passengers (includes FFV seats)
      4 - FFV seats
*/

params ["_class"];

private _cfg = configFile >> "CfgVehicles" >> _class;

private _driver = getNumber (_cfg >> "hasDriver");
private _commander = 0;
private _transportSoldier = getNumber (_cfg >> "transportSoldier");
private _turrets = 0; // gunners or commanders, does not include ffv
private _ffvTurrets = 0; // turrets with showAsCargo = 1
private _allTurrets = 0;

private _fnc_turrets =
{
	{
    _allTurrets = _allTurrets + 1;
		if !(getNumber (_x >> "showAsCargo") > 0) then {_turrets = _turrets + 1} else {_ffvTurrets = _ffvTurrets + 1};
    if (getNumber (_x >> "primaryObserver") > 0) then {_commander = _commander + 1};
		if (isClass (_x >> "Turrets")) then {_x call _fnc_turrets};
	}
	forEach ("true" configClasses (_this >> "Turrets"));
};
_cfg call _fnc_turrets;

_gunners = _turrets - _commander;
_passengers = _allTurrets + _transportSoldier - _commander - _gunners;
_passengersFFV = _passengers - _transportSoldier;

[_driver, _commander, _gunners, _passengers, _passengersFFV];
