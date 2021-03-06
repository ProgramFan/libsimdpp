/*  libsimdpp
    Copyright (C) 2011-2012  Povilas Kanapickas tir5c3@yahoo.co.uk
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

#ifndef LIBSIMDPP_NULL_TRANSPOSE_H
#define LIBSIMDPP_NULL_TRANSPOSE_H
#if SIMDPP_USE_NULL || defined(DOXYGEN_SHOULD_READ_THIS)

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <utility>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif
namespace null {

template<class V>
void transpose2(V& a0, V& a1)
{
    for (unsigned j = 0; j < V::length; j+=2) {
        std::swap(a0.el(j+1), a1.el(j));
    }
}

template<class V>
void transpose4(V& a0, V& a1, V& a2, V& a3)
{
    for (unsigned j = 0; j < V::length; j+=4) {
        std::swap(a0.el(j+1), a1.el(j));
        std::swap(a0.el(j+2), a2.el(j));
        std::swap(a0.el(j+3), a3.el(j));
        std::swap(a1.el(j+2), a2.el(j+1));
        std::swap(a1.el(j+3), a3.el(j+1));
        std::swap(a2.el(j+3), a3.el(j+2));
    }
}

template<class V>
void transpose8(V& a0, V& a1, V& a2, V& a3, V& a4, V& a5, V& a6, V& a7)
{
    transpose4(a0, a1, a2, a3);
    transpose4(a4, a5, a6, a7);

    for (unsigned j = 0; j < V::length; j+=8) {
        for (unsigned i = 0; i < 4; i++) {
            std::swap(a0.el(j+4+i), a4.el(j+i));
            std::swap(a1.el(j+4+i), a5.el(j+i));
            std::swap(a2.el(j+4+i), a6.el(j+i));
            std::swap(a3.el(j+4+i), a7.el(j+i));
        }
    }
}

} // namespace null
#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif
#endif
