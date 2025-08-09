#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // std::cout << "Default constructor is called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
    (void)obj;
    std::cout << "Copy constructor is called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    (void)obj;
    std::cout << "Assignment operator is called" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe()
{
    // std::cout << "Destructor is called" << std::endl;
}

std::deque<int>    PmergeMe::devidePairs(std::deque<int> VStore, int One)
{
    if (VStore.size() < 2)
        return VStore;
    else if (VStore.size() == 2)
    {
        if (VStore[0] > VStore[1])
            std::swap(VStore[0], VStore[1]);
        return VStore;
    }

    std::deque<int> maindeque;
    std::deque<int> penddeque;
    std::deque< std::pair<int, int> > makePair = pairInts(VStore, One);
    size_t i = 0;
    while (i < makePair.size())
    {
        maindeque.push_back(makePair[i].first);
        penddeque.push_back(makePair[i].second);
        i++;
    }
    VStore = devidePairs(maindeque, -1);

    std::deque<int> reorderedPend;
    for (size_t i = 0; i < VStore.size(); i++)
    {
        for (size_t j = 0; j < maindeque.size(); j++)
        {
            if (maindeque[j] == VStore[i])
            {
                reorderedPend.push_back(penddeque[j]);
                break;
            }
        }
    }
    std::deque<int> jacob;
    int j1 = 0;
    int j2 = 1;
    int j = j2;
    while (j < (int)reorderedPend.size())
    {
        jacob.push_back(j); 
        int next = j2 + 2 * j1; 
        j1 = j2;
        j2 = next;
        j = j2;
    }
    std::deque<bool> alrinsert(reorderedPend.size(), false);
    for (size_t i = 0; i < jacob.size(); i++)
    {
        int pos = jacob[i] - 1;
        if (alrinsert[pos] == false)
        {
            int value = reorderedPend[pos];
            std::deque<int>::iterator Lit = std::lower_bound(VStore.begin(), VStore.end(), value);
            VStore.insert(Lit, value);
            alrinsert[pos] = true;
        }
    }
    for (size_t i = 0; i < reorderedPend.size(); i++)
    {
        if (alrinsert[i] == false)
        {
            int value = reorderedPend[i];
            std::deque<int>::iterator Lit = std::lower_bound(VStore.begin(), VStore.end(), value);
            VStore.insert(Lit, value);
        }
    }
    if (One != -1)
    {
        std::deque<int>::iterator insertPos = std::lower_bound(VStore.begin(), VStore.end(), One);
        VStore.insert(insertPos, One);
    }
    return VStore;
}

std::deque< std::pair<int, int> >     PmergeMe::pairInts(std::deque<int> VStore, int &One)
{
    std::deque< std::pair<int, int> > PStore;
    std::deque<int>::iterator it = VStore.begin();
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