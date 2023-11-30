/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:42:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 15:24:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::GradeTooHighException::GradeTooHighException() throw()
    : msg("grade is too high")
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade) throw()
{
    std::stringstream ss;
    ss << grade;
    msg = "grade " + ss.str() + " is too high";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw()
    : msg("grade is too low")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade) throw()
{
    std::stringstream ss;
    ss << grade;
    msg = "grade " + ss.str() + " is too low";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return msg.c_str();
}
