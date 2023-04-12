/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:05:52 by mbouderr          #+#    #+#             */
/*   Updated: 2023/04/07 08:41:46 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_atoi(char *str)
{	
	size_t	i;
	int		sign;
	int		nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f')
		str++;
	if (str[i] == '-')
	{
		i++;
		sign = sign * -1;
	}
	else if (str[i] == '+')
		i++;
			else{
			}
		
	while (str[i] >= '0' && str[i] <= '9')
	
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}