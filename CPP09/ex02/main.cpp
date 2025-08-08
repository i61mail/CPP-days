#include "PmergeMe.hpp"

void    PmergeMe::printV(std::vector<int> VStore, std::string str)
{
    std::vector<int>::iterator Vit = VStore.begin();
    std::cout << str;
    while (Vit != VStore.end())
    {
        std::cout << *Vit;
        Vit++;
        if (Vit != VStore.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

std::vector<int>    PmergeMe::devidePairs(std::vector<int> VStore, int One)
{
    if (VStore.size() < 2)
        return VStore;
    else if (VStore.size() == 2)
    {
        if (VStore[0] > VStore[1])
            std::swap(VStore[0], VStore[1]);
        return VStore;
    }
    std::vector<int> mainVector;
    std::vector<int> pendVector;
    std::vector< std::pair<int, int> > makePair = pairInts(VStore, One);
    std::vector< std::pair<int, int> >::iterator Pit = makePair.begin();
    while (Pit != makePair.end())
    {
        mainVector.push_back(Pit->first);
        pendVector.push_back(Pit->second);
        Pit++;
    }
    // printV(mainVector, "mainVector:  ");
    // printV(pendVector, "pendVector:  ");
    VStore = devidePairs(mainVector, One);

    int firstMain = mainVector[0];
    int firstPair = pendVector[0];
    std::vector<int>::iterator it = std::find(VStore.begin(), VStore.end(), firstMain);
    if (it != VStore.end())
        VStore.insert(it, firstPair);
    pendVector.erase(pendVector.begin());
    return VStore;
}

std::vector< std::pair<int, int> >     PmergeMe::pairInts(std::vector<int> VStore, int &One)
{
    std::vector< std::pair<int, int> > PStore;
    std::vector<int>::iterator it = VStore.begin();
    while (it != VStore.end())
    {
        int a = *it;
        it++;
        if (it == VStore.end())
        {
            One = a;
            return PStore;
        }
        int b = *it;
        if (a < b)
            PStore.push_back(std::make_pair(b, a));
        else
            PStore.push_back(std::make_pair(a, b));
        it++;
    }
    return PStore;
}

void    PmergeMe::checkString(int ac, char **av)
{
    std::vector<int> VStore;
    int                 One = -1;
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
    printV(VStore, "Before:  ");
    std::vector<int> aa = devidePairs(VStore, One);
    printV(aa, "After:   ");
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
