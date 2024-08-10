/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:08:13 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/11 22:12:12 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << PURPLE << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string Wronganimal_type) : type(Wronganimal_type)
{
	std::cout << PURPLE << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) 
{
	std::cout << PURPLE << "WrongAnimal copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) 
{
	std::cout << PURPLE << "WrongAnimal copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << PURPLE << "WrongAnimal destructor called" << RESET << std::endl;
}

void		WrongAnimal::makeSound() const
{
	std::cout << PURPLE << this->type << ": " << RESET << "Bla bla bla ..." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}