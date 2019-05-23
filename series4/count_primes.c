#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h> // Include for use time functions
#include <pthread.h>  // Include for POSIX threads

/** Return milliseconds elapsed since given time. */
int getElapsedTime(struct timeval startTime)
{
	struct timeval stopTime, elapsedTime;
	gettimeofday(&stopTime, NULL);
	timersub(&stopTime, &startTime, &elapsedTime);
	return 1000*elapsedTime.tv_sec + elapsedTime.tv_usec/1000;
}

/** Return true if given number z is a prime number. */
bool isPrime(int z)
{
	int t = 2;
	int tmax = z / 2;
	while (t <= tmax && z % t != 0) {
		t++;
	}
	return t > tmax;
}

/* arguments for the thread-function */
struct chunk_arg {
	int lower;	// lower index of the INCLUSIVE range to operate on
	int upper;	// upper index of the INCLUSIVE range to operate on
	int* rands;	// pointer to the random numbers
};

/* Look for primes in a part of the array */
void* filter_chunk(void* param) {
	struct chunk_arg *arg = param;

	// count primes
	int number_of_primes = 0;
	for (int i = arg->lower; i <= arg->upper; i++)
		if (isPrime(arg->rands[i])) number_of_primes++;

	// return the number of counted primes
	pthread_exit((void*) number_of_primes);
}

/**
 * Main program: Check n integer values for primes.
 */
int main(int argc, char* argv[])
{

	// Extract the number of threads from the arguments
	char* str = argv[1];
	int N = atoi(str);

	// no less than 1 threads
	if (N < 1) {
		printf("ERROR: There has to be at least 1 thread.\n");
		exit(1);
	}

	// no more than 10 threads
	if (N > 10) N = 10;

	// Create n random integers in array
	int numValues = 10000;
	int values[numValues];
	for (int i = 0; i < numValues; i++) {
		values[i] = rand() % 900000 + 100000;
	}

	// Get current time for time measurement
	struct timeval startTime;
	gettimeofday(&startTime, NULL);

	// where to put the threads' handles
	pthread_t thread_handles[10];

	// where to put the threads' results, that is the number of primes each counted
	int thread_returns[10];

	// where to put the threads' configs/args
	struct chunk_arg args[10];

	// how much each thread has to compute
	int interval_width = numValues / N;
	int interval_rest  = numValues % N;	// don't forget what may not fit in

	// configure the threads' args
	for (int n = 0; n < N; n++) {

		// make a new argument struct, and put it neatly in memory
		args[n] = * (struct chunk_arg*) malloc(sizeof(struct chunk_arg));
		args[n].lower =   n   * interval_width;
		args[n].upper = (n+1) * interval_width -1;
		args[n].rands = values;

		// don't forget the cut-off
		if (n == N-1) args[n].upper = numValues -1;
	}

	// make the threads
	for (int n = 0; n < N; n++)
		pthread_create(&thread_handles[n], NULL, filter_chunk, (void*) &args[n]);

	// collect the threads
	for (int n = 0; n < N; n++)
		pthread_join(thread_handles[n], &thread_returns[n]);

	// collect the counted primes
	int numPrimes = 0;
	for (int n = 0; n < N; n++)
		numPrimes += thread_returns[n];

	// Measure computation time
	int msec = getElapsedTime(startTime);

	// Display results
	printf("Found %d primes in %d values in %d ms\n",
	       numPrimes, numValues, msec);

	return 0;
}
