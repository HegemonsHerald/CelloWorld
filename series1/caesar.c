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
