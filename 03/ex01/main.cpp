/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/23 16:41:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  {
    ScavTrap scav_trap;
    scav_trap.attack("gyoon");
    scav_trap.takeDamage(4);
    scav_trap.beRepaired(9);
    scav_trap.guardGate();
  }

  std::cout << std::endl;
  {
    ScavTrap scav_trap2("inticoy");
    scav_trap2.attack("gyoon");
    scav_trap2.takeDamage(5);
    scav_trap2.beRepaired(8);
    scav_trap2.guardGate();

    std::cout << std::endl;

    std::cout << "convert ScavTrap into ClapTrap" << std::endl;
    ClapTrap clap_trap = scav_trap2;
    clap_trap.attack("gyoon");
    clap_trap.takeDamage(6);
    clap_trap.beRepaired(7);
    // clap_trap.guardGate();  // can't be done

    // ScavTrap scav_trap2 = clap_trap; // can't be done;
    // ScavTrap scav_trap2 = static_cast<ScavTrap>(clap_trap); // can't be done;
  }
  return 0;
}