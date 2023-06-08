/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:04:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:15:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string type) : type_(type) {}
Weapon::~Weapon() {}

void Weapon::set_type(std::string type) { this->type_ = type; }
const std::string &Weapon::get_type() const { return type_; }
