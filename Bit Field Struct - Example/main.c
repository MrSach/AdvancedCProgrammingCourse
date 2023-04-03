#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "colour_chart.h"
#include "border_chart.h"
#include "onscreen_box.h"

int main (void)
{
	printf ("\n");
	struct onscreen_box box1 = 
	{
		1,
		1,
		3,
		2,
		2
	};
	
	display_onscreen_box (& box1);
	
	box1.opacity = 0;
	box1.fill_colour = 7;
	box1.border_colour = 5;
	box1.border_format = 0;
	
	display_onscreen_box (& box1);
	
	printf ("\n");
	
	return 0;
}
