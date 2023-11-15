/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/15 21:58:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : msg("grade is too high")
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return msg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : msg("grade is too low")
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return msg.c_str();
}

Bureaucrat::Bureaucrat() : name("Gil-Dong"), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade)
{
}

Bureaucrat::Bureaucrat(const std::string &name) : name(name), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name,
                       unsigned char grade) throw(GradeTooHighException,
                                                  GradeTooLowException)
    : name(name)
{
    if (grade < 1)
    {
        throw(GradeTooHighException());
    }
    else if (grade > 150)
    {
        throw(GradeTooLowException());
    }
    else
    {
        this->grade = grade;
    }
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    grade = b.grade;
    return (*this);
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

const unsigned char &Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
    if (grade == 1)
    {
        throw(GradeTooHighException());
    }
    else
    {
        --grade;
    }
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
    if (grade == 150)
    {
        throw(GradeTooLowException());
    }
    else
    {
        ++grade;
    }
}

void Bureaucrat::signForm(Form &f) const
{
    try
    {
        if (f.beSigned(*this))
        {
            std::cout << name << " signed '" << f.getName() << "'\n";
        }
        else
        {
            std::cout << name << " couldn't sign '" << f.getName();
            std::cout << "' because form is already signed.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << name << " couldn't sign '" << f.getName() << "' because ";
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.name << ", bureaucrat has grade " << static_cast<int>(b.grade);
    return os;
}
