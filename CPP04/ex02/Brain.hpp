#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private :
        std::string ideas[100];
    public :
        Brain();
        Brain(std::string ideas[100]);
        Brain(const Brain &obj);
        Brain &operator=(const Brain &obj);
        ~Brain();
};

#endif