/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:49:56 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 20:21:39 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << CYAN << "ScavTrap default constructor called" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYAN << "ScavTrap name constructor called" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << CYAN << "ScavTrap copy constructor called" << RESET << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << CYAN << "ScavTrap copy assignment operator called" << RESET << std::endl;
	if(this != &copy)
	{
		this->_name = copy._name;
		this->_hit_points = copy._hit_points;
		this->_energy_points = copy._energy_points;
		this->_attack_damage = copy._attack_damage;
	}
	else
		std::cout << RED << "Error!" << RESET << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << CYAN << "ScavTrap destructor called" << RESET << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << CYAN << "ScavTrap " << RESET << this->_name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(ScavTrap &target)
{
	if (_energy_points == 0)
		std::cout << YELLOW << "ScavTrap " << this->_name << " can't attack, he's out of energy points!" << RESET << std::endl;
	else if (_hit_points == 0)
		std::cout << RED << "ScavTrap " << this->_name << " can't attack, he's Down!" << RESET << std::endl;
	else
	{
		this->_energy_points--;
		std::cout << CYAN << "ScavTrap " 
				  << RESET << this->_name
				  << " attacks " << target._name
				  << std::endl;
		if (target._hit_points >= this->_attack_damage)
			target._hit_points -= this->_attack_damage;
		else
		{
			std::cout << RED << "ScavTrap " << target._name << " is Down! Stop attacking!" << RESET << std::endl;
			target._hit_points = 0;
		}
	}
}
