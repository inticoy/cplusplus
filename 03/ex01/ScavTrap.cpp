/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/25 15:14:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  set_hit(100);
  set_energy(50);
  set_attack_damage(20);
  std::cout << "ScavTrap with no name created.\n";
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  set_hit(100);
  set_energy(50);
  set_attack_damage(20);
  std::cout << "ScavTrap " << get_name_for_display() << " created.\n";
}
ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st.get_name()) {
  set_hit(st.get_hit());
  set_energy(st.get_energy());
  set_attack_damage(st.get_attack_damage());
  std::cout << "ScavTrap " << get_name_for_display() << " created.\n";
}
ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << get_name_for_display() << " destroyed.\n";
}
ScavTrap &ScavTrap::operator=(const ScavTrap &st) {
  set_name(st.get_name());
  set_hit(st.get_hit());
  set_energy(st.get_energy());
  set_attack_damage(st.get_attack_damage());
  return *this;
}

void ScavTrap::attack(const std::string &target) {
  if (get_hit() > 0 && get_energy() > 0) {
    set_energy(get_energy() - 1);
    std::cout << "ScavTrap " << get_name_for_display() << " ";
    std::cout << "attacks " << target << ", ";
    std::cout << "causing " << get_attack_damage() << " ";
    std::cout << "points of damage!\n";
  } else if (get_hit() <= 0) {
    std::cout << "ScavTrap " << get_name_for_display() << " ";
    std::cout << "cannot attack " << target << " because of hit point.\n";
  } else {
    std::cout << "ScavTrap " << get_name_for_display() << " ";
    std::cout << "cannot attack " << target << " because of energy point.\n";
  }
}
void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << get_name_for_display() << " ";
  std::cout << "is in a Gate Keeper mode.\n";
}
