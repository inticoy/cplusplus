/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cadet.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:33:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/07/02 15:35:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CADET_HPP
#define CADET_HPP

#include "Animal.hpp"

class Cadet
{
  private:
    Animal *animals[100];

  public:
    Cadet();
    Cadet(const Cadet &cadet);
    ~Cadet();
    Cadet &operator=(const Cadet *cadet);
};

#endif
