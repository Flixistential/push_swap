/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:05:17 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/30 10:55:31 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

void	ft_lstclearps(t_list **lst)
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free (*lst);
			*lst = temp;
		}
	}
	lst = NULL;
}

void	del(void *content)
{
	free(content);
}

int	ft_check_doubles(t_list **head)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *head;
	temp2 = temp->next;
	while (temp->next != NULL)
	{
		while (temp2 != NULL)
		{
			if (temp->content == temp2->content)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
		temp2 = temp->next;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (ft_check(argc, argv, &a) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_lstindex(&a);
	if (is_sorted(&a) == 1)
	{
		ft_lstclearps(&a);
		return (0);
	}
	if (ft_countlist(a) <= 5 && ft_countlist(a) >= 3)
		ft_sort_small(&a, &b);
	if (ft_countlist(a) > 5)
		sort_toute(&a, &b);
	if (!is_sorted(&a))
		ft_final_rotation(&a);
	ft_lstclearps(&a);
}
