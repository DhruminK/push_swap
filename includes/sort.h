/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:20:37 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 15:29:33 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H

# define SORT_H
# include "stack.h"
# include "game_op.h"
# include "list_op.h"
# define MAX_LEN 4
# define MIN_INSERTION 0

int				ft_is_sorted(t_list *a, int *sort, int dir, int len);
int				ft_sort(t_list **a, t_list **b);
int				ft_find_median(t_list *a, int len, int *m);
int				ft_single_sort(t_list **a, int *it, int d, int *m);
void			ft_print_stack(t_list *a);
void			ft_print_ab(t_list *a, t_list *b);
int				ft_find_last(t_list *a, int len, int *num);
int				ft_sort_b_less(t_list **a, t_list **b, int *m, int len);
void			ft_rra(t_list **a, int len, char *op);
int				ft_find_num(t_list *a, int n1, int *n2);
int				ft_push_a(t_list **a, t_list **b, int len, int *m);
int				ft_push_b(t_list **a, t_list **b, int len, int *m);

int				ft_findmin(t_list *a, int *min);
int				ft_findmax(t_list *a, int *max);
void			ft_small(t_list **a, int len);
int				ft_insertion_init_b(t_list **a, t_list **b, int *len);
int				ft_sort_less(t_list **a);
int				ft_sort3(t_list **a);
int				ft_sort_insertion(t_list **a, t_list **b);
int				ft_half_sort_insertion(t_list **a, t_list **b);

int				ft_sort_bubble(t_list **a);
int				ft_sort_bubble_opti(t_list **a, int *j, int len, int dir);
int				ft_sort_insertion(t_list **a, t_list **b);
int				ft_sort_quick(t_list **a, t_list **b);

#endif
