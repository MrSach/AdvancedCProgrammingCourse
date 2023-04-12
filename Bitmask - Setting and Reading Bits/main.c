#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int main (void)
{
	printf ("\n");
	
	/*
		Prompt user for positive value.
		Store into unsigned 32 bit integer.
		Output value to show the value stored.
	*/
	printf ("Enter a positive number: ");
	uint32_t input = 0;
	scanf ("%u", & input);
	printf ("The number entered = %u", input);
	printf ("\n");
	
	/*
		Prompt user for input.
		This is the check digit.
		The check digit is the binary position specified by index.
		0 = 1, 1 = 2, 2 = 4, 3 = 8, etc.
		Output check digit index.
	*/
	printf ("Enter nth bit to check and set (0-31): ");
	uint32_t npos = 0;
	scanf ("%u", & npos);
	printf ("nth bit to check and set = %u", npos);
	printf ("\n");
	
	/*
		Generate a buffer for the input value, whose binary digits are offset to the right by the number specified by the index.
		This should give a value where the first bit is the target bit as needed by the index.
	*/
	uint32_t realign = input >> npos;
	printf ("Realigned value to check the nth digit = %u", realign);
	printf ("\n");
	
	/*
		Check if the target bit is 1 or 0.
	*/
	uint32_t check = realign & 1;
	printf ("The bit in position %u is set to %u", npos, check);
	printf ("\n");
	
	if (check == 1)
	{
		printf ("Target bit is already set to 1, skipping...");
		printf ("\n");
	}
	else
	{
		/*
			Generate a new bitmask.
			Set the value to 1.
			Shift the "1" digit to the target position to match that of the input number.
			Next, perform a bitwise OR to keep the other bits the same, changing only the target bit in the new value from the input.
			Display the value before and after the bitwise manipulation.
		*/
		uint32_t sd = 1;
		sd = sd << npos;
		printf ("Set digit value in decimal = %u", sd);
		printf ("\n");
		uint32_t revised = input | sd;
		printf ("Bit set successfully.");
		printf ("\n");
		printf ("Number before setting bit %u: %u", npos, input);
		printf ("\n");
		printf ("Number after setting bit %u: %u", npos, revised);
		printf ("\n");
	}
	
	printf ("\n");
	return 0;
}
