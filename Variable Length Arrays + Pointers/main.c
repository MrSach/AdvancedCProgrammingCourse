#include <stdio.h>
#include <stdlib.h>

/*
	New line shortcut.
*/
void nl()
{
	printf ("\n");
}

/*
	Generate series of array elements using user input.
	Return a pointer to an integer.
	This is a Variable Length Array (VLA).
	Dynamically allocate using the number of elements previously provided.
	Prompt the user for input for each element in the array.
	Return the array afterwards.
*/
int * series (size_t arr_s)
{
	int * arr = malloc (sizeof (int) * arr_s);
	for (size_t i = 0; i < arr_s; ++i)
	{
		int input = 0;
		printf ("Enter element ");
		printf ("%zd", i);
		printf (": ");
		scanf ("%d", & input);
		arr [i] = input;
	}
	return arr;
}

/*
	Display the numbers in the array with one element per line.
*/
void display_numbers (size_t arr_s, int arr [arr_s])
{
	nl();
	for (size_t i = 0; i < arr_s; ++i)
	{
		printf ("%d", arr [i]);
		nl();
	}
} 

/*
	Generate and display the total of the integer elements within the VLA.
*/
int summer (size_t arr_s, int arr [arr_s])
{
	int total = 0;
	for (size_t i = 0; i < arr_s; ++i)
	{
		total += arr [i];
	}
	return total;
}

int main ()
{
	/*
		Declare and initialise the number of elements in the array.
		The user can be prompted to input a specific number later.
	*/
	size_t arr_size = 0;
	
	nl();
	printf ("How many numbers are in this sequence? ");
	scanf ("%zd", & arr_size);
	printf ("The array size entered is ");
	printf ("%zd", arr_size);
	printf (".");
	nl();
	
	/*
		Call the series() function using arr_size as argument.
		Remember that a pointer is needed here as an array is created dynamically on the heap.
		Show the elements in the array.
		Display the total sum of the elements in the array.
	*/
	int * arr = series (arr_size);
	display_numbers (arr_size, arr);
	nl();
	printf ("Sum of the numbers = ");
	printf ("%d", summer (arr_size, arr));
	free (arr);
	nl();
	nl();
	
	return 0;
}
