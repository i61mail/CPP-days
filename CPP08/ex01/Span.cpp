#include "Span.hpp"

Span::Span()
{
    // std::cout << "Span default constructor is called" << std::endl;
    this->N = 0;
}

Span::Span(unsigned int _N)
{
    // std::cout << "Span constuctor is called" << std::endl;
    this->N = _N;
}

Span::Span(const Span &obj)
{
    // std::cout << "Span copy consturtor is called" << std::endl;
    this->N = obj.N;
}

Span &Span::operator=(const Span &obj)
{
    // std::cout << "Span assignment operator is called" << std::endl;
    if (this != &obj)
        this->N = obj.N;
    return *this;
}

Span::~Span()
{
    // std::cout << "Span destructor is called" << std::endl;
}

unsigned int &Span::getN()
{
    return this->N;
}

void Span::addNumber(long n)
{
    if (this->container.size() >= this->N)
        throw "No Space Left";
    else
        this->container.push_back(n);
}

long Span::longestSpan()
{
    std::vector<long>::iterator maxElem;

    if (this->container.size() <= 1)
        throw "no span can be found";
    
    std::sort(container.begin(), container.end());
    maxElem = std::max_element(container.begin(), container.end());
    return (*maxElem - container.at(0));
}

long Span::shortestSpan()
{
    if (this->container.size() == 1)
        throw "no span can be found";

    long longest = Span::longestSpan();
    std::sort(container.begin(), container.end());
    for (size_t i = 0; i < container.size() - 1; i++)
    {
        long check = container.at(i + 1) - container.at(i);
        if (check < longest)
            longest = check;
    }
    return longest;
}

void    Span::addByOnce(std::vector<long>::iterator begin, std::vector<long>::iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        begin++;
    }
}