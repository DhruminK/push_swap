/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:09:46 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/29 20:41:23 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void			swap_stack(t_list **a, int dir)
{
	if (dir)
		ft_putendl("sa");
	else
		ft_putendl("sb");
	swap(a);
}

int				ft_single_sort(t_list **a, int *it, int dir, int *m)
{
	int				i;
	int				s;
	int				max;
	int				min;

	if (!a || !*a)
		return (1);
	if (!(i = ft_lstmax(*a, &max, &min)))
		return (-1);
	if ((*m) && (*it == 0))
		*m = 0;
	if ((*m))
	{
		*it = *it - 1;
		return (3);
	}
	if (((dir && (*(int*)((*a)->content)) == max) \
			|| (!dir && (*(int*)((*a)->content) == min))) && !(*it = 0))
		return (2);
	if ((i = ft_is_sorted(*a, &s, dir)))
		return (i);
	else if (s == 0 && (*m = 1))
		swap_stack(a, dir);
	else if (s == 1 && (*it = *it + 1))
		return (2);
	else if (s == 2)
		return (3);
	return (ft_single_sort(a, it, dir, m));
}
