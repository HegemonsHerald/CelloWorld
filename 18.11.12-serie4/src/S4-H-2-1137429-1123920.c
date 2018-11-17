#include <stdio.h>
#include <locale.h>


void printBinary(int number, int digits) {

	// code for a)

}



void floatToBinary(int number, int *output);
int binaryToFloat(char[]);



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
	printf("Zahl ist %f\n, ieee.f");

	return 0;

}

