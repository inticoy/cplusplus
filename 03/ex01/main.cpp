/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:22:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        ScavTrap scavTrap;
        scavTrap.ClapTrap::attack("gyoon");
        scavTrap.attack("gyoon");
        scavTrap.takeDamage(4);
        scavTrap.beRepaired(9);
        scavTrap.guardGate();
    }

    std::cout << std::endl;
    {
        ScavTrap scavTrap2("inticoy");
        scavTrap2.attack("gyoon");
        scavTrap2.takeDamage(5);
        scavTrap2.beRepaired(8);
        scavTrap2.guardGate();

        std::cout << std::endl;

        std::cout << "convert ScavTrap into ClapTrap" << std::endl;
        ClapTrap clapTrap = scavTrap2;
        clapTrap.attack("gyoon");
        clapTrap.takeDamage(6);
        clapTrap.beRepaired(7);
        // clapTrap.guardGate();  // can't be done

        // ScavTrap scavTrap2 = clapTrap; // can't be done;
        // ScavTrap scavTrap2 = static_cast<ScavTrap>(clapTrap); // can't be done;
    }
    return 0;
}