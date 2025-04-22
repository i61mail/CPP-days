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
        void    printVector();
        void    addNumber(long n);
        long    shortestSpan();
        long    longestSpan();
        void    addByOnce(std::vector<long>::iterator begin, std::vector<long>::iterator end);

        class noSpaceLeft : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class noSpanCanBeFound : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};


#endif