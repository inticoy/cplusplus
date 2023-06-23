/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:38:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/23 16:21:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() : name_(""), hit_(10), energy_(10), attack_damage_(0) {
  std::cout << "ClapTrap with no name created.\n";
}
ClapTrap::ClapTrap(std::string name)
    : name_(name), hit_(10), energy_(10), attack_damage_(0) {
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

const std::string &ClapTrap::get_name() const { return name_; }
const std::string ClapTrap::get_name_for_display() const {
  return name_.empty() ? "with no name" : "[" + name_ + "]";
}
