#include "whatever.hpp"

int main( void ) 
{
	int a = 5;
	int b = 10;

	::swap( a, b );
	
	std::cout << "a = " << a << " | b = " << b << std::endl;
	std::cout << "Min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "Max(a, b) = " << ::max( a, b ) << std::endl;
	
	std::string c = "str1";
	std::string d = "str2";
	
	::swap(c, d);
	
	std::cout << "c = " << c << " | d = " << d << std::endl;
	std::cout << "Min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "Max(c, d) = " << ::max( c, d ) << std::endl;
	
	return 0;
}
