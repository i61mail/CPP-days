#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address memory of the string : " << &str << std::endl;
    std::cout << "Address memory of the stringPTR : " << stringPTR << std::endl;
    std::cout << "Address memory of the stringREF : " << &stringREF << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "the value of the string : " << str << std::endl;
    std::cout << "the value of the stringPTR : " << *stringPTR << std::endl;
    std::cout << "the value of the stringREF : " << stringREF << std::endl;
    return (0);
}