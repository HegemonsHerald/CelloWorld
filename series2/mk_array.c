#include <stdio.h>

// defines and inits an array
#define MK_ARRAY(TYPE, NAME, LENGTH, INIT)	\
	TYPE NAME[LENGTH]; for(int i=0;i < LENGTH; NAME[i] = INIT, i++) {}

// defines and inits an array, AND CREATES A LENGTH VARIABLE
#define mk_array(TYPE, NAME, LENGTH, INIT)	\
	int len_of_ ## LENGTH;			\
	MK_ARRAY(TYPE, NAME, LENGTH, INIT)

// expands into the LENGTH VARIABLE of an array made with mk_array
#define len(arr)	len_of_ ## arr


int main() {

	int arr1[42];
	for(int i=0; i<42; arr1[i] = 0, i++) {}

	mk_array(int, arr2, 42, i);

	// ain't perfect, but it's at least a little bit shorter ...
	// and now you can implicitely store the length of an array!

	// apparently the c stdlib can be found in man(3), so:
	// $>  man 3 ...

	for(int i=0; i < len(arr2); printf("%d\n", arr2[i]), i++) {}

	return 0;
}
