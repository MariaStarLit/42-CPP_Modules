/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:37:37 by mde-avel          #+#    #+#             */
/*   Updated: 2024/05/09 07:22:11 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a;
	a.guardGate();
	a.printStatus();

	ScavTrap	b("Morgana");
	b.guardGate();
	b.printStatus();
	for (int i = 0; i < 6; i++)
		b.attack(a);
	a.printStatus();
	b.printStatus();
	return (0);
}