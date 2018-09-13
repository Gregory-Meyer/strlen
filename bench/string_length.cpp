#include <string_length/string_length.hpp>

#include <cstring>

#include <benchmark/benchmark.h>

static constexpr std::size_t MAX_ITER = 4096;

constexpr std::size_t naive(const char *str) noexcept {
    std::size_t length = 0;

    for (; *str; ++str, ++length) { }

    return length;
}

static void bm_stdlib(benchmark::State &state) {
    for (auto _ : state) {
        const std::string str(static_cast<std::string::size_type>(state.range(0)), 'a');

        benchmark::DoNotOptimize(std::strlen(str.c_str()));
    }
}
BENCHMARK(bm_stdlib)->Range(0, MAX_ITER);

static void bm_naive(benchmark::State &state) {
    for (auto _ : state) {
        const std::string str(static_cast<std::string::size_type>(state.range(0)), 'a');

        benchmark::DoNotOptimize(naive(str.c_str()));
    }
}
BENCHMARK(bm_naive)->Range(0, MAX_ITER);

static void bm_string_length(benchmark::State &state) {
    for (auto _ : state) {
        const std::string str(static_cast<std::string::size_type>(state.range(0)), 'a');

        benchmark::DoNotOptimize(string_length::string_length(str.c_str()));
    }
}
BENCHMARK(bm_string_length)->Range(0, MAX_ITER);
