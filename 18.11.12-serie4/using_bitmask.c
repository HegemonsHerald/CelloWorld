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
		 * Note: --number_of_digits is used for two reasons:
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


unsigned int pow(unsigned int number, unsigned int exponent) {
	unsigned int result = 1;
	while (exponent > 0) {
		result *= number;
		exponent--;
	}
	return result;
}


int main() {

	/* make a number */

	union {
		float f;
		unsigned int i;
	} float_number;
	
	// float_number.f = -0.29837455;

	scanf("%f", &float_number.f);


	/* make a bitmask of 8 ones */

	unsigned int bitmask = pow(2, 8) - 1;

	printf("pre-shift:\t\t\t");
	to_binary( bitmask, 32 );


	/* shift the bitmask to the masking position */

	bitmask = bitmask << 23;

	printf("post-shift:\t\t\t");
	to_binary( bitmask, 32 );


	/* output the float */

	printf("the float:\t\t\t");
	to_binary( float_number.i, 32 );


	/* apply the bitmask */

	unsigned int result = float_number.i & bitmask;

	printf("the result of bitwise AND:\t");
	to_binary( result, 32 );


	/* reshift the result, to come up with the actual value of the exponent */

	result = result >> 23;

	printf("the result unshifted:\t\t");
	to_binary( result, 32 );


	/* translate to decimal, respecting the two-complement */

	printf("the exponent in 2-complement: %4d\n", result);

	char a = result;
	printf("the exponent as a number:     %4d\n", a);

	/**
	 *
	 * Right mate,
	 *
	 * You still need to return the exponent to its proper value using the
	 * ±127 or something like that!
	 *
	 * Problems with that: you can only add using the 8 bits of the result
	 * that hold its value... So regular integer addition is sort of out
	 * of the question with out further bitmasking... It would be convenient
	 * if you could type-cast the exponent into a char, cause that should
	 * have just 8 bits. See, if that's possible!
	 *
	 */




	return 0;
}
