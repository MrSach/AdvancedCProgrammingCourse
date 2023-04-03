#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/*
	data packet:
		opacity = 1
		border_display = 1
		fill_colour = 3
		border_colour = 3
		border_style = 2
		unused = 6
*/



uint16_t bitmask_prep (const uint16_t offset)
{
	uint16_t masker = 0;
	switch (offset)
	{
		case 0:
			masker = 1;
			break;
		case 1:
			masker = 1;
			break;
		case 2:
			masker = 7;
			break;
		case 5:
			masker = 7;
			break;
		case 8:
			masker = 3;
			break;
		default:
			break;
	}
	return masker;
}

char * get_colour (const uint16_t code)
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
		default:
			return "";
			break;
	}
}

char * get_format (const uint16_t code)
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
		default:
			return "";
			break;
	}
}

uint16_t get_code (const uint16_t * data, const uint16_t offset, const uint16_t length)
{
	uint16_t realign = (* data) >> offset;
	uint16_t masker = bitmask_prep (offset);
	realign = realign & masker;
	return realign;
}

_Bool mod_attr (uint16_t * data, const uint16_t value, const uint16_t offset, const uint16_t length)
{
	uint16_t bitmask = ( pow (2, length - 1) ) - 1;
	bitmask = bitmask << (offset);
	bitmask = ~ bitmask;
	uint16_t reset = 0;
	return 0;
}

void get_info (const uint16_t * data)
{
	printf ("\n");
	uint16_t realign = (* data);
	/*
		Opacity
	*/
	uint16_t bitmask = 1;
	uint16_t code = realign & bitmask;
	printf ("Box is ");
	(code == 1) ? printf ("opaque") : printf ("transparent");
	printf (".");
	printf ("\n");
	
	/*
		Skip ahead to fill colour.
	*/
	bitmask = 7;
	code = (realign / pow (2, 2) );
	code = code & bitmask;
	printf ("The fill colour is ");
	printf ("%s", get_colour (code) );
	printf (".");
	printf ("\n");
	
	/*
		Revert back to border display
	*/
	bitmask = 1;
	realign /= 2;
	printf ("Border ");
	code = realign & bitmask;
	(code == 1) ? printf ("shown") : printf ("hidden");
	printf (".");
	printf ("\n");
	
	/*
		Skip border display again.
		Skip fill colour, too.
		So, go straight ahead to border colour.
	*/
	bitmask = 7;
	realign /= pow (2, 4);
	printf ("The border colour is ");
	code = realign & bitmask;
	printf ("%s", get_colour (code) );
	printf (".");
	printf ("\n");
	
	/*
		Border style
	*/
	bitmask = 3;
	realign /= pow (2, 3);
	code = realign & bitmask;
	printf ("The border style is %s", get_format (code) );
	printf (".");
	printf ("\n");
	printf ("\n");
}

int main (void)
{
	/*
		Set some values for box1.
		Next, display the information.
	*/
	uint16_t box1 = 2;
	box1 = box1 << 3;
	box1 += 2;
	box1 = box1 << 3;
	box1 += 3;
	box1 = box1 << 1;
	box1 += 1;
	box1 = box1 << 1;
	box1 += 1;

	get_info (& box1);
	
	/*
		Reset box1.
		Assign some new values.
		Skip the border style, since 0 represents solid.
		Assign 5 for magenta for border colur.
		Assign 7 for fill colour.
		Assign 1 for border display.
		Leave the default for border opacity, which is 0 for transparent.
		Afterwards, display the information.
	*/
	box1 = 0;
	box1 += 5;
	box1 = box1 << 3;
	box1 += 7;
	box1 = box1 << 1;
	box1 += 1;
	box1 = box1 << 1;
	
	get_info (& box1);

	return 0;
}
