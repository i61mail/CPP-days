#include "class.hpp"

const char *custom::what() const throw()
{
    return ("Exception from derived class");
}

void Printer::printMessage(std::string message)
{
    int length = message.length() / 10;
    if (length > _count)
        throw custom();
    std::cout << message << std::endl;
    _count -= length;
    // std::cout << _count << std::endl;
}