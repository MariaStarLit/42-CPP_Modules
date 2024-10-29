# include "PmergeMe.hpp"

bool validInput(const std::string &str, std::vector<int> &aux)
{
	long int nbr;
	std::vector<int>::iterator it = aux.begin();
	std::vector<int>::iterator ite = aux.end();
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << RED << "Error! Not a valid input or negative number: " << str << RESET << std::endl;
			return (false);
		}
	}
	nbr = atol(str.c_str());
	if (nbr > INT_MAX)
	{
		std::cout << RED << "Error! Number overflow: " << nbr << RESET << std::endl;
		return (false);
	}
	if (find(it, ite, nbr) != ite)
	{
		std::cout << RED << "Error! Forbiden duplicated number found: " << nbr << RESET << std::endl;
		return (false);
	}
	aux.push_back(nbr);
	return (true);
}

int main(int argc, char **argv)
{
	std::vector<int> v_aux;
	if (argc < 2)
	{
		std::cout << RED << "Error! Please use an expression." << RESET << std::endl;
		std::cout << YELLOW << "Example: ./PmergeMe 3 5 9 7 4" << RESET << std::endl;
		return (1);
	}
	else if (argc == 2)
	{
		std::istringstream aux(argv[1]);
		std::string input = "";
		while (aux >> input)
		{
			if (!validInput(input, v_aux))
				return (1);
		}
		if (input.empty())
		{
			std::cout << RED << "Error! Sequence not found." << RESET << std::endl;
			return (1);
		}
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			if (!validInput(argv[i], v_aux))
				return (1);
		}
	}

	PmergeMe sort(v_aux);
	sort.sortVector();
	sort.sortList();

	sort.isSortedVector();
	sort.isSortedList();
	return (0);
}