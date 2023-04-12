#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int bin_to_dec (const long long bnum)
{
	size_t length = 0;
	for (long long running = bnum; running > 0; running /= 10)
	{
		++length;
	}
	
	int dec = 0;
	long long running = bnum;
	for (size_t i = 0; i < length; ++i)
	{
		long long bit = running % 10;
		running /= 10;
		(bit == 1) ? dec += pow (2, i) : 0;
	}
	return dec;
}

int main ()
{
	long long bin = 0;
	printf ("Please enter a binary number consisting of 0s and 1s (any digits above 1 are treated as 0s): ");
	scanf ("%zd", & bin);
	printf ("Test binary number = %zd", bin);
	printf ("\n");
	printf ("Decimal number = %d", bin_to_dec (bin) );
	printf ("\n");
	printf ("\n");
	
	return 0;
}
