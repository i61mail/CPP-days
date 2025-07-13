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

    //reverse iterating through stack 
    MutantStack<int>::reverseIterator itrebegin = mustack.rbegin();
    MutantStack<int>::reverseIterator itrend = mustack.rend();

    while (itrebegin != itrend)
    {
        std::cout << "stack element: " << *itrebegin << std::endl;
        itrebegin++;
    }
    return 0;
}