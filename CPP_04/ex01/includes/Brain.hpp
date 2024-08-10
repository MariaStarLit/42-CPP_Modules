/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:15:09 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/12 03:43:02 by mde-avel         ###   ########.fr       */
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

class Brain
{
	protected:
		std::string		ideas[100];

	public:
		Brain(void);							//Default constructor
		Brain(const Brain &copy);				//Copy constructor
		Brain &operator=(const Brain &copy);	//Copy assignment operator
		~Brain(void);							//Destructor

		//Member Functions
		void	setIdea(int i, std::string ideia);
		void	printIdeas(void);
};