/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:27:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 22:25:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  protected:
    std::string type;

  public:
    Animal();
    Animal(const Animal &a);
    virtual ~Animal();
    Animal &operator=(const Animal &a);

    virtual void makeSound() const = 0;
    virtual void addIdea(const std::string &idea) const = 0;
    virtual void delIdea() const = 0;
    virtual void printIdeas() const = 0;

    void setType(std::string type);
    const std::string &getType() const;
};

#endif
