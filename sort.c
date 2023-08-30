/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:43:58 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/28 20:07:58 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **a)
{
	if (is_sorted(a) == 1)
		return ;
	else
		sa(a);
}

void	sort3(t_list **a)
{
	if ((*a)->i > (*a)->next->i && (*a)->next->i > (*a)->next->next->i 
		&& (*a)->i > (*a)->next->next->i)
	{
		ra(a);
		sa(a);
	}
	else if ((*a)->i > (*a)->next->i && (*a)->next->i < (*a)->next->next->i
		&& (*a)->i > (*a)->next->next->i)
		ra(a);
	else if ((*a)->i > (*a)->next->i && (*a)->next->i < (*a)->next->next->i
		&& (*a)->i < (*a)->next->next->i)
		sa(a);
	else if ((*a)->i < (*a)->next->i && (*a)->next->i > (*a)->next->next->i
		&& (*a)->i < (*a)->next->next->i)
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->i < (*a)->next->i && (*a)->next->i > (*a)->next->next->i
		&& (*a)->i > (*a)->next->next->i)
		rra(a);
}

void	ft_lstindex(t_list **a)
{
	size_t	index;
	t_list	*temp;
	t_list	*temp2;

	if (!a || !*a)
		return ;
	temp = *a;
	temp2 = *a;
	index = 0;
	while (temp)
	{
		while (temp2)
		{
			if (temp->content >= temp2->content)
				index++;
			temp2 = temp2->next;
		}
		temp->i = index;
		index = 0;
		temp = temp->next;
		temp2 = *a;
	}
}

void	sort5(t_list **a, t_list **b)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (ft_countlist(*a) != 3)
		push(a, b, 'b');
	sort3 (a);
	while ((*b) != NULL)
	{
		if ((ft_bigger_then_lst(a, b) == 1 && (*b)))
			ft_case1(a, b);
		if ((ft_smaller_then_lst(a, b) == 1 && (*b)))
			ft_case2(a, b);
		if (!ft_bigger_then_lst(a, b) && !ft_smaller_then_lst(a, b) && (*b))
			ft_case3(a, b);
	}
}
