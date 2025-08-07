#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "Default constructor is called" << std::endl;
}

RPN::RPN(const RPN& obj)
{
    std::cout << "Copy constructor is called" << std::endl;
    this->Store = obj.Store;
}

RPN &RPN::operator=(const RPN &obj)
{
    std::cout << "Assignment operator is called" << std::endl;
    if (this != &obj)
        this->Store = obj.Store;
    return *this;
}

RPN::~RPN()
{
    // std::cout << "Destructor is called" << std::endl;
}