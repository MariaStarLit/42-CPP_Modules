/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:21:53 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 02:50:06 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	//My rainbow tests:
	std::cout << std::endl << RED << "My tests:" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "a   = " << RESET << a << std::endl;
	std::cout << YELLOW << "--a = " << RESET << --a << std::endl;
	std::cout << YELLOW << "a   = " << RESET << a << std::endl;
	std::cout << YELLOW << "a-- = " << RESET << a-- << std::endl;
	std::cout << YELLOW << "a   = " << RESET << a << std::endl << std::endl;

	Fixed c(42);
	std::cout << GREEN << "min(42, 0) = " << RESET << Fixed::min(a, c) << std::endl;
	std::cout << GREEN << "max(42, 0) = " << RESET << Fixed::max(a, c) << std::endl << std::endl;

	a = 2;
	c = c + a;
	std::cout << CYAN << "42 + 2 = " << RESET  << c << std::endl;
	c = c - a;
	std::cout << CYAN << "44 - 2 = " << RESET << c << std::endl;
	c = c * a;
	std::cout << CYAN << "42 * 2 = " << RESET << c << std::endl;
	c = c / a;
	std::cout << CYAN << "84 / 2 = " << RESET << c << std::endl << std::endl;

	a = 40;
	std::cout << PURPLE << "42 > 40 : " << RESET << (c > a) << std::endl;
	std::cout << PURPLE << "42 >= 40: " << RESET << (c >= a) << std::endl;
	std::cout << PURPLE << "42 < 40 : " << RESET << (c < a) << std::endl;
	std::cout << PURPLE << "42 <= 40: " << RESET << (c <= a) << std::endl;
	std::cout << PURPLE << "42 == 40: " << RESET << (c == a) << std::endl;
	std::cout << PURPLE << "42 != 40: " << RESET << (c != a) << std::endl;

	return (0);
}
