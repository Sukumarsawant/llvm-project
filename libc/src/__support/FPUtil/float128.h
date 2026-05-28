//===-- Definition of float128 data type -------------------------*- C++
//-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC___SUPPORT_FPUTIL_FLOAT128_H
#define LLVM_LIBC_SRC___SUPPORT_FPUTIL_FLOAT128_H

#include "hdr/stdint_proxy.h"
#include "src/__support/CPP/bit.h"
#include "src/__support/CPP/type_traits.h"
#include "src/__support/FPUtil/FPBits.h"
#include "src/__support/macros/config.h"
#include "src/__support/uint128.h"
#include "src/__support/macros/config.h"
#include "src/__support/macros/properties/types.h"
#include "src/__support/uint128.h"

namespace LIBC_NAMESPACE_DECL {
namespace fputil {

struct Float128 {
  UInt128 bits;

  LIBC_INLINE Float128() = default;

    LIBC_INLINE constexpr explicit Float128(UInt128 x) : bits(x) {}
}; // struct Float128128

#ifndef LIBC_TYPES_HAS_FLOAT128
using float128 = Float128;
#endif

} // namespace fputil
} // namespace LIBC_NAMESPACE_DECL

#endif // LLVM_LIBC_SRC___SUPPORT_FPUTIL_FLOAT128_H
