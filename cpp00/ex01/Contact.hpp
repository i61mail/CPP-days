#ifndef CONTACT_H
#define CONTACT_H


#include <string>
#include <iostream>

class Contact
{
	public:
		int	addfirstname(std::string firstname);
		int	addlastname(std::string lastname);
		int	addnickname(std::string nickname);
		int	addphonenumber(std::string phonenumber);
		int	adddarkestsecret(std::string darkestsecret);
		std::string	getfirstname(void);
		std::string	getlastname(void);
		std::string	getnickname(void);
		std::string	getphonenumber(void);
		std::string	getdarkestsecret(void);

	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkestsecret;
};

#endif
