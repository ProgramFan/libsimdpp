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

#ifndef LIBSIMDPP_SIMDPP_CORE_ZIP_LO_H
#define LIBSIMDPP_SIMDPP_CORE_ZIP_LO_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/zip_lo.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

/// @{
/** Interleaves the lower halves of two vectors.

    @code
        | 0  1  2  3  4  5  ... N-2      N-1      |
    r = [ a0 b0 a1 b1 a2 b2 ... a(N/2-1) b(N/2-1) ]
    @endcode

    @par 256-bit version:
    The lower and higher 128-bit halves are processed as if 128-bit instruction
    was applied to each of them separately.

    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
template<unsigned N, class E1, class E2>
gint8<N, gint8<N>> zip16_lo(gint8<N,E1> a, gint8<N,E2> b)
{
    return detail::insn::i_zip16_lo(a.eval(), b.eval());
}

template<unsigned N, class E1, class E2>
gint16<N, gint16<N>> zip8_lo(gint16<N,E1> a, gint16<N,E2> b)
{
    return detail::insn::i_zip8_lo(a.eval(), b.eval());
}

template<unsigned N, class E1, class E2>
gint32<N, gint32<N>> zip4_lo(gint32<N,E1> a, gint32<N,E2> b)
{
    return detail::insn::i_zip4_lo(a.eval(), b.eval());
}

template<unsigned N, class E1, class E2>
gint64<N, gint64<N>> zip2_lo(gint64<N,E1> a, gint64<N,E2> b)
{
    return detail::insn::i_zip2_lo(a.eval(), b.eval());
}

/** Interleaves the lower halves of two vectors.

    @code
        | 0  1  2  3  4  5  ... N-2      N-1      |
    r = [ a0 b0 a1 b1 a2 b2 ... a(N/2-1) b(N/2-1) ]
    @endcode

    @par 256-bit version:
    @icost{SSE2-SSE4.1, NEON, ALTIVEC, 2}

    The lower and higher 128-bit halves are processed as if 128-bit instruction
    was applied to each of them separately.
*/
template<unsigned N, class E1, class E2>
float32<N, float32<N>> zip4_lo(float32<N,E1> a, float32<N,E2> b)
{
    return detail::insn::i_zip4_lo(a.eval(), b.eval());
}

template<unsigned N, class E1, class E2>
float64<N, float64<N>> zip2_lo(float64<N,E1> a, float64<N,E2> b)
{
    return detail::insn::i_zip2_lo(a.eval(), b.eval());
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif
