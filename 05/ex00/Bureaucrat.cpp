/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/05 21:50:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : msg("grade_too_high")
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : msg("grade_too_low")
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return msg.c_str();
}

Bureaucrat::Bureaucrat() : name("Gil-Dong, Hong"), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade)
{
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned char grade)
    : name(name), grade(grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    grade = b.grade;
    return (*this);
}

const std::string &Bureaucrat::getName()
{
    return name;
}

const unsigned char &Bureaucrat::getGrade()
{
    return grade;
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
    if (grade == 1)
        throw(GradeTooHighException());
    else
        --grade;
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
    if (grade == 150)
        throw(GradeTooLowException());
    else
        ++grade;
}