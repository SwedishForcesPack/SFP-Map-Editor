if (("sfp_map_editor" callExtension "version") != "") then {
	_curator = allCurators select 0;
	{
		_obj = _x;
		{
			_x removeCuratorEditableObjects [[_obj], true];
		} foreach allCurators;
		deleteVehicle _x;
	} forEach curatorEditableObjects _curator;

	_world = worldName;
	
	"sfp_map_editor" callExtension (format ["openRead;sfp_map_editor_save_%1.txt", toLower(worldName)]);

	_row = "sfp_map_editor" callExtension "read";
	while {_row != ""} do {
		_value = call compile _row;
		if (count _value >= 4) then {
			_className = _value select 0;
			_pos = _value select 1;
			_vectorDir = _value select 2;
			_vectorUp = _value select 3;

			_obj = _className createVehicle [1000000, 1000000, 1000000];
			_obj setPosATL _pos;
			_obj setVectorDirAndUp [_vectorDir, _vectorUp];

			[[[_obj], allCurators], "sfp_map_editor_fnc_AddObjectsToCurators", false] spawn BIS_fnc_MP;
		};

		_row = "sfp_map_editor" callExtension "read";
	};

	["Objects restored", "hint"] call BIS_fnc_MP;
} else {
	["Server needs sfp_map_editor.dll for the restore feature", "hint"] call BIS_fnc_MP;
};

true;
