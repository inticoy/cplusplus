/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:12:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 16:54:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

using std::cout;
using std::endl;

HumanB::HumanB(string name) : name(name), weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::attack()
{
    cout << name << " attacks with their ";
    cout << ((weapon) ? weapon->getType() : "fist") << endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }