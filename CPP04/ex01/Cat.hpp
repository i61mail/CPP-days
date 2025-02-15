#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain *idea;
    public :
        Cat();
        Cat(std::string type);
        Cat(const Cat &obj);
        Cat &operator=(const Cat &obj);
        ~Cat();
        void    makeSound() const;
};

#endif