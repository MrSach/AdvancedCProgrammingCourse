#include <stdio.h>
#include "onscreen_box.h"
#include "colour_chart.h"
#include "border_chart.h"

void display_onscreen_box (const struct onscreen_box * const boxy)
{
	printf ("\n");
	printf ("Box is ");
	(boxy -> opacity == 1) ? printf ("opaque") : printf ("transparent");
	printf (".");
	printf ("\n");
	
	printf ("The fill colour is ");
	printf ("%s", get_colour (boxy -> fill_colour) );
	printf (".");
	printf ("\n");
	
	printf ("Border ");
	(boxy -> border_display == 1) ? printf ("shown") : printf ("hidden");
	printf (".");
	printf ("\n");
	
	printf ("The border colour is ");
	printf ("%s", get_colour (boxy -> border_colour) );
	printf (".");
	printf ("\n");
	
	printf ("The border style is ");
	printf ("%s", get_border_format (boxy -> border_format) );
	printf (".");
	printf ("\n");
	printf ("\n");
}
