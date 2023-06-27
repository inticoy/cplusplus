/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:29:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 20:59:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type("")
{
    std::cout << "WrongAnimal Default Constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    type = a.type;
    std::cout << "WrongAnimal Copy Constructor called.\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called.\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
    std::cout << "WrongAnimal Assignment Operator called.\n";
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "hi\n";
}

void WrongAnimal::setType(std::string type)
{
    this->type = type;
}

const std::string &WrongAnimal::getType() const
{
    return type;
}
