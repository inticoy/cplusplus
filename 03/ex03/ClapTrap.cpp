/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:38:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/24 14:32:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
    : name_(""), hit_(kHit), energy_(kEnergy), attack_damage_(kAttackDamage) {
  std::cout << "ClapTrap with no name created.\n";
}
ClapTrap::ClapTrap(std::string name)
    : name_(name), hit_(kHit), energy_(kEnergy), attack_damage_(kAttackDamage) {
  std::cout << "ClapTrap " << get_name_for_display() << " created.\n";
}
ClapTrap::ClapTrap(const ClapTrap &ct) {
  name_ = ct.name_;
  hit_ = ct.hit_;
  energy_ = ct.energy_;
  attack_damage_ = ct.attack_damage_;
  std::cout << "ClapTrap " << get_name_for_display() << " created.\n";
}
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << get_name_for_display() << " destroyed.\n";
}
ClapTrap &ClapTrap::operator=(const ClapTrap &ct) {
  name_ = ct.name_;
  hit_ = ct.hit_;
  energy_ = ct.energy_;
  attack_damage_ = ct.attack_damage_;
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  std::cout << "ClapTrap " << get_name_for_display() << " ";
  std::cout << "attacks " << target << ", ";
  std::cout << "causing " << attack_damage_ << " ";
  std::cout << "points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount) {
  hit_ -= amount;
  std::cout << "ClapTrap " << get_name_for_display() << " ";
  std::cout << "take " << amount << " of damage, ";
  std::cout << "now health is " << hit_ << ".\n";
}
void ClapTrap::beRepaired(unsigned int amount) {
  hit_ += amount;
  std::cout << "ClapTrap " << get_name_for_display() << " ";
  std::cout << "is repaired " << amount << ", ";
  std::cout << "now health is " << hit_ << ".\n";
}
const std::string ClapTrap::get_name_for_display() const {
  return name_.empty() ? "with no name" : "[" + name_ + "]";
}

void ClapTrap::set_name(std::string name) { name_ = name; }
void ClapTrap::set_hit(int hit) { hit_ = hit; }
void ClapTrap::set_energy(int energy) { energy_ = energy; }
void ClapTrap::set_attack_damage(int attack_damage) {
  attack_damage_ = attack_damage;
}
const std::string &ClapTrap::get_name() const { return name_; }
const int &ClapTrap::get_hit() const { return hit_; }
const int &ClapTrap::get_energy() const { return energy_; }
const int &ClapTrap::get_attack_damage() const { return attack_damage_; }