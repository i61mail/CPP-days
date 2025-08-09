#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include "sys/time.h"

class PmergeMe
{
    private :
        
    public :
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        std::vector<int>   checkString(int ac, char **av);
        std::vector< std::pair<int, int> >     pairInts(std::vector<int> VStore, int &One);
        std::vector<int>     devidePairs(std::vector<int> VStore, int One);
        void    printV(std::vector<int> VStore, std::string str);
};