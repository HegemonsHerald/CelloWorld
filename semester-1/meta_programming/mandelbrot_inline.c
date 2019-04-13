#include <stdio.h>
#include <math.h>

#define Φ(args...)	args
#define E(args...)	({ args; })
#define DO_TIMES(counter, count, action)	for(int counter = 0; counter < count; counter++) { action; }
#define LOOP_N(counter, count, pre, action, post)	E(pre; DO_TIMES(counter, count, action); post)

#define WIDTH		100	// output height
#define HEIGHT		50	// output width
#define ITERATIONS	400	// iterations for test
#define C_WIDTH		2.5	// width  of complex rect
#define C_HEIGHT	2.5	// height of complex rect
#define TOP_LEFT_R	-1.5	// real part of complex anchor
#define TOP_LEFT_I	-1.5	// imag part of complex anchor

#define LET(bindings, expression)	bindings; expression;

int main() {

	// This is the completely inlined version of the mandelbrot expression.
	// As one can see, it doesn't contain a single semi-colon, I haven't written a single statement myself.

	// LET should be an expression, I think. And maybe recursive over its arguments or sth...
	// then you could write functions like return LET(...); and that'd be neat! =)

	DO_TIMES(y, HEIGHT,

	  DO_TIMES(x, WIDTH,

	    LET(float mandelbrot =

	              LOOP_N(i, ITERATIONS,

			// declarations
	                Φ(float  a = 0.0,
	                         b = 0.0,
	                        cr = ((float) x / (float) WIDTH)  * C_WIDTH  + TOP_LEFT_R,
	                        ci = ((float) y / (float) HEIGHT) * C_HEIGHT + TOP_LEFT_I,
	                        zr = 0.0,
	                        zi = 0.0),

			// z' = z*z + c
	                (zr = a*a - b*b + cr,
	                 zi = 2*a*b     + ci,
	                  a = zr,
	                  b = zi),

			// abs(z)
	                sqrt(zr * zr + zi * zi) ),

		// print # if mandelbrot is in the set
	        printf(2.0 >= mandelbrot ? "#" : " ")))
	  
	  // newline at end of row
	  printf("\n"))

	return 0;
}
