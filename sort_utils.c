/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:55:01 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/10 14:31:57 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_countlist(t_list *lst)
{
	size_t	i;

	if(!lst)
		return (0);
	i = 1;
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

size_t ft_findsmallest(t_list *lst)
{
	size_t	i;
	size_t	j;
	t_list	*temp;

	if (!lst)
		return (0);
	i = 1;
	j = lst->i;
	temp = lst;
	while (lst && lst->next != NULL)
	{
		if (j > lst->next->i)
			j = lst->next->i;
		lst = lst->next;
	}
	while (temp && temp->next != NULL && temp->i != j)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

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
	while ((*temp).i == ((*temp2).i - 1) && temp2->next != NULL)
	{
		temp = temp->next;
		temp2 = temp2->next;	
	}
	if ((*temp).i == ((*temp2).i - 1) && temp2->next == NULL)
		return(1);
	else
		return(0);
}