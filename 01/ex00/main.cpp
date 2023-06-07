/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:36:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/07 14:48:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    cout << "[newZombie] Allocate Zombie Dynamically." << endl;
    Zombie *zombie = newZombie("Heap");
    zombie->announce();
    delete zombie;
    cout << endl;
    cout << "[randomChump] Using zombie on the stack." << endl;
    randomChump("Stack");
    return (0);
}
