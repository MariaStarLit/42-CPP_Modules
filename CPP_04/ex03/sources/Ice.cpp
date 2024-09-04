/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:30:42 by mde-avel          #+#    #+#             */
/*   Updated: 2024/08/16 16:59:47 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << BLUE << " Ice Materia created." << RESET << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	*this = copy;
	std::cout << BLUE << "Ice copy constructor called" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &copy) 
{
	std::cout << BLUE << "Ice copy assignment operator called" << RESET << std::endl;
	this->_type = copy._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << BLUE << " Ice Materia destroyed." << RESET << std::endl;
}

AMateria *Ice::clone() const
{
	Ice* clone = new Ice();
	return clone;
}

void Ice::use(ICharacter& target) 
{
	std::cout << PURPLE << " * shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}