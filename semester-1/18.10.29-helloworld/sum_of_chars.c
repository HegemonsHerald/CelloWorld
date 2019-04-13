#import <stdio.h>

#define ARRLENGTH(a) (sizeof(a)/sizeof(*a))

int main() {

	int numbers[] = {1, 2, 3, 4, 5, 9, 4};
	short nu[] = {1, 2, 3, 4, 5, 9, 4};
	char n[] ={1, 2, 3, 4, 5, 3, 3};

	// 28 = 7 * 4

	/**
	 *
	 * 1 Byte =  8 Bit | char
	 * 2 Byte = 16 Bit | short
	 * 4 Byte = 32 Bit | int
	 * 8 Byte = 64 Bit | long
	 *
	 * sizeof(v) / "Byte-size of v" = "number of elements of v"
	 *
	 * Now, you don't wanna keep track of the types of your arrays by hand, so if you're clever you use:
	 * length = sizeof(array)/sizeof(array[0])
	 *
	 */

	// arrays are defined by where they start...
	printf("%d\n", nu);	// (prints the pointer/address to nu)
	printf("%d\n", &nu);	// ... which means nu and &nu are the same thing: the pointer to the first element of nu...
	printf("%d\n", &nu[0]); // ... which means nu is the same as literally the pointer to the first element of nu: &(nu[0])...
	printf("%d\n", nu[0]);	// (prints the value of the first element of nu)
	printf("%d\n", *nu);	// ... which also means, that dereferencing nu yields the value of the first element of nu
	// this also means that
	//   sizeof(a)/sizeof(a[0])   and
	//   sizeof(a)/sizeof(*a)     are the same thing...
	//
	// keep this straight in your brain: an array is nothing but a bunch of values, that are in memory directly after each other!
	// because they are right after each other, you don't need to keep track of them individually, you only need to know, exactly
	// where to start looking for them and then you can offset from there! So an array is the pointer to the first element of the
	// list of consecutive elements in memory, nothing more or in any way fancy.

	printf("%d\t%d\n\n", sizeof(nu), ARRLENGTH(nu));

	printf("%d\t%d\n", sizeof(numbers), sizeof(numbers)/4);
	printf("%d\t%d\n", sizeof(nu),      sizeof(nu)/2);
	printf("%d\t%d\n", sizeof(n),       sizeof(n)/1);		// sizeof returns the bit size, so it returns 2^type-power as size
	// for (char i = 0; i < numbers.length(); i++) {
		//printf("%d\n", numbers[i]);
		// printf("%d\n", numbers[3]);
	// }

	return 0;
}
