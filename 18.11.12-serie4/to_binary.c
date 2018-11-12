#include <stdio.h>

#define MAX_DIGITS 32 // holds the value of how many digits a number can maximally have

/**
 *
 * Function, that displays an input integer in its binary representation
 *
 * Note: since the binary representation includes the most significant bit,
 * I'm using unsigned integers as input here, otherwise I'd get weird output
 * artifacts during computation of the binary digits...
 */
void to_binary(unsigned int number, unsigned int digits) {

	/* Make Vars */

	// Where to put the digits you produced (a number in this task could maximally have MAX_DIGITS digits)
	char single_digits[MAX_DIGITS];

	// Counter for the number of digits in single_digits
	int number_of_digits = 0;


	/* Division Method for conversion to binary representation */

	// Use the division method to compute the digits of number in base 2
	while (number != 0) { // The division method terminates on reaching 0

		// Add the rest as the base 2 digit at the appropriate spot to single_digits
		single_digits[ number_of_digits ] = number % 2;

		// Reassign the number as the base for the next iteration
		number = number / 2;

		// You made a new digit, increase the counter!
		number_of_digits++;

	}


	/* Output */

	// How many leading 0es need to be added?
	int delta_digits = digits - number_of_digits;

	// Note: if the user wants more digits, then there are in the number,
	// the user shall get more digits, then there are in the number!

	// Note: using this subtraction means, that if digits is smaller than
	// number_of_digits no leading 0es will be added and the entire number
	// will be printed anyways!

	// Print the leading 0es
	for (int i = 0; i < delta_digits; i++)
		printf("0");


	// Print the actual digits
	while (number_of_digits > 0) // As long as there are more than 0 digits left to be printed...
		// ... print another digit
		printf("%d", single_digits[ --number_of_digits ]);

		/**
		 * note: --number_of_digits is used for two reasons:
		 *   1. number_of_digits represents the length of digits in single_digits,
		 *      but for display we need to know the index of the digits in single_digits,
		 *      which is offset by 1 because of 0-indexing!
		 *   2. because we don't just want ot print the same digit over and over,
		 *      we have to change number_of_digits (as it is tested for in the while condition)
		 *      anyways, might as well do it here!
		 */

	// Add a newline to the end of the output
	printf("\n");

}


int main() {

	unsigned int number = 2; // == 00000000000000000000000000000010

	printf("Integer 2 as binary:\t\t");
	to_binary( number, 32 );

	printf("Integer 2 as binary:\t\t");
	to_binary( number, 0 );


	union {
		float f;
		unsigned int i;
	} float_number;

	float_number.f = 2.0;

	printf("Float %f as binary:\t", float_number.f);
	to_binary( float_number.i, 32 );

	float_number.f = 12.235;

	printf("Float %f as binary:\t", float_number.f);
	to_binary( float_number.i, 32 );

	float_number.f = 11.15;

	printf("Float %f as binary:\t", float_number.f);
	to_binary( float_number.i, 32 );

	float_number.f = 0.33515;

	printf("Float %f as binary:\t", float_number.f);
	to_binary( float_number.i, 32 );

	float_number.f = -0.29837455;

	printf("Float %f as binary:\t", float_number.f);
	to_binary( float_number.i, 32 );

	return 0;
}
