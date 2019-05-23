The raw data:

| number of threads | ms taken | time taken compared to 1 thread |
| :-: | :-: | :-: |
| 1 | 666 | 100% |
| 2 | 387 | 58.1081% |
| 4 | 323 | 48.4985% |
| 8 | 315 | 47.2973% |


As a (very low resolution) graph:

```
    ▲
ms  |
    |
700 | x
600 |
500 |
400 |    x
300 |          x           x
200 |
100 |
    +---------------------------------▶
      1  2  3  4  5  6  7  8  threads
```
The ms counts are rounded to the nearest multiple of 100ms.

It is obvious, that the speed increase of adding a new thread becomes marginal and smaller the more threads have been added.  Using more than maybe 3 threads to count the number of primes, does not constitute a notable speed increase anymore.

This may be due to scheduling trouble and mostly due to the additional overhead of creating and switching to threads. After using more than two threads the time each thread takes is more and more determined by its overhead, less by the actual time it spends computing, which serves to heavily dampen the ideal speed increase we would like to gain by making the workload of a single thread smaller again. 

It is also notable, that there are only so many threads which will truly run in parallel. This is determined by the hardware and the scheduler in use. Once one crosses the maximum number of threads, which actually can run in parallel, the extra threads will be run in basically a sequential fashion, only with multiple sequences. This further limits the increase in speed we can hope to gain by adding more threads.
