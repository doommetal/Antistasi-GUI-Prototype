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

    // TODO: Check for hq move availability
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

    // Garrison tab map drawing EHs
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;
    // Select marker
    _garrisonMap ctrlAddEventHandler ["Draw", "_this call A3A_fnc_mapDrawSelectEH"];
    // Outposts
    _garrisonMap ctrlAddEventHandler ["Draw","_this call A3A_fnc_mapDrawOutpostsEH"];

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

    // Update titlebar
    _titleBar = _display displayCtrl A3A_IDC_HQDIALOGTITLEBAR;
    _titleBar ctrlSetText localize "STR_antistasi_dialogs_hq_titlebar";

    // Update campaign status section
    // Uupdate war level & aggro
    private _warLevelText = _display displayCtrl A3A_IDC_WARLEVELTEXT;
    private _occupantsAggroText = _display displayCtrl A3A_IDC_OCCAGGROTEXT;
    private _invadersAggroText = _display displayCtrl A3A_IDC_INVAGGROTEXT;
    _warLevelText ctrlSetText str tierWar;
    _occupantsAggroText ctrlSetText ([aggressionOccupants] call A3A_fnc_getAggroLevelString);
    _invadersAggroText ctrlSetText ([aggressionInvaders] call A3A_fnc_getAggroLevelString);

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

    // Update titlebar
    _titleBar = _display displayCtrl A3A_IDC_HQDIALOGTITLEBAR;
    _titleBar ctrlSetText (localize "STR_antistasi_dialogs_hq_titlebar") + " > " + (localize "STR_antistasi_dialogs_hq_garrisons_titlebar");

    // Show back button
    private _backButton = _display displayCtrl A3A_IDC_HQDIALOGBACKBUTTON;
    _backButton ctrlRemoveAllEventHandlers "MouseButtonClick";
    _backButton ctrlAddEventHandler ["MouseButtonClick", {
      ["switchTab", ["main"]] call A3A_fnc_hqDialog;
    }];
    _backButton ctrlShow true;

    // Show map if not already visible
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;
    if (!ctrlShown _garrisonMap) then {_garrisonMap ctrlShow true;};

    /* // Get outpost data // TODO: Remove if not needed
    private _outposts = [];
    {
      _outposts pushBack _x # 0;
    } forEach markersX; */

    // Get selected marker
    private _selectedMarker = _garrisonMap getVariable ["selectedMarker", ""];

    // If no marker is selected (as in you just opened the garrison tab),
    // simulate a map click event to select HQ
    if (_selectedMarker isEqualTo "") exitWith
    {
      Trace("No marker selected, selecting HQ");
      _hqMapPos = _garrisonMap ctrlMapWorldToScreen (getMarkerPos "Synd_HQ");
      ["garrisonMapClicked", [_hqMapPos]] call A3A_fnc_hqDialog;
    };

    // Get the data from the marker
    private _position = getMarkerPos _selectedMarker;
    private _garrisonName = markerText _selectedMarker;
    private _outpostData = [_selectedMarker] call A3A_fnc_getOutpostByMarkerName;
    // private _type = _outpostData select 1; // TODO: Remove if not needed
    private _garrison = garrisons getVariable [_selectedMarker, []];
    _garrison params [
      "_rifleman",
      "_squadLeader",
      "_autorifleman",
      "_grenadier",
      "_medic",
      "_mortar",
      "_marksman",
      "_at"
    ];

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

    // Buttons
    _riflemanAddButton = _display displayCtrl A3A_IDC_RIFLEMANADDBUTTON;
    _riflemanSubButton = _display displayCtrl A3A_IDC_RIFLEMANSUBBUTTON;
    _squadleaderAddButton = _display displayCtrl A3A_IDC_SQUADLEADERADDBUTTON;
    _squadleaderSubButton = _display displayCtrl A3A_IDC_SQUADLEADERSUBBUTTON;
    _autoriflemanAddButton = _display displayCtrl A3A_IDC_AUTORIFLEMANADDBUTTON;
    _autoriflemanSubButton = _display displayCtrl A3A_IDC_AUTORIFLEMANSUBBUTTON;
    _grenadierAddButton = _display displayCtrl A3A_IDC_GRENADIERADDBUTTON;
    _grenadierSubButton = _display displayCtrl A3A_IDC_GRENADIERSUBBUTTON;
    _medicAddButton = _display displayCtrl A3A_IDC_MEDICADDBUTTON;
    _medicSubButton = _display displayCtrl A3A_IDC_MEDICSUBBUTTON;
    _mortarAddButton = _display displayCtrl A3A_IDC_MORTARADDBUTTON;
    _mortarSubButton = _display displayCtrl A3A_IDC_MORTARSUBBUTTON;
    _marksmanAddButton = _display displayCtrl A3A_IDC_MARKSMANADDBUTTON;
    _marksmanSubButton = _display displayCtrl A3A_IDC_MARKSMANSUBBUTTON;
    _atAddButton = _display displayCtrl A3A_IDC_ATADDBUTTON;
    _atSubButton = _display displayCtrl A3A_IDC_ATSUBBUTTON;

    _rebuildGarrisonButton = _display displayCtrl A3A_IDC_REBUILDGARRISONBUTTON;
    _dismissGarrisonButton = _display displayCtrl A3A_IDC_DISMISSGARRISONBUTTON;

    private _addSubButtons = [
      _riflemanAddButton,
      _riflemanSubButton,
      _squadleaderAddButton,
      _squadleaderSubButton,
      _autoriflemanAddButton,
      _autoriflemanSubButton,
      _grenadierAddButton,
      _grenadierSubButton,
      _medicAddButton,
      _medicSubButton,
      _mortarAddButton,
      _mortarSubButton,
      _marksmanAddButton,
      _marksmanSubButton,
      _atAddButton,
      _atSubButton
    ];

    // Reset ctrlEnable for all management buttons
    {_x ctrlEnable true; _x ctrlSetTooltip ""} forEach _addSubButtons;
    _rebuildGarrisonButton ctrlEnable true; // TODO: Check if rebuild is available under attacks, probably shouldn't be?
    _rebuildGarrisonButton ctrlSetTooltip "";
    _dismissGarrisonButton ctrlEnable true;
    _dismissGarrisonButton ctrlSetTooltip "";


    // Disable subtract buttons if number is < 1
    if (_rifleman < 1) then {_riflemanSubButton ctrlEnable false};
    if (_squadLeader < 1) then {_squadleaderSubButton ctrlEnable false};
    if (_autorifleman < 1) then {_autoriflemanSubButton ctrlEnable false};
    if (_grenadier < 1) then {_grenadierSubButton ctrlEnable false};
    if (_medic < 1) then {_medicSubButton ctrlEnable false};
    if (_mortar < 1) then {_mortarSubButton ctrlEnable false};
    if (_marksman < 1) then {_marksmanSubButton ctrlEnable false};
    if (_at < 1) then {_atSubButton ctrlEnable false};

    // TODO: Placeholder prices, replace with server getVariable ["SDKx"] on merge
    _riflemanPrice = 50;
    _squadLeaderPrice = 150;
    _autoriflemanPrice = 75;
    _grenadierPrice = 75;
    _medicPrice = 100;
    _mortarPrice = 650;
    _marksmanPrice = 100;
    _atPrice = 100;

    // Update price labels
    _riflemanPriceText = _display displayCtrl A3A_IDC_RIFLEMANPRICE;
    _squadLeaderPriceText = _display displayCtrl A3A_IDC_SQUADLEADERPRICE;
    _autoriflemanPriceText = _display displayCtrl A3A_IDC_AUTORIFLEMANPRICE;
    _grenadierPriceText = _display displayCtrl A3A_IDC_GRENADIERPRICE;
    _medicPriceText = _display displayCtrl A3A_IDC_MEDICPRICE;
    _mortarPriceText = _display displayCtrl A3A_IDC_MORTARPRICE;
    _marksmanPriceText = _display displayCtrl A3A_IDC_MARKSMANPRICE;
    _atPriceText = _display displayCtrl A3A_IDC_ATPRICE;

    _riflemanPriceText ctrlSetText str _riflemanPrice + "€";
    _squadLeaderPriceText ctrlSetText str _squadLeaderPrice + "€";
    _autoriflemanPriceText ctrlSetText str _autoriflemanPrice + "€";
    _grenadierPriceText ctrlSetText str _grenadierPrice + "€";
    _medicPriceText ctrlSetText str _medicPrice + "€";
    _mortarPriceText ctrlSetText str _mortarPrice + "€";
    _marksmanPriceText ctrlSetText str _marksmanPrice + "€";
    _atPriceText ctrlSetText str _atPrice + "€";

    // Disable add buttons if faction is lacking the resources to recruit them (1HR + money)
    _hr = server getVariable ["hr", 0];
    _factionMoney = server getVariable ["resourcesFIA", 0];
    if (_factionMoney < _riflemanPrice || _hr < 1) then {_riflemanAddButton ctrlEnable false; _riflemanAddButton ctrlSetTooltip "Not enough money/HR"}; // TODO: localize
    if (_factionMoney < _squadLeaderPrice || _hr < 1) then {_squadleaderAddButton ctrlEnable false; _squadleaderAddButton ctrlSetTooltip "Not enough money/HR"};
    if (_factionMoney < _autoriflemanPrice || _hr < 1) then {_autoriflemanAddButton ctrlEnable false; _autoriflemanAddButton ctrlSetTooltip "Not enough money/HR"};
    if (_factionMoney < _grenadierPrice || _hr < 1) then {_grenadierAddButton ctrlEnable false; _grenadierAddButton ctrlSetTooltip "Not enough money/HR"};
    if (_factionMoney < _medicPrice || _hr < 1) then {_medicAddButton ctrlEnable false; _medicAddButton ctrlSetTooltip "Not enough money/HR"};
    if (_factionMoney < _mortarPrice || _hr < 1) then {_mortarAddButton ctrlEnable false; _mortarAddButton ctrlSetTooltip "Not enough money/HR"};
    if (_factionMoney < _marksmanPrice || _hr < 1) then {_marksmanAddButton ctrlEnable false; _marksmanAddButton ctrlSetTooltip "Not enough money/HR"};
    if (_factionMoney < _atPrice || _hr < 1) then {_atAddButton ctrlEnable false; _atAddButton ctrlSetTooltip "Not enough money/HR"};

    // Disable any management buttons if garrison is under attack
    // TODO: This is very placeholdery atm, replace with A3A_fnc_enemyNearCheck on merge
    private _garrisonUnderAttack = false;
    if (_selectedMarker isEqualTo "outpost_1") then {_garrisonUnderAttack = true};
    if (_garrisonUnderAttack) then {
      {
        _x ctrlEnable false;
        _x ctrlSetTooltip "Can't manage garrisons when outpost is under attack."; // TODO: localize
      } forEach _addSubButtons;

      _rebuildGarrisonButton ctrlEnable false;
      _rebuildGarrisonButton ctrlSetTooltip "Can't manage garrisons when outpost is under attack.";
      _dismissGarrisonButton ctrlEnable false;
      _dismissGarrisonButton ctrlSetTooltip "Can't manage garrisons when outpost is under attack.";
    };

    // Pan to location
    _garrisonMap ctrlMapAnimAdd [0.2, ctrlMapScale _garrisonMap, _position];
    ctrlMapAnimCommit _garrisonMap;
  };

  case ("updateMinefieldsTab"):
  {
    _display = findDisplay A3A_IDD_HqDialog;

    // Update titlebar
    _titleBar = _display displayCtrl A3A_IDC_HQDIALOGTITLEBAR;
    _titleBar ctrlSetText (localize "STR_antistasi_dialogs_hq_titlebar") + " > " + (localize "STR_antistasi_dialogs_hq_minefields_titlebar");

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
    private _display = findDisplay A3A_IDD_HqDialog;
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;
    // Find closest marker to the clicked position
    _params params ["_clickedPosition"];
    private _clickedWorldPosition = _garrisonMap ctrlMapScreenToWorld _clickedPosition;
    private _selectedMarker = [markersX, _clickedWorldPosition] call BIS_fnc_nearestPosition;
    Debug_1("Selected marker: %1", _selectedMarker);

    _markerMapPosition = _garrisonMap ctrlMapWorldToScreen (getMarkerPos _selectedMarker);
    private _maxDistance = 8 * GRID_W; // TODO: Move somewhere else?
    private _distance = _clickedPosition distance _markerMapPosition;
    if (_distance > _maxDistance) exitWith
    {
      Debug("Distance too large, no selection change.");
    };

    _garrisonMap setVariable ["selectedMarker", _selectedMarker];
    private _position = getMarkerPos _selectedMarker;
    _garrisonMap setVariable ["selectMarkerData", [_position, 48, 0]];

    ["updateGarrisonTab"] call A3A_fnc_hqDialog;
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
        if (_x isEqualTo _selectedMarker) then {

          private _garrison = garrisons getVariable [_selectedMarker, []];
          _garrison set [_typeIndex, _newVal];
          garrisons setVariable [_selectedMarker, _garrison];
        };
      } forEach markersX;
    };

    _text ctrlSetText str _newVal;

    ["updateGarrisonTab"] call A3A_fnc_hqDialog;
  };

  case ("dismissGarrison"):
  {
    // TODO: on merge replace this with actual antistasi function
    Trace("Dismissing garrison");
    private _display = findDisplay A3A_IDD_HqDialog;
    private _garrisonMap = _display displayCtrl A3A_IDC_GARRISONMAP;
    private _selectedMarker = _garrisonMap getVariable ["selectedMarker", ""];
    if (_selectedMarker isEqualTo "") exitWith {Error("Dismiss garrison: No marker selected")};

    // Set all garrison values to 0
    {
      if (_x == _selectedMarker) then {
        garrisons setVariable [_x, [0,0,0,0,0,0,0,0]];
      };
    } forEach markersX;

    ["updateGarrisonTab"] call A3A_fnc_hqDialog;

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
