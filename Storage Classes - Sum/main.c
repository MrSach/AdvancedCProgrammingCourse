#include <stdio.h>

static int run = 0;

int sum (int add)
{
	return (run += add);
}

int main ()
{
	printf ("\n");
	printf ("%d", sum (25));
	printf ("\n");
	printf ("%d", sum (15));
	printf ("\n");
	printf ("%d", sum (30));
	printf ("\n");
	printf ("\n");
	
	return 0;
}
