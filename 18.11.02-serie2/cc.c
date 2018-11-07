#include <stdio.h>

int main() {

	char a;
	while ((a = getchar()) != 0) {
		printf("%c\n", a);
	}

	return 42;
}
