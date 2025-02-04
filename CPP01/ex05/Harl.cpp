#include "Harl.hpp"

Harl::Harl()
{
    level[0] = "DEBUG";
    level[1] = "INFO";
    level[2] = "WARNING";
    level[3] = "ERROR";
    funcPtr[0] = &Harl::debug;
    funcPtr[1] = &Harl::info;
    funcPtr[2] = &Harl::warning;
    funcPtr[3] = &Harl::error;
}

void    Harl::complain( std::string level )
{
    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
    {
        std::cerr << "Unknown level" << std::endl;
        return ;
    }
    int i = 0;
    while (i < 4)
    {
        if (level == this->level[i])
        {
            (this->*funcPtr[i])();
            return ;
        }
        i++;
    }
}

void    Harl::debug(void)
{
    std::cout << "DEBUG" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "INFO" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "WARNING" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "ERROR" << std::endl;
}
