/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:57:04 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 18:32:37 by gyoon            ###   ########.fr       */
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
                       unsigned char grade) throw(GradeTooHighException,
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

const unsigned char &Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::setGrade(unsigned char grade) throw(GradeTooHighException,
                                                     GradeTooLowException)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
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
        throw GradeTooHighException();
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
        throw GradeTooLowException();
    }
    else
    {
        ++grade;
    }
}

void Bureaucrat::signForm(AForm &f) const
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

void Bureaucrat::executeForm(const AForm &f) const
{
    try
    {
        f.execute(*this);
        std::cout << name << " executed '" << f.getName() << "'\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << name << " can't execute '" << f.getName() << "' because ";
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.name << ", bureaucrat has grade " << static_cast<int>(b.grade);
    return os;
}
