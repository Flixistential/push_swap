/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:04:28 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/30 10:45:16 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case1(t_list **a, t_list **b)
{
	while (ft_islstsmall(a) != 1)
		ra(a);
	if (ft_islstsmall(a) == 1)
		push(b, a, 'a');
}

void	ft_case2(t_list **a, t_list **b)
{
	while (ft_islstsmall(a) != 1)
		ra(a);
	if (ft_islstsmall(a) == 1) 
		push(b, a, 'a');
}

void	ft_case3(t_list **a, t_list **b)
{
	if ((*b)->i > ft_lstlast(*a)->i && (*b)->i < (*a)->i)
		push(b, a, 'a');
	else
		ra(a);
}

void	ft_sort_small(t_list **a, t_list **b)
{
	if (ft_countlist(*a) == 3)
	{
		sort3(a);
	}
	if (ft_countlist(*a) == 4 || ft_countlist(*a) == 5)
	{
		sort5(a, b);
	}
}

int	ft_check(int argc, char **argv, t_list **a)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isdigitsigned(argv[i]))
			return (-1);
		i++;
	}
	if (ft_splatoi(argc, argv, a) != 0)
	{
		ft_lstclearps(a);
		return (-1);
	}
	if (ft_check_doubles(a) != 0)
	{
		ft_lstclearps(a);
		return (-1);
	}
	return (0);
}
