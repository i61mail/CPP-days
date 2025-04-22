#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mustack;

    //push element to stack
    mustack.push(5);
    mustack.push(2);
    mustack.push(17);
    mustack.push(20);
    mustack.push(12);

    //iterate through stack 
    MutantStack<int>::iterator itbegin = mustack.begin();
    MutantStack<int>::iterator itend = mustack.end();

    while (itbegin != itend)
    {
        std::cout << "stack element: " << *itbegin << std::endl;
        itbegin++;
    }

    //print top element stack
    std::cout << "Top element: " << mustack.top() << std::endl;
    //pop element from stack
    mustack.pop();
    //size of stack
    std::cout << "stack size: " << mustack.size() << std::endl;

    //reverse iterating throigh stack 
    MutantStack<int>::reverse_iterator itrebegin = mustack.rbegin();
    MutantStack<int>::reverse_iterator itrend = mustack.rend();

    while (itrebegin != itrend)
    {
        std::cout << "stack element: " << *itrebegin << std::endl;
        itrebegin++;
    }

    //test for copy construction 
    MutantStack<int> mu(mustack);

    //iterating through stack
    MutantStack<int>::iterator muitbegin = mu.begin();
    MutantStack<int>::iterator muitend = mu.end();

    while (muitbegin != muitend)
    {
        std::cout << "mu stack element: " << *muitbegin << std::endl;
        muitbegin++;
    }
    return 0;
}