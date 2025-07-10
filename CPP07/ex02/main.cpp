#include "Array.hpp"

int main()
{
    try
    {
        // normal
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 2;
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        // test for index out of range
        std::cout << arr[7] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}