#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>


class BitcoinExchange
{
    private:
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();

        bool    readInputFile(std::ifstream &infile);

        

};