#include "form.hpp"

int main()
{
    try
    {
        {
            std::cout << "*****************************" << std::endl;
            std::cout << std::endl;
            Form obj("ismail" , true, 150, 1);
            std::cout << obj << std::endl;
            Form obj1("i61mail", false, 150, 1);
            std::cout << obj1 << std::endl;
        }
        // {
        //     std::cout << std::endl;
        //     std::cout << "*****************************" << std::endl;
        //     std::cout << std::endl;
        //     Bureaucrat obj("ismail", 150);
        //     obj.decrementGrade();
        // }
        // {
        //     std::cout << std::endl;
        //     std::cout << "*****************************" << std::endl;
        //     std::cout << std::endl;
        //     Bureaucrat obj("ismail", 1);
        //     obj.incrementGrade();
        // }
    }

    /*    catch exceptions    */
    catch (Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}