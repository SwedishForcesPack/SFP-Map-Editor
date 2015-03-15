_unitUnderCursor = objNull;

// We use the value we set when the last object was created. This is because when we call this
// (inside the module's logic) the object under the mouse is always going to be the newly created
// logic module, and not the actual object that is underneath it. We want to know what the object
// was under the mouse when the module itself was created - under the assumption that the last object
// created was the module, and that the mouse was actually on the object we want when the event
// got fired.
// TODO we could eliminate this issue if we always deleted the logic BEFORE we tried to get
// the item under the cursor.

_mouseOverUnit = sfp_map_editor_CuratorObjectPlaced_UnitUnderCursor;
if (count _mouseOverUnit == 0) then
{
	//diag_log "GetUnitUnderCursor: Not in curator mode";
	// Not in curator mode.
}
else
{
	//diag_log "GetUnitUnderCursor: In curator mode!";
	if (_mouseOverUnit select 0 == "") then
	{
		//diag_log "GetUnitUnderCursor: No unit under cursor";
		// Mouse not over anything editable (value should be [""])
	}
	else
	{
		//diag_log "GetUnitUnderCursor: Elements in select array!";
		if (count _mouseOverUnit == 2) then
		{
			if (_mouseOverUnit select 0 == "OBJECT") then
			{
				// value should be [typeName, object]
				_unitUnderCursor = _mouseOverUnit select 1;
				//diag_log format ["GetUnitUnderCursor: Got unit under cursor: %1 (@%2)", _unitUnderCursor, position _unitUnderCursor];
			}
			else
			{
				//diag_log format ["GetUnitUnderCursor: Unit under cursor was of type '%1' (non-Object). Ignored."];
			}
		}
		else
		{
			//diag_log "GetUnitUnderCursor: Unexpected number of array options";
		};
	};
};

if (isNull _unitUnderCursor) then
{
	//[objNull, "Error - Module needs to be placed on a unit."] call bis_fnc_showCuratorFeedbackMessage;
};

_unitUnderCursor;
