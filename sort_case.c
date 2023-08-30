/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:57:46 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/28 18:57:46 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_rrarb(t_list **a, t_list **b, t_list *move, t_list *pos_b)
{
	while (move != *a)
		rra(a);
	while (pos_b != *b)
		rb(b);
}

void	ft_sort_rarrb(t_list **a, t_list **b, t_list *move, t_list *pos_b)
{
	while (move != *a)
		ra(a);
	while (pos_b != *b)
		rrb(b);
}

void	ft_sort_rrr(t_list **a, t_list **b, t_list *move, t_list *pos_b)
{
	while (move != *a && pos_b != *b)
		rrr(a, b);
	while (move != *a)
		rra(a);
	while (pos_b != *b)
		rrb(b);
}

void	ft_sort_rr(t_list **a, t_list **b, t_list *move, t_list *pos_b)
{
	while (move != *a && pos_b != *b)
		rr(a, b);
	while (move != *a)
		ra(a);
	while (pos_b != *b)
		rb(b);
}
