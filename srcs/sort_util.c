/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:24:56 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/03 16:34:06 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

/*int			ft_is_sorted(t_list *a, int *s, int dir)
{
	t_list			*ele;

	if (!a || !s)
		return (-1);
	ele = a->next;
	if (!ele)
		return (1);
	if (((dir && ft_lstcmp(a, ele) > 0) || (!dir && ft_lstcmp(a, ele) < 0)) \
			&& !(*s = 0))
		return (0);
	ele = ele->next;
	a = a->next;
	while (ele)
	{
		if ((dir && ft_lstcmp(a, ele) > 0) || (!dir && ft_lstcmp(a, ele) < 0))
		{
			*s = 1;
			if (ele->next == 0)
				*s = 2;
			return (0);
		}
		ele = ele->next;
		a = a->next;
	}
	return (1);
}

static int			ft_conv_arr(t_list *a, int *arr, int len)
{
	int			i;

	i = -1;
	if (!a || !arr || !len)
		return (0);
	while (++i < len && a)
	{
		arr[i] = (*((int*)(a->content)));
		a = a->next;
	}
	if (len != i || a)
		return (0);
	return (1);
}

int			ft_find_median(t_list *a, int len, int *m)
{
	int			i;
	int			tmp;
	int			j;
	int			arr[len];

	if (len < 1 || !a || !m || !(ft_conv_arr(a, arr, len)))
		return (0);
	i = -1;
	while (++i < len && (j = -1))
	{
		while (++j < len - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	*m = arr[len % 2 == 0 ? len / 2 : (((len + 1) / 2) - 1)];
	return (1);
}*/

void			ft_print_stack(t_list *a)
{
	ft_putendl("++++++++++++++++++++++++++");
	while (a)
	{
		ft_putnbr(ft_lstdata(a));
		ft_putendl("");
		a = a->next;
	}
	ft_putendl("++++++++++++++++++++++++++");
}

void			ft_print_ab(t_list *a, t_list *b)
{
	int			i;

	i = 0;
	ft_putendl("+++++++++++++++++++++++++++");
	while ((a || b) && (i = i + 1))
	{
		if (a)
		{
			ft_putnbr(ft_lstdata(a));
			a = a->next;
		}
		else
			ft_putstr("  ");
		ft_putstr("     ");
		if (b)
		{
			ft_putnbr(ft_lstdata(b));
			b = b->next;
		}
		else
			ft_putstr("  ");
		ft_putendl("");
	}
	ft_putstr("LENGTH : ");
	ft_putnbr(i);
	ft_putendl("\n+++++++++++++++++++++++++++");
}

int				ft_is_sorted(t_list *a, int *s, int dir)
{
	if (!a || !s)
		return (0);
	*s = 1;
	while (a->next)
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
