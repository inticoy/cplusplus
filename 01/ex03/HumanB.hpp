/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:10:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 16:49:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

using std::string;

class HumanB
{
private:
    Weapon *weapon;
    string name;

public:
    HumanB(string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon &weapon);
};

#endif
