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
class ByteImpl {
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

using Byte = ByteImpl;
} // namespace ara::com

#endif // ARA_CORE_BYTE_H_
