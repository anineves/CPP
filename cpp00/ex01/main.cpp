#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	pb;
	std::string	option;
	
	pb = PhoneBook();

    std::cout << "            *** Welcome to the Phonebook! ***\n";
	while (1)
	{
		std::cout << "          Please choose one: ADD, SEARCH or EXIT \n"<< std::endl;
		std::cout << "Your choose > ";
		std::getline(std::cin, option);
		std::cout << std::endl;
		if (option == "ADD")
			pb.addContact();
		else if (option == "SEARCH")
			pb.searchContact();
		else if (option == "EXIT")
        {
            std::cout << "Thank You\n";
			break;
        }
        else
            std::cout << "          Wrong Input!\n";
	}
}