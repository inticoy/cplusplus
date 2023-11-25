/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:22:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 19:23:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdint>
#include <exception>
#include <stdexcept>

template <typename T> class Array
{
  public:
    Array() : arr(new T[0]), len(0)
    {
    }

    Array(const Array &other) : arr(0), len(0)
    {
        (void)other;
    }

    Array(unsigned int n) : arr(new T[n]), len(n)
    {
    }

    Array &operator=(const Array &other)
    {
        if (this != *other)
        {
            (void)other;
        }
        return *this;
    }

    T &operator[](long long idx) throw(std::exception)
    {
        if (len == 0)
        {
            throw std::out_of_range("out of range");
        }
        else if (idx == -1)
        {
            return arr[len - 1];
        }
        else
        {
            return arr[idx];
        }
    }

    ~Array()
    {
        delete[] arr;
    }

    size_t size() const
    {
        return len;
    }

  private:
    T *arr;
    size_t len;
};

#endif