#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int dec_to_bin (const int d)
{
	int temp = d;
	long long int bin = 0;
	for (size_t i = 0; temp > 0; ++i)
	{
		double x = log2 ( (double) temp );
		int y = (int) floor (x);
		bin += pow (10, y);
		temp -= pow (2, y);
	}
	return bin;
}

int main (void)
{
	printf ("Please enter a whole number in decimal format (to convert to binary): ");
	int n = 0;
	scanf ("%d", & n);
	printf ("n = %d", n);
	printf ("\n");
	printf ("Binary output = %zd", dec_to_bin (n) );
	printf ("\n");
	printf ("\n");
	
	return 0;
}
