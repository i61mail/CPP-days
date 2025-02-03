#include "Contact.hpp"

std::string	trim(std::string str, char c)
{
	str.erase(0, str.find_first_not_of(c));
	str.erase(str. find_last_not_of(c) + 1);
	return (str);
}

int	Contact::addfirstname(std::string firstname)
{
	if (firstname.empty())
	{
		std::cerr << "--Cannot leave field empty!--\n";
		return (-1);
	}
	int i = 0;
	if (firstname[0] == '\t')
		firstname = trim(firstname, '\t');
	else if (firstname[0] == ' ')
		firstname = trim(firstname, ' ');
	while (firstname[i])
	{
		if (!isprint(firstname[i]))
		{
			std::cerr << "A name can't have a non printable char!\n";
			return (-1);
		}
		if (isdigit(firstname[i]) || isspace(firstname[i]))
		{
			std::cerr << "A name can't have a space or a digit!\n";
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
        std::cerr << "--Cannot leave a field empty!--\n";
		return (-1);
	}
	int i = 0;
	if (lastname[0] == '\t')
		lastname = trim(lastname, '\t');
	else
		lastname = trim(lastname, ' ');
	while (lastname[i])
	{
		if (!isprint(lastname[i]))
		{
			std::cerr << "A name can't have a non printable char!\n";
			return (-1);
		}
		if (isdigit(lastname[i]) || isspace(lastname[i]))
		{
			std::cerr << "A name can't have a space or a digit!\n";
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
		std::cerr << "--Cannot leave a field empty!--\n";
		return (-1);
	}
	int	i = 0;
	if (nickname[0] == '\t')
		nickname = trim(nickname, '\t');
	else
		nickname = trim(nickname, ' ');
	while (nickname[i])
	{
		if (!isprint(nickname[i]))
		{
			std::cerr << "A nickname can't have a non printable char!\n";
			return (-1);
		}
		else if (nickname[i] == '\t')
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
		std::cerr << "--Cannot leave a field empty!--\n";
		return (-1);
	}
	int i = 0;
	if (phonenumber[0] == '\t')
		phonenumber = trim(phonenumber, '\t');
	else
		phonenumber = trim(phonenumber, ' ');
	while (phonenumber[i])
	{
		if (isalpha(phonenumber[i]) || isspace(phonenumber[i]) || !isprint(phonenumber[i]))
		{
			std::cerr << "A phone number can't have a space or an alpha or a non printable char!\n";
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
		std::cerr << "--Cannot leave field empty!--\n";
		return (-1);
	}
	int i = 0;
	if (darkestsecret[0] == '\t')
		darkestsecret = trim(darkestsecret, '\t');
	else
		darkestsecret = trim(darkestsecret, ' ');
	while (darkestsecret[i])
	{
		if (!isprint(darkestsecret[i]))
		{
			std::cerr << "Can't have a non printable char!!\n";
			return (-1);
		}
		i++;
	}
	this->darkestsecret = darkestsecret;
	return (0);
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
