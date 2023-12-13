/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:50:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/13 20:37:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) { (void)other; }

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        (void)other;
    return *this;
}

// !!
#include <iostream>
int RPN::calculate(const std::string &expr) throw(std::exception)
{
    std::vector<std::string> splitVector = split(expr);
    std::vector<std::string>::iterator it = splitVector.begin();
    std::vector<Token> tokenVector;
    while (it != splitVector.end())
        tokenVector.push_back(Token(*it++));

    std::stack<int> memory;
    std::vector<Token>::iterator iter = tokenVector.begin();
    while (iter != tokenVector.end())
    {
        Token curr = *iter;
        int left, right;
        if (curr.getType() & RPN::NUM)
            memory.push(curr.getNumber());
        else if (curr.getType() == RPN::ADD)
        {
            right = memory.top();
            memory.pop();
            left = memory.top();
            memory.pop();
            memory.push(left + right);
        }
        else if (curr.getType() == RPN::SUB)
        {
            right = memory.top();
            memory.pop();
            left = memory.top();
            memory.pop();
            memory.push(left - right);
        }
        else if (curr.getType() == RPN::MUL)
        {
            right = memory.top();
            memory.pop();
            left = memory.top();
            memory.pop();
            memory.push(left * right);
        }
        else if (curr.getType() == RPN::DIV)
        {
            right = memory.top();
            memory.pop();
            left = memory.top();
            memory.pop();
            memory.push(left / right);
        }
        iter++;
    }
    return memory.top();
}

std::vector<std::string> RPN::split(const std::string &str)
{
    std::vector<std::string> vec;
    std::stringstream ss(str);
    std::string section;
    while (std::getline(ss, section, ' '))
    {
        std::stringstream sector(section);
        std::string trimmed;
        sector >> trimmed;
        vec.push_back(trimmed);
    }
    return vec;
}

RPN::tokenType_t RPN::Token::getType() const { return type; }

const int &RPN::Token::getNumber() const { return number; }