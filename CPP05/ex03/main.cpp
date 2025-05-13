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
        Bureaucrat b("Boss", 1);
        /*    test with a form that exists    */
        {
            rrf = someRandomIntern.makeForm("robotomy request", "Bur1");
            if (!rrf)
                return 1;
            b.signAForm(*rrf);
            b.executeForm(*rrf);
            delete rrf;
        }
        // {
        //     rrf = someRandomIntern.makeForm("presidential pardon", "Bur2");
        //     if (!rrf)
        //         return 1;
        //     b.signAForm(*rrf);
        //     b.executeForm(*rrf);
        //     delete rrf;
        // }

        // {
        //     rrf = someRandomIntern.makeForm("shrubbery creation", "Bur3");
        //     if (!rrf)
        //         return 1;
        //     b.signAForm(*rrf);
        //     b.executeForm(*rrf);
        //     delete rrf;
        // }
        // {
        //     /*    test with a form that doesn't exist    */
        //     rrf = someRandomIntern.makeForm("nonexistent form", "Bender");
        //     delete rrf;
        // }
    }

    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}