#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;

        /*    test with a form that exists    */
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat b("Bender", 1);
        b.signAForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;

        std::cout << std::endl;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        b.signAForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;

        std::cout << std::endl;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        b.signAForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;

        std::cout << std::endl;
        /*    test with a form that doesn't exist    */
        rrf = someRandomIntern.makeForm("nonexistent form", "Bender");
        delete rrf;
    }

    /*    catch exceptions    */
    catch (AForm::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}