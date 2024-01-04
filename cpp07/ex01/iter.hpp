#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T, typename N>
void	iter(T *array, size_t n, void (*f)(N&))
{
	for (size_t i = 0; i < n; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void printt( T &x )
{
  std::cout << x << std::endl;
}

#endif
