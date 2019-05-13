#include "gtest/gtest.h"

#include "encifs/MemoryPool.h"

using namespace encifs;

TEST(MemoryPool, Allocate) {
  auto block = MemoryPool::allocate(1024);
  ASSERT_TRUE(block.data != nullptr);
  ASSERT_TRUE(block.internalData != nullptr);
  MemoryPool::release(block);
}