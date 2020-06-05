#include <array>

template <typename T, std::size_t N>
class Array {
    public:
        Array() {}
        T& operator [] (int i) { return data[i]; }
    private:
        std::array<T, N> data;
};