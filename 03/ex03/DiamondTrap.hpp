/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:49:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:45:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &diamondTrap);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &diamondTrap);

    void whoAmI();

  private:
    const static int kHit = FragTrap::kHit;
    const static int kEnergy = ScavTrap::kEnergy;
    const static int kAttackDamage = FragTrap::kAttackDamage;

    std::string name;

    const std::string getNameForDisplay() const;
};

#endif
