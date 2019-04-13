#include <stdio.h>

// do action count times
// action will be appended with a ';', so it may be just an expression
#define DO_TIMES(action, count, counter)	for(int counter = 0; counter < count; counter++) { action; }
// #define DO_TIMES(counter, count, action)	for(int counter = 0; counter < count; counter++) { action; }

// *******************************************************************************************************************************************************************
// THE NEXT COUPLE OF DO LOOPS EMULATE THE LISP-DO LOOPS. IT'S NOT ADVISABLE TO USE THESE, BECAUSE THE AREN'T PARTICULARLY READABLE. C IS NOT LISP, AND NEVER WILL BE.
// FOR THESE KINDS OF LOOPING OPERATIONS, USE THE FOR-LOOP DIRECTLY!
// This was an attempt to see, if it could be done at all, and relies on block expressions, which aren't a part of the standard.

// DO_TIMES with a return expression
// first run pre_form, then do action_from count times, then run return_form as the return expression
// pre_form should be used to declare any persistent state, needed for the return_form
#define DO_TIMES_E(counter, count, pre_form, action_form, return_form)	({ pre_form; for(int counter=0; counter < count; counter++) { action_form; }; return_form; })

// run inits, then loop until terminate becomes false.
// runs update on every iteration
// runs return, when terminate becomes false; that becomes the value
// values declared in init are available in return.
/* this is basically lisp's do loop as a macro... it's really hard to use though */
#define DO_LOOP(init, update, terminate, return)	({ init; for(; terminate; update) {}; return; })
#define DO_LOOPB(init, update, terminate, return, body) ({ init; for(; terminate; update) { body; }; return; })
// #define DO_LOOP(init, update, terminate, return)	({ init; while(terminate) { update; }; return; })
// #define DO_LOOPB(init, update, terminate, return, body)	({ init; while(terminate) { update; body; }; return; })

// *******************************************************************************************************************************************************************

// map fname over array ==> THIS IS IMPURE
#define MAPL(fname, array, length, counter)	DO_TIMES(array[counter] = fname(array[counter]), length, counter)

// do fname for each element of array
#define FORL(fname, array, length, counter)	DO_TIMES(fname(array[counter]), length, counter)

// print number, see below...
#define PRINTN(number)	printf("%d\n", number);

