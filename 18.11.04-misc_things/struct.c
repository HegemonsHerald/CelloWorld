#include <stdio.h>

// what struct thing looks like
struct thing {
	char honk[20];
	int answer;
};


int main() {

	// thonk is of type 'struct thing'
	// to initialize you just write, what's to go in each field
	struct thing thonk = { "clairevoyance", 42 };

	/**
	 * Note: Since a structure is a single unit in memory,
	 * whose fields have a specific order, you always know
	 * in which order the fields have to be filled in.
	 * In this example the first field 'honk' is a String,
	 * so the first piece of data in thonk's initialization
	 * is also a string literal, while the second field is
	 * an int and the second piece of data is also an integer.
	 *
	 * With arrays you always know how long they are.
	 * With structs you always know their - well - structure.
	 *
	 * struct thing looks like this:
	 *
	 *                       honk                                          answer
	 * thonk: |pointer|----| |                                             |
	 *                     v v                                             v
	 * memory:   ... | ... | c | l | a | ... | c | e | ... (till 20) ... | 42 | ... | ...
	 *
	 * - thonk points to the beginning of the struct
	 * - the honk accessor gives the offset of the first field of the struct from that pointer, which is 0
	 * - the answer accessor gives the offset of the second field of the struct from that pointer, which is 20 because honk is 20 bytes long
	 *
	 * From that follow, that if you print the pointer of thonk and the fields of thonk, you should see the memory addresses follow those offsets,
	 * which is exactly what is shown with the printf statement below.
	 *
	 * Point is: you always know, where what is and how large it must be,
	 * so you don't need fancy initializer functions, you can just write
	 * it all out plainly in C.
	 *
	 */

	printf("printf thonk:                %d\n", thonk);
	printf("printf thonk.honk:           %s\n", thonk.honk);
	printf("printf thonk.answer:         %d\n\n", thonk.answer);
	printf("The pointer to thonk:        0x%x  %d\n", &thonk, &thonk);			// sth like: 0x77cb8d30
	printf("The pointer to thonk.honk:   0x%x  %d\n", &thonk.honk, &thonk.honk);		// the same: 0x77cb8d30
	printf("The pointer to thonk.answer: 0x%x  %d\n", &thonk.answer, &thonk.answer);	// added 20: 0x77cb8d44 (20 cause the char[] is 20 bytes long)

	int a = &thonk.answer;
	int b = &thonk.honk;
	int c = a - b;
	printf("\nJust for fun: The difference between &honk.answer and &honk.honk is %d!\nJust as expected.\n", c);

	return 0;
}
