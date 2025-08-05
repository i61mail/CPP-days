#include "BitcoinExchange.hpp"


bool    BitcoinExchange::readInputFile(std::ifstream &infile)
{
    std::string line;

    std::getline(infile, line);
    if (line != "data | value")
        throw "invalid Format";
    infile.close();
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
