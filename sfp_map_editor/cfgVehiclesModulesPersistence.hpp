class sfp_map_editor_persistence_save : sfp_map_editor_persistence_module_base
{
	scopeCurator = 2;
	displayName = "Save Objects";
	function = "sfp_map_editor_fnc_SaveData";
	icon = "\sfp_map_editor\data\icons\save_co.paa";
	portrait = "\sfp_map_editor\data\icons\save_co.paa";
};

class sfp_map_editor_persistence_restore : sfp_map_editor_persistence_module_base
{
	scope = 2;
	scopeCurator = 2;
	displayName = "Restore Objects";
	function = "sfp_map_editor_fnc_RestoreData";
	icon = "\sfp_map_editor\data\icons\restore_co.paa";
	portrait = "\sfp_map_editor\data\icons\restore_co.paa";
};

class sfp_map_editor_persistence_export : sfp_map_editor_persistence_module_base
{
	scopeCurator = 2;
	displayName = "Terrain Builder Export";
	function = "sfp_map_editor_fnc_ExportData";
	icon = "\sfp_map_editor\data\icons\export_co.paa";
	portrait = "\sfp_map_editor\data\icons\export_co.paa";
};