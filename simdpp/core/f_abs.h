/*  libsimdpp
    Copyright (C) 2013  Povilas Kanapickas povilas@radix.lt
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_F_ABS_H
#define LIBSIMDPP_SIMDPP_CORE_F_ABS_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/expr/f_abs.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif


/** Computes absolute value of floating point values.

    @code
    r0 = abs(a0)
    ...
    rN = abs(aN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-AVX2, 1-2}
    @icost{ALTIVEC, 1-2}

    @par 256-bit version:
    @icost{SSE2-SSE4.1, 2-3}
    @icost{NEON, 2}
    @icost{AVX-AVX2, 1-2}
    @icost{ALTIVEC, 2-3}
*/
template<unsigned N, class E>
float32<N, expr_abs<float32<N,E>>> abs(float32<N,E> a)
{
    return { { a }, 0 };
}

/** Computes absolute value of floating point values.

    @code
    r0 = abs(a0)
    ...
    rN = abs(aN)
    @endcode

    @par 128-bit version:
    @novec{NEON, ALTIVEC}
    @icost{SSE2-AVX2, 1-2}

    @par 256-bit version:
    @novec{NEON, ALTIVEC}
    @icost{SSE2-SSE4.1, 2-3}
    @icost{AVX-AVX2, 1-2}
*/
template<unsigned N, class E>
float64<N, expr_abs<float64<N,E>>> abs(float64<N,E> a)
{
    return { { a }, 0 };
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

