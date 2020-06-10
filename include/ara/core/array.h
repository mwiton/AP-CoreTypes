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
    class Array : private std::array<T, N>
    {
        public:
            /**
             * @brief Access specified element with bounds checking.
             * 
             */
            using std::array<T, N>::at;
            
            /**
             * @brief Access specified element.
             * 
             */
            using std::array<T, N>::operator[];

            /**
             * @brief Access the first element.
             * 
             */
            using std::array<T, N>::front;

            /**
             * @brief Access the last element.
             * 
             */
            using std::array<T, N>::back;

            /**
             * @brief Direct access to the underlying array.
             * 
             */
            using std::array<T, N>::data;
            
            /**
             * @brief Returns an iterator to the beginning.
             * 
             */
            using std::array<T, N>::begin;

            /**
             * @brief Returns an iterator to the beginning.
             * 
             */
            using std::array<T, N>::cbegin;

            /**
             * @brief Returns an iterator to the end.
             * 
             */
            using std::array<T, N>::end;

            /**
             * @brief Returns an iterator to the end.
             * 
             */
            using std::array<T, N>::cend;

            /**
             * @brief Returns a reverse iterator to the beginning.
             * 
             */
            using std::array<T, N>::rbegin;

            /**
             * @brief Returns a reverse iterator to the beginning.
             * 
             */
            using std::array<T, N>::crbegin;

            /**
             * @brief Returns a reverse iterator to the end.
             * 
             */
            using std::array<T, N>::rend;

            /**
             * @brief Returns a reverse iterator to the end.
             * 
             */
            using std::array<T, N>::crend;

            /**
             * @brief Checks whether the container is empty.
             * 
             */
            using std::array<T, N>::empty;

            /**
             * @brief Returns the number of elements.
             * 
             */
            using std::array<T, N>::size;

            /**
             * @brief Returns the maximum possible number of elements.
             * 
             */
            using std::array<T, N>::max_size;

            /**
             * @brief Fill the container with specified value.
             * 
             */
            using std::array<T, N>::fill;
        
            /**
             * @brief Swaps the contents.
             * 
             */
            template<typename U>
            constexpr auto swap(U&& other) {
                return std::array<T, N>::swap(std::forward<U>(other));
            }
    };

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
