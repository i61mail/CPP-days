#include "RPN.hpp"

void    validString(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]) && str[i] != '\\' && str[i] != '-' && str[i] != '+' && str[i] != '*' && str[i] != ' ')
            throw "Error";
        
        i++;
    }
}

void    RPN::processString(std::string str)
{
    validString(str);
}

int main(int ac, char **av)
{
    RPN obj;
    if (ac == 2)
    {
        std::string str(av[1]);
        if (str.empty())
        {
            std::cerr << "Empty string" << std::endl;
            return 1;
        }
        try 
        {
            obj.processString(str);
        }
        catch(const char *e)
        {
            std::cerr << e << std::endl;
        }
    }
    else
        std::cerr << "Error" << std::endl;
    return 0;
}