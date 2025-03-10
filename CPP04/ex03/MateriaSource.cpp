#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
    std::cout << "MateriaSource default constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        materiaSource[i] = NULL;
}

MateriaSource::MateriaSource(std::string type) : count(0)
{
    std::cout << "MateriaSource constructor is called" << std::endl;
    (void)type;
    for (int i = 0; i < 4; i++)
        materiaSource[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    std::cout << "MateriaSource copy constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        materiaSource[i] = NULL;
    *this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
    std::cout << "MateriaSource assignment operator is called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i < 4; i++)
        {
            delete materiaSource[i];
            materiaSource[i] = NULL;
        }
        this->type = obj.type;
        for (int i = 0; i < 4; i++)
        {
            if (obj.materiaSource[i])
                materiaSource[i] = obj.materiaSource[i]->clone();
        }
        count = obj.count;
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor is called" << std::endl;
}

void    MateriaSource::learnMateria(AMateria *learn)
{
    if (learn != NULL && count < 4)
    {
        materiaSource[count] = learn->clone();
        count++;
        delete learn;
    }
    else if (learn != NULL)
        delete learn;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materiaSource[i] && materiaSource[i]->getType() == type)
            return (materiaSource[i]->clone());
    }
    return (NULL);
}