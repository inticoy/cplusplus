/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:39:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 17:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target("noname")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other.getName(), other.getMinSignGrade(), other.getMinExeGrade()),
      target(other.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->setIsSigned(other.getIsSigned());
        target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
    throw(GradeTooLowException, NotSignedException, ExecuteFailException)
{
    checkRequirements(executor);
    std::string filename(target + "_shrubbery");
    std::fstream fs;
    fs.open(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!fs.is_open())
    {
        throw ExecuteFailException("failed to create file");
    }
    fs << "                                            ." << '\n';
    fs << "                                   .         ;" << '\n';
    fs << "      .              .              ;%%     ;;" << '\n';
    fs << "        ,           ,                :;%%  %%;" << '\n';
    fs << "         :         ;                   :;%%;'     .," << '\n';
    fs << ",.        %%;     %%;            ;        %%;'    ,;" << '\n';
    fs << "  ;       ;%%;  %%%%;        ,     %%;    ;%%;    ,%%'" << '\n';
    fs << "   %%;       %%;%%;      ,  ;       %%;  ;%%;   ,%%;'" << '\n';
    fs << "    ;%%;      %%;        ;%%;        %% ;%%;  ,%%;'" << '\n';
    fs << "     `%%;.     ;%%;     %%;'         `;%%%%;.%%;'" << '\n';
    fs << "      `:;%%.    ;%%%%. %%@;        %%; ;@%%;%%'" << '\n';
    fs << "         `:%%;.  :;bd%%;          %%;@%%;'" << '\n';
    fs << "           `@%%:.  :;%%.         ;@@%%;'" << '\n';
    fs << "             `@%%.  `;@%%.      ;@@%%;" << '\n';
    fs << "               `@%%%%. `@%%%%    ;@@%%;" << '\n';
    fs << "                 ;@%%. :@%%%%  %%@@%%;" << '\n';
    fs << "                   %%@bd%%%%%%bd%%%%:;" << '\n';
    fs << "                     #@%%%%%%%%%%:;;" << '\n';
    fs << "  ''                  %%@@%%%%%%::;" << '\n';
    fs << "   %;     ''         %%@@@%%(o);  . '" << '\n';
    fs << "  ;%   % %'          %%@@@o%%;:(.,'" << '\n';
    fs << "  :%%   %;       `.. %%@@@o%%::;" << '\n';
    fs << "   ;%% %:;          `)@@@o%%::;" << '\n';
    fs << "     %@::            %%@@(o)::;" << '\n';
    fs << "     %@             .%%@@@@%%::;" << '\n';
    fs << "     %@%            ;%%@@@@%%::;." << '\n';
    fs << "    ;%@%;          ;%%@@@@%%%%:;;;." << '\n';
    fs << " ..;%@@%;.     ...;%@@@@@%%:;;;;,.." << '\n';
    fs.close();
}
