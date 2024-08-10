/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:39 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 17:44:23 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);								//Default constructor
		FragTrap(std::string name);					//Name constructor
		FragTrap(const FragTrap &copy);				//Copy constructor
		FragTrap &operator=(const FragTrap &copy);	//Copy assignment operator
		~FragTrap(void);							//Destructor

		//Member Functions
		void	highFivesGuys(void);
};