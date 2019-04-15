#include <stdio.h>

// print newline
#define NL	printf("\n")

// compute length of an array, assuming, that it has at least one element
#define A_LEN(arr)	(sizeof(arr)/sizeof(arr[0]))

#define IS_UPPER(c)		(64 < c && c < 91)
#define IS_LOWER(c)		(96 < c && c < 123)
#define CAESAR_SHIFT(c, offset)	((((c - offset) + 3) % 26) + offset)

char encode(char c) {
	return    IS_UPPER(c) ? CAESAR_SHIFT(c, 65)
		: IS_LOWER(c) ? CAESAR_SHIFT(c, 97)
		: c ;
}

/* How to do it almost properly...

int main( int argc, char *argv[] ) {

	// handle error case
	if (argc == 1) {
		printf("USAGE: %s <string>\n\n<string>\tstring to encode using the caesar cipher\n", argv[0]);
		return -1;
	}

	// Turns out, using A_LEN() on argv[1] produces incorrect results, cause the size
	// of argv[1] ain't known at compile-time...

	// Iterate printing encoded chars til you hit the null-terminator
	for(int i = 0
	   ; argv[1][i] != '\0'
	   ; printf("%c", encode(argv[1][i])), i++) {}

	NL;

	return 0;
}
*/


/* How to do it as just one large expression!

void encode_arg(char string[]) {

	for(int i=0
	  ; string[i] != '\0'
	  ; printf("%c", encode(string[i])), i++) {}

	printf("\n");

}

#define ERR_MSG "error message, yup\n"

int main( int argc, char *argv[] ) {
	return    argc == 1 ? printf("%s", ERR_MSG), -1
		: encode_arg(argv[1]), 0;
}

*/


/* Now for TAIL CALLS, so NO FUCKING FOR LOOPS! */


// Re-Clarifications on pointers, cause they really turn confusing quickly when using arrays and shit
// 1. you have values and you have pointers to values (variables holding references).
// 2. if you have a value, you can get its address using &value
// 3. you make a pointer by declare <type> * <name>, where <type> is the type the pointer points to
// 4. an array is a pointer to the first element of the array
// 5. the argv array is an array of strings, which are themselves arrays, so it must be a pointer to a pointer or pointers --> either char ** argv or char * argv []
// 6. you pass a reference to the first element of argv by using argv directly
// 7. you pass a reference to the first char of the first element of argv by using argv[0] or *argv
//
// A pointer to a char is the same as a string. An array of chars is a pointer to the first char, ergo a string is nothing but a char *.


// this is the solution I want to hand in: it uses everything I love!
//  - only return statements, no bolloks no one needs
//  - tail recursion instead of fucking looping statments
//  - ternary for conditionals so this is some real proper stuff
//  - macros, cause you know, macros
//  - best of all: pointer arithmetic, just cause!

#define ERR_MSG "error message, yup\n"

int encode_arg(char *c) {
	return *c == '\0' ? ( printf("\n"), 0 )					// reach end of argv:	print newline and return successfully
			  : ( printf("%c", encode(*c)), encode_arg(&c[1]) );	// otherwise:		encode character, print it, continue with next character
}

int main( int argc, char **argv ) {
	return argc == 1 ? printf("%s", ERR_MSG), -1	// no arg was given:	print error message, return unsuccessfully
			 : encode_arg(argv[1]);		// otherwise:		print the arg encoded
}

// test string to prove the bit with the tail calls and you know...
// spoilers: it does not stack overflow
// Here's a test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string test string
