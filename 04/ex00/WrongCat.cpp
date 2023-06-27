/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:42:38 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 21:25:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    type = "Cat";
    std::cout << "WrongCat Default Constructor called.\n";
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal()
{
    type = cat.type;
    std::cout << "WrongCat Copy Constructor called.\n";
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called.\n";
}
WrongCat &WrongCat::operator=(const WrongCat &cat)
{
    type = cat.type;
    std::cout << "WrongCat Assignment Operator called.\n";
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Cat meows~\n";
}