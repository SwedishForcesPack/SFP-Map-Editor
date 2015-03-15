_curator = getAssignedCuratorLogic _this;
_otherCurators = allCurators - [_curator];

if (count _otherCurators > 0) then {
	_otherCurator = _otherCurators select 0;
	 
	[[(curatorEditableObjects _otherCurator), [_curator]],"sfp_map_editor_fnc_AddObjectsToCurators", false] spawn BIS_fnc_MP;
};
