#include "RPN.hpp"

void    RPN::makeCalculation(char op)
{
    if (Store.size() < 2)
        throw "Error";
    long a = Store.top();
    Store.pop();
    long b = Store.top();
    Store.pop();
    long maxInt = 2147483647;
    long minInt = -2147483648;

    switch (op)
    {
        case '+': if (a + b > maxInt) throw "Error: Overflow"; Store.push(b + a); break;
        case '-': if (a - b > maxInt || a - b < minInt) throw "Error: Overflow"; Store.push(b - a); break;
        case '/': if (a == 0) throw "Error"; Store.push(b / a); break;
        case '*': if (a * b > maxInt) throw "Error: Overflow"; Store.push(b * a); break; 
    }
}

void    RPN::processString(std::string str)
{
    long i = 0;
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
            continue ;//0 1-
        }
        long number = str[i] - 48;
        if (number > 9 || number < 0)
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

//! the use for RPN is for like that instead of doing the parentesis,
//! the operators can follow the numbers(3 + 5) * (7 - 2) would be written in RPN as: 3 5 + 7 2 -