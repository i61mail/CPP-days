#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "*****************************" << std::endl;
        std::cout << std::endl;

        Bureaucrat bur("le directeur", 2);
        Form paper("paper" , false, 150, 1);
        bur.signForm(paper);

        std::cout << paper << std::endl;

        Form paper1("paper1", false, 2, 1);
        bur.signForm(paper1);
        std::cout << paper1 << std::endl;
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