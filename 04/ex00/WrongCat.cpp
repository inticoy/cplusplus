/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:42:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/07/01 19:12:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat Default Constructor called.\n";
    type = "Cat";
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal()
{
    std::cout << "WrongCat Copy Constructor called.\n";
    type = cat.type;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called.\n";
}
WrongCat &WrongCat::operator=(const WrongCat &cat)
{
    std::cout << "WrongCat Assignment Operator called.\n";
    type = cat.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Cat meows~\n";
}