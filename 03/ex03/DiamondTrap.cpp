/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:33:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/25 15:20:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(""), ScavTrap(""), FragTrap("") {
  set_hit(kHit);
  set_energy(kEnergy);
  set_attack_damage(kAttackDamage);
  std::cout << "DiamondTrap with no name created." << std::endl;
}
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name + "_clap_name"),
      FragTrap(name + "_clap_name"),
      name_(name) {
  set_hit(kHit);
  set_energy(kEnergy);
  set_attack_damage(kAttackDamage);
  std::cout << "DiamondTrap " << get_name_for_display() << " created.\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap &dt) {
  ClapTrap::set_name(dt.ClapTrap::get_name());
  set_name(dt.get_name());
  set_hit(dt.get_hit());
  set_energy(dt.get_energy());
  set_attack_damage(dt.get_attack_damage());
  std::cout << "DiamondTrap " << get_name_for_display() << " created.\n";
}
DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << get_name_for_display() << " destroyed.\n";
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &dt) {
  ClapTrap::set_name(dt.ClapTrap::get_name());
  set_name(dt.get_name());
  set_hit(dt.get_hit());
  set_energy(dt.get_energy());
  set_attack_damage(dt.get_attack_damage());
  return *this;
}

void DiamondTrap::whoAmI() {
  std::cout << "I want to introduce myself.\n";
  std::cout << "DiamondTrap name is " << get_name_for_display() << "\n";
  std::cout << "ClapTrap name is " << ClapTrap::get_name_for_display() << "\n";
}
const std::string DiamondTrap::get_name_for_display() const {
  return name_.empty() ? "with no name" : "[" + name_ + "]";
}

void DiamondTrap::set_name(std::string name) { name_ = name; }
const std::string &DiamondTrap::get_name() const { return name_; }