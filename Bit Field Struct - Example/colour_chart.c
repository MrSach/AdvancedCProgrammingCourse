#include "colour_chart.h"

char * get_colour (const uint32_t code)
{
	switch (code)
	{
		case 0:
			return "Black";
			break;
		case 1:
			return "Red";
			break;
		case 2:
			return "Green";
			break;
		case 3:
			return "Yellow";
			break;
		case 4:
			return "Blue";
			break;
		case 5:
			return "Magenta";
			break;
		case 6:
			return "Cyan";
			break;
		case 7:
			return "White";
			break;
	}
	
	return '\0';
}
