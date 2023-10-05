#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret);
		void displayAll(void);
		
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		static std::string format(std::string field);

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif