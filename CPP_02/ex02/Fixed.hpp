/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:50 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 03:04:24 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

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
		Fixed(void);					//Constructor
		Fixed(const int nbr);			//Int constructor
		Fixed(const float nbr);			//Float constructor
		Fixed(const Fixed &copy);		//Copy constructor
		~Fixed();						//Destructor
		
		//Copy assignment operator
		Fixed	&operator=(const Fixed &copy);
		//Arithmetic operators
		Fixed	operator+(const Fixed &plus);
		Fixed	operator-(const Fixed &minus);
		Fixed	operator*(const Fixed &multiply);
		Fixed	operator/(const Fixed &divide);
		//Incrementation operators
		Fixed	operator++(void);
		Fixed	operator++(int i);
		Fixed	operator--(void);
		Fixed	operator--(int i);
		//Comparison operators
		bool	operator>(const Fixed &big);
		bool	operator>=(const Fixed &bigger);
		bool	operator<(const Fixed &small);
		bool	operator<=(const Fixed &smaller);
		bool	operator==(const Fixed &equal);
		bool	operator!=(const Fixed &diff);
		//Max & Min Member Functions
		static Fixed		&min(Fixed &n1, Fixed &n2);
		static const Fixed	&min(const Fixed &n1, const Fixed &n2);
		static Fixed		&max(Fixed &n1, Fixed &n2);
		static const Fixed	&max(const Fixed &n1, const Fixed &n2);
		//More Member Functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream	&operator<<(std::ostream &val, const Fixed &fix);