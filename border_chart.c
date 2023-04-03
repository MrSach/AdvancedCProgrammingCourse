#include "border_chart.h"

char * get_border_format (const uint32_t code)
{
	switch (code)
	{
		case 0:
			return "Solid";
			break;
		case 1:
			return "Dotted";
			break;
		case 2:
			return "Dashed";
			break;
	}
	
	return '\0';
}
