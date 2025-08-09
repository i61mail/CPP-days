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

std::deque<int>    PmergeMe::devidePairs(std::deque<int> DStore, int One)
{
    if (DStore.size() < 2)
        return DStore;
    else if (DStore.size() == 2)
    {
        if (DStore[0] > DStore[1])
            std::swap(DStore[0], DStore[1]);
        return DStore;
    }

    std::deque<int> maindeque;
    std::deque<int> penddeque;
    std::deque< std::pair<int, int> > makePair = pairInts(DStore, One);
    size_t i = 0;
    while (i < makePair.size())
    {
        maindeque.push_back(makePair[i].first);
        penddeque.push_back(makePair[i].second);
        i++;
    }
    DStore = devidePairs(maindeque, -1);

    std::deque<int> reordPend;
    for (size_t i = 0; i < DStore.size(); i++)
    {
        for (size_t j = 0; j < maindeque.size(); j++)
        {
            if (maindeque[j] == DStore[i])
            {
                reordPend.push_back(penddeque[j]);
                break;
            }
        }
    }
    std::deque<int> jacob;
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
    std::deque<bool> alrinsert(reordPend.size(), false);
    for (size_t i = 0; i < jacob.size(); i++)
    {
        int pos = jacob[i] - 1;
        if (alrinsert[pos] == false)
        {
            int value = reordPend[pos];
            std::deque<int>::iterator Lit = std::lower_bound(DStore.begin(), DStore.end(), value);
            DStore.insert(Lit, value);
            alrinsert[pos] = true;
        }
    }
    for (size_t i = 0; i < reordPend.size(); i++)
    {
        if (alrinsert[i] == false)
        {
            int value = reordPend[i];
            std::deque<int>::iterator Lit = std::lower_bound(DStore.begin(), DStore.end(), value);
            DStore.insert(Lit, value);
        }
    }
    if (One != -1)
    {
        std::deque<int>::iterator insertPos = std::lower_bound(DStore.begin(), DStore.end(), One);
        DStore.insert(insertPos, One);
    }
    return DStore;
}

std::deque< std::pair<int, int> >     PmergeMe::pairInts(std::deque<int> DStore, int &One)
{
    std::deque< std::pair<int, int> > PStore;
    std::deque<int>::iterator it = DStore.begin();
    while (it != DStore.end())
    {
        int a = *it;
        it++;
        if (it == DStore.end())
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