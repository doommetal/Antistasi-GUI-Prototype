// Placeholder
// Already in antistasi, don't merge!

if (player getVariable ["eligible", false]) then {
  player setVariable ["eligible", false];
} else {
  player setVariable ["eligible", true];
};

// Will remove current boss if now ineligible
[] call A3A_fnc_assignBossIfNone;
