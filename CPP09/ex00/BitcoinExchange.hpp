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
        std::string dateDB;
        float valueDB;
        std::string line;
        float num;
        bool leapYear;
        std::map<std::string, float> Store;
        int     month;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();

        bool    readInputFile(std::ifstream &infile);
        bool    processDate();
        bool    processValue();
        void    badInput();
        void    readDB();
        int     checkDB();
        void    checkLeap(int ymd);
        bool    checkDay(int ymd);
};