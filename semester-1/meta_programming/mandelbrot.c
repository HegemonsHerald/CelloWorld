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

// turn x and y from screenspace into r and i in complex space
#define TO_COMPLEX(x, y)	((float) x / (float) WIDTH)  * C_WIDTH  + TOP_LEFT_R,\
				((float) y / (float) HEIGHT) * C_HEIGHT + TOP_LEFT_I

// compute mandelbrot orbit of length iters, starting at cr and ci
float mandelbrot(int iters, float cr, float ci) {

	return

	// yup, this is literally just ONE LARGE EXPRESSION

	LOOP_N( i, iters,

		// init vars
		Φ(float  a = 0.0,
			 b = 0.0,
			zr = 0.0,
			zi = 0.0), 

		// compute mandelbrot numbers
		(zr = a*a - b*b + cr,
		 zi = 2*a*b     + ci,
		  a = zr,
		  b = zi),

		// eval to absolute value of the final mandelbrot number
		sqrt(zr * zr + zi * zi) );

	/* THIS IS HOW YOU WOULD DO THIS USING MY LOOPS:

	float  a = 0.0,
	       b = 0.0,
	      zr = 0.0,
	      zi = 0.0;

	// compute!
	DO_TIMES(i, iters, (zr = a*a - b*b + cr,
			    zi = 2*a*b     + ci,
			     a = zr,
			     b = zi));

	// produce absolute value
	return sqrt(zr * zr + zi * zi);

	*/
}

int is_mandelbrot(float r, float i) { return 2.0 >= mandelbrot(ITERATIONS, r, i); }

int main() {

	DO_TIMES(y, HEIGHT,
	  DO_TIMES(x, WIDTH,
	    printf(is_mandelbrot(TO_COMPLEX(x, y)) ? "#" : " "));
	  printf("\n"));

	return 0;

}
