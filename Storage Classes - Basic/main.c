#include <stdio.h>

/*
	Global double variable.
	Accessible in main.c.
*/
static double b = 2.5;

/*
	Global float variable.
	Accessible in program.
*/
float c = 12.8;

/*
	Function that is accessible only from within main.c.
*/
static void only_me ()
{
	printf ("Static function called");
	printf ("\n");
}

int main (int argc, char ** argv)
{
	printf ("\n");
	/*
		Int variable with block scope.
		Temporary storage.
	*/
	{
		auto int a = 1;
		printf ("a = %d", a);
		printf ("\n");
	}
	
	printf ("b = %f", b);
	printf ("\n");
	
	extern float c;
	printf ("c = %f", c);
	printf ("\n");
	
	/*
		Float local variable.
		Permanent storage.
	*/
	static float d = 10.2;
	printf("d = %f", d);
	printf ("\n");
	
	/*
		Register integer variable.
	*/
	register int e = 20;
	printf("e = %d", e);
	printf ("\n");
	
	only_me();
	
	printf ("\n");
	
	return 0;
}
