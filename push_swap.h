/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:00:54 by fboivin           #+#    #+#             */
/*   Updated: 2023/04/09 19:13:59 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

int		main(int argc, char *argv[]);
int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_isdigitsigned(char *str);
void	print_elem(void *content);
int		*ft_splatoi(char *str, size_t c, int *result);
size_t	word_count_space(char *s);
int		ft_isdigitsigned(char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	print_stack(t_list **a, t_list **b);
int		ft_check_doubles(t_list **head);
void	swap(t_list **head);
t_list	*ft_lst_prev_last(t_list **list);
void	reverse_rotate(t_list **head);
void	rotate(t_list **head);
void	push(t_list **a, t_list **b, char c);
void	sa(t_list **a);
void	sb(t_list **a);
void	ss(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **a);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
size_t	ft_numlen(char *str);
long	ft_atol_toi(char *str);
int		is_sorted(t_list **lst);
void	sort2(t_list **a);
void	sort3(t_list **a);
void	sort5(t_list **a, t_list **b);
void	sort_toute(t_list **a, t_list **b);
size_t	ft_countlist(t_list *lst);
void	ft_lstindex(t_list **a);
int		ft_islstsmall(t_list **a);
int 	ft_islstbig(t_list **a);
int		ft_smaller_then_lst(t_list **a, t_list **b);
int		ft_bigger_then_lst(t_list **a, t_list **b);
size_t 	ft_findsmallest(t_list *lst);

#endif