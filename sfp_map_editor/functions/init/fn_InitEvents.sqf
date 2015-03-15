// Only worry about doing this if we're not a dedicated server. Dedicated servers don't get UI.
if(isServer && isDedicated) exitWith {};

[] spawn {
	[] call sfp_map_editor_fnc_waitForZeus;

	{
		_x addEventHandler ["CuratorGroupPlaced", { _this call sfp_map_editor_fnc_GrpPlaced; }];
		_x addEventHandler ["CuratorObjectPlaced", { _this call sfp_map_editor_fnc_ObjPlaced; }];
	} forEach allCurators;

	if(!(player call sfp_map_editor_fnc_isZeus)) exitWith {};

	[player, "sfp_map_editor_fnc_PlayerConnected", false] call BIS_fnc_MP;
};
