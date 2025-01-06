#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
	public:
		void	getContact(Contact &contact, int index);
		void	store_infos(PhoneBook phonebook);
		void	add_contact(Contact contact);
		int	contact_size(void);
		int	contact_index(void);
		PhoneBook() : size(0), index(0) {};

	private:
		Contact contact[8];
		int	size;
		int	index;
};

#endif
