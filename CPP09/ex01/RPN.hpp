#pragma once

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<size_t> Store;
    public:
        RPN();
        RPN(const RPN& obj);
        RPN &operator=(const RPN &obj);
        ~RPN();

        void    processString(std::string str);
        void    makeCalculation(char op);
};