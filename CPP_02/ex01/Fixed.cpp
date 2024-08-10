/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:47 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 00:56:07 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac_bits = 8;

Fixed::Fixed() : _fixed_point(0)
{std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = (nbr << this->_frac_bits);
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(nbr * (1 << this->_frac_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &copy)
		this->_fixed_point = copy.getRawBits();
	return *this;
}

Fixed::~Fixed()
{std::cout << "Destructor called" << std::endl;}

int		Fixed::getRawBits( void ) const
{return (this->_fixed_point);}

void	Fixed::setRawBits( int const raw )
{this->_fixed_point = raw;}

int		Fixed::toInt( void ) const
{return _fixed_point >> _frac_bits;}

float	Fixed::toFloat( void ) const
{return ((float)_fixed_point / (1 << _frac_bits));}

std::ostream	&operator<<(std::ostream &output, const Fixed &fix)
{return (output << fix.toFloat());}
