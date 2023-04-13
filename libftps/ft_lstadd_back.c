/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 04:28:39 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/13 16:13:15 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftps.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	t_list	*temp;

	if (lst && *lst)
	{
		temp = *lst;
		temp = ft_lstlast (*lst);
		temp->next = new;
		return ;
	}
	*lst = new;
}
