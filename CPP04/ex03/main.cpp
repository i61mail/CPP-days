#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    {
        IMateriaSource *ms = new MateriaSource();
        IMateriaSource &ref = *ms;

        ref.learnMateria(new Ice());
        ref.learnMateria(new Cure());
        AMateria *tmp_ice = ref.createMateria("ice");
        AMateria *tmp_cure = ref.createMateria("cure");
        ICharacter *ch = new Character("ismail");
        ICharacter &cha = *ch;

        cha.equip(tmp_ice);
        cha.equip(tmp_cure);
        // cha.unequip(0);
        // cha.unequip(1);
        cha.unequip(0);
        cha.equip(tmp_ice);


        cha.use(0, cha);
        cha.use(1, cha);

        Character::deleteMateriaList();
        delete ms;
        delete ch;
    }
    // IMateriaSource* src = new MateriaSource();
    
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    
    // ICharacter* me = new Character("me");
    
    // AMateria* tmp;
    
    // tmp = src->createMateria("ice");

    // me->equip(tmp);
    
    // tmp = src->createMateria("cure");
    
    // me->equip(tmp);
    
    // ICharacter* bob = new Character("bob");
    
    // me->use(0, *bob);
    // me->use(1, *bob);

    // Character::deleteMateriaList();
    // delete bob;
    // delete me;
    // delete src;
    return 0;
}