/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:39:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/24 18:16:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  {
    DiamondTrap diamond_trap("T");
    diamond_trap.attack("gyoon");
    diamond_trap.ClapTrap::attack("gyoon");

    diamond_trap.takeDamage(4);
    diamond_trap.beRepaired(9);
    diamond_trap.guardGate();
    diamond_trap.highFivesGuys();

    diamond_trap.whoAmI();
  }
  return 0;
}