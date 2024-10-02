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

class NotFoundException : public std::exception
{
	public:
		const char *what() const throw();
};

template <typename T>
int easyfind(T &container, int element)
{
	typename T::iterator it = std::find(container.begin(), container.end(), element);
	if (it == container.end())
		throw NotFoundException();
	return *it;
}