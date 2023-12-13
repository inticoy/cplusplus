/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:48:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/13 20:38:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

class RPN
{
public:
    typedef enum tokenType
    {
        UNEXPECTED = 0x000,
        NUM = 0x011,
        OPERATOR = 0x100,
        ADD = 0x102,
        SUB = 0x104,
        MUL = 0x106,
        DIV = 0x108,
    } tokenType_t;

    class Token
    {
    public:
        class UnexpectedTokenException : public std::exception
        {
        public:
            UnexpectedTokenException();
            virtual ~UnexpectedTokenException() throw();
            const char *what() const throw();

        private:
            std::string msg;
        };

        Token();
        Token(const std::string &str) throw(UnexpectedTokenException);
        Token(const Token &other);
        virtual ~Token();
        Token &operator=(const Token &other);

        static int stoi(const std::string &str) throw(UnexpectedTokenException);

        tokenType_t getType() const;
        const int &getNumber() const;

    private:
        tokenType_t type;
        int number;
    };

    RPN();
    RPN(const RPN &other);
    ~RPN();
    RPN &operator=(const RPN &other);

    static int calculate(const std::string &expr) throw(std::exception);

private:
    static std::vector<std::string> split(const std::string &str);
};

#endif