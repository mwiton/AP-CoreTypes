#include <iostream>
#include <ara/core/array.h>

#define TEST_SZ 10

int main()
{
    ara::core::Array<int, TEST_SZ> a1;
    ara::core::Array<int, TEST_SZ> a2;

    std::cout << std::endl << "1/x Write data to arrays" << std::endl;
    for(int i = 0; i < TEST_SZ; i++)
    {
        a1[i] = i;
        a2[i] = i*i;
    }

    std::cout << std::endl << "2/x Reading data from arrays" << std::endl;
    for(int i = 0; i < TEST_SZ; i++)
        std::cout << a1[i] << " " << a2[i] << std::endl;

    std::cout << std::endl << "3/x ara::core::swap" << std::endl;
    ara::core::swap(a1, a2);

    std::cout << std::endl << "4/x Reading data from arrays" << std::endl;
    for(int i = 0; i < TEST_SZ; i++)
        std::cout << a1[i] << " " << a2[i] << std::endl;

    std::cout << std::endl << "5/x at" << std::endl;
    std::cout << a1.at(9) << " " << a2.at(9) << std::endl;

    std::cout << std::endl << "6/x front" << std::endl;
    std::cout << a1.front() << " " << a2.front() << std::endl;

    std::cout << std::endl << "7/x back" << std::endl;
    std::cout << a1.back() << " " << a2.back() << std::endl;

    std::cout << std::endl << "8/x data" << std::endl;
    for(int i = 0; i < TEST_SZ; i++)
        std::cout << a1.data()[i] << " " << a2.data()[i] << std::endl;

    std::cout << std::endl << "9/x begin/cbegin end/cend" << std::endl;
    std::for_each(a1.cbegin(), a1.cend(), [](int v)
    {
        std::cout << v << std::endl;
    });

    std::cout << std::endl << "10/x empty / size / max_size" << std::endl;
    std::cout << a1.empty() << " " << a1.size() << " " << a1.max_size() << std::endl;

    std::cout << std::endl << "11/x fill" << std::endl;
    a1.fill(0xAB);
    a2.fill(0xBA);
    for(int i = 0; i < TEST_SZ; i++)
        std::cout << a1[i] << " " << a2[i] << std::endl;

    return 0;
}
