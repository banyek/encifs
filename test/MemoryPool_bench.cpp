#include "benchmark/benchmark.h"

#include "encifs/MemoryPool.h"

using namespace encifs;

static void BM_MemPoolAllocate(benchmark::State& state) {
  while (state.KeepRunning()) {
    auto block = MemoryPool::allocate(1024);
    MemoryPool::release(block);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_MemPoolAllocate);
