/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:14:04 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/12 04:36:22 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			ideas[i] = "(=^ ◡ ^=)Zzzzzz";
		else
			ideas[i] = "(=ㅇㅅㅇ=)Eaaaat";
	}
}

Brain::Brain(const Brain &copy) 
{
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy) 
{
	std::cout << GREEN << "Brain copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << GREEN << "Brain destructor called" << RESET << std::endl;
}

void	Brain::setIdea(int i, std::string ideia)
{
	if (i < 0 || i >= 100)
		std::cout << RED << "Error! Out of Brian scope of ideas!" << RESET << std::endl;
	else
		this->ideas[i] = ideia;
}

void	Brain::printIdeas(void)
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << GREEN << i << ": " << RESET << this->ideas[i] << std::endl;
	}
	std::cout << std::endl;
}