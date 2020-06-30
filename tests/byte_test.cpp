#include <catch2/catch.hpp>

#include <type_traits>

#include "ara/core/byte.h"

TEST_CASE("Byte is not integral type", "[SWS_CORE_10100]")
{
    REQUIRE(std::is_integral_v<ara::core::Byte> == 0);
}

TEST_CASE("Size of Byte is one", "[SWS_CORE_10101]")
{
    REQUIRE(sizeof(ara::core::Byte) == 1);
}

TEST_CASE("Byte should be constrained in unsigned char limits",
          "[SWS_CORE_10102]")
{
    REQUIRE_NOTHROW(ara::core::Byte{0});
    REQUIRE_NOTHROW(ara::core::Byte{std::numeric_limits<unsigned char>::max()});
}

TEST_CASE("Byte can be created with integral type", "[SWS_CORE_10103]")
{
    REQUIRE_NOTHROW(ara::core::Byte{1});
    constexpr ara::core::Byte byte{2};
    REQUIRE_NOTHROW((void) byte);
}

TEST_CASE("Byte can be default constructed", "[SWS_CORE_10104]")
{
    REQUIRE_NOTHROW(ara::core::Byte{});
}

TEST_CASE("Byte is trivially destructable", "[SWS_CORE_10105]")
{
    REQUIRE(std::is_trivially_destructible_v<ara::core::Byte>);
}

TEST_CASE("Byte is not implicitly convertible from any other type",
          "[SWS_CORE_10106]")
{
    REQUIRE_FALSE(std::is_convertible_v<uint8_t, ara::core::Byte>);
    REQUIRE_FALSE(std::is_convertible_v<int, ara::core::Byte>);
    REQUIRE_FALSE(std::is_convertible_v<char, ara::core::Byte>);
}

TEST_CASE("Byte is not implicitly convertible to any other type",
          "[SWS_CORE_10106]")
{
    REQUIRE_FALSE(std::is_convertible_v<ara::core::Byte, uint8_t>);
    REQUIRE_FALSE(std::is_convertible_v<ara::core::Byte, int>);
    REQUIRE_FALSE(std::is_convertible_v<ara::core::Byte, char>);
}

TEST_CASE("Byte can be converted to unsigned char", "[SWS_CORE_10106]")
{
    WHEN("Not in constant expression")
    {
        const unsigned char value{7};
        ara::core::Byte     byteObject{value};
        auto                byteValue = static_cast<unsigned char>(byteObject);
        REQUIRE(value == byteValue);
    }

    WHEN("In constant expression")
    {
        const unsigned char       value{7};
        constexpr ara::core::Byte byteObject{value};
        constexpr auto byteValue = static_cast<unsigned char>(byteObject);
        REQUIRE(value == byteValue);
    }
}

TEST_CASE("Byte shall be comparable for equality", "[SWS_CORE_10106]")
{
    WHEN("Byte objects are equal")
    {
        ara::core::Byte byteObject1{1}, byteObject2{1};
        REQUIRE(byteObject1 == byteObject2);
    }

    WHEN("Byte objects are not equal")
    {
        ara::core::Byte byteObject1{1}, byteObject2{2};
        REQUIRE_FALSE(byteObject1 == byteObject2);
    }
}

TEST_CASE("Byte shall be comparable for non-equality", "[SWS_CORE_10106]")
{
    WHEN("Byte objects are equal")
    {
        ara::core::Byte byteObject1{1}, byteObject2{1};
        REQUIRE_FALSE(byteObject1 != byteObject2);
    }

    WHEN("Byte objects are not equal")
    {
        ara::core::Byte byteObject1{1}, byteObject2{2};
        REQUIRE(byteObject1 != byteObject2);
    }
}

TEST_CASE("Byte can be changed to Integral type", "[]")
{
    ara::core::Byte byteObject{1};
    auto            int32Value(ara::core::to_integer<int32_t>(byteObject));
    REQUIRE(int32Value == 1);
    auto uint16Value(ara::core::to_integer<uint16_t>(byteObject));
    REQUIRE(uint16Value == 1u);
}

TEST_CASE("Byte can be used with shift operators", "[]")
{
    ara::core::Byte byteObject1{4}, byteObject2{1};
    WHEN("Used operator >>") { REQUIRE(byteObject1 >> 2 == byteObject2); }
    WHEN("Used operator <<") { REQUIRE(byteObject2 << 2 == byteObject1); }
    WHEN("Used operator >>=")
    {
        byteObject1 >>= 2;
        REQUIRE(byteObject1 == byteObject2);
    }
    WHEN("Used operator <<=")
    {
        byteObject2 <<= 2;
        REQUIRE(byteObject2 == byteObject1);
    }
}

TEST_CASE("Byte can be used with bitwise operators", "[]")
{
    ara::core::Byte byteObject1{1}, byteObject2{2}, byteObject3{3};
    WHEN("Used |,&,^,~")
    {
        REQUIRE((byteObject1 | byteObject3) == byteObject3);  // 01 | 11 = 11
        REQUIRE((byteObject1 & byteObject3) == byteObject1);  // 01 & 11 = 01
        REQUIRE((byteObject1 ^ byteObject3) == byteObject2);  // 01 ^ 11 = 10
        REQUIRE((~ara::core::Byte{0xFE}) == byteObject1);     // ~0xFE = 0x01
    }
    WHEN("Used |=")
    {
        byteObject1 |= byteObject3;
        REQUIRE(byteObject1 == byteObject3);
    }
    WHEN("Used &=")
    {
        byteObject3 &= byteObject1;
        REQUIRE(byteObject1 == byteObject3);
    }
    WHEN("Used ^=")
    {
        byteObject1 ^= byteObject3;
        REQUIRE(byteObject1 == byteObject2);
    }
}
