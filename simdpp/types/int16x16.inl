/*  libsimdpp
    Copyright (C) 2012-2012  Povilas Kanapickas tir5c3@yahoo.co.uk
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

#ifndef LIBSIMDPP_SIMDPP_TYPES_INT16X16_INL
#define LIBSIMDPP_SIMDPP_TYPES_INT16X16_INL

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types/int16x16.h>
#include <simdpp/null/mask.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

#if SIMDPP_USE_AVX2

template<class E> gint16<16>::gint16(const  gint8<32,E>& d) { *this = bit_cast<gint16<16>>(d.eval()); }
template<class E> gint16<16>::gint16(const gint16<16,E>& d) { *this = bit_cast<gint16<16>>(d.eval()); }
template<class E> gint16<16>::gint16(const gint32<8,E>& d)  { *this = bit_cast<gint16<16>>(d.eval()); }
template<class E> gint16<16>::gint16(const gint64<4,E>& d)  { *this = bit_cast<gint16<16>>(d.eval()); }
template<class E> gint16<16>& gint16<16>::operator=(const  gint8<32,E>& d) { *this = bit_cast<gint16<16>>(d.eval()); return *this; }
template<class E> gint16<16>& gint16<16>::operator=(const gint16<16,E>& d) { *this = bit_cast<gint16<16>>(d.eval()); return *this; }
template<class E> gint16<16>& gint16<16>::operator=(const gint32<8,E>& d)  { *this = bit_cast<gint16<16>>(d.eval()); return *this; }
template<class E> gint16<16>& gint16<16>::operator=(const gint64<4,E>& d)  { *this = bit_cast<gint16<16>>(d.eval()); return *this; }

template<class E> int16<16>::int16(const  gint8<32,E>& d) : gint16(d) {}
template<class E> int16<16>::int16(const gint16<16,E>& d) : gint16(d) {}
template<class E> int16<16>::int16(const gint32<8,E>& d)  : gint16(d) {}
template<class E> int16<16>::int16(const gint64<4,E>& d)  : gint16(d) {}
template<class E> int16<16>& int16<16>::operator=(const  gint8<32,E>& d) { gint16::operator=(d); return *this; }
template<class E> int16<16>& int16<16>::operator=(const gint16<16,E>& d) { gint16::operator=(d); return *this; }
template<class E> int16<16>& int16<16>::operator=(const gint32<8,E>& d)  { gint16::operator=(d); return *this; }
template<class E> int16<16>& int16<16>::operator=(const gint64<4,E>& d)  { gint16::operator=(d); return *this; }

template<class E> uint16<16>::uint16(const  gint8<32,E>& d) : gint16(d) {}
template<class E> uint16<16>::uint16(const gint16<16,E>& d) : gint16(d) {}
template<class E> uint16<16>::uint16(const gint32<8,E>& d)  : gint16(d) {}
template<class E> uint16<16>::uint16(const gint64<4,E>& d)  : gint16(d) {}
template<class E> uint16<16>& uint16<16>::operator=(const  gint8<32,E>& d) { gint16::operator=(d); return *this; }
template<class E> uint16<16>& uint16<16>::operator=(const gint16<16,E>& d) { gint16::operator=(d); return *this; }
template<class E> uint16<16>& uint16<16>::operator=(const gint32<8,E>& d)  { gint16::operator=(d); return *this; }
template<class E> uint16<16>& uint16<16>::operator=(const gint64<4,E>& d)  { gint16::operator=(d); return *this; }

inline gint16x16 gint16x16::zero()
{
    return (uint16x16) make_uint(0);
}

inline gint16x16 gint16x16::ones()
{
    return (uint16x16) make_uint(0xffff);
}

inline mask_int16x16::operator gint16x16() const
{
    return d_;
}

#endif // SIMDPP_USE_AVX2

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif
