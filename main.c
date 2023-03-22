/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:05:17 by fboivin           #+#    #+#             */
/*   Updated: 2023/03/21 23:44:25 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>


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
	if (ft_isspace(s[0]))
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

	i = 0;
	j = 0;
	while (str[i] && j < c)
	{
		while (ft_isspace(str[i]))
			i++;
		result[j] = ft_atoi(&str[i]);
			j++;
		while (!ft_isspace(str[i]))
			i++;
	}
	return (result);
}

void	print_elem(void *content)
{
	printf("%d\n", (int)content);
}

int	main(int argc, char *argv[])
{
	t_list	*head;
	t_list	*temp;
	int		*result;
	int		i;
	int 	j;

	j = 0;
	i = 1;
	head = NULL;
	if (argc <= 2)
		return (0);
	while (argv[i])
	{
		if (!ft_isdigitsigned(argv[i]))
			return (0);
		//printf("%d\n%s\n",(ft_isdigitsigned(argv[i])),(argv[i]));
		i++;
	}
	i = 1;
	while (argv[i])
	{
		result = (int *)malloc(sizeof(int) * word_count_space(argv[i]));
		if (!result)
			return (0);
		result = ft_splatoi(argv[i], word_count_space(argv[i]), result);
		while (result[j])
		{
			temp = ft_lstnew(&result[j]);
			ft_lstadd_back(&head, temp);
			j++;
		}
		free (result);
		j = 0;
		i++;
	}
	ft_lstiter(head, &print_elem);
}
