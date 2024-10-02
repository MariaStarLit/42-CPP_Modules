#include "Span.hpp"

//Constructores
Span::Span() : N(0)
{}

Span::Span(unsigned int n) : N(n)
{
	srand(time(NULL));
}

Span::Span(const Span &copy)  : N(copy.N)
{
	*this = copy;
}

//Destructor
Span::~Span()
{
	this->arr.clear();
}

//Operator
Span &Span::operator=(const Span &copy)
{
	if ( this != &copy )
	{
		this->N = copy.N;
		this->arr = copy.arr;
	}
	return *this;
}

//Member Functions
void Span::addNumber(int nbr)
{
	if (arr.size() >= this->N)
		throw ArrayFullException();
	arr.push_back(nbr);
}

void Span::print_array(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for(int i = 0; begin != end; ++begin)
	{
		std::cout << "Index " << i << " --> " << this->arr[i] << std::endl;
		i++;
	}
	std::cout << std::endl;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->N < std::distance(begin, end))
		throw ArrayFullException();
	arr.insert(arr.begin(), begin, end);
	// std::cout << CYAN << "arr:" << RESET << std::endl;
	// print_array(this->arr.begin(), this->arr.end());
	// std::cout << CYAN << "\nv:" << RESET << std::endl;
	// print_array(begin, end);
};


int Span::shortestSpan(void)
{
	if (arr.size() <= 1)
		throw NoSpanException();
	std::vector<int> ordered (this->arr);
	std::sort(ordered.begin(), ordered.end());
	int small = ordered[1] - ordered[0];
	for (unsigned int i = 2; i < ordered.size(); i++)
	{
		if ((ordered[i] - ordered[i -1]) < small)
			small = ordered[i] - ordered[i - 1];
	}
	return (small);
}

int Span::longestSpan(void)
{
	if (arr.size() <= 1)
		throw NoSpanException();
	int big = *std::max_element(arr.begin(), arr.end()) - *std::min_element(arr.begin(), arr.end());
	return (big);
}

//Exceptions
const char	*Span::NoSpanException::what() const throw()
{
	return ("\033[0;31mNo Span can be found! \033[0m");
}

const char	*Span::ArrayFullException::what() const throw()
{
	return ("\033[0;31mElement limmit reach! \033[0m");
}