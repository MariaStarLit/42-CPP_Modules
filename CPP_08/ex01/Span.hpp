# pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdlib>

class Span
{
	private:
		unsigned int N;
		std::vector<int> arr;
		Span(void);					//Default Constructor

	public:
		Span(unsigned int n);		//Constructor
		Span(const Span &copy);		//Copy Constructor
		~Span(void);				//Destructor

		//Operator
		Span &operator=(const Span &copy);

		//Member Funcitos
		void	addNumber(int nbr);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void	print_array(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

		//Exceptions
		class NoSpanException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class ArrayFullException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
