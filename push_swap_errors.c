/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:55:08 by mbouderr          #+#    #+#             */
/*   Updated: 2023/04/28 00:16:30 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dip(t_mystack *mystack, t_mytools *mytools)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mystack->stack_a[i])
	{
		j = i + 1;
		while (mystack->stack_a[j])
		{
			if (mystack->stack_a[i] == mystack->stack_a[j])
			{
				error_medium(mystack, mytools);
			}
			else
				j++;
		}
		i++;
	}
}

void	is_sorted(t_mystack *mystack, t_mytools *mytools)
{
	int	i;

	i = 0;
	while (i < mystack->len - 1)
	{
		if (mystack->stack_a[i] > mystack->stack_a[i + 1])
		{
			mystack->is_sorted = 0;
			break ;
		}
		i++;
	}
	if (i == mystack->len - 1)
	{
		mystack->is_sorted = 1;
		simple_free(mystack, mytools);
	}
}

int	space_error(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	sign_error(char *str, t_mystack *mystack, t_mytools *mytools)
{
	char	c;
	int		i;
	char	s;

	c = '\0';
	s = ' ';
	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && ((str[i + 1] == c) || (str[i
						+ 1] == s)))
		{
			error_normal(mystack, mytools);
		}
		i++;
	}
}
