/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:10:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:13:56 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>

#include "Weapon.hpp"

class HumanB {
public:
  HumanB(std::string name);
  ~HumanB();
  void attack();
  void set_weapon(Weapon &weapon);

private:
  Weapon *weapon_;
  std::string name_;
};

#endif
