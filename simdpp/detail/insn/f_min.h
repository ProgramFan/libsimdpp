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

#ifndef LIBSIMDPP_SIMDPP_DETAIL_INSN_F_MIN_H
#define LIBSIMDPP_SIMDPP_DETAIL_INSN_F_MIN_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/null/math.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace detail {
namespace insn {


inline float32x4 i_min(float32x4 a, float32x4 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_min_ps(a, b);
#elif SIMDPP_USE_NEON
    return vminq_f32(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_min((__vector float)a, (__vector float)b);
#endif
}

#if SIMDPP_USE_AVX
inline float32x8 i_min(float32x8 a, float32x8 b)
{
    return _mm256_min_ps(a, b);
}
#endif

template<unsigned N>
float32<N> i_min(float32<N> a, float32<N> b)
{
    SIMDPP_VEC_ARRAY_IMPL2(float32<N>, i_min, a, b);
}

// -----------------------------------------------------------------------------

inline float64x2 i_min(float64x2 a, float64x2 b)
{
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
    return null::min(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_min_pd(a, b);
#endif
}

#if SIMDPP_USE_AVX
inline float64x4 i_min(float64x4 a, float64x4 b)
{
    return _mm256_min_pd(a, b);
}
#endif

template<unsigned N>
float64<N> i_min(float64<N> a, float64<N> b)
{
    SIMDPP_VEC_ARRAY_IMPL2(float64<N>, i_min, a, b);
}


} // namespace insn
} // namespace detail
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

