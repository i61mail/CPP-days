#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    std::cout << "default constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name("default")
{
    std::cout << "parameter constructor is called" << std::endl;
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    std::cout << "copy constructor is called" << std::endl;
    *this = obj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    std::cout << "copy assignment operator is called" << std::endl;
    if (this != &obj)
        this->grade = obj.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor is called" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    this->grade++;
}
