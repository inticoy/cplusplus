/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:51:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/10 20:47:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException() : msg("grade_too_high")
{
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
    return msg.c_str();
}

Form::GradeTooLowException::GradeTooLowException() : msg("grade_too_low")
{
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Form::GradeTooLowException::what() const throw()
{
    return msg.c_str();
}

Form::Form()
    : name("default"), minSignGrade(150), minExeGrade(150), isSigned(false)
{
}

Form::Form(const Form &f)
    : name(f.name), minSignGrade(f.minSignGrade), minExeGrade(f.minExeGrade),
      isSigned(false)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &f)
{
}

const std::string &Form::getName() const
{
    return name;
}
const unsigned char &Form::getMinSignGrade() const
{
    return minSignGrade;
}

const unsigned char &Form::getMinExeGrade() const
{
    return minExeGrade;
}

const bool &Form::getIsSigned() const
{
    return isSigned;
}

void Form::beSigned(const Bureaucrat &b) throw(GradeTooLowException)
{
    if (b.getGrade() > minSignGrade)
    {
        throw(GradeTooLowException());
    }
    else
    {
        isSigned = true;
    }
}