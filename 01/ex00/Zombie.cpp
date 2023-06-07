/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:36:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 15:59:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("") { cout << "Zombie created with no name." << endl; }
Zombie::Zombie(string name) : name(name)
{
    cout << "Zombie " << name << " created." << endl;
}
Zombie::~Zombie() { cout << "Zombie " << name << " destroyed." << endl; }

void Zombie::announce()
{
    cout << name << ": ";
    cout << "BraiiiiiiinnnzzzZ..." << endl;
}