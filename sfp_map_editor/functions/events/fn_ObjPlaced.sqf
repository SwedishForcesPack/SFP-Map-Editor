_curator = _this select 0;
_placedObject = _this select 1;

sfp_map_editor_CuratorObjectPlaced_UnitUnderCursor = curatorMouseOver;
sfp_map_editor_CuratorObjectPlaces_LastPlacedObjectPosition = position _placedObject;

[[[_placedObject], (allCurators - [_curator])],"sfp_map_editor_fnc_AddObjectsToCurators", false] spawn BIS_fnc_MP;

nil
