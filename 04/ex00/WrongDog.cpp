/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:46:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 20:53:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

#include <iostream>

WrongDog::WrongDog() : WrongAnimal()
{
    std::cout << "WrongDog Default Constructor called.\n";
    type = "Dog";
}

WrongDog::WrongDog(const WrongDog &dog) : WrongAnimal()
{
    std::cout << "WrongDog Copy Constructor called.\n";
    type = dog.type;
}
WrongDog::~WrongDog()
{
    std::cout << "WrongDog Destructor called.\n";
}
WrongDog &WrongDog::operator=(const WrongDog &dog)
{
    std::cout << "WrongDog Assignment Operator called.\n";
    type = dog.type;
    return *this;
}

void WrongDog::makeSound() const
{
    std::cout << "Dog barks!\n";
}