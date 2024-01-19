#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <string>
#include <sstream> 
#include <iterator>
#include <stdlib.h>
#include <ctime>
#include <cmath>



class PMergeMe {
  private:
    std::vector<int> vector;
		std::deque<int> deque;
  public:
    PMergeMe();
    PMergeMe(std::vector<int> vector);
    PMergeMe(const PMergeMe &source);
    PMergeMe& operator=(const PMergeMe &rhs);
    ~PMergeMe();
  

		void	sortVector(std::vector<int> &vec);
		void	sortDeque(std::deque<int> &deque);
		void	mergeVector(std::vector<int> &left, std::vector<int>&right, std::vector<int> &vector);
		void	mergeDeque(std::deque<int> &left, std::deque<int>&right, std::deque<int> &deque);
};

#endif
