/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboivin <fboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:00:54 by fboivin           #+#    #+#             */
/*   Updated: 2023/08/28 20:58:51 by fboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftps/libftps.h"
# include <limits.h>

int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_isdigitsigned(char *str);
int		ft_splatoi(int argv, char **str, t_list **a);
size_t	word_count_space(char *s);
int		ft_isdigitsigned(char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
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
long	ft_atli(char *str);
int		is_sorted(t_list **lst);
void	sort2(t_list **a);
void	sort3(t_list **a);
void	sort5(t_list **a, t_list **b);
void	sort_toute(t_list **a, t_list **b);
size_t	ft_countlist(t_list *lst);
void	ft_lstindex(t_list **a);
int		ft_islstsmall(t_list **a);
int		ft_islstbig(t_list **a);
int		ft_smaller_then_lst(t_list **a, t_list **b);
int		ft_bigger_then_lst(t_list **a, t_list **b);
size_t	ft_findsmallest(t_list *lst);
void	ft_lstclearps(t_list **lst);
size_t	ft_count_to_small(t_list **a);
size_t	ft_pos(t_list **a, size_t index);
size_t	ft_cm(t_list **a, t_list **b, size_t pos_a, size_t pos_b);
size_t	ft_count_to_small(t_list **a);
size_t	ft_middle_pos(size_t i, t_list **b, t_list **a);
void	sort_best_move(t_list **a, t_list **b, t_list *move);
t_list	*find_best_move(t_list **a, t_list **b);
int		ft_islstsmall(t_list **a);
t_list	*ft_middle(size_t index, t_list **a, t_list **b);
t_list	*ft_smallest(t_list **a);
size_t	ft_count_rrr(size_t list_a, size_t list_b, size_t pos_a, size_t pos_b);
size_t	ft_count_rr(size_t pos_a, size_t pos_b);
size_t	ft_count_rrarb(size_t list_a, size_t pos_a, size_t pos_b);
size_t	ft_count_rarrb(size_t list_b, size_t pos_a, size_t pos_b);
void	ft_sort_rrarb(t_list **a, t_list **b, t_list *move, t_list *pos_b);
void	ft_sort_rarrb(t_list **a, t_list **b, t_list *move, t_list *pos_b);
void	ft_sort_rrr(t_list **a, t_list **b, t_list *move, t_list *pos_b);
void	ft_sort_rr(t_list **a, t_list **b, t_list *move, t_list *pos_b);
void	ft_pushback(t_list **a, t_list **b);
t_list	*ft_middle2(size_t index, t_list **b);
t_list	*ft_bigest(t_list **a);
void	ft_final_rotation(t_list **a);
int		ft_empty(char *str);
void	ft_case1(t_list **a, t_list **b);
void	ft_case2(t_list **a, t_list **b);
void	ft_case3(t_list **a, t_list **b);
int		ft_check(int argc, char **argv, t_list **a);
void	ft_sort_small(t_list **a, t_list **b);

#endif