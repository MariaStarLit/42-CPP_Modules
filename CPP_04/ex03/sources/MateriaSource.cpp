/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:56:44 by mde-avel          #+#    #+#             */
/*   Updated: 2024/09/03 18:55:14 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << CYAN << "MateriaSource created." << RESET << std::endl;
	this->count = 0;
	for(int i = 0; i < 4; i++)
		this->stored_m[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << CYAN << "MateriaSource copy created." << RESET << std::endl;
	for(int i = 0; i < 4; i++)
		this->stored_m[i] = NULL;
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << CYAN << "MateriaSource assignment operator created." << RESET << std::endl;
	if (this == &copy)
		return (*this);
	this->count = copy.count;
	for(int i = 0; i < 4; i++)
	{
		if (this->stored_m[i])
		{
			delete (this->stored_m[i]);
			this->stored_m[i] = NULL;
		}
		this->stored_m[i] = copy.stored_m[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->stored_m[i])
			delete (this->stored_m[i]);
	}
	std::cout << CYAN << "MateriaSource destroyed!" << RESET << std::endl;
}

void MateriaSource::learnMateria(AMateria* mat)
{
	if (this->count >= 4)
	{
		std::cout << RED << "Error! Storage is full." << RESET << std::endl;
		delete (mat);
	}
	else
	{
		this->stored_m[count] = mat;
		std::cout << BLUE << "MateriaSource " << RESET << this->stored_m[count]->getType() << " added to storage." << std::endl;
		this->count++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->stored_m[i] && this->stored_m[i]->getType() == type)
			return (this->stored_m[i]->clone());
	}
	std::cout << RED << "Error! Creating unknown source materia." << RESET << std::endl;
	return (NULL);
}
