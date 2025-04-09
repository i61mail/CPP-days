#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    // std::cout << "PresidentialPardonForm default constructor is called" << std::endl;
    this->target = "PresidentialPardonForm";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", false, 25, 5), target(_target)
{
    // std::cout << "PresidentialPardonForm constructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
    // std::cout << "PresidentialPardonForm copy constructor is called" << std::endl;
    this->target = obj.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    // std::cout << "PresidentialPardonForm assignment operator is called" << std::endl;
    this->target = obj.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    // std::cout << "PresidentialPardonForm destructor is called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return (this->target);
}

void    PresidentialPardonForm::PureExecute() const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}