#include <stdio.h>
#define LEN(a) (sizeof(a)/sizeof(*a))

void pass(int *arrPointer) {
	printf("pass' arrPointer:\t%d\n", arrPointer);	// address of arr
	printf("pass' *arrPointer\t%d\n", *arrPointer);	// 9
}



int main() {

	int arr[5] = { 9, 3, 15, 1, 7 };

	printf("arr:\t%d\n", arr);		// address of arr
	printf("arr[0]:\t%d\n", arr[0]);	// 9
	printf("*arr:\t%d\n", *arr);		// 9

	int *pointA = &arr[0];
	int *pointB = arr;

	printf("pointA:\t%d\n", pointA);	// address of arr
	printf("pointB:\t%d\n", pointB);	// address of arr
	printf("*pointB:\t%d\n", *pointB);	// 9

	printf("sizeof(arr):\t%d\n", sizeof(arr));	// 20 for the whole array
	printf("sizeof(arr):\t%d\n", sizeof(arr[0]));	// 4 for just the first element

	pass(arr);

	/**
	 * Here's the deal:
	 * Because of history, array's aren't "first class citizens", meaning they aren't passed by value, by default.
	 * Also, the definition of the array is: a list of known length, containing values of known type adjacent in memory.
	 * You always know, how large an array is.
	 * The C++ vector is the variable length implementation of the array. Rust has that too, remember? That's where you
	 * can use the .len() method, not here, though. In rust you do have the array.len() method, but that's cause its rust.
	 * The compiler can substitute that value for the known-at-compile-time length of the thing.
	 *
	 */

}
