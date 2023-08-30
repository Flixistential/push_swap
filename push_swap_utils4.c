/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:26:52 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/28 19:38:51 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_middle_pos(size_t i, t_list **b, t_list**a)
{
	t_list	*t;
	size_t	pos;
	size_t	best_pos;
	size_t	bm;

	pos = 1;
	best_pos = 0;
	t = *b;
	bm = (ft_countlist(*b) + ft_countlist(*a));
	if (t->i < i && ft_lstlast(*b)->i > i)
		return (1);
	while (t && t->next)
	{
		pos++;
		if (t->i > i && (t->next->i < i)) 
		{
			if (ft_cm(a, b, ft_pos(a, i), ft_pos(b, t->next->i)) < bm)
			{
				bm = (ft_cm(a, b, ft_pos(a, i), ft_pos(b, t->next->i)));
				best_pos = pos;
			}
		}
		t = t->next;
	}
	return (best_pos);
}

t_list	*find_best_move(t_list **a, t_list **b)
{
	size_t	pos_b;
	t_list	*best_move;
	size_t	moves;
	t_list	*temp;

	pos_b = 0;
	moves = (ft_countlist(*a) + ft_countlist(*b));
	best_move = *a;
	temp = *a;
	while (temp)
	{
		if (ft_bigger_then_lst(b, &temp) || ft_smaller_then_lst(b, &temp))
			pos_b = ft_count_to_small(b);
		else
			pos_b = ft_middle_pos((*temp).i, b, a);
		if (ft_cm(a, b, ft_pos(a, (*temp).i), pos_b) < moves)
		{
			moves = ft_cm(a, b, ft_pos(a, (*temp).i), pos_b);
			best_move = temp;
		}
		temp = (temp)->next;
	}
	return (best_move);
}

void	ft_final_rotation(t_list **a)
{
	while (!is_sorted(a))
	{
		if ((ft_countlist(*a) / 2) >= (ft_findsmallest(*a) - 1))
		{
			while (!is_sorted(a))
				ra(a);
		}
		else 
			while (!is_sorted(a))
				rra(a);
	}
}

int	ft_empty(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
