#include <stdio.h>

#define HONK 42
#define TARD HONK + 19

int main() {

	// The code below produces the correct output, which means
	// you can reference preprocessor parts from within the preprocessor...
	//
	// Kinda makes sense: the instance of HONK in the #define of TARD should be replaces
	// with 42 on the first go of the preprocessor where it'll replace all the HONKs,
	// after which it then has another go, in which TARD is replaced.

	printf("%d\n", HONK);
	printf("%d\n", TARD);
	printf("%d\n", HONK + TARD);

	return 0;

}
