/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:36:13 by luxojr            #+#    #+#             */
/*   Updated: 2024/03/04 13:18:51 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int is_file_valid(char *name)
{
    std::ifstream   file(name);
    
    if (file.good())
    {
        file.close();
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    std::map<std::string, float>    db;
    std::map<std::string, float>    inp;

    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    if (!is_file_valid(argv[1]))
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    db = get_data();
    get_result(argv[1], db);
    
    return (0);
}