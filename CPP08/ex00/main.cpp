#include "easyfind.hpp"

int main()
{
    try
    {
        std::cout << "/*  vector test  */" << std::endl;
        std::vector<int> test;

        for (size_t i = 0; i < 4; i++)
            test.push_back(i);
        std::vector<int>::iterator it = easyfind(test, 2);
        std::cout << "First occurrence = " << *it << std::endl;
        print(test, it);

        std::cout << std::endl;
        
        std::cout << "/*  list test  */" << std::endl;
        std::list<int> test2;
        for (size_t i = 0; i < 4; i++)
            test2.push_back(i);
        std::list<int>::iterator it2 = easyfind(test2, 2);
        std::cout << "First occurrence = " << *it2 << std::endl;
        print(test2, it2);

    }
    catch(const char *message)
    {
        std::cerr <<  message << std::endl;
    }
    return 0;
}