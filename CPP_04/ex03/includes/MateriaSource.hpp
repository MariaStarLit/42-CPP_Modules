/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:13:23 by mde-avel          #+#    #+#             */
/*   Updated: 2024/08/16 18:31:24 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*stored_m[4];
		int			count;
	public:
		MateriaSource(void);									//Default constructor
		MateriaSource(const MateriaSource &copy);				//Copy constructor
		MateriaSource &operator=(const MateriaSource &copy);	//Copy assignment operator
		~MateriaSource(void);									//Destructor

		//Member functions
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const &type);
};
