#ifndef ARRAY_H
#define ARRAY_H

#include <array> // std::array

namespace ara::core
{
    /**
     * @brief Container that encapsulates fixed size arrays.
     * 
     * @req {SWS_CORE_01201}
     */
    template <typename T, std::size_t N>
    class Array : public std::array<T, N> {};

    /**
     * @brief Exchanges content between arrays.
     * 
     * @param lhs first argument of swap invocation
     * @param rhs second argument of swap invocation
     * 
     * @req {SWS_CORE_01296}
     */
    template <typename T, std::size_t N>
    void swap(Array<T, N> &lhs, Array<T, N> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace ara::core

#endif // ARRAY_H