#include <benchmark/benchmark.h>
#include <random>

extern "C" {
    uint8_t baseline_max(int n, uint8_t *x);
    uint8_t pair_max(int n, uint8_t *x);
    uint8_t table_max(int n, uint8_t *x);
}

static void baseline(benchmark::State &state) {
    int n = state.range(0);

    uint8_t *x = new uint8_t[n];

    std::mt19937 mt(3075);
    for (int i = 0; i < n; i++)
        x[i] = std::uniform_int_distribution<uint8_t> {
            std::numeric_limits<uint8_t>::min(),
            std::numeric_limits<uint8_t>::max()
    } (mt);

    for (auto _ : state)
        benchmark::DoNotOptimize(baseline_max(n, x));

    delete[] x;
}

static void pair(benchmark::State &state) {
    int n = state.range(0);

    uint8_t *x = new uint8_t[n];

    std::mt19937 mt(3075);
    for (int i = 0; i < n; i++)
        x[i] = std::uniform_int_distribution<uint8_t> {
            std::numeric_limits<uint8_t>::min(),
            std::numeric_limits<uint8_t>::max()
    } (mt);

   if (baseline_max(n, x) != pair_max(n, x))
       state.SkipWithError("Incorrect max found!");

    for (auto _ : state)
        benchmark::DoNotOptimize(pair_max(n, x));

    delete[] x;
}

static void table(benchmark::State &state) {
    int n = state.range(0);

    uint8_t *x = new uint8_t[n];

    std::mt19937 mt(3075);
    for (int i = 0; i < n; i++)
        x[i] = std::uniform_int_distribution<uint8_t> {
            std::numeric_limits<uint8_t>::min(),
            std::numeric_limits<uint8_t>::max()
    } (mt);

   if (baseline_max(n, x) != table_max(n, x))
       state.SkipWithError("Incorrect max found!");

    for (auto _ : state)
        benchmark::DoNotOptimize(table_max(n, x));

    delete[] x;
}

BENCHMARK(baseline)->Unit(benchmark::kMicrosecond)->Arg(1000000);
BENCHMARK(pair)->Unit(benchmark::kMicrosecond)->Arg(1000000);
BENCHMARK(table)->Unit(benchmark::kMicrosecond)->Arg(1000000);

BENCHMARK_MAIN();
