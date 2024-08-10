/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:35 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 20:30:19 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << PURPLE << "FragTrap default constructor called" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << PURPLE << "FragTrap name constructor called" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << PURPLE << "FragTrap copy constructor called" << RESET << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << PURPLE << "FragTrap copy assignment operator called" << RESET << std::endl;
	if(this != &copy)
	{
		this->_name = copy._name;
		this->_hit_points = copy._hit_points;
		this->_energy_points = copy._energy_points;
		this->_attack_damage = copy._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << PURPLE << "FragTrap destructor called" << RESET << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << PURPLE << "FragTrap "  << this->_name << ": " << RESET << "Hey! Let's High Five!" << std::endl;
}
