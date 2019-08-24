/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:20:37 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/18 18:18:33 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H

# define SORT_H
# include "stack.h"
# include "game_op.h"
# include "list_op.h"

int				ft_is_sorted(t_list *a, int *sort);
int				ft_sort(t_list **a, t_list **b, int it, int d);

#endif
