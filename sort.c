/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:43:58 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/04 15:53:14 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **lst)
{
	t_list *temp;
	t_list *temp2;

	if(!lst)
		return(0);
	temp = *lst;
	if(temp && temp->next == NULL)
		return (1);
	temp2 = temp->next;
	while(*(int*)temp->content < *(int*)temp2->content && temp2->next != NULL)
	{
		temp = temp->next;
		temp2 = temp2->next;	
	}
	if(*(int*)temp->content < *(int*)temp2->content && temp2->next == NULL)
		return(1);
	else
		return(0);
}

void	sort2(t_list **a)
{
	if(is_sorted(a) == 1)
		return;
	else
		sa(a);
}

void	sort3(t_list **a)
{
	if(*(*a)->content > *(*a)->next->content && *(*a)->next->content > *(*a)->next->next->content)
	{
		ra(a);
		sa(a);
	}
	if(*(*a)->content < *(*a)->next->content && *(*a)->next->content > *(*a)->next->next->content)
	{
		rra(a);
		sa(a);
	}
	if (*(*a)->content > *(*a)->next->content && *(*a)->next->content > *(*a)->next->next->content)
		ra(a);
	if (*(*a)->content < *(*a)->next->content && *(*a)->next->content > *(*a)->next->next->content)
		rra(a);
	if(*(*a)->content > *(*a)->next->content && *(*a)->next->content < *(*a)->next->next->content)
		sa(a);
}

void	sort5(t_list **a, t_list **b)
{
	int	i;

	i = 0;
}