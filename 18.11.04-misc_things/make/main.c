#include "stuff.h"

int main() {

	int a = 33;
	int b = 12389;

	int Sum = sum(a, b);
	int Sub = sub(a, b);

	ps("int a: ");
	p(a);
	PN;
	ps("int b: ");
	p(b);
	PN;
	ps("a + b: ");
	p(Sum);
	PN;
	ps("a - b: ");
	p(Sub);
	PN;

	return 0;
}
