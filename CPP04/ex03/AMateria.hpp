
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class AMateria
{
    protected :
        std::string type;
    public :
        AMateria();
        AMateria(std::string const &type);
        AMateria(AMateria const &obj);
        AMateria &operator=(AMateria const &obj);
        virtual ~AMateria();
        
        std::string const & getType() const; //Returns the materia type
        void    setType(const std::string &type);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif