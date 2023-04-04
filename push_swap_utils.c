/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:28:26 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/04 13:54:02 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list *first;
	t_list *second;

	if(!head | !*head | !(*head)->next)
		return;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

t_list	*ft_lst_prev_last(t_list **list)
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	curr = *list;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	return (prev);
}

void	reverse_rotate(t_list **head)
{
	t_list	*temp;
	t_list	*temp2;

	temp = 	NULL;
	temp2 =	NULL;
	if(!head | !*head | !(*head)->next)
		return;
	temp = ft_lst_prev_last(head);
	temp2 = ft_lstlast(*head);
	temp2->next = *head;
	temp->next = NULL;
	*head = temp2;
}

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*temp2;

	temp = 	NULL;
	temp2 =	NULL;
	if(!head | !*head | !(*head)->next)
		return;
	temp = (*head)->next;
	temp2 = ft_lstlast(*head);
	temp2->next = *head;
	(*head)->next = NULL;
	*head = temp;
}

void	push(t_list **a, t_list **b)
{
	t_list *temp;
	t_list *temp2;

	if(!a || !*a)
		return;
	temp = *a;
	temp2 = temp->next;
	temp->next = NULL;
	ft_lstadd_front(b, temp);
	*a = temp2;
}

