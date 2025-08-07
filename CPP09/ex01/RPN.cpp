#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "Default constructor is called" << std::endl;
}

RPN::RPN(const RPN& obj)
{
    (void)obj;
    std::cout << "Copy constructor is called" << std::endl;
}

RPN &RPN::operator=(const RPN &obj)
{
    (void)obj;
    std::cout << "Assignment operator is called" << std::endl;
    return *this;
}

RPN::~RPN()
{
    // std::cout << "Destructor is called" << std::endl;
}