template<typename T>
class Array
{
	private:
		T*				arr;
		unsigned int	size;
	public:
		Array();
		Array(unsigned int size);
		Array(Array const &source);
		Array &operator=(Array const &rhs);
		~Array();

		T& operator[]( unsigned int i ) const;
		unsigned int	size();
	
	class InvalidIndex : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "The index value doesn't belong to the range.";
		}
	};
};
