#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(1)
{
    // std::cout << "Bureaucrat default constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _name, int grade) : name(_name)
{
    // std::cout << "Bureaucrat constructor is called" << std::endl;
    this->grade = grade;
    if (this->grade < 1)
        throw GradeTooHighException();
    else if (this->grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    // std::cout << "Bureaucrat copy constructor is called" << std::endl;
    *this = obj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    // std::cout << "Bureaucrat copy assignment operator is called" << std::endl;
    if (this != &obj)
        this->grade = obj.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "Bureaucrat destructor is called" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    if (--grade <= 0)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    if (++grade >= 151)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (out);
}

void    Bureaucrat::signAForm(AForm &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << this->getName() << " signed " << obj.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't sign " << obj.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
    catch(AForm::FormNotSignedException &e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}