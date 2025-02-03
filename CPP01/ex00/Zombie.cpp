#include "Zombie.hpp"

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
