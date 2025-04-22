#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> test;
        for (size_t i = 0; i < 4; i++)
            test.push_back(i);
        easyfind(test, 4); 
    }
    catch(customException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}