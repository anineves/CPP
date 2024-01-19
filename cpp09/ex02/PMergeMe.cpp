#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{

}

PMergeMe::PMergeMe(std::vector<int> _vector) : vector(_vector), deque(_vector.begin(), _vector.end())
{
    if (vector.size() < 2)
		return ;
	//---------------Vector-------------------------------//
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	clock_t time_vect = clock();
	sortVector(vector);
	time_vect = clock() - time_vect;

	std::cout << "After: ";
	for (std::vector<int>::iterator it2 = vector.begin(); it2 != vector.end(); it2++)
			std::cout << *it2 << " ";
	std::cout << std::endl;

	//---------------Deque-------------------------------//
	std::cout << "Before deque: ";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	clock_t time_deque = clock();
	sortDeque(deque);
	time_deque = clock() - time_deque;

    std::cout << "After deque: ";
	for (std::deque<int>::iterator it3 = deque.begin(); it3 != deque.end(); it3++)
			std::cout << *it3 << " ";
	std::cout << std::endl;

	//---------------Tempo-------------------------------//
    double conv_time_vect = (double)(time_vect) / CLOCKS_PER_SEC * 1000;
	double conv_time_deque = (double)(time_deque) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector: " << conv_time_vect << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque: " << conv_time_deque << " us" << std::endl;
}

PMergeMe::PMergeMe(const PMergeMe &source) : vector(source.vector), deque(source.deque)
{
}

PMergeMe &PMergeMe::operator=(const PMergeMe &rhs)
{
    if (this != &rhs)
	{
		this->vector = rhs.vector;
		this->deque = rhs.deque;
	}
	return (*this);
}

PMergeMe::~PMergeMe() {}


void	PMergeMe::sortVector(std::vector<int> &vect)
{
	if (vect.size() < 2)
        return;

	std::vector<int> first = std::vector<int>(vect.begin(), vect.begin() + (vect.size() / 2));
	std::vector<int> second = std::vector<int>(vect.begin() + (vect.size() / 2), vect.end());
	sortVector(first);
	sortVector(second);
	mergeVector(first, second, vect);
}

void	PMergeMe::mergeVector(std::vector<int> &first, std::vector<int>&second, std::vector<int> &vector)
{
	size_t f = 0;
	size_t s = 0;
	size_t i = 0;

	while (f < first.size() && s < second.size())
	{
	
		if (first[f] < second[s])
		{
			vector[i] = first[f];
			i++;
			f++;
		}
		else
		{
			vector[i] = second[s];
			i++;
			s++;
		}
	}

	while (f < first.size())
	{
		vector[i] = first[f];
		i++;
		f++;
	}
	while (s < second.size())
	{
		vector[i] = second[s];
		i++;
		s++;
	}
}

void	PMergeMe::sortDeque(std::deque<int> &deque)
{
	if (deque.size() < 2)
		return ;

	std::deque<int> first = std::deque<int>(deque.begin(), deque.begin() + (deque.size() / 2));
	std::deque<int> second = std::deque<int>(deque.begin() + (deque.size() / 2), deque.end());
	sortDeque(first);
	sortDeque(second);
	mergeDeque(first, second, deque);
}


void	PMergeMe::mergeDeque(std::deque<int> &first, std::deque<int>&second, std::deque<int> &deque)
{
	size_t f = 0;
	size_t s = 0;
	size_t i = 0;
	
	while (f < first.size() && s < second.size())
	{
		if (first[f] < second[s])
		{
			deque[i] = first[f];
			i++;
			f++;
		}
		else
		{
			deque[i] = second[s];
			i++;
			s++;
		}
	}
	while (f < first.size())
	{
		deque[i] = first[f];
		i++;
		f++;
	}
	while (s < second.size())
	{
		deque[i] = second[s];
		i++;
		s++;
	}
}