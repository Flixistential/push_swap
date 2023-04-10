/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:20:27 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/10 14:21:40 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isdigitsigned(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		j = i;
		if (ft_isspace(str[i]))
			i++;
		if ((str[i] == '-') && (str[i +1] >= '0' && str[i +1] <= '9')
			&& (ft_isspace(str[i - 1]) || !str[i -1]))
		i++;
		if (str[i] >= '0' && str[i] <= '9')
		i++;
		if (str[i] == '\0')
			return (1);
		if (i == j)
			return (0);
	}
	return (0);
}

size_t	word_count_space(char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!ft_isspace(s[0]))
		count++;
	while (s[i])
	{
		if (ft_isspace(s[i]) && !ft_isspace(s[i + 1]) && s[i + 1] != '\0')
		count++;
		i++;
	}
	return (count);
}

int	*ft_splatoi(char *str, size_t c, int *result)
{
	size_t	i;
	size_t	j;
	long	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] && j < c)
	{
		while (ft_isspace(str[i]))
			i++;
		k = ft_atol_toi(&str[i]);
		if(ft_numlen(&str[i]) >= 11 || k > 2147483647 || k < -2147483648)
		{
			ft_printf("Error\n");
			return(NULL);
		}
		result[j] = k;
			j++;
		while (!ft_isspace(str[i]) && j < c)
			i++;
	}
	return (result);
}
