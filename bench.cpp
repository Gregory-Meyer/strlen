#include "string_length.hpp"

#include <cstring>

#include <chrono>

#include <benchmark/benchmark.h>

static constexpr std::size_t MAX_ITER = 4096;

static void benchmark_strlen(benchmark::State &state) {
    for (auto _ : state) {
        const std::string str(static_cast<std::string::size_type>(state.range(0)), 'a');

        benchmark::DoNotOptimize(std::strlen(str.c_str()));
    }
}
BENCHMARK(benchmark_strlen)->Range(0, MAX_ITER);

static void benchmark_string_length(benchmark::State &state) {
    for (auto _ : state) {
        const std::string str(static_cast<std::string::size_type>(state.range(0)), 'a');

        benchmark::DoNotOptimize(string_length(str.c_str()));
    }
}
BENCHMARK(benchmark_string_length)->Range(0, MAX_ITER);
