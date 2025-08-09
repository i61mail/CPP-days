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
    size_t i = 0;
    while (i < makePair.size())
    {
        mainVector.push_back(makePair[i].first);
        pendVector.push_back(makePair[i].second);
        i++;
    }
    VStore = devidePairs(mainVector, -1);

    std::vector<int> reordPend;
    for (size_t i = 0; i < VStore.size(); i++)
    {
        for (size_t j = 0; j < mainVector.size(); j++)
        {
            if (mainVector[j] == VStore[i])
            {
                reordPend.push_back(pendVector[j]);
                break;
            }
        }
    }
    std::vector<int> jacob;
    int j1 = 0;
    int j2 = 1;
    int j = j2;
    while (j < (int)reordPend.size())
    {
        jacob.push_back(j); 
        int next = j2 + 2 * j1; 
        j1 = j2;
        j2 = next;
        j = j2;
    }
    std::vector<bool> alrinsert(reordPend.size(), false);
    for (size_t i = 0; i < jacob.size(); i++)
    {
        int pos = jacob[i] - 1;
        if (alrinsert[pos] == false)
        {
            int value = reordPend[pos];
            std::vector<int>::iterator Lit = std::lower_bound(VStore.begin(), VStore.end(), value);
            VStore.insert(Lit, value);
            alrinsert[pos] = true;
        }
    }
    for (size_t i = 0; i < reordPend.size(); i++)
    {
        if (alrinsert[i] == false)
        {
            int value = reordPend[i];
            std::vector<int>::iterator Lit = std::lower_bound(VStore.begin(), VStore.end(), value);
            VStore.insert(Lit, value);
        }
    }
    if (One != -1)
    {
        std::vector<int>::iterator insertPos = std::lower_bound(VStore.begin(), VStore.end(), One);
        VStore.insert(insertPos, One);
    }
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

std::vector<int>    PmergeMe::checkString(int ac, char **av)
{
    std::vector<int> VStore;
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
    return VStore;
}

int main(int ac, char **av)
{
    PmergeMe obj;
    if (ac != 1)
    {
        try
        {
            struct timeval start, end;
        
            std::vector<int> VStore = obj.checkString(ac, av);
            gettimeofday(&start, NULL);
            VStore = obj.devidePairs(VStore, -1);
            gettimeofday(&end, NULL);
            double VTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
            
            obj.printV(VStore, "After:   ");
            std::cout << "Time to process a range of " << VStore.size() << " elements with std::vector : "
                      << VTime  << " us" << std::endl;

            std::deque<int> DStore(VStore.begin(), VStore.end());
            gettimeofday(&start, NULL);
            DStore = obj.devidePairs(DStore, -1);
            gettimeofday(&end, NULL);
            double DTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
            std::cout << "Time to process a range of " << DStore.size() << " elements with std::deque : "
                      << DTime  << " us" << std::endl;
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
