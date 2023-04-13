/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:05:17 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/12 18:38:38 by fboivin          ###   ########.fr       */
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


void	sort_toute(t_list **a, t_list **b)
{
	size_t	i;
	size_t	j;

	if (!a || !b || !*a)
		return ;
	i = 0;
	j = 0;
	while (*a)
	{
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

void	del(void *content)
{
	free(content);
}

void	print_elem(int content)
{
	printf("%d node\n", content);
}

void print_stack(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if (!a || !b)
		return ;
	temp = *a;
	temp2 = *b;
	ft_printf("a | b\n");
	while(temp || temp2)
	{	
		if(!temp)
			ft_printf("  | %d\n", temp2->content);
		else if(!temp2)
			ft_printf("%d |  \n", temp->content);
		else
			ft_printf("%d | %d\n", temp->content, temp2->content);
		if (temp)
			temp = temp->next;
		if (temp2)
		temp2 = temp2->next;
	}
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
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (-1);
	}
	while (argv[i])
	{
		if (!ft_isdigitsigned(argv[i]))
		{
			ft_printf("Error\n");
			return (-1);
		}
		i++;
	}
	if (ft_splatoi(argc, argv, &a) != 0)
		return (-1);
	if (ft_check_doubles(&a) != 0)
	{
		ft_lstclearps(&a);
		ft_printf("Error\n"); 
			return (-1);
	}
	ft_lstindex(&a);
	if (is_sorted(&a) == 1)
	{
		ft_printf("C'EST SORTÉ TABARNAK\n");
		return (0);
	}
	//ft_lstiter(a, &print_elem);
	if (ft_countlist(a) == 3)
	{
		sort3(&a);
	}
	if (ft_countlist(a) == 4 || ft_countlist(a) == 5)
	{
		sort5(&a, &b);
	}
	if (ft_countlist(a) > 5)
		sort_toute(&a, &b);
	while (!is_sorted(&a))
	{
		if ((ft_countlist(a) / 2) >= (ft_findsmallest(a) - 1))
		{	
			while (!is_sorted(&a))	
				ra(&a);
		}
		else
			while (!is_sorted(&a))
				rra(&a);
	}
	ft_lstclearps(&a);
	//print_stack(&a, &b);
	/*push(&a, &b);
	ft_printf("push\n");
	print_stack(&a, &b);*/
}
