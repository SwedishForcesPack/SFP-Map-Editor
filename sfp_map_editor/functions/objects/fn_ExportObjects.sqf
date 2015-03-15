_objs = _this select 0;
_filename = _this select 1;
_easting = _this select 2;
_northing = _this select 3;

if (("sfp_map_editor" callExtension "version") != "") then {
	"sfp_map_editor" callExtension (format ["openWrite;%1", _filename]);

	{
		_className = typeOf _x;
		_model = getText (configFile >> "CfgVehicles" >> _className >> "model");
		_pitchBank = _x call BIS_fnc_getPitchBank;
		_pos = getPosATL _x;

		while {_model find "\" >= 0} do {
			_pathToUse = (_model find "\") + 1;
			_modelLength = count _model;
			_newLength = _modelLength - _pathToUse;
			_model = _model select [_pathToUse, _newLength];
		};

		while {_model find ".p3d" >= 0} do {
			_modelLength = count _model;
			_newLength = _modelLength - 4;
			_model = _model select [0, _newLength];
		};

		_templateName = toLower _model;
		_posX = (_pos select 0) + _easting;
		_posY = (_pos select 1) + _northing;
		_yaw = getDir _x;
		_pitch = _pitchBank select 0;
		_roll = _pitchBank select 1;
		_scale = 1.0;
		_relHeight = _pos select 2;

		_output = format ["""%1"";%2;%3;%4;%5;%6;%7;%8;", _templateName, _posX, _posY, _yaw, _pitch, _roll, _scale, _relHeight];
		"sfp_map_editor" callExtension (format ["write;%1", _output]);
	} forEach _objs;

	"sfp_map_editor" callExtension ("close");

	hint format(["All objects exported as %1 in your Arma 3 directory", _filename]);
} else {
	hint format(["You need the sfp_map_editor.dll for the export feature", _filename]);
};

true;
