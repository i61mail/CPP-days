#include "PhoneBook.hpp"

void	PhoneBook::add_contact(Contact contact)
{
	if (this->size >= 8)
		this->index = 0;
	this->contact[this->index] = contact;
	if (this->size < 8)
		this->size++;
	this->index++;
	std::cout << "THE CONTACT HAS BEEN SAVED!\n";
}

int	PhoneBook::contact_size(void)
{
	return (this->size);
}

int	PhoneBook::contact_index(void)
{
	return (this->index);
}

void	PhoneBook::getContact(Contact *contact, int index)
{
	*contact = this->contact[index];
}
