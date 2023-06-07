/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:36:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 14:49:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(string name) : name(name)
{
    cout << "Zombie " << name << " created." << endl;
}
Zombie::~Zombie() { cout << "Zombie " << name << " destroyed." << endl; }

void Zombie::announce(void)
{
    cout << name << ": ";
    cout << "BraiiiiiiinnnzzzZ..." << endl;
}