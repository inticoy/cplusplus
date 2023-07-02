/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:26:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/07/02 14:17:25 by gyoon            ###   ########.fr       */
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

    return 0;
}
