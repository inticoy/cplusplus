/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:51:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 19:20:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("default"), minSignGrade(150), minExeGrade(150), isSigned(false)
{
}

AForm::AForm(const AForm &f)
    : name(f.name), minSignGrade(f.minSignGrade), minExeGrade(f.minExeGrade),
      isSigned(false)
{
}

AForm::AForm(const std::string &name)
    : name(name), minSignGrade(150), minExeGrade(150), isSigned(false)
{
}

AForm::AForm(const std::string &name, unsigned char minSignGrade,
             unsigned char minExeGrade) throw(GradeTooHighException,
                                              GradeTooLowException)
    : name(name), minSignGrade(minSignGrade), minExeGrade(minExeGrade),
      isSigned(false)
{
    if (minSignGrade < 1 || minExeGrade < 1)
    {
        throw GradeTooHighException();
    }
    else if (minSignGrade > 150 || minExeGrade > 150)
    {
        throw GradeTooLowException();
    }
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &f)
{
    isSigned = f.isSigned;
    return *this;
}

const std::string &AForm::getName() const
{
    return name;
}

const unsigned char &AForm::getMinSignGrade() const
{
    return minSignGrade;
}

const unsigned char &AForm::getMinExeGrade() const
{
    return minExeGrade;
}

const bool &AForm::getIsSigned() const
{
    return isSigned;
}

void AForm::setIsSigned(bool isSigned)
{
    this->isSigned = isSigned;
}

void AForm::beSigned(const Bureaucrat &b) throw(GradeTooLowException,
                                                DoubleSignException)
{
    if (isSigned)
    {
        throw DoubleSignException();
    }
    else if (b.getGrade() > minSignGrade)
    {
        throw GradeTooLowException();
    }
    else
    {
        isSigned = true;
    }
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "A AForm named '" << f.name;
    os << (f.isSigned ? "' is signed." : "' is not signed.");
    os << "\nIt needs grade ";
    os << static_cast<int>(f.minSignGrade) << " to sign, and grade ";
    os << static_cast<int>(f.minExeGrade) << " to execute.";
    return (os);
}