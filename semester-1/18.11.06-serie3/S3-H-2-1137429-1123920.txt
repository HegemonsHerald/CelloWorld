#include <stdio.h>

int main() {

	/* Declarations */

	// Input
	int dec_number;
	int target_base;

	// Output
	char final_number[100] = {0}; // initialize to 0 or might get random values!
	int final_number_digits; // the number of digits N in the final_number (Stelligkeit)


	/* Get Input */

	// Get a decimal number to convert
	printf("Gib natürliche Zahl mit Basis 10 ein: ");
	scanf("%10d", &dec_number); // max 10 digits: the largest positive integer, we can receive is 2147483647, which has 10 digits

	// Check the decimal number for validity
	// Is the decimal number out of range?
	if (dec_number == 0) {
		printf("Die natuerliche Zahl ist 1-stellig und lautet: 0\n");
		return 0;
	} else if (dec_number < 1) {
		printf("Die natuerliche Zahl ist zu klein um eine natürliche Zahl zu sein!\n");
		printf("... Oder die natuerliche Zahl ist groesser als 2147483647 und damit eine 2-Komplement Zahl und somit auch zu klein!\n");
		printf("... Oder die natuerliche Zahl ist zu gross um von 32-bit Integern dargestellt zu werden!\n");
		return 1;
	}

	// Get a target base to convert the decimal number to
	printf("Konvertierung in welche Basis? Gueltige Basen: 2 bis 16: ");
	scanf("%2d", &target_base);

	// Check the base for validity
	// Is the base in range?
	if (target_base > 16 || target_base < 2) {
		printf("Die Zielbasis ist nicht zulaessig! (Zu klein oder zu gross)\n");
		return 1;
	}


	/* Compute the digits of the decimal number in the target base */
	
	// Tell the user you're doing that
	printf("Konvertiere die Zahl %d aus Basis 10 nach Basis %d\n", dec_number, target_base);

	// Counter, that keeps track of how many digits we've computed
	// (and thereby where the next digit has to go)
	int i = 0;

	// The conversion-by-division terminates at 0,
	// so as long as we haven't reached that: compute!
	while (dec_number != 0) {

		// Add a new digit Zi in the target base to the final_number
		// (the result of modulo with a base is the digit in that base)
		final_number[i] = dec_number % target_base; // final_number[i] = Zi

		// Update dec_number to be the result of this iteration's integer division,
		// so the next iteration can produce the next digit
		dec_number /= target_base;

		// Update the digit counter
		i++;
	}

	// The number of digits we computed is the number of digits the final_number has
	final_number_digits = i;


	/* Print the final_number */

	// Print the sentence, which will be completed below
	printf("Die Zahl ist %d-stellig und lautet: ", final_number_digits);

	/**
	 * N is the number of digits in the number, that is to be
	 * represented.
	 *
	 * Since our number representation begins with the digit
	 * with the index N-1 and ends with the digit with the
	 * index 0, and our Field contains the digits at their
	 * appropriate index, we have to start printing from the
	 * largest index (N-1) and move towards the smallest
	 * index (0).
	 *
	 * In this implementation the variable final_number_digits
	 * serves as the number of digits N (of final_number).
	 */

	// Counter to keep track of how many digits were printed
	int j = final_number_digits - 1; // j = N-1

	// Print digits of the final_number, until you printed all of them
	while (j >= 0) { // loop until j == 0

		// Print in hex, so all possible bases are covered
		printf("%X", final_number[j]); // print digit Zi for i=j

		// Decrease the counter, for you have printed another digit
		j--;
	}

	// Properly finish the output
	printf("\n");

	return 0;
}

