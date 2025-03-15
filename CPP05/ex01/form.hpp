#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
    private :
        const std::string name;
        bool isSigned;
        const int gradeSi;
        const int gradeEx;
    public :
        Form();
        Form(const std::string _name, bool _isSigned, const int _gradeSi, const int _gradeEx);
        Form(const Form &obj);
        Form &operator=(const Form &obj);
        ~Form();
        const std::string &getName() const;
        int   getGradeSi() const;
        int   getGradeEx() const;
        bool    getIsSigned() const;

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
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif