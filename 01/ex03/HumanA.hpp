/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:08:48 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 16:42:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

using std::string;

class HumanA
{
private:
    Weapon &weapon;
    string name;

public:
    HumanA(string name, Weapon &weapon);
    ~HumanA();
    void attack();
};

#endif
