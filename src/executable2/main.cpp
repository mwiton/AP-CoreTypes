#include <iostream>
#include <ara/array.hpp>

int main()
{
    Array<int, 10> test_array;

    for(int i = 0; i < 10; i++)
        test_array[i] = i;
        
    for(int i = 0; i < 10; i++)
        std::cout << test_array[i] << std::endl;

    return 0;
}
