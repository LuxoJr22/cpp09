/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:10:23 by luxojr            #+#    #+#             */
/*   Updated: 2024/03/05 18:32:25 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <list>
# include <vector>
# include <sys/time.h>
# include <sys/types.h>

void	show_vec(std::vector<int> vector);
std::list<int>      sort_list(std::list<int> list);
std::vector<int>    sort_vector(std::vector<int> vector);


#endif