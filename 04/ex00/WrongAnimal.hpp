/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:27:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/27 21:23:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
  protected:
    std::string type;

  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &a);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &a);

    void makeSound() const;

    void setType(std::string type);
    const std::string &getType() const;
};

#endif
