/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:46:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/21 18:36:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
    std::cout << "Dog Default Constructor called.\n";
    type = "Dog";
    brain = new Brain();
    brain->addIdea("I want some bone snack!");
}

Dog::Dog(const Dog &dog) : Animal()
{
    std::cout << "Dog Copy Constructor called.\n";
    type = dog.type;
    brain = new Brain(*dog.brain);
}
Dog::~Dog()
{
    std::cout << "Dog Destructor called.\n";
    delete brain;
}
Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Dog Assignment Operator called.\n";
    type = dog.type;
    brain = new Brain(*dog.brain);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks!\n";
}

Brain *Dog::getBrain() const
{
    return this->brain;
}
