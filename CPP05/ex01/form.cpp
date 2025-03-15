#include "form.hpp"

Form::Form() : name("default"), isSigned(false), gradeSi(0), gradeEx(0)
{
    std::cout << "Form default constructor is called" << std::endl;
}

Form::Form(const std::string _name, bool _isSigned, const int _gradeSi, const int _gradeEx) : \
name(_name), isSigned(_isSigned), gradeSi(_gradeSi), gradeEx(_gradeEx)
{
    std::cout << "Form constructor is called" << std::endl;
    if (this->gradeSi < 1 || this->gradeEx < 1)
        throw GradeTooHighException();
    else if (this->gradeSi > 150 || this->gradeEx > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &obj) : gradeSi(obj.gradeSi), gradeEx(obj.gradeEx)
{
    std::cout << "Form copy constructor is called" << std::endl;
    *this = obj;
}

Form &Form::operator=(const Form &obj)
{
    std::cout << "Form copy assignment operator is called" << std::endl;
    if (this != &obj)
        isSigned = obj.isSigned;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor is called" << std::endl;
}

const std::string &Form::getName() const
{
    return (this->name);
}

int   Form::getGradeSi() const
{
    return (this->gradeSi);
}

int  Form::getGradeEx() const
{
    return (this->gradeEx);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << obj.getName() << ", form grade signed " << obj.getGradeSi() << std::endl;
    out << obj.getName() << ", form grade execute " << obj.getGradeEx() << std::endl;
    out << obj.getName() << ", form isSigned " << obj.getIsSigned();
    return (out);
}
