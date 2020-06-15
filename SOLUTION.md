There are three solutions located in the file `rfp.c`:

## baseline

This is the straightforward implementation given in the problem description.

## pair

This processes the input array in pairs of elements
It starts off initially with a single value if the length is odd, otherwise the max of the first two.

## table

This creates a table to keep tracks of which values have been visited.
Since the input is consists of 1 byte integers, the range of values is 0 – 255, so that a table of length 256 is needed.
Then iterate through that table from the end, and break on the first visited value which will be the maximum.

# Benchmark

Results using the executable generated with the `makefile`:

```
-----------------------------------------------------------
Benchmark                 Time             CPU   Iterations
-----------------------------------------------------------
baseline/1000000        420 us          419 us         1669
pair/1000000            257 us          256 us         2730
table/1000000           214 us          214 us         3269
```

The performance of each relative to baseline is

Test     | Time | Speed-up
---------|------|---------
baseline |  419 |    1.000
pair     |  256 |    1.637
table    |  214 |    1.958

Of course, what are the results when you allow the compiler to perform its optimizations?

```
-----------------------------------------------------------
Benchmark                 Time             CPU   Iterations
-----------------------------------------------------------
baseline/1000000       16.7 us         16.6 us        42070
pair/1000000            256 us          256 us         2732
table/1000000           214 us          214 us         3273
```

The flags `-fno-vectorize -fno-unroll-loops -fno-builtin` were removed.

Only `baseline` was easily optimized by the compiler. Now what are the new values for relative performance?

Test     | Time | Speed-up
---------|------|---------
baseline |  16.6|    1.000
pair     | 256  |    0.065
table    | 214  |    0.078

Comparing against the previous `baseline` might help. (`optline` is `baseline` optimized)

Test     | Time | Speed-up
---------|------|---------
baseline | 419  |    1.000
optline  |  16.6|   25.241
pair     | 256  |    1.637
table    | 214  |    1.958

As shown, simpler algorithms are more readily optimized by the compiler.
