#import <stdio.h>

int main() {

	/* 1. Just doing scanf() */

	// You need somewhere for the input to go, we want a single character, so:
	char character[2];
	// Note: this is a length 2 array, cause we'll get a character and a \0

	// Scanf for a character, note the reference to the beginning of our char-array
	scanf("%c", &character[0]);

	// Show me the character (not the \0 so we go for [0]!)
	printf("%c\n", character[0]);


	// Let's try for a string now, one that's less than or equal to 19 characters long
	char string[20];
	scanf("%s", string);
	printf("%s\n", string);


	// You can also use getchar and putchar, which use the stdin and stdout and listen/write to streams
	char c;
	while ( (c = getchar()) != EOF ) {
		putchar(c);
	}

	// Due to its stream-ing nature, getchar() will actually take any chars you type in, until it finds a \n

	return 0;
}
