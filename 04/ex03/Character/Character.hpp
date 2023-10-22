/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:56:00 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/22 16:24:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
    enum
    {
        kInventory = 4,
    };
    std::string name;
    int nInventory;
    AMateria *inventory[kInventory];

  public:
    Character();
    Character(const Character &c);
    Character(std::string name);
    virtual ~Character();
    Character &operator=(const Character &c);

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};

#endif
