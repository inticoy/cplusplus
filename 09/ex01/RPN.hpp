/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:48:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/12/16 19:54:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <exception>
#include <list>
#include <sstream>
#include <stack>
#include <string>

class RPN
{
public:
    typedef enum tokenType
    {
        UNEXPECTED = 0x00,
        NUM = 0x01,
        OPERATOR = 0x10,
        ADD = 0x12,
        SUB = 0x14,
        MUL = 0x16,
        DIV = 0x18,
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

    class EmptyStackException : public std::exception
    {
    public:
        EmptyStackException();
        virtual ~EmptyStackException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    class TooManyNumbersException : public std::exception
    {
    public:
        TooManyNumbersException();
        virtual ~TooManyNumbersException() throw();
        const char *what() const throw();

    private:
        std::string msg;
    };

    RPN();
    RPN(const RPN &other);
    virtual ~RPN();
    RPN &operator=(const RPN &other);

    static int calculate(const std::string &expr) throw(std::exception);
    static std::list<std::string> split(const std::string &str);
};

#endif