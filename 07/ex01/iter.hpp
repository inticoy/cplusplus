/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:59:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 17:17:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T> void iter(T *arr, size_t len, void (*f)(T))
{
    for (size_t i = 0; i < len; i++)
    {
        f(arr[i]);
    }
}

template <typename T> void println(T t)
{
    std::cout << t << std::endl;
}

#endif