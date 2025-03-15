#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
};

#endif