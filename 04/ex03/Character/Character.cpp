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
#include "MateriaSource.hpp"

Character::Character()
{
    name = "No Name";
    for (int i = 0; i < kInventory; i++)
    {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &c)
{
    name = c.name;
    for (int i = 0; i < kInventory; i++)
    {
        if (c.inventory[i])
        {
            inventory[i] = c.inventory[i]->clone();
        }
        else
        {
            inventory[i] = NULL;
        }
    }
}

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < kInventory; i++)
    {
        inventory[i] = NULL;
    }
}

Character::~Character()
{
    for (int i = 0; i < kInventory; i++)
    {
        if (inventory[i])
        {
            delete inventory[i];
        }
    }
}

Character &Character::operator=(const Character &c)
{
    name = c.name;
    for (int i = 0; i < kInventory; i++)
    {
        if (c.inventory[i])
        {
            inventory[i] = c.inventory[i]->clone();
        }
        else
        {
            inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < kInventory; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            m->getSource()->unequip(m);
        }
    }
    std::cout << "error: inventory is full\n";
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= kInventory)
    {
        std::cout << "error: idx should be between 0 and " << kInventory
                  << ".\n";
    }
    else if (!inventory[idx])
    {
        std::cout << "error: slot " << idx << " is empty.\n";
    }
    else
    {
        inventory[idx]->getSource()->equip(inventory[idx]);
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= kInventory)
    {
        std::cout << "error: idx should be between 0 and " << kInventory;
        std::cout << ".\n";
    }
    else if (!inventory[idx])
    {
        std::cout << "error: slot " << idx << " is empty.\n";
    }
    else
    {
        inventory[idx]->use(target);
    }
}