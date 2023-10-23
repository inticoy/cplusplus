/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:26:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 22:26:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        std::cout << "Test 0" << std::endl;

        // const Animal *animal = new Animal();
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
        dog1->addIdea("I'm a dog.");
        dog1->addIdea("I'm hungry.");
        dog1->addIdea("I'm tired.");
        dog1->delIdea();
        dog1->printIdeas();

        std::cout << std::endl;

        std::cout << "[Dog3]" << std::endl;
        const Animal *dog3 = new Dog(*((Dog *)dog1));
        dog3->addIdea("Hi my friend!");
        dog3->printIdeas();

        std::cout << std::endl;

        delete cat1;
        delete cat2;

        std::cout << std::endl;

        delete dog1;
        delete dog2;
        delete dog3;
    }

    std::cout << std::endl;

    {
        std::cout << "Test 1" << std::endl;

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
            animals[i]->printIdeas();
        }

        std::cout << std::endl;

        for (int i = 0; i < animalCnt; i++)
        {
            delete animals[i];
        }
    }
    return 0;
}
