/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Derived.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:07:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/03 22:08:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DERIVED_HPP
#define DERIVED_HPP

#include "Base.hpp"

class A : public Base
{
public:
    virtual ~A(){};
};

class B : public Base
{
public:
    virtual ~B(){};
};

class C : public Base
{
public:
    virtual ~C(){};
};

#endif