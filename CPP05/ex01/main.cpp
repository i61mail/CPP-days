#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "*****************************" << std::endl;
        std::cout << std::endl;
        Bureaucrat first("name", 2);
        Form obj("ismail" , true, 150, 1);
        obj.beSigned(first);
        first.signForm(obj);
        std::cout << obj << std::endl;
        Form obj1("i61mail", false, 1, 1);
        first.signForm(obj1);
        std::cout << obj1 << std::endl;
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