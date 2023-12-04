/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:57:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/04 13:49:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    {
        std::cout << "[SERIALIZATION]";

        // 2023->0111 11100111, 12->1100, 3->0011
        Data *data = new Data(2023, 12, 3);
        std::cout << "\noriginal addr:\t\t" << data;
        std::cout << "\noriginal data:\t\t" << *data << '\n';

        uintptr_t ptr = Serializer::serialize(data);
        std::cout << "\nserialized addr:\t" << ptr;
        std::cout << "\nserialized data :\t";
        char *temp = reinterpret_cast<char *>(ptr);
        for (size_t i = 0; i < sizeof(Data); i++)
            std::cout << (int)temp[i] << ' ';
        std::cout << '\n';

        Data *dptr = Serializer::deserialize(ptr);
        std::cout << "\ndeserialized address:\t" << dptr;
        std::cout << "\ndeserialized data:\t" << *dptr << '\n';

        delete data;
    }

    return 0;
}