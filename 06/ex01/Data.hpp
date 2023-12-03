/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:51:56 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 18:51:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
class Data
{
public:
    Data();
    Data(const Data &other);
    Data(int x, int y, int z);
    Data &operator=(const Data &other);
    ~Data();

    const int &getX() const;
    const int &getY() const;
    const int &getZ() const;

private:
    int x;
    int y;
    int z;
};

std::ostream &operator<<(std::ostream &os, const Data &d);

#endif