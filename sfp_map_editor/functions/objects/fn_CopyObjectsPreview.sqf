// Call with [object, repeats, offsetX, offsetY, offsetZ]
private ["_obj","_objPos","_objDir"];
_objs = [];
for "_i" from 1 to (_this select 1) do {
	_obj = (typeOf (_this select 0)) createVehicleLocal (position (_this select 0));
	_obj attachTo [(_this select 0), [
		_i*(_this select 2),
		_i*(_this select 3),
		_i*(_this select 4)
	]];
	_objPos = getPosATL _obj;
	_objDir = getDir _obj;
	detach _obj;
	_obj setDir _objDir;
	_obj setPosATL _objPos;
	_objs pushBack _obj;
};
_objs;
