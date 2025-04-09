#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
    protected :
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(const std::string _name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        void    signAForm(AForm &obj);
        void    executeForm(AForm const & form);

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif