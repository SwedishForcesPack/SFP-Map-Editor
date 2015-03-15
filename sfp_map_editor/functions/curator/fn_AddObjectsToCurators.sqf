_objs = _this select 0;
_curators = _this select 1;

{
	_x addCuratorEditableObjects [_objs, true];
} forEach _curators;
