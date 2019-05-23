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

/**
 * Main program: Check n integer values for primes.
 */
int main(int argc, char* argv[])
{
	// Create n random integers in array
	int numValues = 10000;
	int values[numValues];
	for (int i = 0; i < numValues; i++) {
		values[i] = rand() % 900000 + 100000;
	}

	// Get current time for time measurement
	struct timeval startTime;
	gettimeofday(&startTime, NULL);

	// Check array for primes in main thread
	// TODO: Distribute this to m threads!
	int numPrimes = 0;
	for (int i = 0; i < numValues; i++) {
		if (isPrime(values[i])) {
			numPrimes++;
		}
	}

	// Measure computation time
	int msec = getElapsedTime(startTime);

	// Display results
	printf("Found %d primes in %d values in %d ms\n",
	       numPrimes, numValues, msec);

	return 0;
}
