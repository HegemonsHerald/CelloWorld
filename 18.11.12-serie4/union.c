#include <stdio.h>
#include <locale.h>

int main() {

	// Make unicode work
	setlocale(0, "");

	/** Explanation of the Union
	 *
	 * A Union is a pointer to a set field in memory.
	 * That field is allocated, so that it can hold the largest possible value of the union.
	 * Because of that, the union can hold multiple different types, but of course you need
	 * to keep track of what type it holds at the present time.
	 *
	 * Like the Structure the Union has accessors.
	 * Unlike the Structure the Union's accessors all point to the same position in memory, they
	 * just interpret its value differently, whereas the Structure's pointers point to physically
	 * different fields of different types.
	 *
	 * With regards to series 4: if you assign a float to a Union, it will be stored as an
	 * ieee float. If you then access that Union via an integer, you will get the float's binary
	 * representation interpreted as an integer value.
	 *
	 */

	/** how to do the code for series 4
	 *
	 * since you can get the value as an integer, which is a value
	 * in ieee float format, you can turn it into the binary representation... of an ieee float, not just a random number!
	 *
	 * make a function that returns a char[] with the digits,
	 * that you can then slice from
	 *
	 * the slices you can add up to make a binary again, so
	 * that you get integers from the toBinary function
	 *
	 */

	union {
		float f;
		unsigned int i;
	} ieee;

	float input;
	scanf("%f", &input);

	ieee.f = input;

	printf("float %f\nhonk %X\n", ieee.f, ieee.i);

	return 0;

}

