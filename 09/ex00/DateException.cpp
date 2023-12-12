/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:45:50 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/12 22:54:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::WrongFormatException::WrongFormatException() : msg("wrong date format") {}

Date::WrongFormatException::~WrongFormatException() throw() {}

const char *Date::WrongFormatException::what() const throw()
{
    return msg.c_str();
}