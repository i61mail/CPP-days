#include "RPN.hpp"

void    RPN::makeCalculation(char op)
{
    if (Store.size() < 2)
        throw "Error";
    size_t a = Store.top();
    Store.pop();
    size_t b = Store.top();
    Store.pop();

    switch (op)
    {
        case '+': Store.push(b + a); break;
        case '-': Store.push(b - a); break;
        case '/': Store.push(b / a); break;
        case '*': Store.push(b * a); break; 
    }
}

void    RPN::processString(std::string str)
{
    size_t i = 0;
    while (str[i])
    {
        if (!std::isdigit(str[i]) && str[i] != '/' && str[i] != '-' && str[i] != '+' && str[i] != '*' && !isspace(str[i]))
            throw "Error";
        while (std::isspace(str[i]))
            i++;
        if (str[i] == '/' || str[i] == '-' || str[i] == '+' || str[i] == '*')
        {
            makeCalculation(str[i]);
            i++;
            continue ;
        }
        size_t number = str[i] - 48;
        if (number > 9)
            throw "Error";
        Store.push(number);
        i++;
    }
    if (Store.size() > 1)
        throw "Error";
    std::cout << Store.top() << std::endl;
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
