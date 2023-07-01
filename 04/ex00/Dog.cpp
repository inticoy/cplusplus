/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:46:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/07/01 19:12:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
    std::cout << "Dog Default Constructor called.\n";
    type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal()
{
    std::cout << "Dog Copy Constructor called.\n";
    type = dog.type;
}
Dog::~Dog()
{
    std::cout << "Dog Destructor called.\n";
}
Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Dog Assignment Operator called.\n";
    type = dog.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks!\n";
}