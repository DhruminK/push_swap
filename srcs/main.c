/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:58:52 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 17:20:04 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_op.h"
#include "validate.h"
#include "sort.h"

void		ft_del_stack(t_list **alst)
{
	if (!alst)
		return ;
	ft_lstdel(alst, &pop_del);
}

void		init_stack(t_list **a, t_list **b)
{
	if (a)
		*a = 0;
	if (b)
		*b = 0;
}

static int	ft_sort_main(t_list **a, t_list **b)
{
	int			len;

	len = ft_lstlen(*a);
	if (len < 30)
	{
		if (!ft_sort_insertion(a, b))
			return (0);
	}
	else
	{
		if (!ft_sort_quick(a, b))
			return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;
	int			i;

	init_stack(&a, &b);
	if (ac == 1)
		return (0);
	if (!ft_validate(&a, ac, av) || ft_is_sorted(a, &i, 1, -1) == 0 \
			|| (!i && !ft_sort_main(&a, &b)))
	{
		ft_del_stack(&a);
		ft_del_stack(&b);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	ft_del_stack(&a);
	ft_del_stack(&b);
	return (0);
}
