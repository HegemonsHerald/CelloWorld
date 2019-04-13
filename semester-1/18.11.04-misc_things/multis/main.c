#include <stdio.h>

// A structure to represent integers and strings
struct ANYTYPE {

	enum {
		Int,	// if anytype is an int, make this an Int
		Str,	// if anytype is a string, make this an Str
		Any,	// if anytype is an anytype
	} type;

	void* value;	// generic type to hold any value

};

struct ANYTYPE2 {

	enum {
		Int,
		Str,
		// ...
	} type;

	union {			// union: a struct whose members don't HAVE to be initiliazed (are optional)
		int i;		// if anytype is an int, assign the value to i
		char s[5];	// if anytype is a char, assigne the value to s
	} value;

};

void print(struct ANYTYPE a) {
	printf("%s", a.value);
}


int main() {

	// make a vim cmd to make a c file

	struct ANYTYPE a = { Str, "honk\n" };
	print(a);
	
	struct ANYTYPE2 b = { Int, { 32 } };
	struct ANYTYPE c = { Any, &b };
	print(c);

	return 0;
}
