/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:49:59 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 07:07:26 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);								//Default constructor
		ScavTrap(std::string name);					//Name constructor
		ScavTrap(const ScavTrap &copy);				//Copy constructor
		ScavTrap &operator=(const ScavTrap &copy);	//Copy assignment operator
		~ScavTrap(void);							//Destructor

		//Member Functions
		void	guardGate(void);
		void	attack(ScavTrap &target);
};