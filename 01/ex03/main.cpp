/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:47:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/14 22:12:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
  {
    Weapon club = Weapon("crude spicked club");

    HumanA bob("Bob", club);  // HumanA must always be armed.
    bob.attack();
    club.set_type("some other type of club");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spicked club");

    HumanB jim("Jim");     // HumanB may not always have a Weapon.
    jim.set_weapon(club);  // try not executing this line
    jim.attack();
    club.set_type("some other type of club");
    jim.attack();
  }
  return 0;
}