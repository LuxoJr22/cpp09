/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:29:59 by luxojr            #+#    #+#             */
/*   Updated: 2024/03/05 18:49:24 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	show_vec(std::vector<int> vector)
{
	int i = 0;
    int size = vector.size();

	while (i < size)
	{
		std::cout << vector[i] << " ";
		i ++;
	}
	std::cout << std::endl;
}

void    show_arg(char **argv)
{
    int i = 0;

    while (argv[i])
        std::cout << std::atoi(argv[i ++]) << " ";
    std::cout << std::endl;
}

std::list<int>  make_list(char **argv)
{
    int             i = 1;
    std::list<int>  list;

    while (argv[i])
    {
        list.push_back(std::atoi(argv[i]));
        i ++;
    }
    return (list);
}

std::vector<int>  make_vector(char **argv)
{
    int                 i = 1;
    std::vector<int>    vector;

    while (argv[i])
    {
        vector.push_back(std::atoi(argv[i]));
        i ++;
    }
    return (vector);
}

int main(int argc, char **argv)
{
    std::list<int>      list;
    std::list<int>      lis;
    std::vector<int>    vector;
    std::vector<int>    vec;
    struct timeval begin, end;

    if (argc <= 1)
    {
        std::cout << "Error: not enough argument." << std::endl;
        return (1);
    }
    std::cout << "Before:  ";
    show_arg(argv);

    /*********** Vector *************/
    gettimeofday(&begin, 0);
    vector = make_vector(argv);
    vec = sort_vector(vector);
    gettimeofday(&end, 0);
    /********************************/
    
    std::cout << "After:   ";
    show_vec(vec);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << end.tv_usec - begin.tv_usec << " us" << std::endl;

    /************ List **************/
    gettimeofday(&begin, 0);
    list = make_list(argv);
    lis = sort_list(list);
    gettimeofday(&end, 0);
    /********************************/

    std::cout << "Time to process a range of " << list.size() << " elements with std::list   : " << end.tv_usec - begin.tv_usec << " us" << std::endl;
    return (0);
}