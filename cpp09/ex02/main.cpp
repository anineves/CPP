#include "PMergeMe.hpp"


int	checkDoubles(int nb, std::vector<int> &vect)
{
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (nb == *it)
			return 0;
	}
	return 1;
}


int main (int argc, char **argv)
{
    
    if( argc < 3)
    {
        std::cout << "Invalid number of args, please try ./PmergeMe (val1> <val2> <val3> (...)" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
		for (int j = 0; argv[i][j] != '\0'; j++)
        {
			if (!isdigit(argv[i][j]))
            {
				std::cout << "Invalid args, please try ./PmergeMe (val1> <val2> <val3> (...)" << std::endl;
                return 1;
            }
        }
    }

    std::vector<int> vect;
	for (int i = 1; i < argc; i++)
	{
		if (!checkDoubles(atoi(argv[i]), vect))
		{
			std::cerr << "Invalid args, There is duplicate numbers. " << std::endl;
			return 1;
		}
		vect.push_back(atoi(argv[i]));
	}

    PMergeMe merge(vect);
    return 0;
}
