#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // std::cout << "Default constructor is called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
    (void)obj;
    std::cout << "Copy constructor is called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    (void)obj;
    std::cout << "Assignment operator is called" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "Destructor is called" << std::endl;
}
