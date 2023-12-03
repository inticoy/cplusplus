/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:54:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 21:14:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : x(0), y(0), z(0) {}

Data::Data(const Data &other) : x(other.x), y(other.y), z(other.z) {}

Data::Data(int x, int y, int z) : x(x), y(y), z(z) {}

Data::~Data() {}

Data &Data::operator=(const Data &other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

const int &Data::getX() const { return x; }
const int &Data::getY() const { return y; }
const int &Data::getZ() const { return z; }

std::ostream &operator<<(std::ostream &os, const Data &d)
{
    os << "x->" << d.getX() << ", y->" << d.getY() << ", z->" << d.getZ();
    return os;
}
