#include <stdio.h>

/* PREPROCESSING. */

// print newline
#define NL	printf("\n")

// compute length of an array, assuming, that it has at least one element
#define A_LEN(arr)	(sizeof(arr)/sizeof(arr[0]))

// assigns the result of evaluating exp to each element of arr
// the index is called i
// the current element is available as \`el\`
#define MAP(arr, exp...)	LOOPN(A_LEN(arr), typeof(arr[i]) el = arr[i]; arr[i] = exp)

// assigns the result of evaluating exp for each element of src to the corresponding element of dst
// (for mapping across types)
// the index is called i
// the current element is available as \`el\`
#define MAP_TO(src, dst, exp...)	LOOPN(A_LEN(src), typeof(src[i]) el = src[i]; dst[i] = exp)

// executes a number of statements for each element of an array (no implicit assignment)
// the index is called i
// the last statement will have a \`;\` appended
// you may use \`el\` to refer to the current element
#define FOR_EACH(arr, sttmnt...)	for(int i=0; i<A_LEN(arr); i++) { typeof(arr[i]) el = arr[i]; sttmnt; }

// do statements a number of times
// specify the counter variable's name, so you can use multiple ones of these in each other
// the last statement has a \`;\` appended
#define DO_TIMES(counter, count, sttmnt...)	for(int counter=0; counter<count; counter++) { sttmnt; }

// like DO_TIMES, only the counter is always called \`i\`
#define LOOPN(count, sttmnt...)	DO_TIMES(i, count, sttmnt)

// defines and inits an array
#define MK_ARRAY(TYPE, NAME, LENGTH, INIT)	\
	TYPE NAME[LENGTH]; DO_TIMES(i, LENGTH, NAME[i] = INIT)

// defines and inits an array, AND CREATES A LENGTH VARIABLE
#define mk_array(TYPE, NAME, LENGTH, INIT)	\
	int len_of_ ## NAME = LENGTH;		\
	MK_ARRAY(TYPE, NAME, LENGTH, INIT)

// expands into the LENGTH VARIABLE of an array made with mk_array
#define len(arr)	len_of_ ## arr

/* THIS IS WHERE THE MAGIC STARTS */

int main() {

	mk_array(int, honk, 9, 12 * i);

	DO_TIMES(i, len(honk), printf("%d", honk[i]));
	NL;

	FOR_EACH(honk, printf("%d", el));
	NL;

	return 0;
}
