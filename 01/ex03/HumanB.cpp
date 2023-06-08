/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:12:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/09 00:11:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}
HumanB::~HumanB() {}

void HumanB::attack() {
  std::cout << name_ << " attacks with their ";
  std::cout << ((weapon_) ? weapon_->get_type() : "fist") << std::endl;
}

void HumanB::set_weapon(Weapon &weapon) { weapon_ = &weapon; }