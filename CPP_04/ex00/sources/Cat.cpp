/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:31 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/11 22:00:02 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << CYAN << "Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << CYAN << "Cat copy constructor called" << RESET << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy) 
{
	std::cout << CYAN << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << CYAN << "Cat destructor called" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << CYAN << this->type << ": " << RESET << "Meow Meow" << std::endl;
}