_candidateUnit = _this;
_result = false;
{
	_zeusUnit = getAssignedCuratorUnit _x;
	if(_candidateUnit == _zeusUnit) exitWith { _result = true };
} foreach allCurators;

_result;
