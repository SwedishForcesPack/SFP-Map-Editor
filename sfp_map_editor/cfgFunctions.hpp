class sfp_map_editor // This bit will be prefixed when actually calling the function (e.g. "Ares_fnc_...." )
{
	class init
	{
		file = "\sfp_map_editor\functions\init";
		class InitEvents {
        	preInit = 1;
        };
	};

    class events {
    	file = "\sfp_map_editor\functions\events";
    	class GrpPlaced {};
        class ObjPlaced {};
        class PlayerConnected {};
    };

    class objects {
    	file = "\sfp_map_editor\functions\objects";
        class CopyObjects {};
        class CopyObjectsPreview {};
        class ExportObjects {};
        class GetUnitUnderCursor {};
    };

    class persistence {
        file = "\sfp_map_editor\functions\persistence";
        class RestoreDataServer {};
        class SaveDataServer {};
    };

    class curator {
    	file = "\sfp_map_editor\functions\curator";
    	class AddObjectsToCurators {};
    	class IsZeus {};
    	class WaitForZeus {};
    };

	// Functions to perform module actions
	class modules
	{
		file = "\sfp_map_editor\modules";
		class Empty {};
	};
	
	#include "cfgFunctionsObjects.hpp"
	#include "cfgFunctionsPersistence.hpp"
};
