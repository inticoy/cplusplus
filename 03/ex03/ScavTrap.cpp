/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/24 14:47:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), is_guard_(false) {
  set_hit(kHit);
  set_energy(kEnergy);
  set_attack_damage(kAttackDamage);
  std::cout << "ScavTrap with no name created.\n";
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), is_guard_(false) {
  set_hit(kHit);
  set_energy(kEnergy);
  set_attack_damage(kAttackDamage);
  std::cout << "ScavTrap " << get_name_for_display() << " created.\n";
}
ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st.get_name()) {
  set_hit(st.get_hit());
  set_energy(st.get_energy());
  set_attack_damage(st.get_attack_damage());
  is_guard_ = st.is_guard_;
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
  is_guard_ = st.is_guard_;
  return *this;
}

void ScavTrap::attack(const std::string &target) {
  std::cout << "ScavTrap " << get_name_for_display() << " ";
  std::cout << "attacks " << target << ", ";
  std::cout << "causing " << get_attack_damage() << " ";
  std::cout << "points of damage!\n";
}
void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << get_name_for_display() << " ";
  std::cout << (is_guard_ ? "is in a" : "is not in a")
            << " Gate Keeper mode.\n";
}

void ScavTrap::set_is_guard(bool is_guard) { is_guard_ = is_guard; }
const bool &ScavTrap::get_is_guard() const { return is_guard_; }
