#include <stdio.h>

#define A(a)	A(a)

int main() {


	printf(A(9));

	/* It would seem you can indeed use
	 * recursive preprocessor definitions,
	 * though it isn't advisable for obvious
	 * reasons.
	 *
	 * YEEEEAAAASSSSS!!!!!! Whooo-hooo!
	 */


return 0;
}
