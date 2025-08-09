#include <iostream>
#include <vector>


//j(n) = j(n - 1)+ 2 * j(n - 2) starting with j(0) = 0 && j(1) = 1  and j1 == j(n - 2) && j2 == j(n - 1)
int main()
{
    std::vector<int> jacob;
    std::vector<int> hh(2);
    int j1 = 0;
    int j2 = 1;
    int j = j2;
    while (j < (int)hh.size())
    {
        jacob.push_back(j);
        int next = j2 + 2 * j1;
        j1 = j2;
        j2 = next;
        j = j2;
    }
}

