/*
Maintainer: DoomMetal
    Handles the initialization and updating of the HQ Dialog
    This function should only be called from HqDialog onLoad and control activation EHs.

Arguments:
    <STRING> Mode, possible values for this dialog are "onLoad", "switchTab"
    <ARRAY<ANY>> Array of params for the mode when applicable. Params for specific modes are documented in the modes.

Return Value:
    Nothing

Scope: Clients, Local Arguments, Local Effect
Environment: Scheduled for onLoad mode / Unscheduled for everything else unless specified
Public: No
Dependencies:
    None

Example:
    ["onLoad"] spawn A3A_fnc_hqDialog; // initialization
    ["switchTab", ["garrison"]] call A3A_fnc_hqDialog; // switching to the garrison tab
*/

// disableSerialization; // TODO: Remove when merging
#include "..\..\GUI\ids.inc"
#include "..\..\GUI\defines.hpp"

// Logging
#define Log_Debug true
#define Log_Error true
#include "..\..\LogMacros.inc"

params[["_mode","onLoad"], ["_params",[]]];

switch (_mode) do
{
  case ("onLoad"):
  {
    Debug("HQ Dialog onLoad starting...");

    private _display = findDisplay A3A_IDD_HqDialog;

    // Hide HC group icons to stop them from interfering with map controls
    _display setVariable ["HCgroupIcons", groupIconsVisible];
    setGroupIconsVisible [false, false];
    setGroupIconsSelectable false;

    // Show main tab content
    ["switchTab", ["main"]] call A3A_fnc_hqDialog;

    // Button availability stuff
    // TODO: Get actual reasons when merging
    private _moveHqIcon = _display displayCtrl A3A_IDC_MOVEHQICON;
    _moveHqIcon ctrlSetTextColor ([A3A_COLOR_BUTTON_BACKGROUND_DISABLED] call A3A_fnc_configColorToArray);
    private _moveHqButton = _display displayCtrl A3A_IDC_MOVEHQBUTTON;
    _moveHqButton ctrlEnable false;
    _moveHqButton ctrlSetTooltip "Can't move HQ\n\nRemove items from ammo box first"; // TODO: localize later, not final yet

    // Faction money section setup
    private _factionMoneySlider = _display displayCtrl A3A_IDC_FACTIONMONEYSLIDER;
    private _factionMoney = server getVariable ["resourcesFIA", 0];
    _factionMoneySlider sliderSetRange [0,_factionMoney];
    _factionMoneySlider sliderSetSpeed [100, 100];
    _factionMoneySlider sliderSetPosition 0;

    // Rest section setup
    private _restSlider = _display displayCtrl A3A_IDC_RESTSLIDER;
    _restSlider sliderSetRange [0,24];
    _restSlider sliderSetSpeed [1,1];
    _restSlider sliderSetPosition 0;
    ["restSliderChanged"] spawn A3A_fnc_hqDialog;


    // Garrison tab

    // Get the data we need [Outpost name, position, icon, color (side)]
    private _outpostIconData = [];
    {
      _x params ["_marker", "_type", "_garrison"];
      private _name = markerText _marker;
      private _pos = getMarkerPos _marker;
      private _color = [0.1,0.7,0.1,1];

      private _icon = switch (_type) do {
        case ("hq"): {
          "\A3\ui_f\data\Map\Markers\Military\flag_CA.paa";
        };

        case ("outpost"): {
          "\A3\ui_f\data\Map\MapControl\bunker_CA.paa";
        };

        default {
          "\A3\ui_f\data\Map\MapControl\ruin_CA.paa.paa";
        };
      };

      _outpostIconData pushBack [_name, _pos, _icon, _color];
    } forEach outposts;

    Debug_1("Outpost Icon Data: %1", _outpostIconData);

    // Save the data to the map control to make it available in the draw EH
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;
    _garrisonMap setVariable ["outpostIconData", _outpostIconData];

    // Draw EH for outpost icons
    _garrisonMap ctrlAddEventHandler ["Draw","call A3A_fnc_outpostMarkersEH"];

    Debug("HqDialog onLoad complete.");
  };

  case ("onUnload"):
  {
    Debug("HqDialog onUnload starting...");
    private _display = findDisplay A3A_IDD_HqDialog;

    // Remove map drawing EH
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;
    _garrisonMap ctrlRemoveAllEventHandlers "Draw";

    // Restore HC group icons state
    private _groupIcons = _display getVariable ["HCgroupIcons", [false,false]];
    setGroupIconsVisible _groupIcons;
    setGroupIconsSelectable true;

    Debug("HqDialog onUnload complete.");
  };

  case ("switchTab"):
  {
    // Get selected tab
    private _selectedTab = _params select 0;

    Debug_1("HqDialog switching tab to %1.", _selectedTab);

    // Get IDC for selected tab
    private _selectedTabIDC = -1;
    switch (_selectedTab) do
    {
      case ("main"):
      {
        // No permission check needed
        _selectedTabIDC = A3A_IDC_HQDIALOGMAINTAB;
      };

      case ("garrison"):
      {
        _selectedTabIDC = A3A_IDC_HQDIALOGGARRISONTAB;
      };

      case ("minefields"):
      {
        _selectedTabIDC = A3A_IDC_HQDIALOGMINEFIELDSTAB;
      };
    };

    // Log attempt at accessing tab without permission
    if (_selectedTabIDC == -1) exitWith {
      Error("Attempted to access non-existant tab: %1", _selectedTab);
    };

    // Get display
    private _display = findDisplay A3A_IDD_HqDialog;

    // Array of IDCs for all the tabs, including subtabs (like AI & player management)
    // Garrison map is also hidden here, and shown again in updateCommanderTab
    private _allTabs = [
      A3A_IDC_HQDIALOGMAINTAB,
      A3A_IDC_GARRISONMAP,
      A3A_IDC_HQDIALOGGARRISONTAB,
      A3A_IDC_HQDIALOGMINEFIELDSTAB
      ];

    // Hide all tabs
    {
      private _ctrl = _display displayCtrl _x;
      _ctrl ctrlShow false;
    } forEach _allTabs;

    // Hide back button, enable in update tab mode when/if needed
    private _backButton = _display displayCtrl A3A_IDC_HQDIALOGBACKBUTTON;
    _backButton ctrlShow false;

    // Show selected tab
    private _selectedTabCtrl = _display displayCtrl _selectedTabIDC;
    _selectedTabCtrl ctrlShow true;

    switch (_selectedTab) do
    {
      case ("main"):
      {
        ["updateMainTab"] call A3A_fnc_hqDialog;
      };

      case ("garrison"):
      {
        ["updateGarrisonTab"] call A3A_fnc_hqDialog;
      };

      case ("minefields"):
      {
        ["updateMinefieldsTab"] call A3A_fnc_hqDialog;
      };
    };
  };

  case ("updateMainTab"):
  {
    _display = findDisplay A3A_IDD_HqDialog;

    // Update campaign status section
    // TODO: Get actual values here, placeholder totals from Altis
    private _controlledCities = 5;
    private _totalCities = 48;
    private _controlledOutposts = 4;
    private _totalOutposts = 44;
    private _controlledAirbases = 3;
    private _totalAirbases = 6;
    private _controlledResources = 2;
    private _totalResources = 8;
    private _controlledFactories = 1;
    private _totalFactories = 12;
    private _controlledSeaPorts = 0;
    private _totalPorts = 5;

    private _totalPopulation = totalPopulation; // TODO: replace with something like A3A_fnc_resourceCheck
    private _rebelPopulation = rebelPopulation;
    private _deadPopulation = deadPopulation;

    // TODO: Loop through map sites here (citiesX, airportsX, wtfAreOutpostsCalledAgain?, resourcesX, factories, seaports)

    // If we aren't changing tooltips runtime we don't need to get the icons here
    /* _controlledCitiesIcon = _display displayCtrl A3A_IDC_CONTROLLEDCITIESICON;
    _controlledOutpostsIcon = _display displayCtrl A3A_IDC_CONTROLLEDOUTPOSTSICON;
    _controlledAirbasesIcon = _display displayCtrl A3A_IDC_CONTROLLEDAIRBASESICON;
    _controlledResourcesIcon = _display displayCtrl A3A_IDC_CONTROLLEDRESOURCESICON;
    _controlledFactoriesIcon = _display displayCtrl A3A_IDC_CONTROLLEDFACTORIESICON;
    _controlledSeaPortsIcon = _display displayCtrl A3A_IDC_CONTROLLEDSEAPORTSICON; */

    _controlledCitiesText = _display displayCtrl A3A_IDC_CONTROLLEDCITIESTEXT;
    _controlledOutpostsText = _display displayCtrl A3A_IDC_CONTROLLEDOUTPOSTSTEXT;
    _controlledAirbasesText = _display displayCtrl A3A_IDC_CONTROLLEDAIRBASESTEXT;
    _controlledResourcesText = _display displayCtrl A3A_IDC_CONTROLLEDRESOURCESTEXT;
    _controlledFactoriesText = _display displayCtrl A3A_IDC_CONTROLLEDFACTORIESTEXT;
    _controlledSeaPortsText = _display displayCtrl A3A_IDC_CONTROLLEDSEAPORTSTEXT;

    _controlledCitiesText ctrlSetText format ["%1/%2", _controlledCities, _totalCities];
    _controlledOutpostsText ctrlSetText format ["%1/%2", _controlledOutposts, _totalOutposts];
    _controlledAirbasesText ctrlSetText format ["%1/%2", _controlledAirbases, _totalAirbases];
    _controlledResourcesText ctrlSetText format ["%1/%2", _controlledResources, _totalResources];
    _controlledFactoriesText ctrlSetText format ["%1/%2", _controlledFactories, _totalFactories];
    _controlledSeaPortsText ctrlSetText format ["%1/%2", _controlledSeaPorts, _totalPorts];


    // Update population status bar
    private _statusBarRebels = _display displayCtrl A3A_IDC_POPSTATUSBARREB;
    private _statusBarDead = _display displayCtrl A3A_IDC_POPSTATUSBARDEAD;

    // Calculate new positions for status bar
    private _rebelsBarWidth = (_rebelPopulation / _totalPopulation) * 50 * GRID_W;
    private _deadBarWidth = (_deadPopulation / _totalPopulation) * 50 * GRID_W;
    private _deadBarXpos = (50 * GRID_W) - _deadBarWidth;

    // Calculate and format percentages, 1 decimal space
    private _rebPercentage = (round ((_rebelPopulation / _totalPopulation) * 1000)) / 10;
    private _deadPercentage = (round ((_deadPopulation / _totalPopulation) * 1000)) / 10;

    private _rebText = _display displayCtrl A3A_IDC_POPSTATUSREBTEXT;
    private _deadText = _display displayCtrl A3A_IDC_POPSTATUSDEADTEXT;
    _rebText ctrlSetText (str _rebPercentage) + "%";
    _deadText ctrlSetText (str _deadPercentage) + "%";

    _statusBarRebels ctrlSetPosition [0, 0, _rebelsBarWidth, 6 * GRID_H];
    _statusBarRebels ctrlCommit 0;

    _statusBarDead ctrlSetPosition [_deadBarXpos, 0, _deadBarWidth, 6 * GRID_H];
    _statusBarDead ctrlCommit 0;


    // Update faction resources section
    private _hr = server getVariable ["hr", 0];
    private _trainingLevel = skillFIA;
    private _hrText = _display displayCtrl A3A_IDC_FACTIONHRTEXT;
    private _trainingText = _display displayCtrl A3A_IDC_FACTIONTRAININGTEXT;
    _hrText ctrlSetText str _hr;
    _trainingText ctrlSetText format ["%1 / 20", _trainingLevel];

    private _factionMoney = server getVariable ["resourcesFIA", 0];
    private _factionMoneyText = _display displayCtrl A3A_IDC_FACTIONMONEYTEXT;
    _factionMoneyText ctrlSetText format ["%1 €", _factionMoney];


    // TODO: Update rest section with current ingame time
  };

  case ("updateGarrisonTab"):
  {
    _display = findDisplay A3A_IDD_HqDialog;

    // Show map if not already visible
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;
    if (!ctrlShown _garrisonMap) then {_garrisonMap ctrlShow true;};

    // Simulate a map click event to select the garrison closest to the player
    ["garrisonMapClicked", [getPos player select 0, getPos player select 1]] spawn A3A_fnc_hqDialog;

    // Show back button
    private _backButton = _display displayCtrl A3A_IDC_HQDIALOGBACKBUTTON;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["main"]] call A3A_fnc_hqDialog;
    }];
    _backButton ctrlShow true;
  };

  case ("updateMinefieldsTab"):
  {
    _display = findDisplay A3A_IDD_HqDialog;

    // Show back button
    private _backButton = _display displayCtrl A3A_IDC_HQDIALOGBACKBUTTON;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["main"]] call A3A_fnc_hqDialog;
    }];
    _backButton ctrlShow true;
  };

  case ("restSliderChanged"):
  {
    private _display = findDisplay A3A_IDD_HqDialog;

    private _restSlider = _display displayCtrl A3A_IDC_RESTSLIDER;
    private _restText = _display displayCtrl A3A_IDC_RESTTEXT;
    private _time = sliderPosition _restSlider;
    private _restTimeString = [_time, "HM", true] call A3A_fnc_formatTime;
    private _postRestTime = daytime + _time;
    if (_postRestTime > 24) then {_postRestTime = _postRestTime - 24};
    private _postRestTimeString = [_postRestTime, "HH:MM"] call BIS_fnc_timeToString;
    private _message = format [localize "STR_antistasi_dialogs_hq_rest_text" + "<br />" + localize "STR_antistasi_dialogs_hq_wakeup_text", _restTimeString, _postRestTimeString];
    _restText ctrlSetStructuredText parseText _message;
  };

  case ("factionMoneySliderChanged"):
  {
    private _display = findDisplay A3A_IDD_HqDialog;
    private _factionMoneySlider = _display displayCtrl A3A_IDC_FACTIONMONEYSLIDER;
    private _factionMoneyEditBox = _display displayCtrl A3A_IDC_FACTIONMONEYEDITBOX;
    private _sliderValue = sliderPosition _factionMoneySlider;
    _factionMoneyEditBox ctrlSetText str floor _sliderValue;
  };

  case ("factionMoneyEditBoxChanged"):
  {
    private _display = findDisplay A3A_IDD_HqDialog;
    private _factionMoneyEditBox = _display displayCtrl A3A_IDC_FACTIONMONEYEDITBOX;
    private _factionMoneySlider = _display displayCtrl A3A_IDC_FACTIONMONEYSLIDER;
    private _factionMoneyEditBoxValue = floor parseNumber ctrlText _factionMoneyEditBox;
    private _factionMoney = server getVariable ["resourcesFIA", 0];
    _factionMoneyEditBox ctrlSetText str _factionMoneyEditBoxValue; // Strips non-numeric characters
    _factionMoneySlider sliderSetPosition _factionMoneyEditBoxValue;
    if (_factionMoneyEditBoxValue < 0) then {_factionMoneyEditBox ctrlSetText str 0};
    if (_factionMoneyEditBoxValue > _factionMoney) then {_factionMoneyEditBox ctrlSetText str _factionMoney};
  };

  case ("garrisonMapClicked"):
  {
    Debug_1("Garrison map clicked: %1", _params);
    // Find closest marker to the clicked position
    private _clickedPosition = [_params select 0, _params select 1];
    private _outposts = [];
    {
      _outposts pushBack _x # 0;
    } forEach outposts;
    private _selectedMarker = [_outposts, _clickedPosition] call BIS_fnc_nearestPosition;
    Debug_1("Selected marker: %1", _selectedMarker);
    private _position = getMarkerPos _selectedMarker;

    // Get the data from the marker
    private _garrisonName = markerText _selectedMarker;
    private _outpostData = [_selectedMarker] call A3A_fnc_getOutpostByMarkerName;
    private _type = _outpostData select 1;
    private _garrison = _outpostData select 2;
    _garrison params [
      "_rifleman",
      "_squadLeader",
      "_autorifleman",
      "_grenadier",
      "_medic",
      "_mortar",
      "_marksman",
      "_at"];

    // Get the controls
    private _display = findDisplay A3A_IDD_HqDialog;
    private _garrisonTitle = _display displayCtrl A3A_IDC_GARRISONTITLE;
    private _riflemanNumber = _display displayCtrl A3A_IDC_RIFLEMANNUMBER;
    private _squadleaderNumber = _display displayCtrl A3A_IDC_SQUADLEADERNUMBER;
    private _autoriflemanNumber = _display displayCtrl A3A_IDC_AUTORIFLEMANNUMBER;
    private _grenadierNumber = _display displayCtrl A3A_IDC_GRENADIERNUMBER;
    private _medicNumber = _display displayCtrl A3A_IDC_MEDICNUMBER;
    private _mortarNumber = _display displayCtrl A3A_IDC_MORTARNUMBER;
    private _marksmanNumber = _display displayCtrl A3A_IDC_MARKSMANNUMBER;
    private _atNumber = _display displayCtrl A3A_IDC_ATNUMBER;
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;

    // Add currently selected marker to map, we need it later for... stuff...
    _garrisonMap setVariable ["selectedMarker", _selectedMarker];

    // Update controls
    _garrisonTitle ctrlSetText _garrisonName;
    _riflemanNumber ctrlSetText str _rifleman;
    _squadleaderNumber ctrlSetText str _squadleader;
    _autoriflemanNumber ctrlSetText str _autorifleman;
    _grenadierNumber ctrlSetText str _grenadier;
    _medicNumber ctrlSetText str _medic;
    _mortarNumber ctrlSetText str _mortar;
    _marksmanNumber ctrlSetText str _marksman;
    _atNumber ctrlSetText str _at;

    // Draw selection marker
    private _radius = 64;
    private _dir = 0;

    // We need to save the position and animation state of the
    // selection marker between frames, so we do this in the map control itself
    _garrisonMap setVariable["data", [_position, _radius, _dir]];

    // Delete any old selection marker if it exists
    private _selectEH = _garrisonMap getVariable "selectEH";
    if !(isNil "_selectEH") then {
      _garrisonMap ctrlRemoveEventHandler ["Draw", _selectEH];
    };

    // Draw EH for the selection marker
    _selectEH = _garrisonMap ctrlAddEventHandler ["Draw","_this call A3A_fnc_outpostSelectEH"];

    // Save the selection Draw EH to the map control
    _garrisonMap setVariable ["selectEH", _selectEH];

    // Pan to location
    _garrisonMap ctrlMapAnimAdd [0.2, ctrlMapScale _garrisonMap, _position];
    ctrlMapAnimCommit _garrisonMap;
  };

  // Updating the garrison numbers
  // TODO: this needs to be generalized a bit for garrison update compatibility
  case ("garrisonAdd"):
  {
    private _type = _params select 0;
    private _num = _params select 1;

    private _display = findDisplay A3A_IDD_HqDialog;
    private _text = "";
    private _typeIndex = -1;
    switch (_type) do
    {
      case ("rifleman"): {
        _text = _display displayCtrl A3A_IDC_RIFLEMANNUMBER;
        _typeIndex = 0;
      };
      case ("squadleader"): {
          _text = _display displayCtrl A3A_IDC_SQUADLEADERNUMBER;
          _typeIndex = 1;
      };
      case ("autorifleman"): {
          _text = _display displayCtrl A3A_IDC_AUTORIFLEMANNUMBER;
          _typeIndex = 2;
      };
      case ("grenadier"): {
          _text = _display displayCtrl A3A_IDC_GRENADIERNUMBER;
          _typeIndex = 3;
      };
      case ("medic"): {
          _text = _display displayCtrl A3A_IDC_MEDICNUMBER;
          _typeIndex = 4;
      };
      case ("mortar"): {
          _text = _display displayCtrl A3A_IDC_MORTARNUMBER;
          _typeIndex = 5;
      };
      case ("marksman"): {
          _text = _display displayCtrl A3A_IDC_MARKSMANNUMBER;
          _typeIndex = 6;
      };
      case ("at"): {
          _text = _display displayCtrl A3A_IDC_ATNUMBER;
          _typeIndex = 7;
      };
    };

    private _val = parseNumber (ctrlText _text);
    private _newVal = _val + _num;
    _newVal = 0 max _newVal;
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;

    // Update garrison in outpost array
    private _selectedMarker = _garrisonMap getVariable "selectedMarker";
    if (_typeIndex != -1) then {
      {
        if ((_x select 0) == _selectedMarker) then {
          ((outposts select _forEachIndex) select 2) set [_typeIndex, _newVal];
        };
      } forEach outposts;
    };

    _text ctrlSetText str _newVal;
  };

  // TODO: Remove placeholder mode
  case ("debugChangeTime"): {
    private _display = findDisplay A3A_IDD_HqDialog;
    private _restSlider = _display displayCtrl A3A_IDC_RESTSLIDER;
    private _time = sliderPosition _restSlider;
    skipTime _time;
    closeDialog 1;
  };

  default {
      // Log error if attempting to call a mode that doesn't exist
      Error_1("HQ Dialog mode does not exist: %1", _mode);
  };
};
