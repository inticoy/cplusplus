/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:48:09 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 13:43:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <sstream>

Form::GradeTooHighException::GradeTooHighException() throw()
    : msg("grade is too high")
{
}

Form::GradeTooHighException::GradeTooHighException(int grade) throw()
{
    std::stringstream ss;
    ss << grade;
    msg = "grade " + ss.str() + " is too high";
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
    return msg.c_str();
}

Form::GradeTooLowException::GradeTooLowException() throw()
    : msg("grade is too low")
{
}

Form::GradeTooLowException::GradeTooLowException(int grade) throw()
{
    std::stringstream ss;
    ss << grade;
    msg = "grade " + ss.str() + " is too low";
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Form::GradeTooLowException::what() const throw()
{
    return msg.c_str();
}

Form::DoubleSignException::DoubleSignException() throw()
    : msg("form is already signed")
{
}

Form::DoubleSignException::~DoubleSignException() throw()
{
}

const char *Form::DoubleSignException::what() const throw()
{
    return msg.c_str();
}
