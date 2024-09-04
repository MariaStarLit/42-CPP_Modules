/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:51:25 by mde-avel          #+#    #+#             */
/*   Updated: 2024/09/03 18:41:07 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Zero")
{
	std::cout << CYAN << "Default Character '" << _name << "' created." << RESET << std::endl;
	this->_drop = NULL;
	for(int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(std::string const &name)  : _name(name)
{
	std::cout << CYAN << "Character '" << _name << "' created." << RESET << std::endl;
	this->_drop = NULL;
	for(int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name)
{
	std::cout << CYAN << "Character '" << copy._name << "' Copy created." << RESET << std::endl;
	for(int i = 0; i < 4; i++)
			this->_materia[i] = NULL;
	*this = copy;
}

Character &Character::operator=(const Character &copy)
{
	std::cout << CYAN << "Character '" << copy._name << "' copy assignment operator called." << RESET << std::endl;
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	this->_drop = NULL;
	for(int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
		{
			delete (_materia[i]);
			this->_materia[i] = NULL;
		}
		if (copy._materia[i])
		{
			std::cout << CYAN << "slot " << i; 
			this->_materia[i] = copy._materia[i]->clone();
		}
		else
			this->_materia[i] = NULL;
	}
	return (*this);
}

void	cleanDropedMateria(Droped* drop)
{
	if (drop)
	{
		cleanDropedMateria(drop->next);
		delete drop->materia;
		delete drop;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
		{
			std::cout << CYAN << "slot " << i; 
			delete (this->_materia[i]); 
		}
	}
	cleanDropedMateria(this->_drop);
	std::cout << CYAN << "Character '" << this->_name << "' destroyed!" << RESET  << std::endl;
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << RED << "Error! Equiping '" << this->_name << "' with unknown materia." << RESET << std::endl;
		return ;
	}
	if (isArrFull(_materia) == 1)
	{
		std::cout << YELLOW << "Ups! " << this->_name << " Inventory is full." << RESET << std::endl;
		delete (m);
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			std::cout << CYAN << this->_name << RESET << " equiped " << this->_materia[i]->getType()  << " in slot " << i << std::endl;
			break;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
	{
		if (this->_materia[idx])
		{
			if (!_drop)
			{
				_drop = new Droped;
				_drop->materia = this->_materia[idx];
				_drop->next = NULL;
			}
			Droped* tmp = _drop;
			while(tmp->next)
				tmp = tmp->next;
			tmp->materia = this->_materia[idx];
			tmp->next = new Droped;
			tmp->next->materia = 0;
			tmp->next->next = NULL;
			std::cout << CYAN << this->_name << RESET << " unequiped " << this->_materia[idx]->getType()  << " in slot " << idx << std::endl;
			this->_materia[idx] = NULL;
		}
		else
			std::cout << YELLOW << "Ups! " << this->_name << " slot " << idx << " is already empty." << RESET << std::endl;
	}
	else
		std::cout << RED << "Error! " << this->_name << " Inventory only has form 0 to 3 slots." << RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0)
	{
		if (!this->_materia[idx])
		{
			std::cout << YELLOW << "Ups! " << this->_name << " can't attack. No materia in slot " << idx << " of his Inventory." << RESET << std::endl;
			return ;
		}
		std::cout << CYAN << this->_name << RESET; 
		this->_materia[idx]->use(target);
		delete (this->_materia[idx]);
		this->_materia[idx] = NULL;
	}
	else
		std::cout << RED << "Error! " << this->_name << " Inventory only has form 0 to 3 slots." << RESET << std::endl;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

bool Character::isArrFull(AMateria **arr_m)
{
	for(int i = 0; i < 4; i++)
	{
		if (!arr_m[i])
			return (false);
	}
	return (true);
}