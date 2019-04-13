#include <stdio.h>
#include <locale.h>

int f1(int a, int b, int c, int d) {
	return (a && b && c) || (a && !b && c && d) || (a && !b && c && !d) || (a && !b && !c && !d) || (!a && b && c && d) || (!a && b && c && !d) || (!a && !b && !c && !d) || (!a && !b && c) || (a && b && !c && d) || (a && b && !c && !d);
}

int f2(int a, int b, int c, int d) {

	return (!b && !d) || c || (a && b);

}

int main() {

	// Make unicode work
	setlocale(0, "");

	for(int a = 0; a < 2; a ++) {
		for(int b = 0; b < 2; b ++) {
			for(int c = 0; c < 2; c ++) {
				for(int d = 0; d < 2; d ++) {

					printf("f1 a:%d b:%d c:%d d:%d   %d\n", a, b, c, d, f1(a,b,c,d));
					printf("f2 a:%d b:%d c:%d d:%d   %d\n", a, b, c, d, f2(a,b,c,d));

				}
			}
		}
	}

	return 0;

}

