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

TEST_CASE("Returns pointer for data in container", "[SWS_CORE], [SWS_CORE_04110]")
{
    std::vector<int> container{1, 2, 3};
    REQUIRE(ara::core::data(container) == std::data(container));
}


TEST_CASE("Returns pointer for data in const container", "[SWS_CORE], [SWS_CORE_04111]")
{
    const std::vector<int> container{1, 2, 3};
    REQUIRE(ara::core::data(container) == std::data(container));
}


TEST_CASE("Returns pointer for data in array", "[SWS_CORE], [SWS_CORE_04112]")
{
    int array[]{1, 2, 3};
    REQUIRE(ara::core::data(array) == std::data(array));
}


TEST_CASE("Returns pointer for data in initializer_list", "[SWS_CORE], [SWS_CORE_04113]")
{
    std::initializer_list<int> il_list{1, 2, 3};
    REQUIRE(ara::core::data(il_list) == std::data(il_list));
}

TEST_CASE("Returns size of container", "[SWS_CORE], [SWS_CORE_04120]")
{
    std::vector<int> container{1, 2, 3};
    REQUIRE(ara::core::size(container) == std::size(container));
}


TEST_CASE("Returns size of array", "[SWS_CORE], [SWS_CORE_04121]")
{
    int array[]{1, 2, 3};
    REQUIRE(ara::core::size(array) == std::size(array));
}

TEST_CASE("Returns if container empty", "[SWS_CORE], [SWS_CORE_04130]")
{
    std::vector<int> container{1, 2, 3};
    REQUIRE(ara::core::empty(container) == std::empty(container));
}

TEST_CASE("Returns if array empty", "[SWS_CORE], [SWS_CORE_04131]")
{
    int array[]{1, 2, 3};
    REQUIRE(ara::core::empty(array) == std::empty(array));
}


TEST_CASE("Returns if initializer_list empty", "[SWS_CORE], [SWS_CORE_04132]")
{
    std::initializer_list<int> il_list{1, 2, 3};
    REQUIRE(ara::core::empty(il_list) == std::empty(il_list));
}
