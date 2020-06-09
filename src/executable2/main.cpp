#include <iostream>
#include <ara/core/array.h>

int main()
{
    ara::core::Array<int, 10> test_array;

    for(int i = 0; i < 10; i++)
        test_array[i] = i;
        
    for(int i = 0; i < 10; i++)
        std::cout << test_array[i] << std::endl;

    return 0;
}
