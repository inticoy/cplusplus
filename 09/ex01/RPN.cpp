/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:50:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/16 19:59:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::EmptyStackException::EmptyStackException() : msg("empty stack") {}
RPN::EmptyStackException::~EmptyStackException() throw() {}
const char *RPN::EmptyStackException::what() const throw()
{
    return msg.c_str();
}
RPN::TooManyNumbersException::TooManyNumbersException()
    : msg("too many numbers")
{
}
RPN::TooManyNumbersException::~TooManyNumbersException() throw() {}
const char *RPN::TooManyNumbersException::what() const throw()
{
    return msg.c_str();
}

RPN::RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN::~RPN() {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        (void)other;
    return *this;
}

int RPN::calculate(const std::string &expr) throw(std::exception)
{
    std::list<std::string> splitList = split(expr);
    std::list<std::string>::iterator it = splitList.begin();

    std::list<Token> tokenList;
    while (it != splitList.end())
        tokenList.push_back(Token(*it++));

    std::stack<int> memory;
    std::list<Token>::iterator iter = tokenList.begin();
    while (iter != tokenList.end())
    {
        Token curr = *iter;
        int left, right;
        if (curr.getType() & RPN::NUM)
            memory.push(curr.getNumber());
        else if (curr.getType() & RPN::OPERATOR)
        {
            if (memory.empty())
                throw EmptyStackException();
            right = memory.top();
            memory.pop();

            if (memory.empty())
                throw EmptyStackException();
            left = memory.top();
            memory.pop();

            if (curr.getType() == RPN::ADD)
                memory.push(left + right);
            else if (curr.getType() == RPN::SUB)
                memory.push(left - right);
            else if (curr.getType() == RPN::MUL)
                memory.push(left * right);
            else if (curr.getType() == RPN::DIV)
                memory.push(left / right);
        }
        iter++;
    }
    if (memory.size() != 1)
        throw TooManyNumbersException();
    return memory.top();
}

std::list<std::string> RPN::split(const std::string &str)
{
    std::list<std::string> lst;
    std::stringstream ss(str);
    std::string section;
    while (std::getline(ss, section, ' '))
    {
        std::stringstream sector(section);
        std::string trimmed;
        sector >> trimmed;
        if (trimmed.size())
            lst.push_back(trimmed);
    }
    return lst;
}

RPN::tokenType_t RPN::Token::getType() const { return type; }
const int &RPN::Token::getNumber() const { return number; }