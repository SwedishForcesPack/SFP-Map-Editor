class sfp_map_editor_copy_object_dialog
{
	idd = 123;
	movingEnable = true;
	onLoad = ";";
	onUnload = ";";

	class controls 
	{
		class CopyObjectFrame: RscFrame
		{
			idc = 1000;
			text = "Copy Object"; //--- ToDo: Localize;
			x = 0.299415 * safezoneW + safezoneX;
			y = 0.280094 * safezoneH + safezoneY;
			w = 0.406901 * safezoneW;
			h = 0.318864 * safezoneH;
			moving = 1;
		};

		class CopyObjectOffsetXEdit: RscText
		{
			idc = 1101;
			x = 0.603158 * safezoneW + safezoneX;
			y = 0.31308 * safezoneH + safezoneY;
			w = 0.080234 * safezoneW;
			h = 0.0329859 * safezoneH;
		};
		class CopyObjectOffsetXSlider: RscSlider
		{
			idc = 1102;
			x = 0.310877 * safezoneW + safezoneX;
			y = 0.324075 * safezoneH + safezoneY;
			w = 0.28655 * safezoneW;
			h = 0.0219906 * safezoneH;
		};
		class CopyObjectOffsetXText: RscText
		{
			idc = 1103;
			text = "Offset X"; //--- ToDo: Localize;
			x = 0.305146 * safezoneW + safezoneX;
			y = 0.291089 * safezoneH + safezoneY;
			w = 0.05731 * safezoneW;
			h = 0.0329859 * safezoneH;
		};

		class CopyObjectOffsetYEdit: RscText
		{
			idc = 1201;
			x = 0.603158 * safezoneW + safezoneX;
			y = 0.368056 * safezoneH + safezoneY;
			w = 0.080234 * safezoneW;
			h = 0.0329859 * safezoneH;
		};
		class CopyObjectOffsetYSlider: RscSlider
		{
			idc = 1202;
			x = 0.310877 * safezoneW + safezoneX;
			y = 0.379052 * safezoneH + safezoneY;
			w = 0.28655 * safezoneW;
			h = 0.0219906 * safezoneH;
		};
		class CopyObjectOffsetYText: RscText
		{
			idc = 1203;
			text = "Offset Y"; //--- ToDo: Localize;
			x = 0.305146 * safezoneW + safezoneX;
			y = 0.346066 * safezoneH + safezoneY;
			w = 0.063041 * safezoneW;
			h = 0.0329859 * safezoneH;
		};

		class CopyObjectOffsetZEdit: RscText
		{
			idc = 1301;
			x = 0.603158 * safezoneW + safezoneX;
			y = 0.434028 * safezoneH + safezoneY;
			w = 0.080234 * safezoneW;
			h = 0.0329859 * safezoneH;
		};
		class CopyObjectOffsetZSlider: RscSlider
		{
			idc = 1302;
			x = 0.310877 * safezoneW + safezoneX;
			y = 0.434028 * safezoneH + safezoneY;
			w = 0.28655 * safezoneW;
			h = 0.0219906 * safezoneH;
		};
		class CopyObjectOffsetZText: RscText
		{
			idc = 1303;
			text = "Offset Z"; //--- ToDo: Localize;
			x = 0.305146 * safezoneW + safezoneX;
			y = 0.401042 * safezoneH + safezoneY;
			w = 0.063041 * safezoneW;
			h = 0.0329859 * safezoneH;
		};

		class CopyObjectNumberOFElementsEdit: RscText
		{
			idc = 1401;
			x = 0.603158 * safezoneW + safezoneX;
			y = 0.489005 * safezoneH + safezoneY;
			w = 0.080234 * safezoneW;
			h = 0.0329859 * safezoneH;
		};
		class CopyObjectNumberOfElementsSlider: RscSlider
		{
			idc = 1402;
			x = 0.310877 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.28655 * safezoneW;
			h = 0.0219906 * safezoneH;
		};
		class CopyObjectNumberOfElementsText: RscText
		{
			idc = 1404;
			text = "Number of elements"; //--- ToDo: Localize;
			x = 0.305146 * safezoneW + safezoneX;
			y = 0.467014 * safezoneH + safezoneY;
			w = 0.292281 * safezoneW;
			h = 0.0219906 * safezoneH;
		};
		
		
		class CopyObjectCopyButton: RscButton
		{
			idc = 1501;
			text = "Copy"; //--- ToDo: Localize;
			x = 0.310877 * safezoneW + safezoneX;
			y = 0.532986 * safezoneH + safezoneY;
			w = 0.045848 * safezoneW;
			h = 0.0549766 * safezoneH;
			action = "copyObjects = true; closeDialog 0;";
		};
		class CopyObjectCancelButton: RscButton
		{
			idc = 1502;
			text = "Cancel"; //--- ToDo: Localize;
			x = 0.368187 * safezoneW + safezoneX;
			y = 0.532986 * safezoneH + safezoneY;
			w = 0.045848 * safezoneW;
			h = 0.0549766 * safezoneH;
			action = "closeDialog 0;";
		};
	};
};
