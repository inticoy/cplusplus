/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:26:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 16:47:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        const Animal *cat1 = new Cat();
        const Animal *dog1 = new Dog();

        std::cout << std::endl;

        const Animal *cat2 = new Cat(*((Cat *)cat1));
        const Animal *dog2 = new Dog(*((Dog *)dog1));

        std::cout << std::endl;

        cat1->makeSound();
        cat2->makeSound();
        dog1->makeSound();
        dog2->makeSound();

        std::cout << std::endl;

        std::cout << "[Dog1]" << std::endl;
        ((Dog *)dog1)->getBrain()->add_idea("I'm a dog.");
        ((Dog *)dog1)->getBrain()->add_idea("I'm hungry.");
        ((Dog *)dog1)->getBrain()->add_idea("I'm tired.");
        ((Dog *)dog1)->getBrain()->del_idea();
        ((Dog *)dog1)->getBrain()->print_ideas();

        std::cout << std::endl;

        delete cat1;
        delete cat2;

        std::cout << std::endl;

        delete dog1;
        delete dog2;
    }

    return 0;
}

// void f();
// atexit(f);
// void f()
// {
//     system("leaks i_dont_want_to_set_the_world_on_fire");
// }
