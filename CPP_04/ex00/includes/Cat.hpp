/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:15:27 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/11 22:00:06 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);								//Default constructor
		Cat(const Cat &copy);					//Copy constructor
		Cat &operator=(const Cat &copy);		//Copy assignment operator
		~Cat(void);								//Destructor

		//Member Functions
		void	makeSound(void) const;
};