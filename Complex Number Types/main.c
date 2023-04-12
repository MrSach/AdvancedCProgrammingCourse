#include <stdio.h>
#include <complex.h>
#include <math.h>

void nl()
{
	printf("\n");
}

int main ()
{
	nl();
	double _Complex c1 = (I * I);
	printf ("c1 = %+.5f %+.5fi", creal(c1), cimag(c1));
	nl();
	nl();
	
	double _Complex c2 = pow(I, 2);
	printf ("c2 = %.5f %+.5fi", creal(c2), cimag(c2));
	nl();
	nl();
	
	double c3 = (acos (-1));
	printf ("c3 = %.5f", c3);
	nl();
	double _Complex c4 = (c3 * I);
	printf ("c4 = %+.5f %+.5fi", creal(c4), cimag(c4));
	nl();
	double _Complex c5 = exp (c4);
	printf ("c5 = %+.5f %+.5fi", creal(c5), cimag(c5));
	nl();
	nl();
	
	double _Complex c6 = 1.0 + (2 * I);
	double _Complex c7 = c6 * (conj (c6));
	printf ("c7 = %+.5f %+.5fi", creal (c7), cimag (c7) );
	nl();
	nl();
	//double _Complex c8 = 1.0 - (2 * I);
	//double _Complex c9 = conj (c8);
	//printf ("c9 = %+.5f %+.5fi", creal (c9), cimag (c9) );
	//nl();
	//nl();
	
	return 0;
}
