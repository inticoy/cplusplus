/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:33:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/23 22:15:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ScavTrap(""), FragTrap("") {
  std::cout << "DiamondTrap with no name created." << std::endl;
}
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_claptrap"), ScavTrap(), FragTrap(), name_(name) {
  std::cout << "DiamondTrap with " << name_ << " created." << std::endl;
  set_hit(100);
  set_energy(ScavTrap::get_energy());
  set_attack_damage(20);
}
DiamondTrap::DiamondTrap(const DiamondTrap &dt) {}
DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name_ << " destroyed." << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt) {}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}
void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name : " << name_ << std::endl;
  std::cout << "ClapTrap name : " << name_ << std::endl;
}