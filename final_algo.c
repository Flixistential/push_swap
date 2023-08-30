/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:44:59 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/28 19:46:02 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_toute(t_list **a, t_list **b)
{
	t_list	*best_move;

	best_move = NULL;
	if (!a || !b || !*a)
		return ;
	push (a, b, 'b');
	push (a, b, 'b');
	while ((ft_countlist(*a) > 3))
	{
		best_move = find_best_move(a, b);
		sort_best_move(a, b, best_move);
	}
	sort3(a);
	while (*b != NULL)
	{
		ft_pushback(a, b);
	}
}

size_t	ft_cm(t_list **a, t_list **b, size_t pos_a, size_t pos_b)
{
	size_t	move_a;
	size_t	move_b;
	size_t	moves;

	moves = 0;
	move_a = (ft_countlist(*a));
	move_b = (ft_countlist(*b));
	if ((pos_a > move_a / 2) && pos_b > ((move_b / 2)))
		moves = ft_count_rrr(move_a, move_b, pos_a, pos_b);
	else if (pos_a <= ((move_a / 2) + 1) && pos_b <= (((move_b / 2) + 1)))
		moves = ft_count_rr(pos_a, pos_b);
	else if (pos_a > (move_a / 2) && pos_b <= ((move_b / 2) + 1))
		moves = ft_count_rrarb(move_a, pos_a, pos_b);
	else if (pos_a <= ((move_a / 2) + 1) && pos_b > ((move_b / 2)))
		moves = ft_count_rarrb(move_b, pos_a, pos_b);
	return (moves);
}

size_t	ft_count_to_small(t_list **a)
{
	t_list	*temp;
	size_t	i;
	size_t	pos;

	i = (*a)->i;
	temp = *a;
	pos = 1;
	while (temp && temp->next != NULL)
	{
		if ((*temp).i < ((*temp).next)->i)
			i = (*temp).next->i;
		temp = temp->next;
	}
	temp = *a;
	while ((*temp).i != i)
	{
		temp = temp->next;
		pos++;
	}
	return (pos);
}

size_t	ft_pos(t_list **a, size_t index)
{
	t_list	*temp;
	size_t	pos;

	temp = *a;
	pos = 1;
	while (temp && temp->i != index)
	{
		temp = temp->next;
		pos++;
	}
	return (pos);
}

void	sort_best_move(t_list **a, t_list **b, t_list *move)
{
	t_list	*pos_b;

	pos_b = NULL;
	if (ft_bigger_then_lst(b, &move) || ft_smaller_then_lst(b, &move))
		pos_b = ft_smallest(b);
	else
		pos_b = ft_middle((*move).i, a, b);
	while (move != *a || pos_b != *b)
	{
		if ((ft_pos(a, move->i)) > (ft_countlist(*a) / 2) 
			&& (ft_pos(b, pos_b->i)) > ((ft_countlist(*b) / 2)))
			ft_sort_rrr(a, b, move, pos_b);
		else if ((ft_pos(a, move->i)) <= ((ft_countlist(*a) / 2) + 1) 
			&& (ft_pos(b, pos_b->i)) <= (((ft_countlist(*b) / 2) + 1)))
			ft_sort_rr(a, b, move, pos_b);
		else if ((ft_pos(a, move->i)) > (ft_countlist(*a) / 2) 
			&& (ft_pos(b, pos_b->i)) <= (((ft_countlist(*b) / 2) + 1)))
			ft_sort_rrarb(a, b, move, pos_b);
		else if ((ft_pos(a, move->i)) <= ((ft_countlist(*a) / 2) + 1) 
			&& (ft_pos(b, pos_b->i)) > ((ft_countlist(*b) / 2)))
			ft_sort_rarrb(a, b, move, pos_b);
	}
	push(a, b, 'b');
}
