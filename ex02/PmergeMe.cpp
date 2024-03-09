/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:10:21 by luxojr            #+#    #+#             */
/*   Updated: 2024/03/05 18:48:05 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


std::list<int>::iterator	get_iterator(std::list<int>::iterator it, int i)
{
	std::advance(it, i);
	return (it);
}

int	list_find_it(std::list<int> lis, int nb)
{
	int							i = 0;
	std::list<int>::iterator	it;

	it = lis.begin();
	while (it != lis.end() && *it < nb)
	{
		it ++;
		i ++;
	}
	return (i);
}

int	list_binary(std::list<int> lis, int nb, int start, int finish)
{
	int i = (start + finish) / 2;
	
	if (finish - start <= 1)
	{
		if (nb < *get_iterator(lis.begin(), start))
			return (start);
		return (finish);
	}
	if (*get_iterator(lis.begin(), start) == nb)
		return (i);
	if (*get_iterator(lis.begin(), start) > nb)
		return (list_binary(lis, nb, start, finish - (finish - start) / 2));
	else
		return (list_binary(lis, nb, start + (finish - start) / 2, finish));
}

std::list<int>  sort_list(std::list<int> list)
{
    std::list<int>				lis;
	std::list<int>::iterator	ite;
	std::list<int>::iterator	it2;
	int							it;
	int							min = 1;

	ite = list.begin();
	it2 = list.begin();
	it2 ++;
	while (it2 != list.end())
	{
		if (*ite < *it2)
				std::swap(*ite, *it2);
		std::advance(ite, 2);
		std::advance(it2, 2);
	}
	ite = list.begin();
	while (ite != list.end())
	{
		if (std::distance(list.begin(), ite) % 2 == 0)
		{
			if (lis.empty())
				lis.push_back(*ite);
			else
			{
				it = list_find_it(lis, *ite);
				if (it == 0)
					min = std::distance(list.begin(), ite);
				lis.insert(get_iterator(lis.begin(), it), *ite);
			}
		}
		ite ++;
	}
	lis.insert(lis.begin(), *get_iterator(list.begin(), min - 1));
	ite = list.begin();
	while (ite != list.end())
	{
		if (std::distance(list.begin(), ite) % 2 == 0 && std::distance(list.begin(), ite) != min - 1)
		{
			it = list_binary(lis, *ite, 0, lis.size());
			lis.insert(get_iterator(lis.begin(), it), *ite);
		}
		ite ++;
	}
	return (lis);
}

/***************************************************************/
/*********************    VECTOR   *****************************/
/***************************************************************/

int	find_it(std::vector<int> vec, int nb)
{
	int	i = 0;
	int	len = vec.size();

	while (i < len && vec[i] < nb)
		i++;
	return (i);
}

int	vec_binary(std::vector<int> vec, int nb, int start, int finish)
{
	int i = (start + finish) / 2;
	
	if (finish - start <= 1)
	{
		if (nb < vec[start])
			return (start);
		return (finish);
	}
	if (vec[i] == nb)
		return (i);
	if (vec[i] > nb)
		return (vec_binary(vec, nb, start, finish - (finish - start) / 2));
	else
		return (vec_binary(vec, nb, start + (finish - start) / 2, finish));
}

std::vector<int>  sort_vector(std::vector<int> vector)
{
    std::vector<int>			vec;
	int							it;
	int							i = 0;
	int							min = 1;
	int							len = vector.size();

	while (vector[i])
	{
		if (i % 2 != 0)
		{
			if (vector[i] < vector[i - 1])
				std::swap(vector[i], vector[i - 1]);
		}
		i ++;
	}
	i = 0;
	while (vector[i])
	{
		if (i % 2 != 0)
		{
			if (vec.empty())
				vec.push_back(vector[i]);
			else
			{
				it = find_it(vec, vector[i]);
				if (it == 0)
					min = i;
				vec.insert(vec.begin() + it, vector[i]);
			}
		}
		i ++;
	}
	vec.insert(vec.begin(), vector[min - 1]);
	i = 0;
	while (i < len)
	{
		if (i % 2 == 0 && i != min - 1)
		{
			it = vec_binary(vec, vector[i], 0, vec.size());
			vec.insert(vec.begin() + it, vector[i]);
		}
		i ++;
	}
	return (vec);
}