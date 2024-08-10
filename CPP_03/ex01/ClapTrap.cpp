/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:38:24 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 20:26:48 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Nothing"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "ClapTrap name constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << GREEN << "ClapTrap copy constructor called" << RESET << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << GREEN << "ClapTrap copy assignment operator called" << RESET << std::endl;
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
	std::cout << GREEN << "ClapTrap destructor called" << RESET << std::endl;
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

// void		ClapTrap::setName(std::string name)			{this->_name = name;}
// void		ClapTrap::setHealth(unsigned int health)	{this->_hit_points = health;}
// void		ClapTrap::setEnergy(unsigned int energy)	{this->_energy_points = energy;}
// void		ClapTrap::setAttack(unsigned int attack)	{this->_attack_damage = attack;}

// std::string		ClapTrap::getName(void) const			{return (this->_name);}
// unsigned int	ClapTrap::getHealth(void) const			{return (this->_hit_points);}
// unsigned int	ClapTrap::getEnergy(void) const			{return (this->_energy_points);}
// unsigned int	ClapTrap::getAttack(void) const			{return (this->_attack_damage);}