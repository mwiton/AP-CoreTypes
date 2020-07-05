/**
 * Copyright (c) 2020
 * umlaut Software Development and contributors
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef ARA_CORE_BYTE_H_
#define ARA_CORE_BYTE_H_

#include <cstddef>

namespace ara::core {
/**
 * @brief Wrapper class for std::byte class
 *
 */
class ByteImpl
{
 public:
    using ByteType = uint8_t;

    /**
     * @brief Construct a new Byte Impl object with no defined value
     *
     */
    ByteImpl() = default;
    /**
     * @brief Constuct object with given value
     * @arg Value of byte
     *
     */
    constexpr explicit ByteImpl(ByteType value) : impl{value} {}

    /**
     * @brief Default destructor
     *
     */
    ~ByteImpl() = default;

    /**
     * @brief Cast operator for machine byte type
     *
     * @return ByteType Value of byte given in byte machine type
     */
    constexpr explicit operator ByteType() const
    {
        return static_cast<ByteType>(impl);
    }

    /**
     * @brief Equality operator for Byte object
     *
     * @return true When given Byte object is equal
     * @return false When given Byte object is not equal
     */
    constexpr bool operator==(const ByteImpl&) const = default;

    /**
     * @brief No equality operator for Byte object
     *
     * @return true When given Byte object is not equal
     * @return false When given Byte object is equal
     */
    constexpr bool operator!=(const ByteImpl&) const = default;

 private:
    std::byte impl;
};

/**
 * @brief Gives value of Byte object as integer.
 *
 * @tparam IntegerType Exact type of integer to return
 * @param b Byte object
 * @return constexpr IntegerType Integer value
 */
template<class IntegerType> constexpr IntegerType
to_integer(ByteImpl b) noexcept requires std::integral<IntegerType>
{
    return IntegerType(static_cast<ByteImpl::ByteType>(b));
}

/**
 * @brief Left shift operator for Byte object
 *
 * @tparam IntegerType Type of integer used by argument
 * @param b Byte object
 * @param shift Amount bits to shift
 * @return constexpr ByteImpl Object with shifted value
 */
template<class IntegerType> constexpr ByteImpl
operator<<(ByteImpl b, IntegerType shift) noexcept
  requires std::integral<IntegerType>
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(b) << shift);
}

/**
 * @brief Left shift operator with assigment for Byte object
 *
 * @tparam IntegerType Type of integer used by argument
 * @param b Byte object
 * @param shift Amount bits to shift
 * @return constexpr ByteImpl& Reference to object with shifted value
 */
template<class IntegerType> constexpr ByteImpl&
operator<<=(ByteImpl& b, IntegerType shift) noexcept
  requires std::integral<IntegerType>
{
    return b = b << shift;
}

/**
 * @brief Right shift operator for Byte object
 *
 * @tparam IntegerType Type of integer used by argument
 * @param b Byte object
 * @param shift Amount bits to shift
 * @return constexpr ByteImpl Object with shifted value
 */
template<class IntegerType> constexpr ByteImpl
operator>>(ByteImpl b, IntegerType shift) noexcept
  requires std::integral<IntegerType>
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(b) >> shift);
}

/**
 * @brief Right shift operator with assigment for Byte object
 *
 * @tparam IntegerType Type of integer used by argument
 * @param b Byte object
 * @param shift Amount bits to shift
 * @return constexpr ByteImpl& Reference to object with shifted value
 */
template<class IntegerType> constexpr ByteImpl&
operator>>=(ByteImpl& b, IntegerType shift) noexcept
  requires std::integral<IntegerType>
{
    return b = b >> shift;
}

/**
 * @brief Bitwise OR operator for Byte object
 *
 * @param l Left byte object
 * @param r Right byte object
 * @return constexpr ByteImpl Object with result of OR operation
 */
constexpr ByteImpl operator|(ByteImpl l, ByteImpl r) noexcept
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(l)
                    | static_cast<ByteImpl::ByteType>(r));
}

/**
 * @brief Bitwise OR operator with assigment for Byte object
 *
 * @param l Left byte object
 * @param r Right byte object
 * @return constexpr ByteImpl& Reference to object with result of OR operation
 */
constexpr ByteImpl& operator|=(ByteImpl& l, ByteImpl r) noexcept
{
    return l = l | r;
}

/**
 * @brief Bitwise AND operator for Byte object
 *
 * @param l Left byte object
 * @param r Right byte object
 * @return constexpr ByteImpl Object with result of AND operation
 */
constexpr ByteImpl operator&(ByteImpl l, ByteImpl r) noexcept
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(l)
                    & static_cast<ByteImpl::ByteType>(r));
}

/**
 * @brief Bitwise AND operator with assigment for Byte object
 *
 * @param l Left byte object
 * @param r Right byte object
 * @return constexpr ByteImpl& Reference to object with result of AND operation
 */
constexpr ByteImpl& operator&=(ByteImpl& l, ByteImpl r) noexcept
{
    return l = l & r;
}

/**
 * @brief Bitwise XOR operator for Byte object
 *
 * @param l Left byte object
 * @param r Right byte object
 * @return constexpr ByteImpl Object with result of XOR operation
 */
constexpr ByteImpl operator^(ByteImpl l, ByteImpl r) noexcept
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(l)
                    ^ static_cast<ByteImpl::ByteType>(r));
}

/**
 * @brief Bitwise XOR operator with assigment for Byte object
 *
 * @param l Left byte object
 * @param r Right byte object
 * @return constexpr ByteImpl& Reference to object with result of XOR operation
 */
constexpr ByteImpl& operator^=(ByteImpl& l, ByteImpl r) noexcept
{
    return l = l ^ r;
}

/**
 * @brief Bit inversion oprator for Byte object
 *
 * @param b Byte object
 * @return constexpr ByteImpl Object with value after inverting bits
 */
constexpr ByteImpl operator~(ByteImpl b) noexcept
{
    return ByteImpl(~static_cast<ByteImpl::ByteType>(b));
}

}  // namespace ara::core

#endif  // ARA_CORE_BYTE_H_
