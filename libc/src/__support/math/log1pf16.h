//===-- Implementation header for log1pf16 ----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC___SUPPORT_MATH_LOG1PF16_H
#define LLVM_LIBC_SRC___SUPPORT_MATH_LOG1PF16_H

#include "include/llvm-libc-macros/float16-macros.h"

// TODO: Add guard later
// #ifdef LIBC_TYPES_HAS_FLOAT16

#include "exp10_float16_constants.h"
#include "expxf16_utils.h"
#include "hdr/errno_macros.h"
#include "hdr/fenv_macros.h"
#include "src/__support/FPUtil/FEnvImpl.h"
#include "src/__support/FPUtil/FPBits.h"
#include "src/__support/FPUtil/PolyEval.h"
#include "src/__support/FPUtil/cast.h"
#include "src/__support/FPUtil/except_value_utils.h"
#include "src/__support/FPUtil/multiply_add.h"
#include "src/__support/common.h"
#include "src/__support/macros/config.h"
#include "src/__support/macros/optimization.h"
#include "src/__support/macros/properties/cpu_features.h"

namespace LIBC_NAMESPACE_DECL {

namespace math {

LIBC_INLINE float16 log1pf16(float16 x) {
/*
Points to consider near x = -1 , 0 
Domain 
x < -1        → undefined (domain error, NaN)
x = -1        → ln(0) = -inf
-1 < x < 0   → negative output, approaching 0 as x→0
x = 0         → ln(1) = 0
x > 0         → positive, grows slowly
x = +inf      → +inf
*/

/* 8000 = -0
   7000 = +0
   7C00 = +INF ( 0 11111 0000000000)
   FC00 = -INF 
   3C00 = +1
   BC00 = -1
*/
  using FPBits = fputil::FPBits<float16>;
  FPBits x_bits(x);

  uint16_t x_u = x_bits.uintval();
  uint16_t x_abs = x_u & 0x7fffU;


  }
} // namespace math
} // namespace LIBC_NAMESPACE_DECL


#endif // LLVM_LIBC_SRC___SUPPORT_MATH_LOG1PF16_H
