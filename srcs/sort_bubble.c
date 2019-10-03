/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:27:31 by dkhatri           #+#    #+#             */
/*   Updated: 2019/09/22 16:09:19 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int			ft_sort_bubble(t_list **a)
{
	int			len;
	int			i;
	int			j;
	int			s;

	len = ft_lstlen(*a);
	i = -1;
	while (++i < len && (j = -1))
	{
		while (++j < len - 1)
		{
			if (ft_lstcmp((*a), (*a)->next) > 0)
			{
				ft_putendl("sa");
				swap(a);
			}
			ft_putendl("ra");
			rotate(a);
		}
		ft_putendl("ra");
		rotate(a);
		if (ft_is_sorted(*a, &s, 1) && s)
			break ;
	}
	return (1);
}

int			ft_sort_bubble_opti(t_list **a, int *j, int len, int dir)
{
	int				s;

	if (ft_is_sorted(*a, &s, dir) && s)
		return (1);
	if (*j < len - 1)
	{
		if ((dir && ft_lstcmp((*a), (*a)->next) > 0) \
				|| (!dir && ft_lstcmp((*a), (*a)->next) < 0))
			return (2);
		*j = *j + 1;
		return (3);
	}
	*j = 0;
	return (3);
}
