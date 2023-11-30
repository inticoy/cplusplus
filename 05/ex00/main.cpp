/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:57:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/30 14:50:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    {
        std::cout << "[TEST 1]\n";

        try
        {
            Bureaucrat president("Gyoon", 1);
            std::cout << president << std::endl;
            president.decrementGrade();
            std::cout << president << std::endl;
            president.incrementGrade();
            std::cout << president << std::endl;
            president.incrementGrade();
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "\n[TEST 2]\n";

        try
        {
            Bureaucrat servant("Gyoon", 150);
            std::cout << servant << std::endl;
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

    {
        std::cout << "\n[TEST 3]\n";

        try
        {
            Bureaucrat high("Gyoon", 10);
            for (;;)
            {
                std::cout << high << std::endl;
                high.incrementGrade();
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "\n[TEST 4]\n";
        try
        {
            Bureaucrat low("Gyoon", 140);
            for (;;)
            {
                std::cout << low << std::endl;
                low.decrementGrade();
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "\n[TEST 5]\n";

        try
        {
            Bureaucrat zero("Gyoon", 0);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "\n[TEST 6]\n";

        try
        {
            Bureaucrat over("Gyoon", 151);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
