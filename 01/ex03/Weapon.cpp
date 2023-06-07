/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:04:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 16:27:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(string type) : type(type) {}
Weapon::~Weapon() {}

void Weapon::setType(string type) { this->type = type; }
string const &Weapon::getType() const { return type; }
