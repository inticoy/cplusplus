// /* **************************************************************************
// */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:02:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 15:50:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    // std::cout << "Character Default Constructor called.\n";
    name = "No Name";
    nInventory = 0;
    for (int i = 0; i < kInventory; i++)
    {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &c)
{
    // std::cout << "Character Copy Constructor called.\n";
    name = c.name;
    nInventory = c.nInventory;
    for (int i = 0; i < nInventory; i++)
    {
        inventory[i] = c.inventory[i]->clone();
    }
}

Character::Character(std::string name)
{
    // std::cout << "Character Name Constructor called.\n";
    this->name = name;
    nInventory = 0;
    for (int i = 0; i < kInventory; i++)
    {
        inventory[i] = NULL;
    }
}

Character::~Character()
{
    // std::cout << "Character Destructor called.\n";
    for (int i = 0; i < nInventory; i++)
    {
        delete inventory[i];
    }
}

Character &Character::operator=(const Character &c)
{
    // std::cout << "Character Assignment Operator called.\n";
    for (int i = 0; i < nInventory; i++)
    {
        delete inventory[nInventory];
    }
    name = c.name;
    nInventory = c.nInventory;
    for (int i = 0; i < nInventory; i++)
    {
        inventory[i] = c.inventory[i]->clone();
    }
    return *this;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (nInventory >= kInventory)
    {
        std::cout << "error: inventory is full.\n";
    }
    else
    {
        inventory[nInventory++] = m;
        m->setEquipped();
    }
}

void Character::unequip(int idx)
{
    if (nInventory <= 0)
    {
        std::cout << "error: inventory is empty.\n";
    }
    else
    {
        inventory[--nInventory]->setRemoved();
        inventory[nInventory] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= kInventory)
    {
        std::cout << "error: idx should be between 0 and " << kInventory;
        std::cout << ".\n";
    }
    else if (idx > nInventory - 1)
    {
        std::cout << "error: slot " << idx << " is empty.\n";
    }
    else
    {
        inventory[idx]->use(target);
    }
}