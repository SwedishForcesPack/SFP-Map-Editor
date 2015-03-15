class sfp_map_editor_objects_copy : sfp_map_editor_objects_module_base
{
	scopeCurator = 1;
	displayName = "Copy object";
	function = "sfp_map_editor_fnc_CopyObject";
	icon = "\sfp_map_editor\data\icons\copy_co.paa";
	portrait = "\sfp_map_editor\data\icons\copy_co.paa";
};

class sfp_map_editor_objects_limit : sfp_map_editor_objects_module_base
{
	scope = 1;
	scopeCurator = 1;
	displayName = "Limit objects";
	function = "sfp_map_editor_fnc_LimitObjects";
};

class sfp_map_editor_objects_position : sfp_map_editor_objects_module_base
{
	scopeCurator = 1;
	displayName = "Position object";
	function = "sfp_map_editor_fnc_PositionObject";
};
