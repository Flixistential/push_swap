/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_toi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:24:15 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/04 12:57:30 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_numlen(char *str)
{	
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0' && !ft_isspace(str[i]))
		i++;
	if(str[0] == '-')
		i--;
	return (i);
}

long	ft_atol_toi(char *str)
{
	int		i;
	long	sign;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '+' || str[i] == '-') && (ft_isdigit(str[i +1]) != 0))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
