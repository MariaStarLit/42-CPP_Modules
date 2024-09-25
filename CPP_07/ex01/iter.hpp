#pragma once

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <iostream>

template <typename T, typename T2>
void	iter(T *array, int length, T2 func)
{
	if (!array)
		return;
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void	add(T &var)
{
	var += 4;
}

template <typename T>
void	print(T &var)
{
	if (!var)
		return;
	std::cout << var << ", ";
}