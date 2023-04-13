/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:44:59 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/13 19:05:28 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_toute(t_list **a, t_list **b)
{
	size_t	i;
	size_t	j;

	if (!a || !b || !*a)
		return ;
	while(ft_countlist(*b) != 2)
		push(a, b, 'b');
	i = 0;
	j = 0;
	while (*a && ft_countlist(*b) != 3)
	{
		ft_check_moves(a, b);
		i = ft_findsmallest(*a);
		j = ft_countlist(*a);
		if (i > (j / 2))
		{
			i = (j - i + 1);
			while (i != 0)
			{
				rra(a);
				i--;
			}
			push(a, b, 'b');
		}
		else
		{
			while (i != 1)
			{
				ra(a);
				i--;
			}
			push(a, b, 'b');
		}
	}
	while (*b)
		push(b, a, 'a');
}

void	sort5(t_list **a, t_list **b)
{
	t_list	*temp;
	int i;

	i = 0;
	temp = NULL;
	while(ft_countlist(*a) != 3)
		push(a, b, 'b');
	sort3 (a);
	while ((*b) != NULL)
	{
		if ((ft_bigger_then_lst(a, b) == 1 && (*b)))
		{
			while (ft_islstsmall(a) != 1)
				ra(a);
			if (ft_islstsmall(a) == 1)
				push(b, a, 'a');
		}
		if ((ft_smaller_then_lst(a, b) == 1 && (*b)))
		{
			while (ft_islstsmall(a) != 1)
				ra(a);
			if (ft_islstsmall(a) == 1) 
				push(b, a, 'a');			
		}
		if (!ft_bigger_then_lst(a, b) && !ft_smaller_then_lst(a, b) && (*b))
		{
			if ((*b)->i > ft_lstlast(*a)->i && (*b)->i < (*a)->i)
				push(b, a, 'a');
			else
				ra(a);
		}
	}
}

void	sort_toute(t_list **a, t_list **b)
{
	size_t	pos_a;
	size_t	pos_b;
	size_t	best_move;

	if (!a || !b || !*a)
		return ;
	pos_b = 0;
	pos_a = 0;
	best_move = 0;
    push (a, b, 'b');
    push (a, b, 'b');
	while (temp_a)
	{
		if (ft_bigger_then_b(b, &temp_a) || ft_smaller_then_b(b, &temp_a))
		{
        pos_a = ft_position(a, (*temp_a)->i) 
		pos_b =ft_count_to_small(b);
		best_move = ft_count_moves(a, b, pos_a, pos_b);
		}
		
	}
}


void	sort5(t_list **a, t_list **b)
{
	while (ft_countlist(*a) != 3)
		push(a, b, 'b');
	sort3 (a);
	while ((*b) != NULL)
	{
		if ((ft_bigger_then_lst(a, b) == 1 && (*b)))
		{
			while (ft_islstsmall(a) != 1)
				ra(a);
			if (ft_islstsmall(a) == 1)
				push(b, a, 'a');
		}
		if ((ft_smaller_then_lst(a, b) == 1 && (*b)))
		{
			while (ft_islstsmall(a) != 1)
				ra(a);
			if (ft_islstsmall(a) == 1) 
				push(b, a, 'a');			
		}
		if (!ft_bigger_then_lst(a, b) && !ft_smaller_then_lst(a, b) && (*b))
		{
			if ((*b)->i > ft_lstlast(*a)->i && (*b)->i < (*a)->i)
				push(b, a, 'a');
			else
				ra(a);
		}
	}
}

size_t  ft_count_moves(t_list **a, t_list **b, size_t pos_a, size_t pos_b)
{
    size_t  biggest_list
    size_t	pos;
	size_t  moves;
    
	pos = 0;
	moves = 0;
	if (ft_countlist(a) > ft_countlist(b))
		biggest_list = ft_countlist(a);
			else
		biggest_list = ft_countlist(a);
	if (pos_a > (biggest_list / 2) && pos_a > (biggest_list / 2))
	{
		while (pos_a !> biggest_list && pos_b  !> biggest_list)
		{
			pos_a++;
			pos_b++;
			move++;
		}
	}
	else
	{ 
		while(pos_a ||)
}

size_t  ft_count_to_small(t_list **a)
{
	t_list	*temp;
	size_t	i;
	size_t	pos;

	i = (*a)->i;
	temp = *a;
	pos = 1;
	while (temp)
	{
		if ((*temp).i > ((*temp)->next).i)
			i = (*temp)->next.i;
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

size_t	ft_position(t_list **a, size_t index)
{
	t_list	*temp;
	size_t	pos;

	temp = *a;
	pos = 1;
	while (temp && temp.i != index)
	{
		temp = temp->next;
		pos++;
	}
	return (pos);
}