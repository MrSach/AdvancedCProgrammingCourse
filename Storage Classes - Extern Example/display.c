#include <stdio.h>

void display ()
{
	extern int a;
	printf ("%d", a++);
	printf ("\n");
}
