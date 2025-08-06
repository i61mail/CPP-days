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
        int b;
        if (!(iss >> b) || !iss.eof())
        {
            badInput();
            return false;
        }

        if (i == 0)
        {
            if (b < 2009 || b > 2025)
            {
                badInput();
                return false;
            }
            //todo: une fois l3am is valid need to check for leap year
        }
        else if (i == 1)
        {
            if (b < 1 || b > 12)
            {
                badInput();
                return false;
            }
        }
        else if (i == 2)
        {
            // todo: khasni n39el 3la chher bach n9der n decide wach nhar valid wla la 
            if (b < 1 || b > 31)
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
    return true;
}

void    BitcoinExchange::badInput()
{
    std::cerr << "Error: bad input => " << line << std::endl;
}

int BitcoinExchange::checkDB()
{
    // todo: need to check data base for values
    return 1;
}

bool    BitcoinExchange::readInputFile(std::ifstream &infile)
{
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
        this->Store[date] = value;
        std::cout << date << " => " << Store[date] << " = " << checkDB() << std::endl;
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
        std::ifstream infile(file);
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


// todo: kabisa wla ma3rt