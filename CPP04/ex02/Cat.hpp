#ifndef CAT_HPP
#define CAT_HPP

#include "_Animal.hpp"
#include "Brain.hpp"

class Cat : public _Animal
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