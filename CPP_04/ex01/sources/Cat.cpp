/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:31 by mde-avel          #+#    #+#             */
/*   Updated: 2024/08/16 17:42:36 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << CYAN << "Cat default constructor called" << RESET << std::endl;
	this->_brian = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << CYAN << "Cat copy constructor called" << RESET << std::endl;
	this->_brian = NULL;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy) 
{
	std::cout << CYAN << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->_brian;
		this->_brian = new Brain(*copy._brian);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << CYAN << "Cat destructor called" << RESET << std::endl;
	delete this->_brian;
}

void	Cat::makeSound() const
{
	std::cout << CYAN << this->type << ": " << RESET << "Meow Meow" << std::endl;
}

void	Cat::telepathy(void) const 
{
	std::cout << CYAN << this->type << ": " << RESET << std::endl;
	_brian->printIdeas();
}

void	Cat::changeIdea(int i, std::string ideia)
{
	_brian->setIdea(i, ideia);
}