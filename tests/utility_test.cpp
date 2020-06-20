#include <catch2/catch.hpp>

#include <type_traits>

#include "ara/core/utility.h"

TEST_CASE("Byte is an alias for std::byte", "[SWS_CORE], [SWS_CORE_04200]")
{
    REQUIRE(std::is_same_v<ara::core::Byte, std::byte>);
}

TEST_CASE("ara::core::in_place_t is an alias for std::in_place_t",
          "[SWS_CORE], [SWS_CORE_04011]")
{
    REQUIRE(std::is_same_v<ara::core::in_place_t, std::in_place_t>);
}

TEST_CASE("in_place_t can be constructed", "[SWS_CORE], [SWS_CORE_04012]")
{
    REQUIRE_NOTHROW(ara::core::in_place_t{});
}

TEST_CASE("There is instance of in_place_t", "[SWS_CORE], [SWS_CORE_04013]")
{
    REQUIRE_NOTHROW((void) ara::core::in_place);
}

TEST_CASE("ara::core::in_place_type_t is an alias for std::in_place_type_t",
          "[SWS_CORE], [SWS_CORE_04021]")
{
    REQUIRE(std::is_same_v<ara::core::in_place_type_t<int>,
                           std::in_place_type_t<int>>);
}

TEST_CASE("in_place_type_t can be constructed", "[SWS_CORE], [SWS_CORE_04022]")
{
    REQUIRE_NOTHROW(ara::core::in_place_type_t<int>{});
}

TEST_CASE("ara::core::in_place_index_t is an alias for std::in_place_index_t",
          "[SWS_CORE], [SWS_CORE_04031]")
{
    REQUIRE(std::is_same_v<ara::core::in_place_index_t<1u>,
                           std::in_place_index_t<1u>>);
}

TEST_CASE("in_place_index_t can be constructed", "[SWS_CORE], [SWS_CORE_04032]")
{
    REQUIRE_NOTHROW(ara::core::in_place_index_t<1u>{});
}
