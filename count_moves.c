/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:18:50 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/28 13:18:50 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_count_rrr(size_t list_a, size_t list_b, size_t pos_a, size_t pos_b)
{
	size_t	moves;

	moves = 1;
	if (((list_a - (pos_a) + 1) > (list_b - (pos_b) + 1)))
		moves = (list_a - (pos_a) + 2);
	else
		moves = (list_b - (pos_b) + 2);
	return (moves);
}

size_t	ft_count_rr(size_t pos_a, size_t pos_b)
{
	size_t	moves;

	moves = 1;
	if (pos_a > pos_b)
		moves = (pos_a);
	else
		moves = (pos_b);
	return (moves);
}

size_t	ft_count_rrarb(size_t list_a, size_t pos_a, size_t pos_b)
{
	size_t	moves;

	moves = 1;
	moves = (list_a - pos_a) + 2 + (pos_b - 1);
	return (moves);
}

size_t	ft_count_rarrb(size_t list_b, size_t pos_a, size_t pos_b)
{
	size_t	moves;

	moves = 1;
	moves = ((list_b - pos_b) + 2 + (pos_a - 1));
	return (moves);
}
