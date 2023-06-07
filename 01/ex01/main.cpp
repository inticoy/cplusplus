/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:36:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 15:29:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    cout << "[zombieHorde] Allocate 10 zombies in a single allocation." << endl;
    Zombie *zombie = zombieHorde(10, "zombieHorde");
    for (int i = 0; i < 10; i++)
        zombie[i].announce();
    delete[] zombie;
    return (0);
}
