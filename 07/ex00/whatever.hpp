/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:36:35 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 16:56:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> const T &min(const T &a, const T &b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <typename T> const T &max(const T &a, const T &b)
{
    if (a > b)
        return a;
    else
        return b;
}

#endif
