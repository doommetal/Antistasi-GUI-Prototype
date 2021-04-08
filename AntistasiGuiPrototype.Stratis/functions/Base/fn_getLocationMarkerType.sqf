// TODO: Update header
params ["_marker"];

private _markerType = "";
switch (true) do
{
  case (_marker in citiesX): {_markerType = "city"};
  case (_marker in outposts): {_markerType = "outpost"};
  case (_marker in airportsX): {_markerType = "airport"};
  case (_marker in factories): {_markerType = "factory"};
  case (_marker in resourcesX): {_markerType = "resource"};
  case (_marker in seaports): {_markerType = "seaport"};
  case (_marker isEqualTo "Synd_HQ"): {_markerType = "hq"};
};
_markerType;
