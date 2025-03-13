#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete (meta);
    delete (j);
    delete (i);

    //Wronganimal
    std::cout << std::endl;
    std::cout << "---------- TESTS FOR WRONGANIMAL -----------" << std::endl;
    std::cout << std::endl;

    const WrongAnimal *temp = new WrongAnimal();
    const WrongAnimal *temp1 = new WrongCat();
    std::cout << temp->getType() << std::endl;
    std::cout << temp1->getType() << std::endl;

    temp->makeSound();
    temp1->makeSound();

    delete temp;
    delete temp1;

    return (0);
}
