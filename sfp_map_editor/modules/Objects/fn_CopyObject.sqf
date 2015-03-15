#include "\sfp_map_editor\module_header.hpp";

_unitUnderCursor = call sfp_map_editor_fnc_GetUnitUnderCursor;

if (not isNull _unitUnderCursor) then
{
	// create the dialog
	disableSerialization;
	createDialog "sfp_map_editor_copy_object_dialog";
	waitUntil {dialog};
	_display = findDisplay 123;

	_offsetXEdit = _display displayCtrl 1101;
	_offsetXSlider = _display displayCtrl 1102;
	_offsetXText = _display displayCtrl 1103;

	_offsetYEdit = _display displayCtrl 1201;
	_offsetYSlider = _display displayCtrl 1202;
	_offsetYText = _display displayCtrl 1203;

	_offsetZEdit = _display displayCtrl 1301;
	_offsetZSlider = _display displayCtrl 1302;
	_offsetZText = _display displayCtrl 1303;

	_numberOfElementsEdit = _display displayCtrl 1401;
	_numberOfElementsSlider = _display displayCtrl 1402;
	_numberOfElementsText = _display displayCtrl 1403;

	// Reset dialog
	_offsetXEdit ctrlSetText "0";
	_offsetXSlider sliderSetRange [0, 100];
	_offsetXSlider sliderSetPosition 0;

	_offsetYEdit ctrlSetText "0";
	_offsetYSlider sliderSetRange [0, 100];
	_offsetYSlider sliderSetPosition 0;

	_offsetZEdit ctrlSetText "0";
	_offsetZSlider sliderSetRange [0, 100];
	_offsetZSlider sliderSetPosition 0;

	_numberOfElementsEdit ctrlSetText "0";
	_numberOfElementsSlider sliderSetRange [0, 100];
	_numberOfElementsSlider sliderSetPosition 0;
	_numberOfElementsSlider sliderSetSpeed [1, 1];

	copyObjects = false;
	_currentObjs = [];
	_offsetX = sliderPosition _offsetXSlider;
	_offsetY = sliderPosition _offsetYSlider;
	_offsetZ = sliderPosition _offsetZSlider;
	_numberOfElements = sliderPosition _numberOfElementsSlider;

	while {dialog} do {
		_offsetX = sliderPosition _offsetXSlider;
		_offsetY = sliderPosition _offsetYSlider;
		_offsetZ = sliderPosition _offsetZSlider;
		_numberOfElements = sliderPosition _numberOfElementsSlider;

		_offsetXEdit ctrlSetText str _offsetX;
		_offsetYEdit ctrlSetText str _offsetY;
		_offsetZEdit ctrlSetText str _offsetZ;
		_numberOfElementsEdit ctrlSetText str _numberOfElements;

		{
			deleteVehicle _x;
		} forEach _currentObjs;

		_currentObjs = [_unitUnderCursor, _numberOfElements, _offsetX, _offsetY, _offsetZ] call sfp_map_editor_fnc_CopyObjectsPreview;
		
		sleep 0.2;
	};

	{
		deleteVehicle _x;
	} forEach _currentObjs;

	if (copyObjects) then {
		_objs = [_unitUnderCursor, _numberOfElements, _offsetX, _offsetY, _offsetZ] call sfp_map_editor_fnc_CopyObjects;
		[[_objs, allCurators], "sfp_map_editor_fnc_AddObjectsToCurators", false] spawn BIS_fnc_MP;
	};
}
else
{
	[objnull, "No unit under cursor."] call bis_fnc_showCuratorFeedbackMessage;
};

#include "\sfp_map_editor\module_footer.hpp";
