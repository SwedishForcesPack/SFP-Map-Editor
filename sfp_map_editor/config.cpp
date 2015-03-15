class CfgPatches
{
	class sfp_map_editor
	{
		weapons[] = {};
		requiredVersion = 0.1;
		author[] = { "Björn Dahlgren" };
		authorUrl = "https://github.com/dahlgren/";
		version = 1.0.0;
		versionStr = "1.0.0";
		versionAr[] = {1,0,0};
		
		#include "units.hpp"

		requiredAddons[] =
		{
			"A3_UI_F",
			"A3_UI_F_Curator",
			"A3_Functions_F",
			"A3_Functions_F_Curator",
			"A3_Modules_F",
			"A3_Modules_F_Curator"
		};
	};
};

class CfgFactionClasses
{
	class sfp_map_editor
	{
		displayname = "SFP Map Editor";
		priority = 8;
		side = 7;

		addon = "sfp_map_editor";

		class subCategories
		{
			class Objects
			{
				displayName = "Objects";
				moduleClass = "sfp_map_editor_module_empty";
			};

			class Persistence
			{
				displayName = "Persistence";
				moduleClass = "sfp_map_editor_module_empty";
			};
		};
	};
};

class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ModuleDescription
		{
			class AnyPlayer;
			class AnyBrain;
			class EmptyDetector;
		};
	};

	class sfp_map_editor_module_base : Module_F
	{
		mapSize = 1;
		author = "Björn Dahlgren";
		vehicleClass = "Modules";
		category = "sfp_map_editor";
		subCategory = "Persistence";
		side = 7;

		scope = 1;				// Editor visibility; 2 will show it in the menu, 1 will hide it.
		scopeCurator = 1;		// Curator visibility; 2 will show it in the menu, 1 will hide it.

		displayName = "SFP Map Editor";	// Name displayed in the menu
		icon = "\sfp_map_editor\data\icons\atlas_co.paa";
		picture = "\sfp_map_editor\data\icons\atlas_co.paa";
		portrait = "\sfp_map_editor\data\icons\atlas_co.paa";

		function = "";			// Name of function triggered once conditions are met
		functionPriority = 1;	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
		isGlobal = 2;			// 0 for server only execution, 1 for remote execution on all clients upon mission start, 2 for persistent execution
		isTriggerActivated = 0;	// 1 for module waiting until all synced triggers are activated
		isDisposable = 0;		// 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		// curatorInfoType = "RscDisplayAttributeModuleNuke";	// Menu displayed when the module is placed or double-clicked on by Zeus
		
		class Arguments {};
		class ModuleDescription: ModuleDescription
		{
			description = "SFP Map Editor";
		};
	};

	class sfp_map_editor_objects_module_base : sfp_map_editor_module_base
	{
		subCategory = "Objects";
	};
	
	class sfp_map_editor_persistence_module_base : sfp_map_editor_module_base
	{
		subCategory = "Persistence";
	};

	// Placeholder class that doesn't do anything. Used for generating categories in UI.
	class sfp_map_editor_module_empty : sfp_map_editor_module_base
	{
		category = "Curator";
		subCategory = "";
		mapSize = 0;
		displayName = "SFP Map Editor Module Empty";
		//icon = "";
		function = "sfp_map_editor_fnc_Empty";
	};

	#include "cfgVehiclesModulesObjects.hpp"
	#include "cfgVehiclesModulesPersistence.hpp"
};

class CfgFunctions
{
	#include "cfgFunctions.hpp"
};

#include "ui\baseDialogs.hpp"
#include "ui\copyObjectDialog.hpp"
