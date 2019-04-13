#include <stdio.h>

/* PREPROCESSING. */

// print newline
#define NL	printf(\"\n\")

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



/* THIS IS WHERE THE MAGIC STARTS */

int main() {

	return 0;
}
