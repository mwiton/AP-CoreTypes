/**
 * Copytight (c) 2020
 * umlaut Software Development and contributors
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef ARA_CORE_UTILITY_H_
#define ARA_CORE_UTILITY_H_

#include <utility>

namespace ara::core {
/**
 * Ara::core type alias for std::byte
 *
 * It is a type that is able to hold a “byte” of the machine.
 * It is an owntype distinct from any other type.
 *
 * @req {SWS_CORE_04200}
 */
using Byte = std::byte;

/**
 * Ara::core type alias for std::in_place_t
 *
 * An instance of this type can be passed to certain constructors of
 * ara::core::Optional to denote the intention that construction of the
 * contained type shall be done in-place.
 *
 * @req {SWS_CORE_04011, SWS_CORE_04012}
 */
using in_place_t = std::in_place_t;

/**
 * Instance of ara::core::in_place_t
 *
 * @req {SWS_CORE_04013}
 */
inline constexpr in_place_t in_place{};

/**
 * Ara::core type alias for in_place_type_t
 *
 * An instance of this type can be passed to certain constructors of
 * ara::core::Variant to denote the intention that construction of the contained
 * type shall be done in-place. Denote an type-distinguishing operation.
 *
 * @req {SWS_CORE_04021, SWS_CORE_04022}
 */
template<typename T> using in_place_type_t = std::in_place_type_t<T>;

/**
 * Ara::core type alias for std::in_place_index_t
 *
 * An instance of this type can be passed to certain constructors of
 * ara::core::Variant to denote the intention that construction of the contained
 * type shall be done in-place. Denote an index-distinguishing operation.
 *
 * @req {SWS_CORE_04031, SWS_CORE_04032}
 */
template<std::size_t I> using in_place_index_t = std::in_place_index_t<I>;

template<typename Container> constexpr auto data(Container& c)
  -> decltype(c.data())
{
    return std::data(c);
}

template <typename Container> constexpr auto data (Container const &c) -> decltype(c.data())
{
    return std::data(c);
}

template <typename T, std::size_t N> constexpr T* data (T(&array)[N]) noexcept
{
    return std::data(array);
}

template <typename E> constexpr E const * data (std::initializer_list< E > il) noexcept
{
    return std::data(il);
}

template <typename Container> constexpr auto size (Container const &c) -> decltype(c.size())
{
    return std::size(c);
}

template <typename T, std::size_t N> constexpr std::size_t size (T(&array)[N]) noexcept
{
    return std::size(array);
}

template <typename Container> constexpr auto empty (Container const &c) -> decltype(c.empty())
{
    return std::empty(c);
}

template <typename T, std::size_t N> constexpr bool empty (T(&array)[N]) noexcept
{
    return std::empty(array);
}

template <typename E> constexpr bool empty (std::initializer_list< E > il) noexcept
{
    return std::empty(il);
}
}  // namespace ara::core
#endif  // ARA_CORE_ERRORCODE_H_
