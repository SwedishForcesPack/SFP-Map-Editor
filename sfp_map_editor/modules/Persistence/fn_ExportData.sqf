#include "\sfp_map_editor\module_header.hpp";

_curator = allCurators select 0;
_datetime = "sfp_map_editor" callExtension "datetime";
_filename = format ["export_%1_%2.txt", toLower(worldName), _datetime];

[curatorEditableObjects _curator, _filename, 200000, 0] call sfp_map_editor_fnc_ExportObjects;

#include "\sfp_map_editor\module_footer.hpp";
