/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:17:46 by luxojr            #+#    #+#             */
/*   Updated: 2024/02/21 13:26:41 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	is_op(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

int	is_blank(char c)
{
	if ((c > 9 && c < 13) || c == 32)
		return (1);
	return (0);
}

void	ft_error(std::stack<int> *nb, std::stack<char> *op)
{
	delete op;
	delete nb;
	std::cout << "Error" << std::endl;
	exit(1);
}

void	operate(std::stack<int> *nb, std::stack<char> *op)
{
	int	top;
	int	last;

	if (nb->size() < 2)
		ft_error(nb, op);
	top = nb->top();
	nb->pop();
	last = nb->top();
	nb->pop();
	if (op->top() == '*')
		nb->push(last * top);
	else if (op->top() == '/')
		nb->push(last / top);
	else if (op->top() == '+')
		nb->push(last + top);
	else if (op->top() == '-')
		nb->push(last - top);
	else 
		ft_error(nb, op);
	op->pop();
}

int	RPN(char* str)
{
	std::stack<int>		*nb = new std::stack<int>;
	std::stack<char>	*op = new std::stack<char>;
	int					i;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_blank(str[i]))
			i ++;
		if (str[i])
		{
			if (str[i] >= '0' && str[i] <= '9')
				nb->push(str[i] - '0');
			else if (is_op(str[i]))
				op->push(str[i]);
			else
				ft_error(nb, op);
			i ++;
			if (str[i] && !is_blank(str[i]))
				ft_error(nb, op);
		}
		if (!op->empty())
			operate(nb, op);
	}
	if (nb->size() > 2 && !op->empty())
		ft_error(nb, op);
	i = nb->top();
	delete nb;
	delete op;
	return (i);
}