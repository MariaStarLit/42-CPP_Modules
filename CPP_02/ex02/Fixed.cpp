/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:47 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 03:04:16 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac_bits = 8;

//Constructor
Fixed::Fixed() : _fixed_point(0)
{}

Fixed::Fixed(const int nbr)
{this->_fixed_point = (nbr << this->_frac_bits);}

Fixed::Fixed(const float nbr)
{this->_fixed_point = roundf(nbr * (1 << this->_frac_bits));}

Fixed::Fixed(const Fixed &copy)
{*this = copy;}

//Destructor
Fixed::~Fixed()
{}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &copy)
{
	if(this != &copy)
		this->_fixed_point = copy.getRawBits();
	return (*this);
}

//Arithmetic operators
Fixed	Fixed::operator+(const Fixed &plus)
{
	Fixed res;
	res.setRawBits(this->getRawBits() + plus.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &minus)
{
	Fixed res;
	res.setRawBits(this->getRawBits() - minus.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &multiply)
{
	Fixed res;
	res.setRawBits((this->getRawBits() * multiply.getRawBits()) >> _frac_bits);
	return (res);
}

Fixed	Fixed::operator/(const Fixed &divide)
{
	Fixed res;
	res.setRawBits((this->getRawBits() / divide.getRawBits()) << _frac_bits);
	return (res);
}

//Pre-Incrementation operators
Fixed	Fixed::operator++(void)
{
	++this->_fixed_point;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	--this->_fixed_point;
	return (*this);
}

//Pos-Incrementation operators
Fixed	Fixed::operator++(int i)
{
	(void)i;
	Fixed	temp(*this);
	this->_fixed_point++;
	return (temp);
}

Fixed	Fixed::operator--(int i)
{
	(void)i;
	Fixed	temp(*this);
	this->_fixed_point--;
	return (temp);
}

//Comparison operators
bool	Fixed::operator>(const Fixed &big)
{
	if (this->_fixed_point > big.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed &bigger)
{
	if (this->_fixed_point >= bigger.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed &small)
{
	if (this->_fixed_point < small.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed &smaller)
{
	if (this->_fixed_point <= smaller.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed &equal)
{
	if (this->_fixed_point == equal.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed &diff)
{
	if (this->_fixed_point != diff.getRawBits())
		return true;
	return false;
}

//Max & Min Member Functions
Fixed		&Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1._fixed_point < n2._fixed_point)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed		&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1._fixed_point > n2._fixed_point)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

//More Member Functions
int		Fixed::getRawBits( void ) const
{return (this->_fixed_point);}

void	Fixed::setRawBits( int const raw )
{this->_fixed_point = raw;}

int		Fixed::toInt( void ) const
{return (_fixed_point >> _frac_bits);}

float	Fixed::toFloat( void ) const
{return ((float)_fixed_point / (1 << _frac_bits));}

std::ostream	&operator<<(std::ostream &val, const Fixed &fix)
{return (val << fix.toFloat());}
