#include "Intern.hpp"

Intern::Intern()
{
    // std::cout << "Intern default constructor called" << std::endl;
    forms[0] = "robotomy request";
    forms[1] = "presidential pardon";
    forms[2] = "shrubbery creation";
    formFunctions[0] = &Intern::createRobotomyRequest;
    formFunctions[1] = &Intern::createPresidentialPardon;
    formFunctions[2] = &Intern::createShrubberyCreation;
}

Intern::Intern(const Intern &obj)
{
    // std::cout << "Intern copy constructor called" << std::endl;
    *this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
    // std::cout << "Intern assignment operator called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i < 3; i++)
        {
            forms[i] = obj.forms[i];
            formFunctions[i] = obj.formFunctions[i];
            AForm *form = (this->*formFunctions[i])(forms[i]);
            if (form)
                delete form;
        }
    }
    return *this;
}

Intern::~Intern()
{
    // std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::createRobotomyRequest(std::string target)
{
    return new RobotomyRequestForm(target);

}

AForm *Intern::createPresidentialPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyCreation(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    AForm *test = NULL;

    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            try
            {
                test = (this->*formFunctions[i])(formTarget);
            }
            catch(const AForm::GradeTooHighException &e)
            {
                std::cerr << e.what() << std::endl;
            }
            return test;
        }
    }
    std::cerr << "Intern cannot create " << formName << std::endl;
    return NULL;
}