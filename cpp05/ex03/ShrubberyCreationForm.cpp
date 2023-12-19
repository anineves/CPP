#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("target") 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) 
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src) 
{

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) 
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
}


void ShrubberyCreationForm::executeFormAction()const
{
    std::ofstream   file;
	std::string		filename;
	
	filename = target + "_shrubbery";
	file.open(filename.c_str(), std::ofstream::out);
    try
    {
        if (file.fail())
                throw ShrubberyCreationForm::OpenShrubberyException();
        std::cout << "Create a tree" << std::endl;
        file << "           * "<< std::endl;
        file << "          *** "<< std::endl;
        file << "         ***** "<< std::endl;
        file << "        ******* "<< std::endl;
        file << "       ********* "<< std::endl;
        file << "      *********** "<< std::endl;
        file << "     ************* "<< std::endl;
        file << "    *************** "<< std::endl;
        file << "   ***************** "<< std::endl;
        file << "          |  | "<< std::endl;
        file << "          |  | "<< std::endl;
        
        file.close();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
