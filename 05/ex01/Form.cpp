/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:51:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/14 19:25:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

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

Form::Form(const std::string &name, const unsigned char &minSignGrade,
           const unsigned char &minExeGrade)
    : name(name), minSignGrade(minSignGrade), minExeGrade(minExeGrade),
      isSigned(false)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &f)
{
    isSigned = f.isSigned;
    return (*this);
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

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "A form named " << f.name;
    os << (f.isSigned ? " is signed." : "is not signed.");
    os << "\nIt needs grade ";
    os << static_cast<int>(f.minSignGrade) << " to sign, and grade ";
    os << static_cast<int>(f.minExeGrade) << " to execute.";
    return (os);
}