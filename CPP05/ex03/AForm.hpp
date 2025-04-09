#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm : public Bureaucrat
{
    private :
        const std::string name;
        bool    isSigned;
        const int gradeSi;
        const int gradeEx;
    public :
        AForm();
        AForm(const std::string _name, const int _gradeSi, const int _gradeEx);
        AForm(const std::string _name, bool _isSigned, const int _gradeSi, const int _gradeEx);
        AForm(const AForm &obj);
        AForm &operator=(const AForm &obj);
        virtual ~AForm();
        const std::string &getName() const;
        int   getGradeSi() const;
        int   getGradeEx() const;
        bool    getIsSigned() const;
        void    beSigned(Bureaucrat &obj);

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

        class FormNotSignedException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };

        void    execute(Bureaucrat const & executor) const;
        virtual void    PureExecute() const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif