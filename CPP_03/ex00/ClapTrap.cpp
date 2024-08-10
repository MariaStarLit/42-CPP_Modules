/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:38:24 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 20:27:26 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Nothing"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "Name constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
	if(this != &copy)
	{
		this->_name = copy._name;
		this->_hit_points = copy._hit_points;
		this->_energy_points = copy._energy_points;
		this->_attack_damage = copy._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << GREEN << "Destructor called" << RESET << std::endl;
}

ClapTrap::operator std::string() const 
{
	return this->_name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy_points == 0)
		std::cout << YELLOW << "ClapTrap " << this->_name << " can't attack, he's out of energy points!" << RESET << std::endl;
	else if (_hit_points == 0)
		std::cout << RED << "ClapTrap " << this->_name << " can't attack, he's Down!" << RESET << std::endl;
	else
	{
		this->_energy_points--;
		std::cout   << GREEN << "ClapTrap "
					<< RESET << this->_name
					<< " attacks " << target
					<< ", causing " << this->_attack_damage
					<< " points of damage!"
					<< RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
		std::cout << RED << "Come on why attack someone who's already Down!" << RESET << std::endl;
	else
	{
		if (this->_hit_points >= amount)
			this->_hit_points -=amount;
		else
			this->_hit_points = 0;
		std::cout   << GREEN << "ClapTrap "
					<< RESET << this->_name
					<< " was attacked, causing " << amount
					<< " points of damage, " << this->_hit_points
					<< " health points remain." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points == 0)
		std::cout << YELLOW << "ClapTrap " << this->_name << " can't be Repaired, he's out of energy points!" << RESET << std::endl;
	else
	{
		this->_energy_points--;
		this->_hit_points +=amount;
		std::cout   << GREEN << "ClapTrap "
					<< RESET << this->_name
					<< " was repaired, " << amount
					<< " points restored, now he has " << this->_hit_points
					<< " health points." << std::endl;
	}
}

void	ClapTrap::printStatus()
{
	std::cout << std::endl;
	std::cout   << GREEN << "ClapTrap status:" << std::endl
				<< GREEN << "Name: " << RESET << this->_name << std::endl 
				<< GREEN << "Health: " << RESET << this->_hit_points << std::endl
				<< GREEN << "Energy: " << RESET << this->_energy_points << std::endl
				<< GREEN << "Attack: " << RESET << this->_attack_damage << std::endl << std::endl;
}