#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {};
        MutantStack(const MutantStack &obj) : std::stack<T>(obj) {};
        MutantStack &operator=(const MutantStack &obj){
            if (this != &obj)
                std::stack<T>::operator=(obj);
            return *this;
        }
        ~MutantStack() {};

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverseIterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        reverseIterator rbegin()
        {
            return this->c.rbegin();
        }
        reverseIterator rend()
        {
            return this->c.rend();
        }
};

#endif