#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    // std::cout << "RobotomyRequestForm default constructor is called" << std::endl;
    this->target = "RobotomyRequestForm";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", false, 0, 45), target(_target)
{
    // std::cout << "RobotomyRequestForm constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
    // std::cout << "RobotomyRequestForm copy constructor is called" << std::endl;
    this->target = obj.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    // std::cout << "RobotomyRequestForm assignment operator is called" << std::endl;
    this->target = obj.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << "RobotomyRequestForm destructor is called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void    RobotomyRequestForm::PureExecute() const
{
    static int i;

    std::cout << "Making some drilling noises..." << std::endl;

    if (i > 10)
        i = 0;
    bool success = (i++ % 2) == 0;
    if (success)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << getTarget() << "!" << std::endl;
}