#include <stdio.h>
#include <stdlib.h>

struct myArray
{
	size_t length;
	int array [];
};

void nl ()
{
	printf ("\n");
}

size_t sizer ()
{
	nl();
	printf ("Enter the size of the flexible array: ");
	size_t input = 0;
	scanf ("%zd", & input);
	printf ("Array set to %zd elements.", input);
	nl();
	return input;
}

struct myArray * generate (size_t length)
{
	struct myArray * obj = NULL;
	size_t alloc_size = 0;
	alloc_size = sizeof (struct myArray) + (sizeof (int) * length);
	obj = malloc (alloc_size);
	obj->length = length;
}

void set_arr (struct myArray * arr)
{
	for (size_t i = 0; i < arr->length; ++i)
	{
		printf ("Enter element %zd: ", i + 1);
		int buf = 0;
		scanf ("%d", & buf);
		arr->array [i] = buf;
		printf ("Element %zd = %d", i + 1, arr->array [i]);
		nl();
	}
}

void display (struct myArray * arr)
{
	nl();
	for (size_t i = 0; i < arr->length; ++i)
	{
		printf ("Element %zd = %d", i + 1, arr->array [i]); 
		nl();
	}
	nl();
}

int main ()
{
	size_t length = sizer();
	struct myArray * target = NULL;
	target = generate (length);
	set_arr (target);
	display (target);
	free (target);
	return 0;
}
