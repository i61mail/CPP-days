#include "Bureaucrat.hpp"

int main()
{
    try
    {
        {
            std::cout << "*****************************" << std::endl;
            std::cout << std::endl;
            Bureaucrat obj("ismail" , 1);
            obj.decrementGrade();
            std::cout << obj << std::endl;
            Bureaucrat obj1("i61mail", 150);
            obj1.incrementGrade();
            std::cout << obj1 << std::endl;
        }
        // {
        //     std::cout << "*****************************" << std::endl;
        //     std::cout << std::endl;
        //     Bureaucrat obj("ismail", 150);
        //     obj.decrementGrade();
        // }
        // {
        //     std::cout << "*****************************" << std::endl;
        //     std::cout << std::endl;
        //     Bureaucrat obj("ismail", 1);
        //     obj.incrementGrade();
        // }
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