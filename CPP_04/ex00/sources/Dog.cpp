/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:24 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/11 21:13:31 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << CYAN << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << CYAN << "Dog copy constructor called" << RESET << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy) 
{
	std::cout << CYAN << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << CYAN << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << CYAN << this->type << ": " << RESET << "Woof Woof" << std::endl;
}