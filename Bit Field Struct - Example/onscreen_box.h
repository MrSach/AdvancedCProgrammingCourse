#pragma once
#ifndef S8C4A1_HEADER_TEST_FOR_ADVANCED_C_ONSCREEN_BOX
#define S8C4A1_HEADER_TEST_FOR_ADVANCED_C_ONSCREEN_BOX

#include <stdint.h>

struct onscreen_box
{
	uint32_t : 6;
	uint32_t opacity: 1;
	uint32_t border_display: 1;
	uint32_t fill_colour: 3;
	uint32_t border_colour: 3;
	uint32_t border_format: 2;
};

void display_onscreen_box (const struct onscreen_box * const boxy);

#endif
