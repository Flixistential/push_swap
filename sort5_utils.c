/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:10:06 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/09 18:28:47 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_islstsmall(t_list **a)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = (*a)->next;
	while (temp)
	{
		if ((*temp).i < (*a)->i)
			i = 0;
		temp = temp->next;
	}
	return (i);
}

int	ft_islstbig(t_list **a)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = (*a)->next;
	while (temp)
	{
		if ((*temp).i > (*a)->i)
			i = 0;
		temp = temp->next;
	}
	return (i);
}

int	ft_smaller_then_lst(t_list **a, t_list **b)
{
	int		i;
	t_list	*temp_a;

	i = 1;
	if (!a || !b || !*a || !*b)
		return (0);
	temp_a = *a;
	while (temp_a) 
	{
		if ((*temp_a).i < (*b)->i)
			i = 0;
		temp_a = temp_a->next;
	}
	return (i);
}

int		ft_bigger_then_lst(t_list **a, t_list **b)
{
	int		i;
	t_list	*temp_a;

	i = 1;
	if (!a || !b || !*a || !*b)
		return (0);
	temp_a = *a;
	while (temp_a) 
	{
		if ((*temp_a).i > (*b)->i)
		i = 0;
		temp_a = temp_a->next;
	}
	return (i);
}