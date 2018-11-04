#import <stdio.h>

int main() {

	// Make a thing
	int theAnswer = 42;

	// Declare ref to be a pointer
	int *ref;

	// Assign the address of theAnswer to ref
	ref = &theAnswer;

	/**
	 *
	 * '&' is the 'reference' operator, it gives you the reference/address of a thing
	 *
	 * '*' is the 'dereference' operator, it dereferences a pointer to give you the actual value
	 * In a declaration '*' turns the declared thingy into a reference, that can later be dereferenced
	 *
	 */

	// print the answer
	printf("%d\n", theAnswer);

	// print the address of the answer
	printf("%d\n", ref);

	// print the answer by dereferencing
	printf("%d\n", *ref);

	return 0;
}
