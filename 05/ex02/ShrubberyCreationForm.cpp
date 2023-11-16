/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/16 22:04:41 by gyoon            ###   ########.fr       */
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
    target = scf.target;
    return (*this);
}

bool ShrubberyCreationForm::execute(const Bureaucrat &e) const
    throw(GradeTooLowException)
{
    if (!this->getIsSigned())
    {
        return false;
    }
    else if (e.getGrade() > this->getMinExeGrade())
    {
        throw(GradeTooLowException());
    }
    else
    {
        std::fstream fs;

        fs.open(target + "_shrubbery", std::ios::out | std::ios::trunc);

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
        return true;
    }
}
