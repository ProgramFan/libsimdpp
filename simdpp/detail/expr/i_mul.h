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

#ifndef LIBSIMDPP_SIMDPP_DETAIL_EXPR_I_MUL_H
#define LIBSIMDPP_SIMDPP_DETAIL_EXPR_I_MUL_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/core/i_mull.h>
#include <simdpp/core/move_l.h>
#include <simdpp/core/permute4.h>
#include <simdpp/core/shuffle2.h>
#include <simdpp/core/unzip_hi.h>
#include <simdpp/null/math.h>
#include <simdpp/null/foreach.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace detail {


template<class E1, class E2>
gint16<8> expr_eval(expr_mul_lo<gint16<8,E1>,
                                gint16<8,E2>> q)
{
    gint16<8> a = q.a.eval();
    gint16<8> b = q.b.eval();
#if SIMDPP_USE_NULL
    return null::mul(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_mullo_epi16(a, b);
#elif SIMDPP_USE_NEON
    return vmulq_s16(a, b);
#elif SIMDPP_USE_ALTIVEC
    return vec_mladd((__vector uint16_t)a, (__vector uint16_t)b,
                     (__vector uint16_t)uint16x8::zero());
#endif
}

#if SIMDPP_USE_AVX2
template<class E1, class E2>
gint16<16> expr_eval(expr_mul_lo<gint16<16,E1>,
                                 gint16<16,E2>> q)
{
    gint16<16> a = q.a.eval();
    gint16<16> b = q.b.eval();
    return _mm256_mullo_epi16(a, b);
}
#endif

template<unsigned N, class E1, class E2>
gint16<N> expr_eval(expr_mul_lo<gint16<N,E1>,
                                gint16<N,E2>> q)
{
    gint16<N> a = q.a.eval();
    gint16<N> b = q.b.eval();
    SIMDPP_VEC_ARRAY_IMPL2(gint16<N>, mul_lo, a, b);
}

// -----------------------------------------------------------------------------

template<class E1, class E2>
int16<8> expr_eval(expr_mul_hi<int16<8,E1>,
                               int16<8,E2>> q)
{
    int16<8> a = q.a.eval();
    int16<8> b = q.b.eval();
#if SIMDPP_USE_NULL
    return null::foreach<int16x8>(a, b, [](int16_t a, int16_t b){ return (int32_t(a) * b) >> 16; });
#elif SIMDPP_USE_SSE2
    return _mm_mulhi_epi16(a, b);
#elif SIMDPP_USE_NEON
    return unzip8_hi((int16x8)mull_lo(a, b), (int16x8)mull_hi(a, b));
#elif SIMDPP_USE_ALTIVEC
    return unzip8_lo((int16x8)mull_lo(a, b), (int16x8)mull_hi(a, b));
#endif
}

#if SIMDPP_USE_AVX2
template<class E1, class E2>
int16<16> expr_eval(expr_mul_hi<int16<16,E1>,
                                int16<16,E2>> q)
{
    int16<16> a = q.a.eval();
    int16<16> b = q.b.eval();
    return _mm256_mulhi_epi16(a, b);
}
#endif

template<unsigned N, class E1, class E2>
int16<N> expr_eval(expr_mul_hi<int16<N,E1>,
                               int16<N,E2>> q)
{
    int16<N> a = q.a.eval();
    int16<N> b = q.b.eval();
    SIMDPP_VEC_ARRAY_IMPL2(int16<N>, mul_hi, a, b);
}

// -----------------------------------------------------------------------------

template<class E1, class E2>
uint16<8> expr_eval(expr_mul_hi<uint16<8,E1>,
                                uint16<8,E2>> q)
{
    uint16<8> a = q.a.eval();
    uint16<8> b = q.b.eval();
#if SIMDPP_USE_NULL
    return null::foreach<uint16x8>(a, b, [](uint16_t a, uint16_t b){ return (int64_t(a) * b) >> 16; });
#elif SIMDPP_USE_SSE2
    return _mm_mulhi_epu16(a, b);
#elif SIMDPP_USE_NEON
    return unzip8_hi((uint16x8)mull_lo(a, b), (uint16x8)mull_hi(a, b));
#elif SIMDPP_USE_ALTIVEC
    return unzip8_lo((uint16x8)mull_lo(a, b), (uint16x8)mull_hi(a, b));
#endif
}

#if SIMDPP_USE_AVX2
template<class E1, class E2>
uint16<16> expr_eval(expr_mul_hi<uint16<16,E1>,
                                 uint16<16,E2>> q)
{
    uint16<16> a = q.a.eval();
    uint16<16> b = q.b.eval();
    return _mm256_mulhi_epu16(a, b);
}
#endif

template<unsigned N, class E1, class E2>
uint16<N> expr_eval(expr_mul_hi<uint16<N,E1>,
                                uint16<N,E2>> q)
{
    uint16<N> a = q.a.eval();
    uint16<N> b = q.b.eval();
    SIMDPP_VEC_ARRAY_IMPL2(uint16<N>, mul_hi, a, b);
}

// -----------------------------------------------------------------------------

template<class E1, class E2>
gint32<4> expr_eval(expr_mul_lo<gint32<4,E1>,
                                gint32<4,E2>> q)
{
    gint32<4> a = q.a.eval();
    gint32<4> b = q.b.eval();
#if SIMDPP_USE_NULL
    return null::mul(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_mullo_epi32(a, b);
#elif SIMDPP_USE_SSE2
    gint32x4 a1, b1;
    a1 = move4_l<1>(a);
    b1 = move4_l<1>(b);
    a = _mm_mul_epu32(a, b);
    a1 = _mm_mul_epu32(a1, b1);
    a = shuffle2<0,2,0,2>(a, a1); // additional latency unavoidable
    a = permute4<0,2,1,3>(a);
    return a;
#elif SIMDPP_USE_NEON
    return vmulq_s32(a, b);
#elif SIMDPP_USE_ALTIVEC
    // implement in terms of 16-bit multiplies
    uint16x8 la, lb, ha, hb;
    uint32x4 rl, rh1, rh2;
    la = a;  lb = b;
    ha = move8_r<1>(la);
    hb = move8_r<1>(lb);

    rl = mull_lo(la, lb);
    rh1 = mull_lo(la, hb);
    rh2 = mull_lo(ha, lb);

    rh1 = shift_l<16>(add(rh1, rh2));
    rl = add(rl, rh1);
    return rl;
#endif
}

#if SIMDPP_USE_AVX2
template<class E1, class E2>
gint32<8> expr_eval(expr_mul_lo<gint32<8,E1>,
                                gint32<8,E2>> q)
{
    gint32<8> a = q.a.eval();
    gint32<8> b = q.b.eval();
    return _mm256_mullo_epi32(a, b);
}
#endif

template<unsigned N, class E1, class E2>
gint32<N> expr_eval(expr_mul_lo<gint32<N,E1>,
                                gint32<N,E2>> q)
{
    gint32<N> a = q.a.eval();
    gint32<N> b = q.b.eval();
    SIMDPP_VEC_ARRAY_IMPL2(gint32<N>, mul_lo, a, b);
}

} // namespace detail
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

