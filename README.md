[![Build Status](https://travis-ci.com/Gregory-Meyer/strlen.svg?branch=master)](https://travis-ci.com/Gregory-Meyer/strlen)

A little function to compute the length of a null-terminated string. Almost as fast as my standard
library's implementation.

Output of `./bench` on my system, a 2017 Surface Pro i7 running Arch Linux.

```
--------------------------------------------------------------------
Benchmark                             Time           CPU Iterations
--------------------------------------------------------------------
benchmark_strlen/0                    8 ns          8 ns  78555381
benchmark_strlen/1                    8 ns          8 ns  83346525
benchmark_strlen/8                    9 ns          9 ns  75439269
benchmark_strlen/64                  19 ns         19 ns  36910904
benchmark_strlen/512                 26 ns         26 ns  26536099
benchmark_strlen/4096               118 ns        117 ns   5915315
benchmark_string_length/0             2 ns          2 ns 417515740
benchmark_string_length/1             2 ns          2 ns 311759642
benchmark_string_length/8             7 ns          7 ns  97849345
benchmark_string_length/64           19 ns         19 ns  36237146
benchmark_string_length/512          31 ns         30 ns  22916379
benchmark_string_length/4096        146 ns        146 ns   4832956

```
