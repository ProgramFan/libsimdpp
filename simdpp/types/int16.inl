/*  libsimdpp
    Copyright (C) 2013  Povilas Kanapickas tir5c3@yahoo.co.uk
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

#ifndef LIBSIMDPP_SIMDPP_TYPES_INT16_INL
#define LIBSIMDPP_SIMDPP_TYPES_INT16_INL

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types/int16.h>
#include <simdpp/null/mask.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

template<unsigned N> template<class E> gint16<N>::gint16(const  gint8<N*2,E>& d) { *this = bit_cast<gint16<N>>(d.eval()); }
template<unsigned N> template<class E> gint16<N>::gint16(const gint16<N,E>& d)   { *this = bit_cast<gint16<N>>(d.eval()); }
template<unsigned N> template<class E> gint16<N>::gint16(const gint32<N/2,E>& d) { *this = bit_cast<gint16<N>>(d.eval()); }
template<unsigned N> template<class E> gint16<N>::gint16(const gint64<N/4,E>& d) { *this = bit_cast<gint16<N>>(d.eval()); }
template<unsigned N> template<class E> gint16<N>& gint16<N>::operator=(const  gint8<N*2,E>& d) { *this = bit_cast<gint16<N>>(d.eval()); return *this; }
template<unsigned N> template<class E> gint16<N>& gint16<N>::operator=(const gint16<N,E>& d)   { *this = bit_cast<gint16<N>>(d.eval()); return *this; }
template<unsigned N> template<class E> gint16<N>& gint16<N>::operator=(const gint32<N/2,E>& d) { *this = bit_cast<gint16<N>>(d.eval()); return *this; }
template<unsigned N> template<class E> gint16<N>& gint16<N>::operator=(const gint64<N/4,E>& d) { *this = bit_cast<gint16<N>>(d.eval()); return *this; }

template<unsigned N> template<class E> int16<N>::int16(const  gint8<N*2,E>& d) : gint16<N>(d) {}
template<unsigned N> template<class E> int16<N>::int16(const gint16<N,E>& d)   : gint16<N>(d) {}
template<unsigned N> template<class E> int16<N>::int16(const gint32<N/2,E>& d) : gint16<N>(d) {}
template<unsigned N> template<class E> int16<N>::int16(const gint64<N/4,E>& d) : gint16<N>(d) {}
template<unsigned N> template<class E> int16<N>& int16<N>::operator=(const  gint8<N*2,E>& d) { gint16<N>::operator=(d); return *this; }
template<unsigned N> template<class E> int16<N>& int16<N>::operator=(const gint16<N,E>& d)   { gint16<N>::operator=(d); return *this; }
template<unsigned N> template<class E> int16<N>& int16<N>::operator=(const gint32<N/2,E>& d) { gint16<N>::operator=(d); return *this; }
template<unsigned N> template<class E> int16<N>& int16<N>::operator=(const gint64<N/4,E>& d) { gint16<N>::operator=(d); return *this; }

template<unsigned N> template<class E> uint16<N>::uint16(const  gint8<N*2,E>& d) : gint16<N>(d) {}
template<unsigned N> template<class E> uint16<N>::uint16(const gint16<N,E>& d)   : gint16<N>(d) {}
template<unsigned N> template<class E> uint16<N>::uint16(const gint32<N/2,E>& d) : gint16<N>(d) {}
template<unsigned N> template<class E> uint16<N>::uint16(const gint64<N/4,E>& d) : gint16<N>(d) {}
template<unsigned N> template<class E> uint16<N>& uint16<N>::operator=(const  gint8<N*2,E>& d) { gint16<N>::operator=(d); return *this; }
template<unsigned N> template<class E> uint16<N>& uint16<N>::operator=(const gint16<N,E>& d)   { gint16<N>::operator=(d); return *this; }
template<unsigned N> template<class E> uint16<N>& uint16<N>::operator=(const gint32<N/2,E>& d) { gint16<N>::operator=(d); return *this; }
template<unsigned N> template<class E> uint16<N>& uint16<N>::operator=(const gint64<N/4,E>& d) { gint16<N>::operator=(d); return *this; }

template<unsigned N> maskdata_int16<N>::operator uint16<N>() const
{
    uint16<N> r;
    for (unsigned i = 0; i < vec_length; ++i) r[i] = d_[i];
    return r;
}

template<unsigned N> mask_int16<N>::mask_int16(const maskdata_int16<N>& d) : uint16<N>(d), mask_(d) {}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif
