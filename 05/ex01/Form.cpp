/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:51:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 16:08:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("untitled"), minSignGrade(150), minExeGrade(150), isSigned(false)
{
}

Form::Form(const Form &other)
    : name(other.name), minSignGrade(other.minSignGrade),
      minExeGrade(other.minExeGrade), isSigned(other.isSigned)
{
}

Form::Form(const std::string &name)
    : name(name), minSignGrade(150), minExeGrade(150), isSigned(false)
{
}

Form::Form(const std::string &name, int minSignGrade,
           int minExeGrade) throw(GradeTooHighException, GradeTooLowException)
    : name(name), minSignGrade(minSignGrade), minExeGrade(minExeGrade),
      isSigned(false)
{
    if (minSignGrade < 1)
        throw GradeTooHighException(minSignGrade);
    else if (minExeGrade < 1)
        throw GradeTooHighException(minExeGrade);
    else if (minSignGrade > 150)
        throw GradeTooLowException(minSignGrade);
    else if (minExeGrade > 150)
        throw GradeTooLowException(minExeGrade);
}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

const std::string &Form::getName() const { return name; }

const int &Form::getMinSignGrade() const { return minSignGrade; }

const int &Form::getMinExeGrade() const { return minExeGrade; }

const bool &Form::getIsSigned() const { return isSigned; }

void Form::beSigned(const Bureaucrat &signer) throw(GradeTooLowException,
                                                    DoubleSignException)
{
    if (isSigned)
        throw DoubleSignException();
    else if (signer.getGrade() > minSignGrade)
        throw GradeTooLowException(signer.getGrade());
    else
        isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "A form named '" << f.getName();
    os << (f.getIsSigned() ? "' is signed." : "' is not signed.") << '\n';
    os << "It needs grade " << f.getMinSignGrade() << " to sign, and grade ";
    os << f.getMinExeGrade() << " to execute.";
    return (os);
}