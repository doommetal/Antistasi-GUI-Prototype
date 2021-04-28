// Placeholder
// Already in Antistasi, don't merge!
if (player getVariable ["eligible", false]) then {
  [] spawn {
    sleep 10;
    theBoss = player;
  };
} else {
  theBoss = objNull;
};
