#include <stdio.h>
#include <locale.h>

#define p(n) printf("%d\n", n)

/**
 * Let's make generator functions...
 * Reminder: Generator functions are functions with a preserved internal state,
 * so they are functions from whose execution you can dip in and dip out.
 */

/* Define a generator */
// this function adds its argument to an internal sum variable
int continued_sum(int a) {

	// static sum is initialized with 0 and preserved across function calls
	static int sum = 0;
	// note that this variable is only initialized with 0, it can be changed
	// and keeps its value across calls, so this statement doesn't mean that
	// sum will be set to 0 in the beginning of every function call

	sum += a;

	return sum;
}




int main() {

	// Make unicode work
	setlocale(0, "");

	p(continued_sum(19)); //  0 + 19 = 19
	p(continued_sum(19)); // 19 + 19 = 38
	p(continued_sum(19)); // 38 + 19 = 57

	return 0;

}

