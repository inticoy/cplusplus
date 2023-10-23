/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:26:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 20:53:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void f()
// {
//     system("leaks i_dont_want_to_set_the_world_on_fire");
// }

int main()
{
    // atexit(f);
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
        ((Dog *)dog1)->getBrain()->addIdea("I'm a dog.");
        ((Dog *)dog1)->getBrain()->addIdea("I'm hungry.");
        ((Dog *)dog1)->getBrain()->addIdea("I'm tired.");
        ((Dog *)dog1)->getBrain()->delIdea();
        ((Dog *)dog1)->getBrain()->printIdeas();

        std::cout << std::endl;

        std::cout << "[Dog3]" << std::endl;
        const Animal *dog3 = new Dog(*((Dog *)dog1));
        ((Dog *)dog3)->getBrain()->addIdea("Hi my friend!");
        ((Dog *)dog3)->getBrain()->printIdeas();

        std::cout << std::endl;

        delete cat1;
        delete cat2;

        std::cout << std::endl;

        delete dog1;
        delete dog2;
        delete dog3;
    }

    return 0;
}