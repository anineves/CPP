#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <ctime>

class PMergeMe {
private:
    std::vector<int> vector;
    std::deque<int> deque;

public:
    PMergeMe();
    PMergeMe(std::vector<int> vector);
    PMergeMe(const PMergeMe &source);
    PMergeMe &operator=(const PMergeMe &rhs);
    ~PMergeMe();

    std::vector<int> sortVector(std::vector<int> &vec);
    std::deque<int> sortDeque(std::deque<int> &deq);
    void recursiveSort(std::vector<std::pair<int, int> >& pairs, int n);
    void recursiveSort(std::deque<std::pair<int, int> >& pair, int n);
    std::vector<int> sequenceJacobsthal(std::vector<std::pair<int, int> > &pairs);
    std::deque<int> sequenceJacobsthal(std::deque<std::pair<int, int> > &pairs);
    std::vector<int> generateJacobsthal(int index);
    std::deque<int>  generateJacobsthal2(int index);
};

#endif