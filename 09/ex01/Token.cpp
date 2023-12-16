/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:48:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/16 19:58:25 by gyoon            ###   ########.fr       */
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

RPN::Token::Token() : type(RPN::UNEXPECTED), number(0) {}
RPN::Token::Token(const std::string &str) throw(UnexpectedTokenException)
{
    number = 0;
    if (str == "+")
        type = RPN::ADD;
    else if (str == "-")
        type = RPN::SUB;
    else if (str == "*")
        type = RPN::MUL;
    else if (str == "/")
        type = RPN::DIV;
    else
    {
        type = RPN::NUM;
        number = stoi(str);
        if (number < 0 || number > 9)
            throw UnexpectedTokenException();
    }
}
RPN::Token::Token(const Token &other) : type(other.type), number(other.number)
{
}
RPN::Token::~Token() {}
RPN::Token &RPN::Token::operator=(const Token &other)
{
    if (this != &other)
    {
        type = other.type;
        number = other.number;
    }
    return *this;
}

int RPN::Token::stoi(const std::string &s) throw(UnexpectedTokenException)
{
    std::stringstream ss(s);
    int i;
    ss >> i;
    if (ss.fail() || ss.bad() || !ss.eof())
        throw UnexpectedTokenException();
    return i;
}