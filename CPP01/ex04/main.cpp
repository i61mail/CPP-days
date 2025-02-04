#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        if (s1.empty())
        {
            std::cerr << "s1 is empty" << std::endl;
            return (1);
        }
        std::ifstream infile(filename.c_str());
        if (!infile.is_open())
        {
            std::cerr << "cannot open file" << std::endl;
            return (1);
        }
        std::string outFileName = filename;
        std::ofstream outfile(outFileName.append(".replace").c_str());
        if (!outfile.is_open())
        {
            std::cerr << "cannot open file" << std::endl;
            return (1);
        }
        replaceLine(infile, s1, s2, outfile);
        infile.close();
        outfile.close();
    }
    else
        std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
    return (0);
}
