// Already in antistasi, don't merge

#define Log_Debug true
#define Log_Error true
#define Log_Trace true
#include "..\..\LogMacros.inc"

params ["_level"];

if(_level == 1) exitWith {"Low"};
if(_level == 2) exitWith {"Medium"};
if(_level == 3) exitWith {"High"};
if(_level == 4) exitWith {"Very High"};
if(_level == 5) exitWith {"Extreme"};

Error_1("Bad level recieved, cannot generate string, was %1", _level);
"None"
