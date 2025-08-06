#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "Default constructor is called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    (void)obj;
    // std::cout << "Copy constructor is called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    (void)obj;
    // std::cout << "Copy assignment operator" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "Destructor is called" << std::endl;
    // infile.close();
}

