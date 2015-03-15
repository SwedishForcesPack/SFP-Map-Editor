#define MAIN_SCOPE_NAME "module_cleanup"
scopeName MAIN_SCOPE_NAME;

[_this select 0, _this select 1, _this select 2] call
{
	_logic = _this select 0;

	// If module was not dropped by the current curator, exit!
	if (!local _logic) then { breakTo MAIN_SCOPE_NAME; };
	if (!(_this select 2)) then { breakTo MAIN_SCOPE_NAME; };

	if (local _logic) then {
		{
			_x removeCuratorEditableObjects [[_logic], true];
		} forEach allCurators;
		deleteVehicle _logic;
	};

	// The code inside the module will actually run here...
