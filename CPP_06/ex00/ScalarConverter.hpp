# pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# define IMPOSSIBLE 0
# define CHAR 1
# define INT 2
# define FLOAT 2
# define DOUBLE 2

# include <iostream>
# include <iomanip>
# include <cmath>
# include <string>
# include <climits>
# include <cfloat>

class ScalarConverter
{
	private:
		ScalarConverter();											//Default constructor
		ScalarConverter(const ScalarConverter &copy);				//Copy constructor
		ScalarConverter &operator=(const ScalarConverter &copy);	//Copy assignment operator
		~ScalarConverter();											//Destructor
	
	public:
		//Member function
		static void		convert(std::string var);
};
