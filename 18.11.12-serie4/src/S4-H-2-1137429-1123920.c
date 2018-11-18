#include <stdio.h>
#include <locale.h>


#define IEEE_BITS 32

// #define EXP_START (32 - 1)
#define EXP_START 31
#define EXP_BITS  8

// #define MAN_START (32 - 9)
#define MAN_START 23



/**
 * 1. create print binary
 *
 * 2. recreate the code for the bitmask making
 * 3. recreate the code for retrieving the exponent
 * 4. create the code for getting MSB
 * 5. create the code for getting Mantissa
 *
 * 6. do the things... tasks.
 *
 */





//void printBinary(int number, int digits) {
void printBinary(int number, int d) {

	// code for a)

	// basically the division method and printing thing from series 2
	// with an added guard for the digits

	int target_base = 2;
	char digits[32];
	int i = 0;
	
	while (number != 0) {

		digits[i] = number % target_base;

		// Update number to be the result of this iteration's integer division,
		// so the next iteration can produce the next digit
		number /= target_base;

		// Update the digit counter
		i++;
	}

	for (int j = i-1; j >= 0; j--) {
		printf("%d", digits[j]);
	}

	printf("\n");
}

int pow(int number, int exponent) {

	int out = number;

	for (int i = 1; i <= exponent; i++) {
		out *= number;
	}

	return out;

}



int main() {

	// Make unicode work
	setlocale(0, "");


	unsigned int sign, mantissa, exponent;
	char expUnbiased;

	float input;

	union {
		float f;
		unsigned int i;
	} ieee;

	printf("Gib die zu analysierende Zahl ein: ");
	scanf("%f", &input);

	ieee.f = input;

	// code for b)



	if ((ieee.i & IEEE_BITS) == 0) {
		sign = 0;
	} else {
		sign = 1;
	}


	// Create the bitmask and the unshift value
	unsigned int exponent_shift = MAN_START;
	unsigned int exponent_mask = pow(2, EXP_BITS - 1) << exponent_shift; // lots of 0s and then 8 1s
	unsigned int temp_exponent = 0;

	// Isolate the exponent from the float
	temp_exponent = ieee.i & exponent_mask;

	// Unshift the exponent's bits
	temp_exponent = temp_exponent >> exponent_shift;

	char t = temp_exponent;
	t = ~(--t);

	exponent = t;

	printf("2 ^ Bits-1:     %d\n", pow(2, EXP_BITS)-1);
	printf("exponent_mask:  %d\n", exponent_mask);
	printBinary(255 << exponent_shift, 8);
	printBinary((pow(2, EXP_BITS) -1) << exponent_shift, 8);
	printBinary(exponent_mask, 8);
	printf("exponent_shift: %d\n", exponent_shift);
	printBinary(exponent_shift, 8);
	printf("ieee.i       :  %d\n", ieee.i);
	printBinary(ieee.i, 8);
	printf("temp_exponent:  %d\n", temp_exponent);
	printBinary(temp_exponent, 8);
	printf("t:              %d\n", t);
	printf("exponent:       %d\n", exponent);


	/**
	 *
	 *  10.0
	 *   1.00 * 2^1
	 *
	 *  exp: 1 - 127 = -126
	 *
	 *  |0|10000001|00000000000000000000000|
	 *
	 *  number:
	 *  01000000100000000000000000000000
	 *
	 *  exponent mask unshifted:
	 *  00000000000000000000000011111111
	 *
	 *  exponent mask shifted 23:
	 *  01111111100000000000000000000000
	 *
	 *  bitwise AND:
	 *  01000000100000000000000000000000
	 *  01111111100000000000000000000000
	 *   ||||||||
	 *  01000000100000000000000000000000
	 *
	 *  exponent unshift by 23:
	 *  00000000000000000000000010000001
	 *
	 *  exponent value:
	 *  00000000000000000000000010000001 - 1
	 *  00000000000000000000000010000000 | bit-turn the 8
	 *  00000000000000000000000001111111
	 *
	 */








	printf("Float %f als Hex %X ist zerlegt in\n Vorzeichen %d,\nMantisse %X,\nExponent: %d,\nExpUnbiased %d\n", ieee.f, ieee.i, sign, mantissa, exponent, expUnbiased);

	printf("\nVorzeichen ist\t");
	printBinary(sign, 1);

	printf("\nMantisse binär ist\t");
	printBinary(mantissa, 23);

	printf("\nExponent binär ist\t");
	printBinary(exponent, 8);

	printf("\nExpUnbiased binär ist\t");
	printBinary(expUnbiased, 8);


	// check for special cases of ieee

	// code for c)

	// for standard case normalized, reassemble the float-parts
	// to a proper ieee, so that it can be printed via ieee.f
	// ?

	// code for d)
	printf("Zahl ist %f\n", ieee.f);

	return 0;

}

