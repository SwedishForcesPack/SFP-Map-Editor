#include "\sfp_map_editor\module_header.hpp";

{
	_x addEventHandler [
		"CuratorObjectRegistered",
		{
			_classes = _this select 1;
			_costs = [];
			{
				_cost = if (_x isKindOf "Static" OR _x isKindOf "Thing") then {[true,0]} else {[false,0]}; // Show only objects of type "Static", hide everything else
				_costs = _costs + [_cost];
			} forEach _classes; // Go through all classes and assign cost for each of them
			_costs
		}
	];
} forEach allCurators;

#include "\sfp_map_editor\module_footer.hpp";
