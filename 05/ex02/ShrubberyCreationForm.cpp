/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/18 19:24:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137), target("temp")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
    : AForm(scf.getName(), scf.getMinSignGrade(), scf.getMinExeGrade()),
      target(scf.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &scf)
{
    if (this != &scf)
    {
        this->setIsSigned(scf.getIsSigned());
        target = scf.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &e) const
    throw(GradeTooLowException, NotSignedException)
{
    if (!this->getIsSigned())
    {
        throw NotSignedException();
    }
    else if (e.getGrade() > this->getMinExeGrade())
    {
        throw GradeTooLowException();
    }
    else
    {
        std::fstream fs;
        fs.open(target + "_shrubbery", std::ios::out | std::ios::trunc);
        if (!fs.is_open())
        {
            throw FileCreateFailException();
        }
        fs << "                                            .\n";
        fs << "                                   .         ;\n";
        fs << "      .              .              ;%%     ;;\n";
        fs << "        ,           ,                :;%%  %%;\n";
        fs << "         :         ;                   :;%%;'     .,\n";
        fs << ",.        %%;     %%;            ;        %%;'    ,;\n";
        fs << "  ;       ;%%;  %%%%;        ,     %%;    ;%%;    ,%%'\n";
        fs << "   %%;       %%;%%;      ,  ;       %%;  ;%%;   ,%%;'\n";
        fs << "    ;%%;      %%;        ;%%;        %% ;%%;  ,%%;'\n";
        fs << "     `%%;.     ;%%;     %%;'         `;%%%%;.%%;'\n";
        fs << "      `:;%%.    ;%%%%. %%@;        %%; ;@%%;%%'\n";
        fs << "         `:%%;.  :;bd%%;          %%;@%%;'\n";
        fs << "           `@%%:.  :;%%.         ;@@%%;'\n";
        fs << "             `@%%.  `;@%%.      ;@@%%;\n";
        fs << "               `@%%%%. `@%%%%    ;@@%%;\n";
        fs << "                 ;@%%. :@%%%%  %%@@%%;\n";
        fs << "                   %%@bd%%%%%%bd%%%%:;\n";
        fs << "                     #@%%%%%%%%%%:;;\n";
        fs << "                     %%@@%%%%%%::;\n";
        fs << "                     %%@@@%%(o);  . '\n";
        fs << "                     %%@@@o%%;:(.,'\n";
        fs << "                 `.. %%@@@o%%::;\n";
        fs << "                    `)@@@o%%::;\n";
        fs << "                     %%@@(o)::;\n";
        fs << "                    .%%@@@@%%::;\n";
        fs << "                    ;%%@@@@%%::;.\n";
        fs << "                   ;%%@@@@%%%%:;;;.\n";
        fs << "               ...;%@@@@@%%:;;;;,..\n";
        fs.close();
    }
}
