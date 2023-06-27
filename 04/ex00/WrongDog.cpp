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
    type = "WrongDog";
    std::cout << "WrongDog Default Constructor called.\n";
}

WrongDog::WrongDog(const WrongDog &dog) : WrongAnimal()
{
    type = dog.type;
    std::cout << "WrongDog Copy Constructor called.\n";
}
WrongDog::~WrongDog()
{
    std::cout << "WrongDog Destructor called.\n";
}
WrongDog &WrongDog::operator=(const WrongDog &dog)
{
    std::cout << "WrongDog Assignment Operator called.\n";
    return *this;
}

void WrongDog::makeSound() const
{
    std::cout << "Dogs meow\n";
}