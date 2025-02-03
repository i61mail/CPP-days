#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <cstring>
#include "Contact.hpp"

class PhoneBook
{
	public:
		void	getContact(Contact *contact, int index);
		void	add_contact(Contact contact);
		int		contact_size(void);
		int		contact_index(void);
		PhoneBook(int) : size(0), index(0) {};

	private:
		Contact contact[8];
		int	size;
		int	index;
};

#endif