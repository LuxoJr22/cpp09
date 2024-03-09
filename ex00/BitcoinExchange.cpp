/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:36:59 by luxojr            #+#    #+#             */
/*   Updated: 2024/03/04 13:09:51 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float>  get_data()
{
    std::map<std::string, float>    db;
    std::ifstream                   file("data.csv");
	std::string						line;
	int								i;

	file >> line;
	if (line.compare("date,exchange_rate") == 0)
	{
		while (file.good())
		{
			file >> line;
			i = line.find(",");
			db[line.substr(0, i)] = std::atof(line.substr(i + 1, line.length()).c_str());
		}
	}
    file.close();
	return (db);
}

int is_valid(float f)
{
	if (f >= 0 && f <= 1000)
		return (1);
	else
	{
		if (f < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
		return (0);
	}
}

int	is_date(std::string date)
{
	struct tm	time;

	if (strptime(date.c_str(), "%Y-%m-%d", &time))
		return (1);
	else
	{
		std::cout << "Error : bad input => " << date << std::endl;
		return (0);
	}
}

void  get_result(char *name, std::map<std::string, float> db)
{
    std::ifstream                   		file(name);
	std::string								line;
	std::string								date;
	std::map<std::string, float>::iterator	it;

	file >> line;
	file >> line;
	file >> line;
	if (line.compare("value") == 0)
	{
		while (file.good())
		{
			file >> line;
			if (is_date(line))
			{
				date = line;
				it = db.lower_bound(line);
				if (it->first > date)
					if (it != db.begin())
						it --;
				file >> line;
				if (line.compare("|") == 0)
				{
					file >> line;
					if (is_valid(std::atof(line.c_str())))
						std::cout << date << " => " << line << " = " << std::atof(line.c_str()) * it->second << std::endl;
				}
			}
		}
	}
    file.close();
}