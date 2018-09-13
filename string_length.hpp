// BSD 3-Clause License
//
// Copyright (c) 2018, Gregory Meyer
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS AS IS
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include <cstddef>

#include <memory>

#include <emmintrin.h>
#include <immintrin.h>
#include <pmmintrin.h>

template <typename T, typename U>
constexpr T&& byte_cast(U &&u) noexcept {
    return static_cast<T&&>(*reinterpret_cast<T*>(std::addressof(u)));
}

inline std::size_t string_length(const char *str) noexcept {
    const auto modulo = byte_cast<std::uintptr_t>(str) % 32;
    for (std::size_t i = 0; i < modulo; ++i) {
        if (!str[i]) {
            return i;
        }
    }

    str += modulo;
    const __m256i zeros = _mm256_setzero_si256();

    for (std::size_t length = modulo;; str += 32, length += 32) {
        const __m256i vec = _mm256_load_si256(reinterpret_cast<const __m256i*>(str));
        const __m256i equal = _mm256_cmpeq_epi8(zeros, vec);
        const auto mask = byte_cast<unsigned>(_mm256_movemask_epi8(equal));

        if (mask != 0) {
            const auto num_trailing_zeros = __builtin_ctz(mask);

            return length + static_cast<std::size_t>(num_trailing_zeros);
        }
    }
}
