/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:46:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 21:18:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog Default Constructor called.\n";
}

Dog::Dog(const Dog &dog) : Animal()
{
    type = dog.type;
    std::cout << "Dog Copy Constructor called.\n";
}
Dog::~Dog()
{
    std::cout << "Dog Destructor called.\n";
}
Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Dog Assignment Operator called.\n";
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks!\n";
}