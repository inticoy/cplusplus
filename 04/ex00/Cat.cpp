/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:42:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/07/01 19:11:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal()
{
    std::cout << "Cat Default Constructor called.\n";
    type = "Cat";
}

Cat::Cat(const Cat &cat) : Animal()
{
    std::cout << "Cat Copy Constructor called.\n";
    type = cat.type;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor called.\n";
}
Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat Assignment Operator called.\n";
    type = cat.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows~\n";
}