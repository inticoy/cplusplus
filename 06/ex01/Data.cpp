/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:54:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 14:57:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : number(0)
{
}

Data::Data(const Data &other) : number(other.number)
{
}

Data::Data(int number) : number(number)
{
}

Data::~Data()
{
}

Data &Data::operator=(const Data &other)
{
    if (this != &other)
    {
        number = other.number;
    }
    return *this;
}
