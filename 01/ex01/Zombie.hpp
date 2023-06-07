/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:30:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 16:00:25 by gyoon            ###   ########.fr       */
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
    void announce();
    void setName(string name);
    string getName();
};

Zombie *zombieHorde(int N, string name);

#endif
