/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:27:40 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/09 18:28:15 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (!lst)
		return (0);
	temp = *lst;
	if (temp && temp->next == NULL)
		return (1);
	temp2 = temp->next;
	while ((*temp).i == ((*temp2).i + 1) && temp2->next != NULL)
	{
		temp = temp->next;
		temp2 = temp2->next;	
	}
	if ((*temp).i == ((*temp2).i + 1) && temp2->next == NULL)
		return (1);
	else
		return (0);
}

	if ((ft_smaller_then_lst(a, b) == 1))
	{
		while (ft_islstsmall(a) != 1)
			ra (a);
		if (ft_islstsmall(a) == 1) 
			push(b, a, 'a');		
	}
	if (!ft_bigger_then_lst(a, b) && !ft_smaller_then_lst(a, b))
	{
	if((*b)->i > ft_lstlast(*a)->i && (*b)->i < (*a)->i) 
		push(b, a, 'a');
	else
		ra (a);
}