/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:20 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/11 21:30:10 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);								//Default constructor
		Dog(const Dog &copy);					//Copy constructor
		Dog &operator=(const Dog &copy);		//Copy assignment operator
		~Dog(void);								//Destructor

		//Member Functions
		void	makeSound(void) const;
};