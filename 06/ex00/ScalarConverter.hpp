/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:23:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 22:25:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter
{
  public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &sc);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &sc);

  private:
};

#endif