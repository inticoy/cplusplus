/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:22:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/10 13:41:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
public:
    Array() : arr(new T[0]), len(0) {}
    Array(unsigned int n) : arr(new T[n]), len(n) {}
    Array(const Array &other) : arr(new T[other.len]), len(other.len)
    {
        for (size_t i = 0; i < len; i++)
            arr[i] = other.arr[i];
    }
    ~Array() { delete[] arr; }

    Array &operator=(const Array &other)
    {
        if (this != *other)
        {
            delete arr;
            arr = new T[other.len];
            len = other.len;
            for (size_t i = 0; i < len; i++)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    T &operator[](size_t idx) throw(std::exception)
    {
        if (idx < 0 || idx >= len)
            throw std::out_of_range("out of range");
        else
            return arr[idx];
    }

    size_t size() const { return len; }

private:
    T *arr;
    size_t len;
};

#endif