#include "PhoneBook.hpp"

std::string	check_input(std::string input)
{
	std::string	temp;

	if (input.length() > 9)
	{
		temp = input.substr(0, 9);
		temp[8] = '.';
        	return (temp);
    	}
   	return (input);
}

void	displayinfos(Contact contact, PhoneBook phonebook, int index)
{
	if (phonebook.contact_size() <= index)
	{
		std::cout << "Empty contact!\n";
		return ;
	}
	phonebook.getContact(contact, index);
	std::cout << "Extra informations :\n";
        std::cout << "First name == " << contact.getfirstname() << "\n";
	std::cout << "Last name == " << contact.getlastname() << "\n";
	std::cout << "Nickname == " << contact.getnickname() << "\n";
	std::cout << "Phone number == " << contact.getphonenumber() << "\n";
        std::cout << "darkest secret == " << contact.getdarkestsecret() << "\n";
}

void	check_index(std::string index, PhoneBook phonebook, Contact contact)
{
	if (index.compare("0") == 0)
	{
		std::cerr << "from 1 to 8 please!\n";
		return ;
	}
	else if (index.compare("1") == 0)
		displayinfos(contact, phonebook, 0);
	else if (index.compare("2") == 0)
                displayinfos(contact, phonebook, 1);
	else if (index.compare("3") == 0)
                displayinfos(contact, phonebook, 2);
	else if (index.compare("4") == 0)
                displayinfos(contact, phonebook, 3);
	else if (index.compare("5") == 0)
                displayinfos(contact, phonebook, 4);
	else if (index.compare("6") == 0)
                displayinfos(contact, phonebook, 5);
	else if (index.compare("7") == 0)
                displayinfos(contact, phonebook, 6);
	else if (index.compare("8") == 0)
                displayinfos(contact, phonebook, 7);
	else
		std::cerr << "Invalid index !\n";
}

void	DisplayContactTable(PhoneBook phonebook)
{
	Contact	contact;
	std::string	index;
	int	i = 0;

	if (phonebook.contact_size() == 0)
	{
		std::cout << "None of the contacts are added yet!\n";
		return ;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	std::cout << "*    Index |First Name| Last Name| Nickname *" << "\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	while (i < phonebook.contact_size())
	{
		std::cout << "*";
		std::cout << std::setw(10);
		phonebook.getContact(contact, i);
		std::cout << i + 1 << "| ";
		std::cout << std::setw(9);
		std::cout << check_input(contact.getfirstname()) << "| ";
		std::cout << std::setw(9);
		std::cout << check_input(contact.getlastname()) << "| ";
		std::cout << std::setw(9);
		std::cout << check_input(contact.getnickname()) << "*\n";
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
		i++;
	}
	std::cout << "Insert the index from 1 to 8 =>  ";
	if (!getline(std::cin, index))
		return ;
	check_index(index, phonebook, contact);
	return ;
}


void	store_infos(PhoneBook *phonebook)
{
	Contact		contact;
	std::string	input;

	std::cout << "/*   first name : ";
	if (!getline(std::cin, input))
		return ;
	if (contact.addfirstname(input) == -1)
		return ;
	std::cout << "/*   last name : ";
	if (!getline(std::cin, input))
		return ;
	if (contact.addlastname(input) == -1)
		return ;
	std::cout << "/*   nickname : ";
	if (!getline(std::cin, input))
		return ;
	if (contact.addnickname(input) == -1)
		return ;
	std::cout << "/*   phone number : ";
	if (!getline(std::cin, input))
		return ;
	if (contact.addphonenumber(input) == -1)
		return ;
	std::cout << "/*   darkest secret : ";
	if (!getline(std::cin, input))
		return ;
	if (contact.adddarkestsecret(input) == -1)
		return ;
	phonebook->add_contact(contact);
}


int main()
{
	std::string	arg;
	PhoneBook	phonebook;
	
	while (1)
	{
		std::cout << "ENTER A COMMAND! ";
		if (!getline(std::cin, arg))
			break ;
		if (arg.compare("ADD") == 0)
			store_infos(&phonebook);
		else if (arg.compare("SEARCH") == 0)
			DisplayContactTable(phonebook);
		else if (arg.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "Invalid command !\n";
	}
	return (0);
}
