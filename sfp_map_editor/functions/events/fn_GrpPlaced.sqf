_curator = _this select 0;
_placed = _this select 1;

[[(units _placed), (allCurators - [_curator])], "sfp_map_editor_fnc_AddObjectsToCurators", false] spawn BIS_fnc_MP;

nil
