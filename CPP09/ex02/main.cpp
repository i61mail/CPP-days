#include "PmergeMe.hpp"

void    PmergeMe::printV()
{
    // std::vector< std::pair<int, int> >::iterator Pit = PStore.begin();
    // while (Pit != PStore.end())
    // {
    //     std::cout << "first == " << Pit->first << " second == " << Pit->second << std::endl;
    //     Pit++;
    // }
    // std::cout << "leftOver == " << One << std::endl;
    std::vector<int>::iterator Vit = VStore.begin();
    std::cout << "Before:  ";
    while (Vit != VStore.end())
    {
        std::cout << *Vit;
        Vit++;
        if (Vit != VStore.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::print(std::vector<int> aa)
{
    std::vector<int>::iterator Vit = aa.begin();
    std::cout << "After:   ";
    while (Vit != aa.end())
    {
        std::cout << *Vit;
        Vit++;
        if (Vit != aa.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

std::vector<int>    PmergeMe::devidePairs()
{
    if (VStore.size() < 1)
        return VStore;
    else if (VStore.size() == 2)
    {
        if (VStore[0] > VStore[1])
            std::swap(VStore[0], VStore[1]);
        return VStore;
    }
    std::vector<int> mainVector;
    std::vector<int> pendVector;
    std::vector< std::pair<int, int> >::iterator Pit = PStore.begin();
    while (Pit != PStore.end())
    {
        mainVector.push_back(Pit->first);
        pendVector.push_back(Pit->second);
        Pit++;
    }
    // print(mainVector);
    // print(pendVector);
    return VStore;
}

void    PmergeMe::pairInts()
{
    std::vector<int>::iterator it = VStore.begin();
    while (it != VStore.end())
    {
        int a = *it;
        it++;
        if (it == VStore.end())
        {
            One = a;
            return ;
        }
        int b = *it;
        if (a < b)
            PStore.push_back(std::make_pair(a, b));
        else
            PStore.push_back(std::make_pair(b, a));
        it++;
    }
}

void    PmergeMe::checkString(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string str(av[i]);
        if (str.empty())
            throw "Error";
        int j = 0;
        while (str[j])
        {
            if (!isdigit(str[j]))
                throw "Error";
            j++;
        }
        if (str.size() > 10)
            throw "Error";
        long number = std::strtod(str.c_str(), NULL);
        if (number > 2147483647)
            throw "Error";
        VStore.push_back(number);
    }
    printV();
    pairInts();
    std::vector<int> aa = devidePairs();
    print(aa);
}

int main(int ac, char **av)
{
    PmergeMe obj;
    if (ac != 1)
    {
        try
        {
            obj.checkString(ac, av);
        }
        catch (const char *e)
        {
            std::cout << e << std::endl;
        }
    }
    else
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}