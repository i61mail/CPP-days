#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        std::string forms[3];
        AForm *(Intern::*formFunctions[3])(std::string);
        AForm *createRobotomyRequest(std::string target);
        AForm *createPresidentialPardon(std::string target);
        AForm *createShrubberyCreation(std::string target);
    public:
        Intern();
        Intern(const Intern &obj);
        ~Intern();
        Intern &operator=(const Intern &obj);

        AForm *makeForm(std::string formName, std::string formTarget);
};


#endif