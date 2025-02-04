#include "replace.hpp"

void    replaceLine(std::ifstream &infile, std::string s1, std::string s2, std::ofstream &outfile)
{
    std::string line;

    while (std::getline(infile, line))
    {
        size_t i = 0;
        i = line.find(s1, i);
        while (i != (size_t)-1)
        {
            line.erase(i, s1.length());
            line.insert(i, s2);
            i += s2.length();
            i = line.find(s1, i);
        }
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;
    }
}