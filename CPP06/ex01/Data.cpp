#include "Data.hpp"

Serializer::Serializer()
{
    // std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &obj)
{
    // std::cout << "Serializer copy constructor called" << std::endl;
    *this = obj;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
    // std::cout << "Serializer copy assignment operator called" << std::endl;
    (void)obj;
    return *this;
}

Serializer::~Serializer()
{
    // std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data data;
    data.i = 42;
    data.c = 'a';
    data.f = 3.14f;
    data.d = 13.37;

    std::cout << "Original Data:" << std::endl;
    std::cout << "i: " << data.i << std::endl;
    std::cout << "c: " << data.c << std::endl;
    std::cout << "f: " << data.f << std::endl;
    std::cout << "d: " << data.d << std::endl;
    std::cout << "Address of original data: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "i: " << deserializedData->i << std::endl;
    std::cout << "c: " << deserializedData->c << std::endl;
    std::cout << "f: " << deserializedData->f << std::endl;
    std::cout << "d: " << deserializedData->d << std::endl;
    std::cout << "Address of original data: " << &data << std::endl;

    return 0;
}