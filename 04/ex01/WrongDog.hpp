/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:01:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 21:02:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
  public:
    WrongDog();
    WrongDog(const WrongDog &dog);
    ~WrongDog();
    WrongDog &operator=(const WrongDog &dog);

    void makeSound() const;
};

#endif