/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:30:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 15:23:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void leaks()
{
    system("leaks league_of_sorcerers");
}

int main()
{
    atexit(leaks);

    {
        std::cout << "Test 0" << std::endl;

        IMateriaSource *src = new MateriaSource();

        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me");

        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);

        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << std::endl;

    {
        std::cout << "Test 0" << std::endl;

        IMateriaSource *src = new MateriaSource();

        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        delete src;
    }
    return 0;
}