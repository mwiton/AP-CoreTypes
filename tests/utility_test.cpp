#include <catch2/catch.hpp>

#include <type_traits>

#include "ara/core/utility.h"

TEST_CASE("Byte is alias for std::byte", "[SWS_CORE], [SWS_CORE_04200]")
{
    REQUIRE(std::is_same_v<ara::core::Byte, std::byte>);
}
