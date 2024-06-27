#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

long long test_f (size_t a1, ...);

double test_f2 (double b1, double b2, ...);

_Bool printme (char * str, ...);

int main (int argc, char ** argv)
{
	/*
		Title and spacing
	*/
	printf ("\n");
	printf ("Challenge - Variadic Functions - Attempt 1");
	printf ("\n");

	/*
		Program logic goes here.
	*/

	printf ("\n");
	
	auto long long number = test_f (5, 11, 22, 33, 44, 55);
	printf ("11 + 22 + 33 + 44 + 55 = %lli", number);
	printf ("\n");
	
	number = test_f (3, 1, 3, 5);
	printf ("1 + 3 + 5 = %lli", number);
	printf ("\n");
	
	number = test_f (10, 93, 52, 335, 912, 3121, 442, 515, 9074, 1175, 668);
	printf ("93 + 52 + 335 + 912 + 3121 + 442 + 515 + 9074 + 1175 + 668 = %lli", number);
	printf ("\n");
	
	auto double number_2 = test_f2 (2.0, 3.2364, 0.505, 0.0);
	printf ("2.0 + 3.2364 + 0.505 = %f", number_2);
	printf ("\n");
	
	number_2 = test_f2 (0.00133, 0.00012, 0.0206, 1.43, 7.803, 5.41, 8.888, 0.00905, 0.0);
	printf ("0.00133 + 0.00012 + 0.0206 + 1.43 + 7.803 + 5.41 + 8.888 + 0.00905 = %f", number_2);
	printf ("\n");

	printf ("\n");
	printf ("\n");
	
	auto _Bool printftest = printme ("Testing!");
	printf ("\n");
	
	printftest = printme ("Another test %d", 55);
	printf ("\n");
	
	printftest = printme ("Char %c and char %c in one line", 'm', 'n');
	printf ("\n");
	
	printftest = printme ("Testing again and again with %c and %s", 'e', "Strings AND chars");
	printf ("\n");
	
	printftest = printme ("Hello %s, %s and %s, I got here just after %ld and arrived in ", 'e', "Strings AND chars");
	printf ("\n");

	printf ("\n");
	printf ("\n");

	return 0;
}

long long test_f (size_t a1, ...)
{
	va_list args;
	va_start (args, a1);
	
	long long total = 0;
	
	for (size_t i = 0; i < a1; ++i)
	{
		long long value = va_arg (args, long long);
		total += value;
	}
	
	va_end (args);
	
	return total;
}

double test_f2 (double b1, double b2, ...)
{
	va_list args;
	va_start (args, b2);

	double total = b1 + b2;
	printf ("\n %f \n", total);

	for (double value = va_arg (args, double); value != 0.0; value = va_arg (args, double))
	{
		printf("\n%f\n", value);
		total += value;
	}

	va_end (args);

	return total;
}

_Bool printme (char * str, ...)
{
	va_list args;
	va_start (args, str);	

	_Bool escaped = 0;

	for (size_t i = 0; * (str + i) != '\0'; ++i)
	{
		int * n = (int *) malloc (sizeof (int) );
		* n = * (str + i);
		char c = (char) * n;
		free (n);		
		
		if (c == '%')
		{
			char arr [1000];
			arr [0] = '%';
			++i;
			for (size_t j = 1; * (str + i) != '\0'; ++i)
			{
				c = (char) ( * (str + i) );
				
				if (c == '\0')
				{
					break;
				}
				else if (c == '%')
				{
					arr [0] = c;
					j = 0;
					continue;
				}
				else if (c >= (int) ('0') && c<= (int) ('9') )
				{
					arr [j++] = c;
					c = * (str + i);
					continue;
				}
				else if (c == (int) '.' )
				{
					arr [j++] = c;
					c = * (str + i);
					continue;
				}
				else if (c == 'l')
				{
					arr [j++] = c;
					++i;
					c = * (str + i);
					if (c == 'd' || c == 'i' || c == 'u')
					{
						arr [++j] = '\0';
						fprintf (stdout, arr, va_arg (args, long int) );
						break;
					}
					else if (c == 'f')
					{
						arr [++j] = '\0';
						fprintf (stdout, arr, va_arg (args, double) );
						break;
					}
					else
					{
						break;
					}
				}
				else if (c == 'L')
				{
					arr [j++] = c;
					++i;
					c = * (str + i);
					if (c == 'd' || c == 'i' || c == 'u')
					{
						arr [++j] = '\0';
						fprintf (stdout, arr, va_arg (args, long long int) );
						break;
					}
					else if (c == 'f')
					{
						arr [++j] = '\0';
						fprintf (stdout, arr, va_arg (args, long double) );
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					arr [j] = c;
					if (c == 'd' || c == 'h' || c == 'i' || c == 'u')
					{
						arr [++j] = '\0';
						fprintf (stdout, arr, va_arg (args, int) );
						break;
					}
					else if (c == 'f')
					{
						arr [++j] = '\0';
						fprintf (stdout, arr, va_arg (args, double) );
						break;
					}
					else if (c == 'c')
					{
						arr [++j] = '\0';
						fprintf (stdout, arr, va_arg (args, int) );
						break;
					}
					else if (c == 's')
					{
						arr [++j] = '\0';
						fprintf (stdout, arr, va_arg (args, char *) );
						break;
					}
				}
			}
		}
		
		else
		{
			fprintf (stdout, "%c", (char) c );
		}
		
	}

	va_end (args);

	return 0;
}
