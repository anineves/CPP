#include "Array.hpp"

int	main(void)
{

    std::cout << "------------------------INT---------------------------" << std::endl;
	try
	{
		Array<int>	arrayInt(12);
		Array<int>	arrayInt2(5);
		Array<int>	arrayInt3;


		for (unsigned int i = 0; i < arrayInt.size(); i++)
			arrayInt[i] = i;
		for (unsigned int i = 0; i < arrayInt2.size(); i++)
			arrayInt2[i] = i + 2;
		arrayInt3 = arrayInt;
		for (unsigned int i = 0; i < arrayInt3.size(); i++)
			arrayInt3[i] = i * 2;
		std::cout << "arrayInt: " << std::endl;
		for (unsigned int i = 0; i < arrayInt.size(); i++)
			std::cout << arrayInt[i] << std::endl;
		std::cout << std::endl;
		
        std::cout << "arrayInt2: " << std::endl;
		for (unsigned int i = 0; i < arrayInt2.size(); i++)
			std::cout << arrayInt2[i] << std::endl;
		std::cout << std::endl;

        std::cout << "arrayInt3: " << std::endl;
		for (unsigned int i = 0; i < arrayInt3.size(); i++)
			std::cout << arrayInt3[i] << std::endl;
		std::cout << std::endl;

		std::cout << " Verificar arrayInt: " << std::endl;
		for (unsigned int i = 0; i < arrayInt.size(); i++)
			std::cout << arrayInt[i] << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "------------------------CHAR---------------------------" << std::endl;

	try
	{

		Array<char>	arrayChar(12);
		Array<char>	arrayChar2(5);


		for (unsigned int i = 0; i < arrayChar.size(); i++)
			arrayChar[i] = 'A' + i;
		for (unsigned int i = 0; i < arrayChar2.size(); i++)
			arrayChar2[i] = 'D' + i;
		//for (unsigned int i = 0; i < arrayChar3.size(); i++)
			//arrayChar3[i] = 'E' + i;
		Array<char>	arrayChar3(arrayChar);

        std::cout << "arrayChar: " << std::endl;
		for (unsigned int i = 0; i < arrayChar.size(); i++)
			std::cout << arrayChar[i] << std::endl;
		std::cout << std::endl;
		
        std::cout << "arrayChar2: " << std::endl;
		for (unsigned int i = 0; i < arrayChar2.size(); i++)
			std::cout << arrayChar2[i] << std::endl;
		std::cout << std::endl;

		std::cout << "Exception: " << std::endl;
		std::cout << arrayChar2[arrayChar2.size()] << std::endl;

        std::cout << "arrayChar3: " << std::endl;
		for (unsigned int i = 0; i < arrayChar3.size(); i++)
			std::cout << arrayChar3[i] << std::endl;
		std::cout << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Exception: " << std::endl;
	Array<int> numbers(15);
	try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


}
