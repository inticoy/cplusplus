/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/19 15:08:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
                       int grade) throw(GradeTooHighException,
                                        GradeTooLowException)
    : name(name)
{
    setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    grade = b.grade;
    return *this;
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

const int &Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::setGrade(int grade) throw(GradeTooHighException,
                                           GradeTooLowException)
{
    if (grade < 1)
    {
        throw GradeTooHighException(grade);
    }
    else if (grade > 150)
    {
        throw GradeTooLowException(grade);
    }
    else
    {
        this->grade = grade;
    }
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
    if (grade == 1)
    {
        throw GradeTooHighException(grade);
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
        throw GradeTooLowException(grade);
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
        f.beSigned(*this);
        std::cout << name << " signed '" << f.getName() << "'\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << name << " can't sign '" << f.getName() << "' because ";
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat has grade " << b.getGrade();
    return os;
}
