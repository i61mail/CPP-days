#include "Array.hpp"

int main()
{
    try
    {
        //exception test
        // Array <int> arrError(0);

        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 2;
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        Array<int> arr2(arr);
        for (unsigned int i = 0; i < arr2.size(); i++)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;

        Array<int> arr3;
        arr3 = arr2;
        for (unsigned int i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;

        //test for checking if the other array is not affected
        arr2[0] = 42;
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        for (unsigned int i = 0; i < arr2.size(); i++)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}