// param 0: STR - Marker
// Returns: [Marker name (STR), Garrison (Array <int>)]]

params ["_marker"];

_outpost = [];
{
  if (_x select 0 == _marker) then {
    _outpost = _x;
  };
} forEach outposts;
_outpost;
