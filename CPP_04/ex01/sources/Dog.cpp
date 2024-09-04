/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:24 by mde-avel          #+#    #+#             */
/*   Updated: 2024/08/16 17:42:55 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << CYAN << "Dog default constructor called" << RESET << std::endl;
	this->_brian = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << CYAN << "Dog copy constructor called" << RESET << std::endl;
	this->_brian = NULL;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy) 
{
	std::cout << CYAN << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->_brian;
		this->_brian = new Brain(*copy._brian);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << CYAN << "Dog destructor called" << RESET << std::endl;
	delete this->_brian;
}

void	Dog::makeSound() const
{
	std::cout << CYAN << this->type << ": " << RESET << "Woof Woof" << std::endl;
}

void	Dog::telepathy(void) const 
{
	std::cout << CYAN << this->type << ": " << RESET << std::endl;
	_brian->printIdeas();
}

void	Dog::changeIdea(int i, std::string ideia)
{
	_brian->setIdea(i, ideia);
}