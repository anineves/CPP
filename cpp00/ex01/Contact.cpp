#include "Contact.hpp"

Contact :: Contact(void)
{

}

Contact :: ~Contact(void)
{

}

Contact :: Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret)
{
	this->firstName = first;
	this->lastName = last;
	this->nickName = nick;
	this->phoneNumber = number;
	this->darkestSecret = secret;
}

void Contact::displayAll(void)
{
	std::cout << std::endl;
	std::cout << "First name:     " << this->firstName << std::endl;
	std::cout << "Last name:      " << this->lastName << std::endl;
	std::cout << "Nickname:       " << this->nickName << std::endl;
	std::cout << "Phone Number:   " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
	std::cout << std::endl;
}

std::string Contact::format(std::string data)
{
	if (data.length() > 10)
		return (data.substr(0, 9) + ".");
	return (data);
}

std::string Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string Contact::getLastName(void)
{
	return (this->lastName);
}

std::string Contact::getNickName(void)
{
	return (this->nickName);
}
