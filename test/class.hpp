#include <iostream>

class custom : public std::exception
{
    public :
        virtual const char *what() const throw();
};

class Printer
{
        int _count;
    public :
        Printer(int count) : _count(count) {}
        void    printMessage(std::string message);


};
