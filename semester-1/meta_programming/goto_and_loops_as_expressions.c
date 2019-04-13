#include <stdio.h>

#define EXPR(expr...)	({ expr; })
#define GOTO(label)	({ goto label; })


int main() {

	int count = 5;

	int fib = ({
		int n=0, f=0, c=1, p=1;

	loop:	(f=c, c+=p, p=f, n++),
		n < count ? ({ goto loop; }) : 0;

		c;
	});


// dig: t*
#define τ(args...)	args

// This is a general-purpose for loop, that expands as an expression
// type is used to declare the return value.
// return_expr will be assigned to the return value.
#define FOR(expr1, expr2, expr3, return_expr, type)		\
	({ type ret;						\
	   for(expr1; expr2; expr3) { ret = return_expr; }	\
	   ret; })

#define FIB(count)	FOR(τ(int n=0, f=0, c=1, p=1), n <= count, (f=c, c+=p, p=f, n++), ret=c, int);

	int ffib = FIB(5);


	// as one can see, I don't really get much out of this macro....
	int sum = FOR(τ(int i=0, sum=0), i<=10, (sum += i++), sum, int);
	int ssum; for(int i=0, sum=0; i<=10; sum += i++) { ssum = sum; }

#define LOOP(init, cond, update, return, type)			\
	({ type ret;						\
	   init;						\
	   while( cond ) {					\
	   	update;						\
	 	ret = return;					\
	   }							\
	   ret; })						\

	// this is exactly the same thing, just with a while loop, so it allows
	// for statements in the loop expressions...
	int sssum = LOOP(τ(int i=0, sum=0), i<=10, (sum += i++), sum, int);
	int ssssum = LOOP(\
		τ(int i=0, sum=0; printf("Initialized Loop Vars.\n")),\
		i<=10,\
		sum += i++;       printf("Updated Loop Vars. %d %d\n", i, sum),\
		sum, int);


	// These macros are sth to keep up my sleeves, for if I ever actually
	// need to do a proper loop in an expression and I really don't want
	// to extract it out into a pre-statement of some kind.
	//
	// These macros are less readable, but they make loops be expressions.
	// I like 'em. =)



	printf("%d\n", fib);
	printf("%d\n", ffib);

	
#define DO_TIMES(counter, count, action)	for(int counter = 0; counter < count; counter++) { action; }

	DO_TIMES(n, 10, printf("%d %d\n", n, fibonacci(n)));

	return 0;
}

// just a copy of FOR called (dig:) F*
#define Φ(expr1, expr2, expr3, return_expr, type)		\
	({ type ret;						\
	   for(expr1; expr2; expr3) { ret = return_expr; }	\
	   ret; })

int fibonacci(int n) {
	// and i know, that the Φ-loop includes correct results for n=0 and n=1...
	// this is showing off!
	return    n == 0 ? 1
		: n == 1 ? 1
		: Φ(τ(int f=0,i=0,c=1,p=1), i<=n-1, (f=c,c+=p,p=f,i++), c, int);
}
