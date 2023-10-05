#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{

}

PhoneBook::~PhoneBook(void)
{

}

void PhoneBook::addContact(void)
{
	std::string first, last, nick, number, secret;

	std::cout << "Please fill all data  \n"  << std::endl;
	std::cout << "First Name: "; 
	std::getline(std::cin, first, '\n');
	std::cout << "Last Name: "; 
	std::getline(std::cin, last, '\n');
	std::cout << "Nickname: "; 
	std::getline(std::cin, nick, '\n');
	std::cout << "Phone number: "; 
	std::getline(std::cin, number, '\n');
	std::cout << "Darkest Secret: "; 
	std::getline(std::cin, secret, '\n');
	
	if (first.empty()|| last.empty() || nick.empty() 
		|| number.empty() || secret.empty())
	{
		std::cout << "\n   The contact has empty fields, please try again by filling in all the fields\n" << std::endl;
		return ;
	}
	if(!number.find_first_not_of("0123456789"))
	{
		std::cout << "\n Phone number can only contain numbers \n" << std::endl;
		return ;
	}
	this->contacts[this->i++ % 8] = Contact(first, last, nick, number, secret);
	std::cout << "\n                    Contact Saved!" << std::endl;
}

void PhoneBook::display(void)
{
	std::string data;

	std::cout << "     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int j = 0; j < this->i; j++)
	{
		std::cout << std::setw(10) << j  << "|";
		data = this->contacts[j].getFirstName() ;
		std::cout << std::setw(10) << Contact::format(data) << "|";
		data = this->contacts[j].getLastName();
		std::cout << std::setw(10) << Contact::format(data) << "|";
		data = this->contacts[j].getNickName();
		std::cout << std::setw(10) <<Contact::format(data) << "|" << std::endl;
	}
}

void PhoneBook::searchContact(void)
{
	int	id;
	int	maxId;

	if(this->i > 0)
	{
		if(this->i > 7 )
		{
			maxId = 7;
		}
		else
		{
			maxId = this->i - 1;
		}
		this->display();
		std::cout << "\nChoose ID, to display the contact information > ";
		std::cin >> id;
		if (std::cin.fail() || id > 7 || id < 0)
		{
			std::cout << "\n   Invalid input, please choose a valid  input\n" << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			PhoneBook::searchContact();
		}
		else if ( id < 0 || id > maxId )
		{
			std::cout << "\n \n   Contact " << id <<  " has not yet been filled  please choose a valid contact \n" << std::endl;
			PhoneBook::searchContact();
		}
		else
		{
			std::cin.ignore(1000, '\n');
			this->contacts[id].displayAll();
		}
	}
	else
		std::cout << "\n          Don't have any contact\n" << std::endl;
}