/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:02:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 20:13:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
}

Character::Character(const Character &c)
{
}

Character::Character(std::string name)
{
}

Character::~Character()
{
}

Character &Character::operator=(const Character &c)
{
}

std::string const &Character::getName() const
{
}

void Character::equip(AMateria *m)
{
}

void Character::unequip(int idx)
{
}

void Character::use(int idx, ICharacter &target)
{
}