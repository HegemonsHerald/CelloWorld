# Apparently this is mostly bogus.

The tables on the slides are hardly understandable without someone actually explainging them, ***THEY ARE BY NO MEANS SELF-EXPLANATORY*** and really actually rather untintuitive.
I don't like them. Fuck this shite.


### (a) FIFO

The Frame, that changed, is highlighted.  

New pages are loaded into frame 3, bumping all already loaded pages up one frame.
That way the page to replace is always the one in the frame with the lowest number.

| Anfragen: | 0 | 1 | 4 | 3 | 0 | 3 | 5 | 4 | 1 | 0 | 1 | 2 | 3 | 5 | 2 | 1 | 0 | 1 | 2 | 5 |
| :-        | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
| frame 0:  | **0** |   0   |   0   |   0   |   0   |   0   | **5** |   5   |   5   |   5   |   5   |   5   | **3** |   3   |   3   |   3   |   3   |   3   | **2** |   2   | 
| frame 1:  |   .   | **1** |   1   |   1   |   1   |   1   |   1   |   1   |   1   | **0** |   0   |   0   |   0   | **5** |   5   |   5   |   5   |   5   |   5   |   5   | 
| frame 2:  |   .   |   .   | **4** |   4   |   4   |   4   |   4   |   4   |   4   |   4   | **1** |   1   |   1   |   1   |   1   |   1   | **0** |   0   |   0   |   0   | 
| frame 3:  |   .   |   .   |   .   | **3** |   3   |   3   |   3   |   3   |   3   |   3   |   3   | **2** |   2   |   2   |   2   |   2   |   2   | **1** |   1   |   1   | 
| faults:   |   ✗   |   ✗   |   ✗   |   ✗   |       |       |   ✗   |       |       |   ✗   |   ✗   |   ✗   |   ✗   |   ✗   |       |       |   ✗   |   ✗   |   ✗   |       | 

**Total: 12 page faults**

### (b) SECOND CHANCE

The Frame, that changed, is highlighted.  
New pages are inserted as in (a), pages with a second chance are moved to frame 3, bumping the pages above to fill the vacancy.

| Anfragen:   | 0 | 1 | 4 | 3 | 0 | 3 | 5 | 4 | 1 | 0 | 1 | 2 | 3 | 5 | 2 | 1 | 0 | 1 | 2 | 5 |
| :-          | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
| frame 0:    | **0** |   0   |   0   |   0   |   0   |   0   |   0   |   0   | **1** |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |
| frame 1:    |   .   | **1** |   1   |   1   |   1   |   1   | **5** |   5   |   5   |   5   |   5   | **2** |   2   |   2   |   2   |   2   |   2   |   2   |   2   |   2   |
| frame 2:    |   .   |   .   | **4** |   4   |   4   |   4   |   4   |   4   |   4   |   4   |   4   |   4   | **3** |   3   |   3   |   3   | **0** |   0   |   0   |   0   |
| frame 3:    |   .   |   .   |   .   | **3** |   3   |   3   |   3   |   3   |   3   | **0** |   0   |   0   |   0   | **5** |   5   |   5   |   5   |   5   |   5   |   5   |
| faults:     |   ✗   |   ✗   |   ✗   |   ✗   |       |       |   ✗   |       |   ✗   |   ✗   |       |   ✗   |   ✗   |   ✗   |       |       |   ✗   |       |       |       |       
| change 1st: |   -   |   -   |   -   |   0   |   1   |   1   |   4   |   0   |   3   |   5   |   5   |   4   |   0   |   1   |   1   |   3   |   5   |   5   |   5   |   0   |
| change 2nd: |   -   |   -   |   -   |   1   |   4   |   4   |   0   |   3   |   5   |   4   |   4   |   0   |   1   |   2   |   3   |   5   |   2   |   2   |   0   |   1   |
| change 3rd: |   -   |   -   |   -   |   4   |   3   |   0   |   3   |   5   |   4   |   1   |   0   |   1   |   2   |   3   |   5   |   2   |   1   |   0   |   1   |   2   |
| change 4th: |   -   |   -   |   -   |   3   |   0   |   3   |   5   |   4   |   1   |   0   |   1   |   2   |   3   |   5   |   2   |   1   |   0   |   1   |   2   |   5   |

**Total: 11 page faults**

The "change …:" rows are there to illustrate the order in which the frame's values are to be replaced at any given point.
The first three columns aren't filled, as the queue doesn't apply for replacement before all frames are filled.

### (c) LEAST RECENT

The Frame, that changed, is highlighted.  

| Anfragen: | 0 | 1 | 4 | 3 | 0 | 3 | 5 | 4 | 1 | 0 | 1 | 2 | 3 | 5 | 2 | 1 | 0 | 1 | 2 | 5 |
| :-        | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
| frame 0:  | **0** |   0   |   0   |   0   |   0   |   0   |   0   |   0   | **1** |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |
| frame 1:  |   .   | **1** |   1   |   1   |   1   |   1   | **5** |   5   |   5   |   5   |   5   | **2** |   2   |   2   |   2   |   2   |   2   |   2   |   2   |   2   |
| frame 2:  |   .   |   .   | **4** |   4   |   4   |   4   |   4   |   4   |   4   |   4   |   4   |   4   | **3** |   3   |   3   |   3   | **0** |   0   |   0   |   0   |
| frame 3:  |   .   |   .   |   .   | **3** |   3   |   3   |   3   |   3   |   3   | **0** |   0   |   0   |   0   | **5** |   5   |   5   |   5   |   5   |   5   |   5   |
| faults:   |   ✗   |   ✗   |   ✗   |   ✗   |       |       |   ✗   |       |   ✗   |   ✗   |       |   ✗   |   ✗   |   ✗   |       |       |   ✗   |       |       |       |

**Total: 11 page faults**

### (d) OPTIMAL REPLACEMENT

The Frame, that changed, is highlighted.

| Anfragen: | 0 | 1 | 4 | 3 | 0 | 3 | 5 | 4 | 1 | 0 | 1 | 2 | 3 | 5 | 2 | 1 | 0 | 1 | 2 | 5 |
| :-        | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
| frame 0:  | **0** |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   |   0   | **3** |   3   |   3   |   3   | **0** |   0   |   0   |   0   |
| frame 1:  |   .   | **1** |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |   1   |
| frame 2:  |   .   |   .   | **4** |   4   |   4   |   4   |   4   |   4   |   4   |   4   |   4   | **2** |   2   |   2   |   2   |   2   |   2   |   2   |   2   |   2   |
| frame 3:  |   .   |   .   |   .   | **3** |   3   |   3   | **5** |   5   |   5   |   5   |   5   |   5   |   5   |   5   |   5   |   5   |   5   |   5   |   5   |   5   |
| faults:   |   ✗   |   ✗   |   ✗   |   ✗   |       |       |   ✗   |       |       |       |       |   ✗   |   ✗   |       |       |       |   ✗   |       |       |       |

**Total: 8 page faults**
