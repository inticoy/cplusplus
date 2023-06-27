/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:26:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 21:24:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
    {
        std::cout << "# Right Animal" << std::endl;

        const Animal *meta = new Animal();
        const Animal *i = new Cat();
        const Animal *j = new Dog();

        std::cout << std::endl;

        meta->makeSound();
        i->makeSound();
        j->makeSound();

        std::cout << std::endl;

        delete meta;
        delete i;
        delete j;
    }

    std::cout << std::endl;

    {
        std::cout << "# Wrong Animal" << std::endl;

        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *j = new WrongDog();
        const WrongAnimal *i = new WrongCat();

        std::cout << std::endl;

        meta->makeSound();
        i->makeSound();
        j->makeSound();

        std::cout << std::endl;

        delete meta;
        delete i;
        delete j;
    }
    return 0;
}