/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:38 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/12 04:15:24 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << BLUE << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(std::string animal_type) : type(animal_type)
{
	std::cout << BLUE << "Animal constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &copy) 
{
	std::cout << BLUE << "Animal copy constructor called" << RESET << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy) 
{
	std::cout << BLUE << "Animal copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal destructor called" << RESET << std::endl;
}

void		Animal::makeSound() const
{
	std::cout << BLUE << this->type << ": " << RESET << "*Animal noise*" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void		Animal::telepathy(void) const {}

void		Animal::changeIdea(int i, std::string ideia) 
{
	(void)i;
	(void)ideia;
}