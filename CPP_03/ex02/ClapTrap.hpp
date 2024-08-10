/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:37:31 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 07:05:26 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:50 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/07 19:33:56 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// Colors
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:
		ClapTrap(void);								//Default constructor
		ClapTrap(std::string name);					//Name constructor
		ClapTrap(const ClapTrap &copy);				//Copy constructor
		ClapTrap &operator=(const ClapTrap &copy);	//Copy assignment operator
		~ClapTrap(void);								//Destructor

		//Member Functions
		operator		std::string() const;
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			printStatus(void);
};

// void			setName(std::string name);
// void			setHealth(unsigned int health);
// void			setEnergy(unsigned int energy);
// void			setAttack(unsigned int attack);
// std::string		getName(void) const;
// unsigned int	getHealth(void) const;
// unsigned int	getEnergy(void) const;
// unsigned int	getAttack(void) const;