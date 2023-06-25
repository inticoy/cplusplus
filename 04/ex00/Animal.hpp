/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:27:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/06/25 16:34:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
  Animal();
  Animal(const Animal &a);
  ~Animal();
  Animal &operator=(const Animal &a);

  void setType(std::string type);
  std::string &getType();

protected:
  std::string type;
};

#endif
