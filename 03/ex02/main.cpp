/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:22:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        FragTrap fragTrap;
        fragTrap.attack("gyoon");
        fragTrap.takeDamage(20);
        fragTrap.beRepaired(50);
        fragTrap.highFivesGuys();
    }

    std::cout << std::endl;
    {
        FragTrap fragTrap("frag");
        fragTrap.attack("gyoon");
        fragTrap.takeDamage(20);
        fragTrap.beRepaired(50);
    }
    return 0;
}