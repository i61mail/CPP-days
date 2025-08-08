#pragma once

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
    private :
        std::vector<int> VStore;
        std::vector< std::pair<int, int> > PStore;
        int             One;
    public :
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();

        void    checkString(int ac, char **av);
        void    pairInts();
        std::vector<int>     devidePairs();
        void    printV();
        void    print(std::vector<int> aa);
};