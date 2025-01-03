#include "Contact.hpp"

int	Contact::addfirstname(std::string firstname)
{
	if (firstname.empty())
	{
		std::cout << "--Cannot leave a field empty!--\n";
		return (-1);
	}
	int i = 0;
	while (firstname[i])
	{
		if (isdigit(firstname[i]) || isspace(firstname[i]))
		{
			std::cout << "A name can't have a space or a digit!\n";
			return (-1);
		}
		i++;
	}
	this->firstname = firstname;
	return 0;
}

int	Contact::addlastname(std::string lastname)
{
	if (lastname.empty())
        {
                std::cout << "--Cannot leave a field empty!--\n";
                return (-1);
        }
	int i = 0;
	while (firstname[i])
        {
                if (isdigit(firstname[i]) || isspace(firstname[i]))
                {
                        std::cout << "A name can't have a space or a digit!\n";
                        return (-1);
                }
                i++;
        }
	this->lastname = lastname;
	return 0;
}

int	Contact::addnickname(std::string nickname)
{
	if (nickname.empty())
        {
                std::cout << "--Cannot leave a field empty!--\n";
                return (-1);
        }
	int	i = 0;
	while (nickname[i])
	{
		if (nickname[i] == '\t')
		{
			nickname[i] = ' ';
		}
		i++;
	}
	this->nickname = nickname;
	return 0;
}

int	Contact::addphonenumber(std::string phonenumber)
{
	if (phonenumber.empty())
        {
                std::cout << "--Cannot leave a field empty!--\n";
                return (-1);
        }
	int i = 0;
	while (firstname[i])
        {
                if (isalpha(!firstname[i]) || isspace(firstname[i]))
                {
                        std::cout << "A phone number can't have a space or an alpha!\n";
                        return (-1);
                }
                i++;
        }
	this->phonenumber = phonenumber;
	return 0;
}

int	Contact::adddarkestsecret(std::string darkestsecret)
{
	if (darkestsecret.empty())
        {
                std::cout << "--Cannot leave a field empty!--\n";
                return (-1);
        }
	this->darkestsecret = darkestsecret;
	return 0;
}

std::string	Contact::getfirstname(void)
{
	return (this->firstname);
}

std::string	Contact::getlastname(void)
{
	return (this->lastname);
}

std::string	Contact::getnickname(void)
{
	return (this->nickname);
}

std::string	Contact::getphonenumber(void)
{
	return (this->phonenumber);
}

std::string	Contact::getdarkestsecret(void)
{
	return (this->darkestsecret);
}
