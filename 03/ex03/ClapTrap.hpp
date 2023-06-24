/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:33:23 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/24 14:32:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
  static const int kHit = 10;
  static const int kEnergy = 10;
  static const int kAttackDamage = 0;

  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &ct);
  ~ClapTrap();
  ClapTrap &operator=(const ClapTrap &ct);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  const std::string get_name_for_display() const;

  void set_name(std::string name);
  void set_hit(int hit);
  void set_energy(int energy);
  void set_attack_damage(int attack_damage);
  const std::string &get_name() const;
  const int &get_hit() const;
  const int &get_energy() const;
  const int &get_attack_damage() const;

private:
  std::string name_;
  int hit_;
  int energy_;
  int attack_damage_;
};

#endif
