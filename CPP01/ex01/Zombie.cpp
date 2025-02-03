#include "Zombie.hpp"

void    Zombie::NameZombie(std::string zombieName)
{
    this->name = zombieName;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie( void )
{
    std::cout << this->name << " is destroyed." << std::endl;
}

Zombie::Zombie(std::string zombieName)
{
    this->name = zombieName;
}

void    Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
