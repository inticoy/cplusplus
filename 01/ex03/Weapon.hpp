/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:44:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 16:27:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

using std::string;

class Weapon
{
private:
    string type;

public:
    Weapon();
    Weapon(string type);
    ~Weapon();
    void setType(string type);
    string const &getType() const;
};

#endif
