#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <stdint.h>

typedef struct Data
{
    int         i;
    char        c;
    float       f;
    double      d;
} Data;

class Serializer
{
    private :
        Serializer();
        Serializer(const Serializer &obj);
        Serializer &operator=(const Serializer &obj);
        ~Serializer();
    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
