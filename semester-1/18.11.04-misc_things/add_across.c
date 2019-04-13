#include <stdio.h>
#define len(a) (sizeof(a)/sizeof(*a))
#define NN printf("\n");

void turn_to_numbers(char arr[], char len) {
	for (char i=0; i<len; i++) {
		arr[i] -= 48;
	}
}

char sum(char arr[], char len) {
	char sum = 0;
	for (char i=0; i<len; i++) {
		sum += arr[i];
	}
	return sum;
}

void parr(char arr[], char len) {
	for (char i=0; i<len; i++) {
		printf("The %dth value of the array: %d", i, arr[i]);
		NN
	}
}

int main() {

	// getchar();
	// putchar();
	// scanf();
	// printf();
	// Also: can I just say, how awesome the preprocessor is?

	printf("Input 123, then press Return\n");

	// read 3 characters and a \0
	char input[3];
	scanf("%s", input);

	// comparison thing
	char numbs[] = { 1, 2, 3 };

	NN

	// tell me, what the arrays are now
	parr(input, len(input)); NN
	parr(numbs, len(numbs)); NN

	// add them up
	printf("result from adding chars: %d", sum(input, len(input))); NN
	printf("result from adding numbs: %d", sum(numbs, len(numbs))); NN

	NN

	// turn the input to numbers by subtracting 48 from the char values (that's the ascii-to-numbers differential
	turn_to_numbers(input, len(input));

	// tell me, what the input is now
	parr(input, len(input)); NN

	// tell me, that the change-up worked!
	printf("result from adding chars: %d", sum(input, len(input))); NN

	return 0;
}
