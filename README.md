[![Build Status](https://travis-ci.com/Gregory-Meyer/strlen.svg?branch=master)](https://travis-ci.com/Gregory-Meyer/strlen)

A little function to compute the length of a null-terminated string. Almost as fast as my standard
library's implementation.

Output of `./bench` on my system, a 2017 Surface Pro i7 running Arch Linux.

```
-------------------------------------------------------------
Benchmark                      Time           CPU Iterations
-------------------------------------------------------------
bm_stdlib/0                    8 ns          8 ns   80608858
bm_stdlib/1                    8 ns          8 ns   82170845
bm_stdlib/8                    9 ns          9 ns   75452795
bm_stdlib/64                  19 ns         19 ns   37051008
bm_stdlib/512                 24 ns         24 ns   28866023
bm_stdlib/4096               118 ns        117 ns    6025466
bm_naive/0                     2 ns          2 ns  384836255
bm_naive/1                     2 ns          2 ns  412423744
bm_naive/8                     6 ns          6 ns  123375341
bm_naive/64                   31 ns         31 ns   22590948
bm_naive/512                 178 ns        177 ns    3955587
bm_naive/4096               1449 ns       1441 ns     485621
bm_string_length/0             2 ns          2 ns  417131219
bm_string_length/1             2 ns          2 ns  310021220
bm_string_length/8             7 ns          7 ns   96750934
bm_string_length/64           19 ns         19 ns   36768390
bm_string_length/512          24 ns         24 ns   29141574
bm_string_length/4096        144 ns        144 ns    4924037

```
