/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:57:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 22:15:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    {
        std::cout << "[SERIALIZATION]\n";

        // 2023->0111 11100111, 12->1100, 3->0011
        Data *data = new Data(2023, 12, 3);
        std::cout << "original addr:\t\t" << data << '\n';
        std::cout << "original data:\t\t" << *data << '\n' << '\n';

        uintptr_t ptr = Serializer::serialize(data);
        std::cout << "serialized addr:\t" << ptr;
        std::cout << "\nserialized data :\t";
        char *temp = reinterpret_cast<char *>(ptr);
        for (size_t i = 0; i < sizeof(Data); i++)
            std::cout << (int)temp[i] << ' ';
        std::cout << '\n' << '\n';

        Data *dptr = Serializer::deserialize(ptr);
        std::cout << "deserialized address:\t" << dptr << '\n';
        std::cout << "deserialized data:\t" << *dptr << '\n';

        delete data;
    }

    return 0;
}