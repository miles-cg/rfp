# rfp
Range Finding Puzzle

From the paper [Index-Of, A 30-Year Quest](https://www.jsoftware.com/papers/indexof/indexof.htm) by Roger Hui.

## Problem

Find the maximum of a vector of 1-byte ints without using multicore, vector instructions, loop unrolling, etc.
Can you do it faster in C than the following?

    max=*x++; for(i=1;i<n;++i){if(max<*x)max=*x; ++x;}

Hint:

    x←?1e6⍴1000
    a. ¯1+{≢⍵}⌸(⍳1000),x     1.00       (_1+#/.~(i.1000),x  )
    b. ¯1+{≢⍵}⌸(⍳1+⌈/x),x    1.62       (_1+#/.~(i.1+>./x),x)

That is, # occurrences of unique elements of x takes 1.00 ;   maximum of x takes 0.62

A solution to the puzzle is faster by a factor of 1.5
