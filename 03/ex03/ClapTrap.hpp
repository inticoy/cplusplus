/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:33:23 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/26 15:56:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &clapTrap);
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap &clapTrap);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

  protected:
    std::string name;
    int hit;          // HP
    int energy;       // Mana
    int attackDamage; // AD

    const std::string getNameForDisplay() const;
};

#endif
