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

template <typename T>
void	swap(T &n1, T &n2)
{
	T tmp = n1;
	n1 = n2;
	n2 = tmp;
}

template <typename T>
T	min(T n1, T n2)
{
	if (n1 < n2)
		return (n1);
	else
		return(n2);
}

template <typename T>
T	max(T n1, T n2)
{
	if (n1 > n2)
		return (n1);
	else
		return(n2);
}