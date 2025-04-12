#include "iter.hpp"

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    iter(tab, sizeof(tab) / (size_t)4, print);

    char *c = new char[5];
    c[0] = 'a';
    c[1] = 'b';
    c[2] = 'c';
    c[3] = 'd';
    c[4] = 'e';
    iter(c, 5, change);
    delete[] c;
    return (0);
}