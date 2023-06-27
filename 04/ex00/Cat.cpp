/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:42:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 21:17:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat Default Constructor called.\n";
}

Cat::Cat(const Cat &cat) : Animal()
{
    type = cat.type;
    std::cout << "Cat Copy Constructor called.\n";
}
Cat::~Cat()
{
    std::cout << "Cat Destructor called.\n";
}
Cat &Cat::operator=(const Cat &cat)
{
    type = cat.type;
    std::cout << "Cat Assignment Operator called.\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows~\n";
}