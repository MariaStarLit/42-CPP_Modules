#pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>

class RPN
{
	private:
		static std::stack<double>	pile_n;
		static double				result;
		RPN();						//Default Constructor
		RPN(const RPN &copy);		//Copy Constructor
		~RPN();						//Destructor

		//Operator
		RPN &operator=(const RPN &copy);

	public:
		//Member Functions
		static void	calculate(std::string expression);
		static void executeOperation(char op);
};