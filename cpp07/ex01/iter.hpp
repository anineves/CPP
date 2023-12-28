#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void	iter(T *array, int n, void (*f)(const T& array))
{
	for (int i = 0; i < n; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void print( T &x )
{
  std::cout << x << std::endl;
  return;
}

#endif
