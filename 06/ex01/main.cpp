/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:57:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 15:06:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    {
        Data *data = new Data(42);
        uintptr_t ptr = Serializer::serialize(data);
        Data *dptr = Serializer::deserialize(ptr);

        std::cout << "original:\t" << data << std::endl;
        std::cout << "serialized:\t" << ptr << std::endl;
        std::cout << "deserialized:\t" << dptr << std::endl;

        delete data;
    }

    return 0;
}