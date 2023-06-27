/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:42:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 21:01:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    type = "Cat";
    std::cout << "Cat Default Constructor called.\n";
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal()
{
    type = cat.type;
    std::cout << "Cat Copy Constructor called.\n";
}
WrongCat::~WrongCat()
{
    std::cout << "Cat Destructor called.\n";
}
WrongCat &WrongCat::operator=(const WrongCat &cat)
{
    std::cout << "Cat Assignment Operator called.\n";
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Cats meow\n";
}