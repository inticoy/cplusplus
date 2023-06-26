/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:14:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:42:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &scavTrap);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &scavTrap);

    void attack(const std::string &target);
    void guardGate();

  protected:
    const static int kHit = 100;
    const static int kEnergy = 50;
    const static int kAttackDamage = 20;
};

#endif
