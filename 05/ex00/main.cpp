/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/14 19:41:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    {
        Bureaucrat president("Gyoon", 1);

        std::cout << president << std::endl;
        try
        {
            president.incrementGrade();
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << std::endl;

    {
        Bureaucrat servant("Gyoon", 150);

        std::cout << servant << std::endl;
        try
        {
            servant.incrementGrade();
            std::cout << servant << std::endl;
            servant.decrementGrade();
            std::cout << servant << std::endl;
            servant.decrementGrade();
            std::cout << servant << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << std::endl;

    {
        Bureaucrat middle("Gyoon", 75);

        try
        {
            for (;;)
            {
                std::cout << middle << std::endl;
                middle.decrementGrade();
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
