#include <stdio.h>
#include <math.h>

#define Φ(args...)	args
#define E(args...)	({ args; })
#define DO_TIMES(counter, count, action)	for(int counter = 0; counter < count; counter++) { action; }
#define LOOP_N(counter, count, pre, action, post)	E(pre; DO_TIMES(counter, count, action); post)

#define WIDTH		1000	// output height
#define HEIGHT		500	// output width
#define ITERATIONS	400	// iterations for test
#define C_WIDTH		2.5	// width  of complex rect
#define C_HEIGHT	2.5	// height of complex rect
#define TOP_LEFT_R	-1.5	// real part of complex anchor
#define TOP_LEFT_I	-1.5	// imag part of complex anchor

// turn x and y from screenspace into r and i in complex space
#define TO_COMPLEX(x, y)	((float) x / (float) WIDTH)  * C_WIDTH  + TOP_LEFT_R,\
				((float) y / (float) HEIGHT) * C_HEIGHT + TOP_LEFT_I

// compute mandelbrot orbit of length iters, starting at cr and ci
// THIS ONE USES TAIL CALL RECURSION
float mandelbrot(int iters, float zr, float zi, float cr, float ci) {
	return   iters <= 0 ?
		 sqrt(zr * zr + zi * zi)
	       : mandelbrot(--iters,
			    zr*zr - zi*zi + cr,
			    2*zr*zi + ci,
			    cr, ci);
}

int is_mandelbrot(float r, float i) { return 2.0 >= mandelbrot(ITERATIONS, 0.0, 0.0, r, i); }

int main() {

	DO_TIMES(y, HEIGHT,
	  DO_TIMES(x, WIDTH,
	    printf(is_mandelbrot(TO_COMPLEX(x, y)) ? "#" : " "));
	  printf("\n"));

	return 0;

}
