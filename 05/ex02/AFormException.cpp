/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFormException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:15:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 13:58:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <sstream>

AForm::GradeTooHighException::GradeTooHighException() throw()
    : msg("grade is too high")
{
}

AForm::GradeTooHighException::GradeTooHighException(int grade) throw()
{
    std::stringstream ss;
    ss << grade;
    msg = "grade " + ss.str() + " is too high";
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return msg.c_str();
}

AForm::GradeTooLowException::GradeTooLowException() throw()
    : msg("grade is too low")
{
}

AForm::GradeTooLowException::GradeTooLowException(int grade) throw()
{
    std::stringstream ss;
    ss << grade;
    msg = "grade " + ss.str() + " is too low";
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return msg.c_str();
}

AForm::DoubleSignException::DoubleSignException() throw()
    : msg("AForm is already signed")
{
}

AForm::DoubleSignException::~DoubleSignException() throw()
{
}

const char *AForm::DoubleSignException::what() const throw()
{
    return msg.c_str();
}

AForm::NotSignedException::NotSignedException() throw()
    : msg("AForm is not signed")
{
}

AForm::NotSignedException::~NotSignedException() throw()
{
}

const char *AForm::NotSignedException::what() const throw()
{
    return msg.c_str();
}