#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *animal[10];

    for (int i = 0; i < 5; i++)
        animal[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animal[i] = new Cat();
    for (int i = 0; i < 10; i++)
        animal[i]->makeSound();
    for (int i = 0; i < 10; i++)
        delete animal[i];
    return (0);
}
