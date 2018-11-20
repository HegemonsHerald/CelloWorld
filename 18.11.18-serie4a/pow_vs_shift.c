#include <stdio.h>

unsigned int pow(unsigned int number, unsigned int exponent) {
        unsigned int result = 1;
        while (exponent > 0) { // so lange der exponent nicht 0 wird...
                result *= number; // die zahl mit sich selbst multiplizieren!
                exponent--;
        }
        return result;
}
int main() {

	printf("result of pow: %d\n", pow(2, 8));
	printf("result of <<:  %d\n", 1 << 8);

}
