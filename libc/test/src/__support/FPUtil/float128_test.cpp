//===-- Smoke tests for Float128 emulation ----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/__support/FPUtil/float128.h"
#include "test/UnitTest/Test.h"

namespace LIBC_NAMESPACE_DECL {
namespace fputil {
TEST(LlvmLibcFloat128Test, BasicConstruct) {
  Float128 a;
  (void)a;
  EXPECT_TRUE(true);
}

} // namespace fputil
} // namespace LIBC_NAMESPACE_DECL
