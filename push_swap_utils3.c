/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:18:09 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/28 19:44:46 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_bigest(t_list **a)
{
	t_list	*temp;
	size_t	i;

	i = (*a)->i;
	temp = *a;
	while (temp && temp->next != NULL)
	{
		if ((*temp).i > (*temp).next->i)
			i = (*temp).next->i;
		temp = temp->next;
	}
	temp = *a;
	while ((*temp).i != i)
	{
		temp = temp->next;
	}
	return (temp);
}

t_list	*ft_middle2(size_t index, t_list **b)
{
	t_list	*temp_b;

	temp_b = *b;
	if (temp_b->i > index && ft_lstlast(*b)->i < index)
		return (temp_b);
	while (temp_b)
	{
		if (temp_b->i < index && (temp_b->next->i > index))
		{
			return (temp_b->next);
		}
		temp_b = temp_b->next;
	}
	return (temp_b);
}

void	ft_pushback(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b; 

	temp_a = *a;
	temp_b = *b;
	if (ft_bigger_then_lst(a, b) || ft_smaller_then_lst(a, b))
		temp_a = ft_bigest(a);
	else
		temp_a = ft_middle2(temp_b->i, a);
	if (ft_pos(a, temp_a->i) <= (ft_countlist(*a) / 2))
	{
		while (temp_a != *a)
			ra(a);
	}
	else if (ft_pos(a, temp_a->i) > (ft_countlist(*a) / 2))
		while (temp_a != *a)
			rra(a);
	push(b, a, 'a');
}

t_list	*ft_smallest(t_list **a)
{
	t_list	*temp;
	size_t	i;

	i = (*a)->i;
	temp = *a;
	while (temp && temp->next != NULL)
	{
		if ((*temp).i < (*temp).next->i)
			i = (*temp).next->i;
		temp = temp->next;
	}
	temp = *a;
	while ((*temp).i != i)
	{
		temp = temp->next;
	}
	return (temp);
}

t_list	*ft_middle(size_t index, t_list **a, t_list **b)
{
	t_list	*temp_b;
	t_list	*best_move;
	size_t	move;

	move = (ft_countlist(*a) + ft_countlist(*b));
	best_move = *b;
	temp_b = *b;
	if (temp_b->i < index && ft_lstlast(*b)->i > index)
		return (temp_b);
	while (temp_b && temp_b->next)
	{
		if (temp_b->i > index && (temp_b->next->i < index))
		{
			if (ft_cm(a, b, ft_pos(a, index), 
					ft_pos(b, temp_b->next->i)) < move)
			{
				move = (ft_cm(a, b, ft_pos(a, index), 
							ft_pos(b, temp_b->next->i)));
				best_move = temp_b->next;
			}
		}
		temp_b = temp_b->next;
	}
	return (best_move);
}
