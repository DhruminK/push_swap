/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:20:37 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/28 17:51:54 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H

# define SORT_H
# include "stack.h"
# include "game_op.h"
# include "list_op.h"

int				ft_is_sorted(t_list *a, int *sort, int dir);
int				ft_sort(t_list **a, t_list **b);
int				ft_conv_arr(t_list *a, int *arr, int len);
int				ft_find_median(t_list *a, int len, int *m);

#endif
