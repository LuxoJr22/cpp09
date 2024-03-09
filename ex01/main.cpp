/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:17:16 by luxojr            #+#    #+#             */
/*   Updated: 2024/02/21 13:10:49 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    int result;
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    result = RPN(argv[1]);
    std::cout << result << std::endl;
    return (0);
}