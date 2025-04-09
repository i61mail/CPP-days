#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeSi(1), gradeEx(1)
{
    // std::cout << "AForm default constructor is called" << std::endl;
}

AForm::AForm(const std::string _name, bool _isSigned, const int _gradeSi, const int _gradeEx) : \
name(_name), isSigned(_isSigned), gradeSi(_gradeSi), gradeEx(_gradeEx)
{
    // std::cout << "AForm constructor is called" << std::endl;
    if (this->gradeSi < 1 || this->gradeEx < 1)
        throw GradeTooHighException();
    else if (this->gradeSi > 150 || this->gradeEx > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string _name, const int _gradeSi, const int _gradeEx) : name(_name), gradeSi(_gradeSi), gradeEx(_gradeEx)
{
    // std::cout << "AForm constructor is called" << std::endl;
    this->isSigned = false;
    if (this->gradeSi < 1 || this->gradeEx < 1)
        throw GradeTooHighException();
    else if (this->gradeSi > 150 || this->gradeEx > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &obj) : Bureaucrat() ,gradeSi(obj.gradeSi), gradeEx(obj.gradeEx)
{
    // std::cout << "AForm copy constructor is called" << std::endl;
    *this = obj;
}

AForm &AForm::operator=(const AForm &obj)
{
    // std::cout << "AForm copy assignment operator is called" << std::endl;
    if (this != &obj)
        isSigned = obj.isSigned;
    return (*this);
}

AForm::~AForm()
{
    // std::cout << "AForm destructor is called" << std::endl;
}

const std::string &AForm::getName() const
{
    return (this->name);
}

int   AForm::getGradeSi() const
{
    return (this->gradeSi);
}

int  AForm::getGradeEx() const
{
    return (this->gradeEx);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << obj.getName() << ", Aform grade signed " << obj.getGradeSi() << std::endl;
    out << obj.getName() << ", Aform grade execute " << obj.getGradeEx() << std::endl;
    out << obj.getName() << ", Aform isSigned " << obj.getIsSigned();
    return (out);
}

void    AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() <= this->gradeSi)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

void    AForm::execute(Bureaucrat const & executor) const
{
    if (this->isSigned == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->gradeEx)
        throw AForm::GradeTooLowException();
    PureExecute();
}