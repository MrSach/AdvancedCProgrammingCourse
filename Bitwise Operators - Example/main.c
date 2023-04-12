/*
	Title
		C - Bitwise Operators Example
	
	Purpose
		Demonstrate the use of bitwise operators to manipulate numerical values.
		Displays the decimal and binary representations (note that Two's Complement is not used here in this example).
		The program takes input for the user with 2 values.
		The program then processes these 2 values and the first one is used for both unary and binary operators, while the second is used in binary operators.
	
	Date
		2023-3-29
		
	Author
		Sacha
*/

/*
	Include necessary libraries.
	stdio
		I/O.
		Output to Terminal.
		Take input from the user.
	math
		Used for pow().
	stdlib
		Used for the size_t data type.
	stdint
		Used for the int32_t data type.
	stdbool
		Used for the bool data type.
	
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
	Convert from decimal to binary.
	Takes a pointer (so reads a reference to the number) to the 32-bit integer value.
	This reads the decimal value and uses it to generate a binary representation of it.
	Negative values are output as positive values but preceded with a negative sign.
	Example: 
	Returns a long long integer value, which is the binary number representation in this case.
*/
long long int dec_to_bin (const int32_t * n)
{
	/*
		Flag whether the number is positive.
		As the number is passed through as a read-only parameter, declare a new mutable variable, "x", and initialise "x" to the value of "* n".
		Where "x" is negative, flag the "positive" boolean to be false.
		Also make "x" positive if it is currently negative.
		Declare "y" to be a long long integer.
		This is used for the return output.
		
	*/
	bool positive = 1;
	int32_t x = * n;
	if (x < 0)
	{
		positive = 0;
		x *= (-1);
	}
	long long int y = 0;

	/*
		Loop through iterations of "i".
		For each iteration, declare "z", which is the modulus from "x" % 2.
		If "x" is odd, use this to add '1' to the relevant binary digit position, based on the value of "i".
		Afterwards, divide "x" by 2 and repeat.
		Exit the loop when "x" reaches 0.
	*/
	for (size_t i = 0; x > 0; ++i)
	{
		short int z = x % 2;
		y += z * pow (10, i);
		x /= 2;
	}
	
	/*
		Remember to restore the negative status for values where "* n" < 0.
		For negative numbers, multiply "y" by -1.
	*/
	if (positive == 0)
	{
		y *= (-1);
	}

	return y;
} 

int main (void)
{

	printf ("\n");
	/*
		Prompt the user for input for 2 numbers.
		Display the 2 numbers in decimal and binary format.
	*/
	printf ("Enter an integer: ");
	int32_t n1 = 0;
	scanf ("%d", & n1);
	printf ("Enter another integer: ");
	int32_t n2 = 0;
	scanf ("%d", & n2);
	printf ("n1 (decimal) = %d", n1);
	printf ("\n");
	printf ("n2 (decimal) = %d", n2);
	printf ("\n");
	long long int b1 = dec_to_bin (& n1);
	printf ("n1 (binary) = %lld", b1 );
	printf ("\n");
	long long int b2 = dec_to_bin (& n2);
	printf ("n2 (binary) = %lld", b2 );
	printf ("\n");
	
	/*
		Apply the "~" operator on the first number.
		Bitwise NOT should reverse the bits for the decimal value.
		This gives (-n -1).
	*/
	{
		int32_t n1b = ~ n1;
		printf ("~ n1 (decimal) = %d", n1b);
		printf ("\n");
		long long int b1b = dec_to_bin (& n1b);
		printf ("The result of applying the ~ operator on number %d (%lld) is %d (%lld)", n1, b1, n1b, b1b);
		printf ("\n");
	}
	
	/*
		Apply the "~" operator on the second number.
		Bitwise NOT should reverse the bits for the decimal value.
		This gives (-n -1).
	*/
	{
		int32_t n2b = ~ n2;
		printf ("~ n2 (decimal) = %d", n2b);
		printf ("\n");
		long long int b2b = dec_to_bin (& n2b);
		printf ("The result of applying the ~ operator on number %d (%lld) is %d (%lld)", n2, b2, n2b, b2b);
		printf ("\n");
	}
	
	/*
		Demonstrates the "&" bitwise operator.
		For positions mutually populated with "1" in the binary digits in both numbers, a "1" will also be populated in the respective position, otherwise populate with "0".
	*/
	{
		int32_t n3 = n1 & n2;
		long long int b3 = dec_to_bin (& n3);
		printf ("The result of applying the & operator on number %d (%lld) and number %d (%lld) is %d (%lld)", n1, b1, n2, b2, n3, b3);
		printf ("\n");
	}
	
	/*
		Demonstrates the "|" bitwise operator.
		For both numbers, the resulting number will also have a "1" populated where either number contains a "1" in that respective position in the binary digits.
	*/
	{
		int32_t n3 = n1 | n2;
		long long int b3 = dec_to_bin (& n3);
		printf ("The result of applying the | operator on number %d (%lld) and number %d (%lld) is %d (%lld)", n1, b1, n2, b2, n3, b3);
		printf ("\n");
	}
	
	/*
		Demonstrates the bitwise "^" operator.
		This performs XOR.
		Compares both numbers and only populates a "1" in the resulting number for the respective bit where only one number contains a "1", but not both simultaneously.
	*/
	{
		int32_t n3 = n1 ^ n2;
		long long int b3 = dec_to_bin (& n3);
		printf ("The result of applying the ^ operator on number %d (%lld) and number %d (%lld) is %d (%lld)", n1, b1, n2, b2, n3, b3);
		printf ("\n");
	}
	
	/*
		Bitwise "<<" operator.
		This example shifts bits of the first number two positions to the left.
		The result will likely enlarge the value.
	*/
	{
		size_t off = 2;
		int32_t n3 = n1 << off;
		long long int b3 = dec_to_bin (& n3);
		printf ("The result of applying the << operator on number %d (%lld) by %zd is %d (%lld)", n1, b1, off, n3, b3);
		printf ("\n");
	}
	
	/*
		Bitwise ">>" operator.
		This example shifts bits of the first number two positions to the right.
		The result will likely reduce the value.
	*/
	{
		size_t off = 2;
		int32_t n3 = n1 >> off;
		long long int b3 = dec_to_bin (& n3);
		printf ("The result of applying the >> operator on number %d (%lld) by %zd is %d (%lld)", n1, b1, off, n3, b3);
		printf ("\n");
	}
	
	printf ("\n");

	return 0;
}
