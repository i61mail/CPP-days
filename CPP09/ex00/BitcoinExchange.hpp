#pragma once

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>


class BitcoinExchange
{
    private:
        std::string date;
        std::string value;
        std::string line;
        double num;
        std::map<std::string, std::string> Store;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();

        bool    readInputFile(std::ifstream &infile);
        bool    processDate();
        bool    processValue();
        void    badInput();
        int     checkDB();

        

};