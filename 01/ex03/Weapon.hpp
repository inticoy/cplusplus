/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:44:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/08 17:15:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
  Weapon();
  Weapon(std::string type);
  ~Weapon();
  void set_type(std::string type);
  const std::string &get_type() const;

private:
  std::string type_;
};

#endif
