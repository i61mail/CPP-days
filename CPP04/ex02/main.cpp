#include "_Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    _Animal *_animal[10];

    for (int i = 0; i < 5; i++)
        _animal[i] = new Dog();
    for (int i = 5; i < 10; i++)
        _animal[i] = new Cat();
    for (int i = 0; i < 10; i++)
        _animal[i]->makeSound();
    for (int i = 0; i < 10; i++)
        delete _animal[i];
    return (0);
}
