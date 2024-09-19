#include "ScalarConverter.hpp"

//Constructores
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &	ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

//Destructor
ScalarConverter::~ScalarConverter() {}

//Other functions
int		findType(std::string var)
{
	if (var == "nan" || var == "-inf" || var == "+inf")
	{
		std::cout << CYAN << "char: " << RED << "impossible" << RESET << std::endl;
		std::cout << CYAN << "int: " << RED << "impossible" << RESET << std::endl;
		std::cout << CYAN << "float: " << RED << var << "f" << RESET << std::endl;
		std::cout << CYAN << "double: " << RED << var << RESET << std::endl;
		return (5);
	}
	if (var == "nanf" || var == "-inff" || var == "+inff")
	{
		std::cout << CYAN << "char: " << RED << "impossible" << RESET << std::endl;
		std::cout << CYAN << "int: " << RED << "impossible" << RESET << std::endl;
		std::cout << CYAN << "float: " << RED << var << RESET << std::endl;
		std::cout << CYAN << "double: " << RED << var.substr(0, var.length() - 1) << RESET << std::endl;
		return (5);
	}
	if (var.length() == 1 && !isdigit(var[0]))
		return (CHAR);
	size_t i = 0;
	if (var[0] == '+' || var[0] == '-')
		i = 1;
	while (isdigit(var[i]) && i < var.length())
		i++;
	if (i == var.length())
		return (INT);
	if (var[i] == '.')
	{
		i++;
		if(!var[i] || !isdigit(var[i]))
			return (IMPOSSIBLE);
		while (isdigit(var[i]) && i < var.length())
			i++;
		if (var[i] == 'f' && i == var.length() - 1)
			return (FLOAT);
		if (i == var.length())
			return (DOUBLE);
	}
	return (IMPOSSIBLE);
}

void	printChar(int ch)
{
	std::cout << CYAN << "char: " << RESET;
	if (ch < 0 || ch > 127)
		std::cout << RED << "impossible" << RESET << std::endl;
	else if (isprint(ch))
		std::cout << "'" << static_cast<char>(ch) << "'" << std::endl;
	else
		std::cout << RED << "Non displayable" << RESET << std::endl;
}

void	printInt(long nbr)
{
	std::cout << CYAN << "int: " << RESET;
	if (nbr > INT_MAX || nbr < INT_MIN)
		std::cout << RED << "impossible" << RESET << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;
}

void	printFloat(float nbr)
{
	std::cout << CYAN << "float: " << RESET;
	if (nbr > FLT_MAX || nbr < -FLT_MAX)
		std::cout << RED << "impossible" << RESET << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;
}

void	printDouble(double nbr)
{
	std::cout << CYAN << "double: " << RESET;
	if (nbr > DBL_MAX || nbr < -DBL_MAX)
		std::cout << RED << "impossible" << RESET << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << nbr << std::endl;
}

//Member function
void	ScalarConverter::convert(std::string var)
{
	int type = findType(var);
	switch(type)
	{
		case 0:
			std::cout << CYAN << "char: " << RED << "impossible" << RESET << std::endl;
			std::cout << CYAN << "int: " << RED << "impossible" << RESET << std::endl;
			std::cout << CYAN << "float: " << RED << "impossible" << RESET << std::endl;
			std::cout << CYAN << "double: " << RED << "impossible" << RESET << std::endl;
			break;
		case 1:
			printChar(static_cast<int>(var[0]));
			printInt(static_cast<int>(var[0]));
			printFloat(static_cast<float>(var[0]));
			printDouble(static_cast<double>(var[0]));
			break;
		case 2:
			printChar(atoi(var.c_str()));
			printInt(atol(var.c_str()));
			printFloat(atof(var.c_str()));
			printDouble(atof(var.c_str()));
			break;
		default:
			break;
	}
}