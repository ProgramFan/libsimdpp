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

#ifndef LIBSIMDPP_SIMDPP_DETAIL_INSN_UNZIP_HI_H
#define LIBSIMDPP_SIMDPP_DETAIL_INSN_UNZIP_HI_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/core/shuffle2.h>
#include <simdpp/core/zip_hi.h>
#include <simdpp/null/shuffle.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace detail {
namespace insn {

inline gint8x16 i_unzip16_hi(gint8x16 a, gint8x16 b)
{
#if SIMDPP_USE_NULL
    return null::unzip16_hi(a, b);
#elif SIMDPP_USE_SSE2
    a = _mm_srai_epi16(a, 8);
    b = _mm_srai_epi16(b, 8);
    a = _mm_packs_epi16(a, b);
    return a;
#elif SIMDPP_USE_NEON
    return vuzpq_u8(a, b).val[1];
#elif SIMDPP_USE_ALTIVEC
    return vec_pack((__vector uint16_t)a, (__vector uint16_t)b);
#endif
}

#if SIMDPP_USE_AVX2
inline gint8x32 i_unzip16_hi(gint8x32 a, gint8x32 b)
{
    a = _mm256_srai_epi16(a, 8);
    b = _mm256_srai_epi16(b, 8);
    a = _mm256_packs_epi16(a, b);
    return a;
}
#endif

template<unsigned N>
gint8<N> i_unzip16_hi(gint8<N> a, gint8<N> b)
{
    SIMDPP_VEC_ARRAY_IMPL2(gint8<N>, i_unzip16_hi, a, b)
}

// -----------------------------------------------------------------------------

inline gint16x8 i_unzip8_hi(gint16x8 a, gint16x8 b)
{
#if SIMDPP_USE_NULL
    return null::unzip8_hi(a, b);
#elif SIMDPP_USE_SSE2
    a = _mm_srai_epi32(a, 16);
    b = _mm_srai_epi32(b, 16);
    a = _mm_packs_epi32(a, b);
    return a;
#elif SIMDPP_USE_NEON
    return vuzpq_u16(a, b).val[1];
#elif SIMDPP_USE_ALTIVEC
    return vec_pack((__vector uint32_t)a, (__vector uint32_t)b);
#endif
}

#if SIMDPP_USE_AVX2
inline gint16x16 i_unzip8_hi(gint16x16 a, gint16x16 b)
{
    a = _mm256_srai_epi32(a, 16);
    b = _mm256_srai_epi32(b, 16);
    a = _mm256_packs_epi32(a, b);
    return a;
}
#endif

template<unsigned N>
gint16<N> i_unzip8_hi(gint16<N> a, gint16<N> b)
{
    SIMDPP_VEC_ARRAY_IMPL2(gint16<N>, i_unzip8_hi, a, b)
}

// -----------------------------------------------------------------------------

inline gint32x4 i_unzip4_hi(gint32x4 a, gint32x4 b)
{
#if SIMDPP_USE_NULL
    return null::unzip4_hi(a, b);
#elif SIMDPP_USE_SSE2 || SIMDPP_USE_ALTIVEC
    return shuffle2<1,3,1,3>(a, b);
#elif SIMDPP_USE_NEON
    return vuzpq_u32(a, b).val[1];
#endif
}

#if SIMDPP_USE_AVX2
inline gint32x8 i_unzip4_hi(gint32x8 a, gint32x8 b)
{
    return shuffle2<1,3,1,3>(a, b);
}
#endif

template<unsigned N>
gint32<N> i_unzip4_hi(gint32<N> a, gint32<N> b)
{
    SIMDPP_VEC_ARRAY_IMPL2(gint32<N>, i_unzip4_hi, a, b)
}

// -----------------------------------------------------------------------------

template<unsigned N>
gint64<N> i_unzip2_hi(gint64<N> a, gint64<N> b)
{
    return i_zip2_hi(a, b);
}

// -----------------------------------------------------------------------------

inline float32x4 i_unzip4_hi(float32x4 a, float32x4 b)
{
#if SIMDPP_USE_NULL
    return null::unzip4_hi(a, b);
#elif SIMDPP_USE_SSE2
    return shuffle2<1,3,1,3>(a,b);
#elif SIMDPP_USE_NEON
    return vuzpq_f32(a, b).val[1];
#elif SIMDPP_USE_ALTIVEC
    return float32x4(i_unzip4_hi((uint32x4)a, (uint32x4)b));
#endif
}

#if SIMDPP_USE_AVX
inline float32x8 i_unzip4_hi(float32x8 a, float32x8 b)
{
    return shuffle2<1,3,1,3>(a, b);
}
#endif

template<unsigned N>
float32<N> i_unzip4_hi(float32<N> a, float32<N> b)
{
    SIMDPP_VEC_ARRAY_IMPL2(float32<N>, i_unzip4_hi, a, b)
}

// -----------------------------------------------------------------------------

template<unsigned N>
float64<N> i_unzip2_hi(float64<N> a, float64<N> b)
{
    return i_zip2_hi(a, b);
}

} // namespace insn
} // namespace detail
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

