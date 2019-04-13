#include <stdio.h>


#define DO_TIMES(counter, count, action)	for(int counter = 0; counter < count; counter++) { action; }

// expressionify statements
#define E(args...)	({ args; })

// do_times loop as an expression
// run pre, then do_times with counter, count and action, then evaluate to post
#define LOOP_N(counter, count, pre, action, post)	E(pre; DO_TIMES(counter, count, action); post)

// compute length of array
#define ALENGTH(array)	sizeof(array) / sizeof(array[0])

// fold over an array.
// provides an accumulator variable called 'acc' of type acc_type, with initial value start_value.
// action must evaluate to the new value of acc.
// the expression evaluates to acc's final value.
// you may use elem as the current element and i as the index of elem.
#define FOLD(array, type, acc_type, start_value, action)	\
E(int LENGTH = ALENGTH(array);		\
  acc_type acc = start_value;					\
  DO_TIMES(i, LENGTH, type elem = array[i]; acc = action);		\
  acc)

// sum up numeric values in array by using a fold
#define SUM(array, type, start)	FOLD(array, type, type, start, acc + elem)

#define Φ(args...)	args

int main() {

	int sum_10 = LOOP_N(i, 11, int s=0, s+=i, s);

	int nums[] = { 1, 2, 3, 4, 5, 6 };
	float n[] = {1.0, 2.0, 3.0, 4.0, 5.0, };

	// acc_update_action: if i==0 there is no previous element to compare to...
	int is_sorted = FOLD(nums, int,
			     int, 1, // acc is boolean, starting with true
			     acc && (i == 0 ? 1 : nums[i-1] <= elem)); // set acc to false, if the last two elems aren't sorted

	float average = SUM(n, float, 0.0) / ((float) ALENGTH(n));

	float super_sum = SUM(n, float, ((float) SUM(nums, int, 0)));

	printf("%d\n", sum_10);
	printf("is sorted: %d\n", is_sorted);
	printf("average: %f\n", average);
	printf("super_sum: %f\n", super_sum);

	return 0;
}
