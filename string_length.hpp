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
