/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:58:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/13 20:38:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::Token::UnexpectedTokenException::UnexpectedTokenException()
    : msg("unexpected token")
{
}
RPN::Token::UnexpectedTokenException::~UnexpectedTokenException() throw() {}
const char *RPN::Token::UnexpectedTokenException::what() const throw()
{
    return msg.c_str();
}