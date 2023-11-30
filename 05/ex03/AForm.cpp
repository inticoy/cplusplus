/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:51:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 16:34:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("untitled"), minSignGrade(150), minExeGrade(150), isSigned(false)
{
}

AForm::AForm(const AForm &other)
    : name(other.name), minSignGrade(other.minSignGrade),
      minExeGrade(other.minExeGrade), isSigned(other.isSigned)
{
}

AForm::AForm(const std::string &name)
    : name(name), minSignGrade(150), minExeGrade(150), isSigned(false)
{
}

AForm::AForm(const std::string &name, int minSignGrade,
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

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

const std::string &AForm::getName() const { return name; }

const int &AForm::getMinSignGrade() const { return minSignGrade; }

const int &AForm::getMinExeGrade() const { return minExeGrade; }

const bool &AForm::getIsSigned() const { return isSigned; }

void AForm::setIsSigned(bool isSigned) { this->isSigned = isSigned; }

void AForm::beSigned(const Bureaucrat &signer) throw(GradeTooLowException,
                                                     DoubleSignException)
{
    if (isSigned)
        throw DoubleSignException();
    else if (signer.getGrade() > minSignGrade)
        throw GradeTooLowException(signer.getGrade());
    else
        isSigned = true;
}

void AForm::checkRequirements(const Bureaucrat &executor) const
    throw(GradeTooLowException, NotSignedException)
{
    if (!isSigned)
        throw NotSignedException();
    else if (executor.getGrade() > minExeGrade)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "A form named '" << f.getName();
    os << (f.getIsSigned() ? "' is signed." : "' is not signed.") << '\n';
    os << "It needs grade " << f.getMinSignGrade() << " to sign, and grade ";
    os << f.getMinExeGrade() << " to execute.";
    return (os);
}