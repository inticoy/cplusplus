/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:09:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 22:07:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : name_(name), weapon_(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack() {
  std::cout << name_ << " attacks with his/her " << weapon_.get_type();
  std::cout << std::endl;
}