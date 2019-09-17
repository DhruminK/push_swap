/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:20:37 by dkhatri           #+#    #+#             */
/*   Updated: 2019/09/17 15:26:56 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H

# define SORT_H
# include "stack.h"
# include "game_op.h"
# include "list_op.h"
# define MAX_LEN 4

int				ft_is_sorted(t_list *a, int *sort);
int				ft_sort(t_list **a, t_list **b);
int				ft_conv_arr(t_list *a, int *arr, int len);
int				ft_find_median(t_list *a, int len, int *m);
int				ft_single_sort(t_list **a, int *it, int d, int *m);
void			ft_print_stack(t_list *a);

#endif
