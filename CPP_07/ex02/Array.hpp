#pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		unsigned int	n_el;
		T				*elements;
	
	public:
		
		Array();					//Default Constructor
		Array(unsigned int n);		//Constructores
		Array(const Array &copy);	//Copy Constructores
		~Array();					//Destructor

		//Operatores
		Array&	operator=(const Array &copy);
		T&		operator[](unsigned int i) const;

		//Member function
		unsigned int	size() const;

		//Exception
		class IndexException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("\033[0;31mIndex out off bounds! \033[0m");
				}
		};
};

# include "Array.tpp"