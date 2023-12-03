/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:47:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 22:13:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

// /* real serializer */
// uintptr_t Serializer::serialize(Data *ptr)
// {
//     std::cout << "Serializing Data Class in " << ptr << '\n';
//     char *serialized = new char[sizeof(Data)];
//     char *readByByte = reinterpret_cast<char *>(ptr);
//     for (size_t i = 0; i < sizeof(Data); i++)
//         serialized[i] = readByByte[i];
//     return reinterpret_cast<uintptr_t>(serialized);
// }

// Data *Serializer::deserialize(uintptr_t raw)
// {
//     std::cout << "Deserializing Data Class in ";
//     std::cout << reinterpret_cast<void *>(raw) << '\n';
//     Data *deserialized = new Data;
//     char *dataInByte = reinterpret_cast<char *>(deserialized);
//     char *serialized = reinterpret_cast<char *>(raw);
//     for (size_t i = 0; i < sizeof(Data); i++)
//         dataInByte[i] = serialized[i];
//     return deserialized;
// }

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer::~Serializer() {}
Serializer &Serializer::operator=(const Serializer &other)
{
    if (this != &other)
        (void)other;
    return *this;
}