// this is a print macro, that can print ANY number, and prints anything else by
// stringifying it using a special macro-directive (#x)
#define printf_generic(x) _Generic((x), \
    char:           printf("%c",   x) , \
    signed char:    printf("%hhd", x) , \
    unsigned char:  printf("%hhu", x) , \
    signed short:   printf("%hd",  x) , \
    unsigned short: printf("%hu",  x) , \
    signed int:     printf("%d",   x) , \
    unsigned int:   printf("%u",   x) , \
    long int:       printf("%ld",  x) , \
    long long int:  printf("%lld", x) , \
    float:          printf("%f",   x) , \
    double:         printf("%f",   x) , \
    long double:    printf("%Lf",  x) , \
    char *:         printf("%s",   x) , \
    void *:         printf("%p",   x) , \
    unsigned long int: printf("%lu", x) , \
    unsigned long long int: printf("%llu", x) , \
    default:        printf("%s",  #x) )

#define PRINT(x)	printf_generic(x)
#define PRINTLN(x)	printf_generic(x), printf("\n")

/* Now, this behemoth macro certainly is very interesting,
 * although it only works with numbers........
 * Anyways, it's probably better to instead use local
 * type-specific helper macros, cause this thing will out-
 * put a warning on every type-case, that didn't match. =(
 *
 * ;)
 */



// helpers
#define TIMES2(n)	2 * (n) 
int timesTwo (int n) { return 2 * n; }

int main() {

	int vals[] = { 1, 10, 100, 1000, 10000 };

	int vals_copy[5];


	DO_TIMES(vals[i] = timesTwo(vals[i]), 5, i);
	// for(int i = 0; i < 5; vals[i]=timesTwo(vals[i]), i++) {}
	// I know I shouldn't use this, but it's sooooo fucking coooool!

	DO_TIMES(printf("%d\t", vals[i]), 5, i);
	// for(int i = 0; i < 5; i++) { printf("%d\n", vals[i]; }

	MAPL(timesTwo, vals, 5, i);
	// for(int i = 0; i < 5; i++) { vals[i] = timesTwo(vals[i]); }

	// Yup, partial syntax... I know, it's bad.
	FORL(vals_copy[i] = , vals, 5, i);
	// for(int i = 0; i < 5; i++) { vals_copy[i] = (vals[i]); }

	MAPL(TIMES2, vals, 5, i);
	// for(int i = 0; i < 5; i++) { vals[i] = 2 * (vals[i]); }

	FORL(PRINTLN, vals, 5, i);
	// for(int i = 0; i < 5; i++) { PRINTN(vals[i]); }
	// for(int i = 0; i < 5; i++) { printf("%d\n", vals[i]); }

	FORL(PRINTLN, vals_copy, 5, i);

	PRINTLN("yupdidoodle");


	int height=4, width=4;
	for (int x=0,y=0; y < height; x<width-1 ? x++ : (x=0,y++)) { printf("y: %d\tx: %d\n", y, x); }

	DO_TIMES( DO_TIMES( printf("y: %d\tx: %d\n", y, x), width, x), height, y );

	/* If you need multiple multi-dimensional loops, consider this:

#define DO_TIMES(counter, count, action)	for(int counter = 0; counter < count; counter++) { action; }
#define DO_TIMES_2D(x_name, y_name, width, height, action)	DO_TIMES(y_name, height, DO_TIMES(x_name, width, action))

	DO_TIMES_2D( x, y, width, height, printf("y: %d\tx: %d\t index: %d\n", y, x, y*width+x) );

	*/

	// This is how you do the switch expression right!

	int number = 12;

	int n =   number == 1 ? 3
	        : number == 3 ? 5
		: number == 5 ? 7
		: number == 7 ? 1
		              : 42;

	PRINTN(n);

	int x = { printf("honk\n"), 88 };
	PRINTN(x);

	int zz = ({ int x=0; for(int i=0, s=0; i<=10; s+=i++) {x=s;}; x; });
	PRINTN(zz);


	int zzz = DO_TIMES_E(i, 11, int s=0, s+=i, s);
	int zzzz = 0; for(int i=0, sum=0; i<=10; sum+=i++) {zzzz=sum;}

	// compute fibonacci
	int f = DO_TIMES_E(i, 5, int f=0;int c=1;int p=1, (f=c, c+=p, p=f), c);
	PRINTN(f);

	int ff = DO_LOOP(int f = 0; int c = 1; int p = 1; int n = 5,\
			 (f=c, c+=p, p=f, n--),\
			 n>0,\
			 c);
	PRINTN(ff);

	PRINTN(fib_do_times(4)  );
	PRINTN(fib_do_times_e(4));
	PRINTN(fib_do_loop(4)   );
	PRINTN(fib(4)           );

	return 0;
}

int fib_do_times(int n) {
	int f=0,current=1, previous=1;
	DO_TIMES((f=current,current+=previous,previous=f), (n-1), i);
	return current;
}

int fib_do_times_e(int n) {
	return DO_TIMES_E(\
		i, n-1, \
		int f=0;int c=1;int p=1, \
		(f=c,c+=p,p=f), \
		c);
}

int fib_do_loop(int n) {
	return DO_LOOP(\
		int f = 0; int c = 1; int p = 1, \
		(f=c, c+=p, p=f, n--), \
		n>1, \
		c);
}

int fib(int n) {
	return    n == 0 ? 1
		: n == 1 ? 1
		: fib(--n) + fib(--n);
}
