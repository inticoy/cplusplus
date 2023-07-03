/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:26:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/07/03 15:32:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        // const Animal *animal = new Animal();
        const Animal *cat = new Cat();
        const Animal *dog = new Dog();

        std::cout << std::endl;

        // animal->makeSound();
        cat->makeSound();
        dog->makeSound();

        std::cout << std::endl;

        delete cat;
        delete dog;
    }

    std::cout << std::endl;

    {
        const int animalCnt = 10;
        Animal *animals[animalCnt];
        for (int i = 0; i < animalCnt / 2; i++)
        {
            animals[i] = new Cat();
        }

        std::cout << std::endl;

        for (int i = 0; i < animalCnt / 2; i++)
        {
            animals[i + animalCnt / 2] = new Dog();
        }

        std::cout << std::endl;

        for (int i = 0; i < animalCnt; i++)
        {
            animals[i]->makeSound();
        }

        std::cout << std::endl;

        for (int i = 0; i < animalCnt; i++)
        {
            delete animals[i];
        }
    }

    return 0;
}
