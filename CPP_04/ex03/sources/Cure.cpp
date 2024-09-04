/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:38:38 by mde-avel          #+#    #+#             */
/*   Updated: 2024/08/16 17:00:02 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << BLUE << " Cure Materia created." << RESET << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	*this = copy;
	std::cout << BLUE << "Cure copy constructor called" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &copy) 
{
	std::cout << BLUE << "Cure copy assignment operator called" << RESET << std::endl;
	this->_type = copy._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << BLUE << " Cure Materia destroyed." << RESET << std::endl;
}

AMateria *Cure::clone() const
{
	Cure* copy = new Cure();
	return (copy);
}

void Cure::use(ICharacter& target) 
{
	std::cout << PURPLE << " * heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}