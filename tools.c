/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:56:53 by mbouderr          #+#    #+#             */
/*   Updated: 2023/04/30 20:23:13 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_push(char *str, t_mytools *mytools, t_mystack *mystack)

{
	size_t	i;
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (*str == ' ')
		str++;
	if (str[i] == '-' && str[i + 1] != ' ')
	{
		i++;
		sign = sign * -1;
	}
	else if (str[i] == '+' && str[i + 1] != ' ')
		i++;
	nbr = calculate_number(str + i, sign, mytools, mystack);
	return (nbr);
}

long	calculate_number(char *str, int sign, t_mytools *mytools,
		t_mystack *mystack)
{
	size_t	i;
	long	nbr;
	int		digit;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			nbr = nbr * 10 + digit;
			if ((sign * nbr) > INT_MAX || (sign * nbr) < INT_MIN)
				error_medium(mystack, mytools);
		}
		else
		{
			error_medium(mystack, mytools);
		}
		i++;
	}
	return (nbr * sign);
}

void	r_rotate_ab(t_mystack *mystack)
{
	if (mystack->len_a == 1 || mystack->len_a == 0)
		return ;
	else if (mystack->len_b == 0 || mystack->len_b == 1)
		return ;
	else
	{
		r_rotate_a(mystack);
		r_rotate_b(mystack);
		ft_printf("rrr\n");
	}
}
