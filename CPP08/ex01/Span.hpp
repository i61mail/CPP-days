#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private :
        unsigned int N;
        std::vector<long> container;
    public :
        Span();
        Span(unsigned int _N);
        Span(const Span &obj);
        Span &operator=(const Span &obj);
        ~Span();
        unsigned int &getN();
        void    addNumber(long n);
        long    shortestSpan();
        long    longestSpan();
        void    addByOnce(std::vector<long>::iterator begin, std::vector<long>::iterator end);
};


#endif