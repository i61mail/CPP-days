#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

void    replaceLine(std::ifstream &infFile, std::string s1, std::string s2, std::ofstream &outfile);

#endif