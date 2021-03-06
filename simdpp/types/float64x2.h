/*  libsimdpp
    Copyright (C) 2011  Povilas Kanapickas tir5c3@yahoo.co.uk
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

#ifndef LIBSIMDPP_SIMDPP_TYPES_FLOAT64X2_H
#define LIBSIMDPP_SIMDPP_TYPES_FLOAT64X2_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/setup_arch.h>
#include <simdpp/types/fwd.h>
#include <simdpp/types/int64x2.h>
#include <simdpp/core/cast.h>
#include <simdpp/detail/construct_eval.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

/// @ingroup simd_vec_fp
/// @{

/// Class representing float64x2 vector
template<>
class float64<2, void> {
public:

    using element_type = double;
    using uint_element_type = uint64_t;
    using int_vector_type = gint64x2;
    using uint_vector_type = uint64x2;
    using base_vector_type = float64x2;
    using mask_type = mask_float64x2;
    using maskdata_type = maskdata_float64<2>;

    static constexpr unsigned length = 2;
    static constexpr unsigned vec_length = 1;
    static constexpr unsigned num_bits = 64;
    static constexpr uint_element_type all_bits = 0xffffffffffffffff;

    float64<2>() = default;
    float64<2>(const float64x2&) = default;
    float64<2>& operator=(const float64x2&) = default;

    /// Construct from the underlying vector type
#if SIMDPP_USE_SSE2
    float64<2>(__m128d d) : d_(d) {}
    float64<2>& operator=(__m128d d) { d_ = d; return *this; }
#endif

    /// Convert to underlying vector type
#if SIMDPP_USE_SSE2
    operator __m128d() const { return d_; }
#endif

    /// @{
    /// Construct from compatible int64x2 integer vector type
    explicit float64<2>(gint64x2 d)     { *this = bit_cast<float64x2>(d); }
    float64<2>& operator=(gint64x2 d)   { *this = bit_cast<float64x2>(d); return *this; }
    /// @}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    template<class E> float64<2>(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr());
    }
    template<class E> float64<2>& operator=(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr()); return *this;
    }
#endif

    /// @{
    /// Access base vectors
    const float64x2& operator[](unsigned) const { return *this; }
          float64x2& operator[](unsigned)       { return *this; }
    /// @}

    float64<2> eval() const { return *this; }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
    /// For internal use only
    const double& el(unsigned i) const { return d_[i]; }
          double& el(unsigned i)       { return d_[i]; }
#endif
#endif

    /** Creates a float64x2 vector with the contens set to zero

        @code
        r0 = 0.0
        r1 = 0.0
        @endcode
    */
    static float64x2 zero();

private:
#if SIMDPP_USE_SSE2
    __m128d d_;
#elif SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC || SIMDPP_USE_NULL
    double d_[2];
#endif
};


/// Class representing possibly optimized mask data for 2x 64-bit floating point
/// vector
template<>
class maskdata_float64<2> {
public:
    using base_vector_type = maskdata_float64<2>;
    static constexpr unsigned length = 2;
    static constexpr unsigned vec_length = 1;

    maskdata_float64<2>() = default;
    maskdata_float64<2>(const maskdata_float64<2> &) = default;
    maskdata_float64<2> &operator=(const maskdata_float64<2> &) = default;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
#else
    maskdata_float64<2>(float64x2 d) : d_(d) {}
#endif
#endif

    /// Convert to bitmask
    operator float64<2>() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
    bool& el(unsigned id) { return b_[id]; }
    const bool& el(unsigned id) const { return b_[id]; }
#endif
#endif

    const maskdata_float64<2>& operator[](unsigned) const { return *this; }
          maskdata_float64<2>& operator[](unsigned)       { return *this; }

private:
#if SIMDPP_USE_NULL || SIMDPP_USE_NEON || SIMDPP_USE_ALTIVEC
    bool b_[2];
#else
    float64x2 d_;
#endif
};


/// Class representing a mask for 2x 64-bit floating-point vector
template<>
class mask_float64<2, void> : public float64<2, void> {
public:

    mask_float64<2>() = default;
    mask_float64<2>(const mask_float64x2 &) = default;
    mask_float64<2> &operator=(const mask_float64x2 &) = default;
    mask_float64<2>(const maskdata_float64<2>& d);

    /// @{
    /// Construct from the underlying vector type
#if SIMDPP_USE_SSE2
    mask_float64<2>(__m128d d);
    mask_float64<2>(float64<2> d);
#endif
    /// @}

    mask_float64<2> eval() const { return *this; }

    const maskdata_float64<2>& mask() const { return mask_; }
#if !DOXYGEN_SHOULD_SKIP_THIS && SIMDPP_USE_NULL
    maskdata_float64<2>& m_mask() { return mask_; }
#endif

private:
    maskdata_float64<2> mask_;
};

/// @} -- end ingroup

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif
