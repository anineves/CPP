/*
The merge-insertion sort
The Ford-Johnson merge-insertion sort is a three-step algorithm, let n
 be the number of elements to sort:

Divida a coleção em n / 2 pares de 2 elementos e ordene esses elementos aos pares. Se o número de elementos for ímpar, o último elemento da coleção não está emparelhado com nenhum elemento.

Classifique recursivamente os pares de elementos pelo seu valor mais alto. Se o número de elementos for ímpar, o último elemento não é considerado o valor mais alto e fica no final da coleção. Considere que os valores mais altos formam uma lista ordenada que chamaremos de cadeia principal , enquanto o restante dos elementos será conhecido como elementos pendentes . Identifique os elementos da cadeia principal com os nomes a1,a2,a3, . . . ,an / 2 em seguida, marque os elementos pendentes com os nomesb1,b2,b3, . . . ,bn / 2
Para cada k, temos a relação bk≤ak


Insira os elementos pendentes na cadeia principal . Sabemos que o primeiro elemento pend b1
é menor que a1; consideramos que faz parte da cadeia principal que então se torna{b1,a1,a2,a3, . . . ,an / 2}
Agora, precisamos inserir os outros elementos pendentes na cadeia principal de uma forma que garanta que o tamanho da área de inserção seja uma potência de2 menos1O mais frequente possível. Basicamente, vamos inserir b3 em{b1,a1,a2} (sabemos que é menor que a3), então inseriremos b2
em{b1,a1,b3} não importa onde b3 foi inserido. Observe que durante essas inserções o tamanho da área de inserção é sempre no máximo 3.
O valor do próximo elemento pendente bk a inserir na cadeia principal enquanto minimiza o número de comparações corresponde, na verdade, ao próximo número de Jacobsthal . Inserimos o elemento 3 primeiro, então o próximo será 5 então 11 então21
, etc...

Resumindo, a ordem de inserção dos primeiros elementos pend na cadeia principal é a seguinte:b1,b3,b2,b5,b4,b11,b10,b9,b8,b7,b6, . . .
.


https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
*/

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe(std::vector<int> _vector) : vector(_vector), deque(_vector.begin(), _vector.end())
{
    //---------------Vector-------------------------------//
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    clock_t time_vect = clock();
    std::vector<int> vector_ord = sortVector(vector);
    time_vect = clock() - time_vect;

    std::cout << "After: ";
    for (std::vector<int>::iterator it2 = vector_ord.begin(); it2 != vector_ord.end(); it2++)
        std::cout << *it2 << " ";
    std::cout << std::endl;
    
    //---------------Deque-------------------------------//
    std::cout << "Before deque: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    clock_t time_deque = clock();
    std::deque<int> deque_ord = sortDeque(deque);
    time_deque = clock() - time_deque;

    std::cout << "After deque: ";
    for (std::deque<int>::iterator it3 = deque_ord.begin(); it3 != deque_ord.end(); it3++)
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

std::vector<int> PMergeMe::sortVector(std::vector<int> &vect)
{
    if (vect.size() < 2)
        return vect;

    int odd = 0;

    if ((vect.size() % 2) != 0)
    {
        odd = vect.back();
        vect.pop_back();
    }
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i < vect.size(); i += 2)
    {
        pairs.push_back(std::pair<int, int>(vect[i], vect[i + 1]));
    }

    for (std::vector<std::pair<int, int> >::iterator it_p = pairs.begin(); it_p != pairs.end(); it_p++)
    {
        if (it_p->first < it_p->second)
            std::swap(it_p->first, it_p->second);
    }

    std::vector<int> mainChain;
    std::vector<int> pendElements;

    recursiveSort(pairs, pairs.size() - 1);
    for (std::vector<std::pair<int, int> >::iterator it_p2 = pairs.begin(); it_p2 != pairs.end(); it_p2++)
    {
        mainChain.push_back(it_p2->first);
        pendElements.push_back(it_p2->second);
    }
    
    /*for(size_t j = 0 ; j < mainChain.size(); j++)
    {
        std::cout << mainChain[j] << " ";
    }
        std::cout << std::endl;*/
    if (odd)
        pairs.push_back(std::pair<int, int>(0, odd));

    if (!pendElements.empty())
    {
        mainChain.insert(mainChain.begin(), pendElements[0]);
        pendElements.erase(pendElements.begin());
    }
    std::vector<int> insert_sequence = sequenceJacobsthal(pairs);


    for (std::vector<int>::iterator it = insert_sequence.begin(); it != insert_sequence.end(); ++it)
    {
        std::vector<int>::iterator it2 = mainChain.begin();

        std::cout << "Valor sequencia:" << *it << std::endl;  
        if (*it - 1 < (int)pairs.size())
        {
            while (it2 != mainChain.end() && *it2 < pairs[*it - 1].second)
            {
                ++it2;
            }
            std::cout << "Valor main:" << *it2  << " valor: pendent"<< pairs[*it - 1].second << std::endl;
            mainChain.insert(it2, pairs[*it - 1].second);
        }
    }

    return mainChain;
}

std::deque<int> PMergeMe::sortDeque(std::deque<int> &deq)
{
    if (deq.size() < 2)
        return deq;

    int odd = 0;

    if ((deq.size() % 2) != 0)
    {
        odd = deq.back();
        deq.pop_back();
    }
    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i < deq.size(); i += 2)
    {
        pairs.push_back(std::pair<int, int>(deq[i], deq[i + 1]));
    }

    for (std::deque<std::pair<int, int> >::iterator it_p = pairs.begin(); it_p != pairs.end(); it_p++)
    {
        if (it_p->first < it_p->second)
            std::swap(it_p->first, it_p->second);
    }

    std::deque<int> pendElements;
    std::deque<int> mainChain;

    recursiveSort(pairs, pairs.size() - 1);
    for (std::deque<std::pair<int, int> >::iterator it_p2 = pairs.begin(); it_p2 != pairs.end(); it_p2++)
    {
        mainChain.push_back(it_p2->first);
        pendElements.push_back(it_p2->second);
    }
    if (odd)
        pairs.push_back(std::pair<int, int>(0, odd));

    if (!pendElements.empty())
    {
        mainChain.insert(mainChain.begin(), pendElements[0]);
        pendElements.erase(pendElements.begin());
    }

    std::deque<int> insert_sequence = sequenceJacobsthal(pairs);

    for (std::deque<int>::iterator it = insert_sequence.begin(); it != insert_sequence.end(); ++it)
    {
        std::deque<int>::iterator it2 = mainChain.begin();
        if (*it - 1 < (int)pairs.size())
        {
            while (it2 != mainChain.end() && *it2 < pairs[*it - 1].second)
            {
                ++it2;
            }
            mainChain.insert(it2, pairs[*it - 1].second);
        }
    }

    return mainChain;
}

bool comparePairs(const std::pair<int, int> &left, const std::pair<int, int> &right)
{
    return left.first < right.first;
}

void PMergeMe::recursiveSort(std::vector<std::pair<int, int> > &pair, int n)
{
    if (n < 1)
        return;

    recursiveSort(pair, n - 1);
    std::pair<int, int> element = pair[n];
    pair.erase(pair.begin() + n);
    std::vector<std::pair<int, int> >::iterator insertion_pos = std::upper_bound(pair.begin(), pair.begin() + n, element, comparePairs);
    pair.insert(insertion_pos, element);
}

void PMergeMe::recursiveSort(std::deque<std::pair<int, int> > &pair, int n)
{
    if (n < 1)
        return;

    recursiveSort(pair, n - 1);
    std::pair<int, int> element = pair[n];
    pair.erase(pair.begin() + n);
    std::deque<std::pair<int, int> >::iterator insertion_pos = std::upper_bound(pair.begin(), pair.begin() + n, element, comparePairs);
    pair.insert(insertion_pos, element);
}

std::vector<int> PMergeMe::generateJacobsthal(int index)
{
    std::vector<int> sequence;
    sequence.push_back(1);

    int prev = 0;
    int current = 1;

    for (int i = 2; i <= index; i++)
    {
        int next = current + 2 * prev;
        sequence.push_back(next);
        prev = current;
        current = next;
    }

    return sequence;
}

std::deque<int> PMergeMe::generateJacobsthal2(int index)
{
    std::deque<int> sequence;
    sequence.push_back(1);

    int prev = 0;
    int current = 1;

    for (int i = 2; i <= index; i++)
    {
        int next = current + 2 * prev;
        sequence.push_back(next);
        prev = current;
        current = next;
    }

    return sequence;
}

// calcular uma sequência de números que indicam quantos elementos devem ser inseridos em cada etapa do processo de ordenação com base na sequência de Jacobsthal).
std::vector<int> PMergeMe::sequenceJacobsthal(std::vector<std::pair<int, int> > &pairs)
{
    std::vector<int> sequence;

    std::vector<int> jacobsthal = generateJacobsthal(32);

    int len = pairs.size();
    int index = 0;

    while (len > jacobsthal[index])
        index++;

    for (int i = 0; i < index; i++)
    {
        int actual = jacobsthal[i + 1];

        if (len < actual)
            actual = len;

        while (actual > jacobsthal[i])
        {
            sequence.push_back(actual);
            actual--;
        }
    }
    /*for(size_t j = 0; j < sequence.size(); j++)
    {
        std::cout << sequence[j] << " ";
    }*/
    return sequence;
}

std::deque<int> PMergeMe::sequenceJacobsthal(std::deque<std::pair<int, int> > &pairs)
{
    std::deque<int> sequence;

    std::deque<int> jacobsthal = generateJacobsthal2(35);

    int len = pairs.size();
    int index = 0;

    while (len > jacobsthal[index])
        index++;

    for (int i = 0; i < index; i++)
    {
        int actual = jacobsthal[i + 1];

        if (len < actual)
            actual = len;

        while (actual > jacobsthal[i])
        {
            sequence.push_back(actual);
            actual--;
        }
    }
    return sequence;
}