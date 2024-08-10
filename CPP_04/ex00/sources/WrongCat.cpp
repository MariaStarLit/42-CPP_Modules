/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:08:20 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/11 22:19:59 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << CYAN << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << CYAN << "WrongCat copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) 
{
	std::cout << CYAN << "WrongCat copy assignment operator called" << RESET << std::endl;
	WrongAnimal::operator=(copy);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << CYAN << "WrongCat destructor called" << RESET << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << CYAN << this->type << ": " << RESET << "Oink Oink" << std::endl;
}