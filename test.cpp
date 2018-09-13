#include "string_length.hpp"

#include <cstddef>

#include "catch.hpp"

static constexpr inline std::size_t MAX_LENGTH = 4096;

TEST_CASE("string_length") {
    std::string str;

    for (std::size_t i = 0; i < MAX_LENGTH; ++i) {
        REQUIRE(string_length(str.c_str()) == i);

        str.push_back('a');
        str.shrink_to_fit();
    }
}
