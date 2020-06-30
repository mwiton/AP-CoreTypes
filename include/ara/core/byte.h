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
class ByteImpl
{
 public:
    using ByteType = uint8_t;

    ByteImpl() = default;
    constexpr explicit ByteImpl(ByteType value) : impl{value} {}

    ~ByteImpl() = default;

    constexpr explicit operator ByteType() const
    {
        return static_cast<ByteType>(impl);
    }

    constexpr bool operator==(const ByteImpl&) const = default;

    constexpr bool operator!=(const ByteImpl&) const = default;

 private:
    std::byte impl;
};

template<class IntegerType> constexpr IntegerType
to_integer(ByteImpl b) noexcept requires std::integral<IntegerType>
{
    return IntegerType(static_cast<ByteImpl::ByteType>(b));
}

template<class IntegerType> constexpr ByteImpl
operator<<(ByteImpl b, IntegerType shift) noexcept
  requires std::integral<IntegerType>
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(b) << shift);
}

template<class IntegerType> constexpr ByteImpl&
operator<<=(ByteImpl& b, IntegerType shift) noexcept
  requires std::integral<IntegerType>
{
    return b = b << shift;
}

template<class IntegerType> constexpr ByteImpl
operator>>(ByteImpl b, IntegerType shift) noexcept
  requires std::integral<IntegerType>
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(b) >> shift);
}

template<class IntegerType> constexpr ByteImpl&
operator>>=(ByteImpl& b, IntegerType shift) noexcept
  requires std::integral<IntegerType>
{
    return b = b >> shift;
}

constexpr ByteImpl operator|(ByteImpl l, ByteImpl r) noexcept
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(l)
                    | static_cast<ByteImpl::ByteType>(r));
}

constexpr ByteImpl& operator|=(ByteImpl& l, ByteImpl r) noexcept
{
    return l = l | r;
}

constexpr ByteImpl operator&(ByteImpl l, ByteImpl r) noexcept
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(l)
                    & static_cast<ByteImpl::ByteType>(r));
}

constexpr ByteImpl& operator&=(ByteImpl& l, ByteImpl r) noexcept
{
    return l = l & r;
}

constexpr ByteImpl operator^(ByteImpl l, ByteImpl r) noexcept
{
    return ByteImpl(static_cast<ByteImpl::ByteType>(l)
                    ^ static_cast<ByteImpl::ByteType>(r));
}

constexpr ByteImpl& operator^=(ByteImpl& l, ByteImpl r) noexcept
{
    return l = l ^ r;
}

constexpr ByteImpl operator~(ByteImpl b) noexcept
{
    return ByteImpl(~static_cast<ByteImpl::ByteType>(b));
}

using Byte = ByteImpl;
}  // namespace ara::core

#endif  // ARA_CORE_BYTE_H_
