#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        void announce( void );
        void NameZombie(std::string zombieName);
        Zombie(std::string zombieName);
        Zombie(void);
        ~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif