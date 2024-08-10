/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:50 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 00:58:16 by mde-avel         ###   ########.fr       */
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

class Fixed
{
	private:
		int					_fixed_point;
		static const int	_frac_bits;

	public:
		Fixed(void);							//Default constructor
		Fixed(const Fixed &copy);				//Copy constructor
		Fixed &operator=(const Fixed &copy);	//Copy assignment operator
		~Fixed();								//Destructor

		//Member Functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};
