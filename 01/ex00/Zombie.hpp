/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:30:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 14:35:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
private:
    string name;

public:
    Zombie();
    Zombie(string name);
    ~Zombie();
    void announce(void);
};

Zombie *newZombie(string name);
void randomChump(string name);

#endif
