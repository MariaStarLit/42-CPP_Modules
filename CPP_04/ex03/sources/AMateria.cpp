/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:38 by mde-avel          #+#    #+#             */
/*   Updated: 2024/09/02 22:08:03 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Fists")
{
	//std::cout << BLUE << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	//std::cout << BLUE << "AMateria constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	//std::cout << BLUE << "AMateria copy constructor called" << RESET << std::endl;
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy) 
{
	//std::cout << BLUE << "AMateria copy assignment operator called" << RESET << std::endl;
	this->_type = copy._type;
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << BLUE << "AMateria destructor called" << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target) 
{
	(void)target;
}