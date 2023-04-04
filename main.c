/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:05:17 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/04 14:53:35 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

void del(void *content)
{
	free(content);
}

void	print_elem(void *content)
{
	printf("%d node\n", *(int*)content);
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
			ft_printf("  | %d\n", *temp2->content);
		else if(!temp2)
			ft_printf("%d |  \n", *temp->content);
		else
			ft_printf("%d | %d\n", *temp->content, *temp2->content);
		if(temp)
			temp = temp->next;
		if(temp2)
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
			if (*(int *)temp->content == *(int *)temp2->content)
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
	int		*result;
	int		i;
	size_t	j;

	j = 0;
	i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (-1);
	while (argv[i])
	{
		if (!ft_isdigitsigned(argv[i]))
			return (-1);
		i++;
	}
	i = 1;
	while (argv[i])
	{
		result = (int *)malloc(sizeof(int) * word_count_space(argv[i]));
		if (!result)
		//need better protection aka free the list and result
			return (-1);
		result = ft_splatoi(argv[i], word_count_space(argv[i]), result);
			if (result == NULL)
				return(-1);
		while (j < word_count_space(argv[i]))
		{
			ft_lstadd_back(&a, ft_lstnew(&result[j]));
			j++;
		}
		j = 0;
		//ft_lstiter(a, &print_elem);
		i++;
	}
	if (ft_check_doubles(&a) != 0)
	{
		ft_lstclear(&a, del);
		ft_printf("Double agent\n"); 
			return (-1);
	}
	if(is_sorted(&a) == 1)
	{
		ft_printf("C'EST SORTÉ TABARNAK\n");
	}
	ft_lstiter(a, &print_elem);
	if(argc == 4)
	{
		sort3(&a);
	}
	print_stack(&a, &b);
	/*push(&a, &b);
	ft_printf("push\n");
	print_stack(&a, &b);*/
}
