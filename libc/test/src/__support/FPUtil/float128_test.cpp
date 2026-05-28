//===-- Smoke tests for Float128 emulation ----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/__support/FPUtil/float128.h"
#include "src/__support/FPUtil/FPBits.h"
#include "src/__support/integer_literals.h"
#include "test/UnitTest/Test.h"

using LIBC_NAMESPACE::operator""_u128;

namespace LIBC_NAMESPACE_DECL {
namespace fputil {

TEST(LlvmLibcFloat128Test, BasicConstruct) {
  // Verify default construction yields zero
  Float128 a;
  EXPECT_EQ(a.bits, UInt128(0));

  // Validate bit-level round-trip semantics
  // Create a known bit pattern
  UInt128 test_pattern = 0x3FFF2000'00000000'00000000'00000000_u128;

  // Construct Float128 from the pattern
  Float128 b(test_pattern);

  // Read back the bits and assert equality
  EXPECT_EQ(b.bits, test_pattern);

  // Test with FPBits for additional validation
  FPBits<Float128> fp_bits(b);
  EXPECT_EQ(fp_bits.uintval(), test_pattern);
}

} // namespace fputil
} // namespace LIBC_NAMESPACE_DECL
