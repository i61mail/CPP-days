#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bu("Bureaucrat", 20);
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("robot");
        PresidentialPardonForm presi("presidential");

        std::cout << "---INFOS---" << std::endl;
        std::cout << bu << std::endl;
        std::cout << std::endl;
        std::cout << shrub << std::endl;
        std::cout << std::endl;
        std::cout << robot << std::endl;
        std::cout << std::endl;
        std::cout << presi << std::endl;
        std::cout << std::endl;

        std::cout << "---SIGNING---" << std::endl;
        bu.signAForm(shrub);
        bu.signAForm(robot);
        bu.signAForm(presi);
        std::cout << std::endl;
        std::cout << shrub << std::endl;
        std::cout << std::endl;
        std::cout << robot << std::endl;
        std::cout << std::endl;
        std::cout << presi << std::endl;
        std::cout << std::endl;

        std::cout << "---EXECUTING---" << std::endl;
        bu.executeForm(shrub);
        bu.executeForm(robot);
        bu.executeForm(presi);
    }

    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}