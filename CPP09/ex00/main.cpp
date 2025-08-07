#include "BitcoinExchange.hpp"

int    hasTwoDashes(std::string str)
{
    int count = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '-')
            count++;
    }
    return count;
}

void    BitcoinExchange::checkLeap(int ymd)
{
    if (ymd % 4 == 0)
    {
        //* ila kan divisible b 100, -> not leap ila ida kan divisible b 400
        if (ymd % 100 == 0)
        {
            if (ymd % 400 == 0)
                leapYear = true; //* divisible by 400 → leap
            else
                leapYear = false; //* divisible by 100 but 400 la → not leap
        }
        else
            leapYear = true;       //* divisible by 4 but 100 la → leap
    }
    else
        leapYear = false; //* machi divisible b 4 → not leap
}

bool    BitcoinExchange::checkDay(int ymd)
{
    if (month == 2)
    {
        if (ymd < 1 || (ymd > 28 && leapYear == false))
            return false;
        else if (ymd < 1 || (ymd > 29 && leapYear == true))
            return false;
    }
    else if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (ymd < 1 || ymd > 30)
            return false;
    }
    else
    {
        if (ymd < 1 || ymd > 31)
            return false;
    }
    return true;
}

bool    BitcoinExchange::processDate()
{
    if (hasTwoDashes(date) != 2)
    {
        badInput();
        return false;
    }
    std::stringstream ss(date);
    std::string word;
    int i = 0;
    while (std::getline(ss, word, '-'))
    {
        std::istringstream iss(word);
        int ymd;
        if (!(iss >> ymd) || !iss.eof())
        {
            badInput();
            return false;
        }

        if (i == 0)
        {
            if (ymd < 2009 || ymd > 2025)
            {
                badInput();
                return false;
            }
            checkLeap(ymd);
        }
        else if (i == 1)
        {
            if (ymd < 1 || ymd > 12)
            {
                badInput();
                return false;
            }
            month = ymd;
        }
        else if (i == 2)
        {
            if (checkDay(ymd) == false)
            {
                badInput();
                return false;
            }
        }
        i++;
    }
    if (processValue() == false)
        return false;
    return true;
}

bool   BitcoinExchange::processValue()
{
    value = value.substr(2, value.size());

    int dotPos = 0;
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
        {
            if (value.size() == i || !isdigit(value[i + 1]) || !isdigit(value[i - 1]))
            {
                std::cerr << "Error: bad input" << std::endl;
                return false;
            }
            dotPos++;
        }
        else if (!std::isdigit(value[i]))
        {
            if (value[i] == '-')
            {
                std::cerr << "Error: not a positive number." << std::endl;
                return false;
            }
            std::cerr << "Error: not a digit " << value << std::endl;
            return false;
        }
    }
    if (dotPos > 1)
    {
        std::cerr << "Error: bad input" << std::endl;
        return false;
    }
    std::istringstream iss(value);
    if (!(iss >> num))
    {
        std::cerr << "Error: bad input" << std::endl;
        return false;
    }
    if (num < 0.0 || num > 1000.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;

    }
    this->inputMap[date] = num;
    return true;
}

void BitcoinExchange::readDB()
{
    // todo: need to check data base for values
    std::ifstream infile("data.csv");
    if (!infile.is_open())
        throw "Error: cannot open file";
    std::string line;
    if (!std::getline(infile, line))
        throw "Error: empty data base";
    while (std::getline(infile, line))
    {
        std::stringstream ss(line);
        std::string tempValue;
        if (std::getline(ss, dateDB, ',') && std::getline(ss, tempValue))
        {
            valueDB = std::atof(tempValue.c_str());
            DBmap[dateDB] = valueDB;
        }
    }
}

float BitcoinExchange::checkDB()
{
    std::map<std::string, float>::iterator it = this->DBmap.find(date);
    if (it != this->DBmap.end())
        return it->second * this->inputMap[date];
    else
    {
        it = this->DBmap.lower_bound(date);
        if (it == this->DBmap.begin())
            return it->second * this->inputMap[date];
        if (it == this->DBmap.end() || it->first != date)
            --it;
        return it->second * this->inputMap[date];
    }
    return 1;
}

bool    BitcoinExchange::readInputFile(std::ifstream &infile)
{
    readDB();
    std::getline(infile, line);

    if (line != "date | value")
        throw "Error: invalid Format";
    
    while (std::getline(infile, line))
    {
        size_t delimPos = line.find("|");
        if (delimPos == std::string::npos || delimPos != 11)
        {
            badInput();
            continue;
        }
        else if (delimPos == 11)
        {
            if (!std::isspace(line[10]) || !std::isspace(line[12]))
            {
                badInput();
                continue;
            }
        }
        date = line.substr(0, delimPos - 1);
        value = line.substr(delimPos, line.size());

        if (processDate() == false)
            continue ;
        std::cout << date << " => " << num << " = " << checkDB() << std::endl;
    }
    
    return true;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string file(av[1]);
        if (file.empty())
        {
            std::cerr << "Error: file is empty." << std::endl;
            return 1;
        }
        std::ifstream infile(file.c_str());
        if (!infile.is_open())
        {
            std::cerr << "Error: cannot open file" << std::endl;
            return 1;
        }
        try
        {
            BitcoinExchange btc;
            btc.readInputFile(infile);
        }
        catch(const char *e)
        {
            std::cerr << e << std::endl;
        }
        
    }
    else if (ac > 2)
        std::cerr << "Error: too many args." << std::endl;
    else
        std::cerr << "Error: could not open file." << std::endl;
    return 0;
}
