#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    // std::cout << "ShrubberyCreationForm default constructor is called" << std::endl;
    this->target = "ShrubberyCreationForm";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", false, 145, 137), target(_target)
{
    // std::cout << "ShrubberyCreationForm constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
    // std::cout << "ShrubberyCreationForm copy constructor is called" << std::endl;
    this->target = obj.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    // std::cout << "ShrubberyCreationForm assignment operator is called" << std::endl;
    this->target = obj.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "ShrubberyCreationForm destructor is called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

void ShrubberyCreationForm::PureExecute() const
{
    std::string filename = this->target + "_shrubbery";

    std::ofstream outfile(filename.c_str());
    if (!outfile)
        throw std::runtime_error("Cannot open file " + filename);
    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;

    outfile.close();
}