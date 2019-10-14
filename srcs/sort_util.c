/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:24:56 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 15:46:30 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int				ft_is_sorted(t_list *a, int *s, int dir, int len)
{
	int			tmp;

	if (!a || !s)
		return (0);
	*s = 1;
	tmp = len > 0 ? 1 : 0;
	while (((tmp && len-- > 0) || !tmp) && a->next)
	{
		if (((dir && ft_lstcmp(a, a->next) > 0) \
					|| (!dir && ft_lstcmp(a, a->next) < 0)) \
				&& !(*s = 0))
			break ;
		a = a->next;
	}
	return (1);
}

int				ft_find_last(t_list *a, int len, int *num)
{
	int				i;

	if (!a)
		return (0);
	i = 1;
	while (a && i++ < len)
		a = a->next;
	if (!a)
		return (0);
	if (num)
		*num = ft_lstdata(a);
	return (1);
}

void			ft_rra(t_list **a, int len, char *op)
{
	int			i;

	i = 0;
	while (++i <= len)
	{
		ft_putendl(op);
		rrotate(a);
	}
}

int				ft_find_num(t_list *a, int n1, int *n2)
{
	int			len;
	int			num;

	if (!a)
		return (0);
	num = ft_lstdata(a);
	len = 0;
	while (a && n1 <= num && ((n2 && *n2 >= num) || !n2))
	{
		len = len + 1;
		a = a->next;
		if (a)
			num = ft_lstdata(a);
	}
	return (len);
}
