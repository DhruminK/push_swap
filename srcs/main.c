/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:58:52 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/24 19:10:53 by dkhatri          ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;
	int			i;
	int			num;

	init_stack(&a, &b);
	if (!ft_validate(&a, ac, av))
	{
		ft_del_stack(&a);
		ft_putendl("Error");
		return (1);
	}
	i = 0;
	if (ft_sort(&a, &b, 0, 100) < 1)
	{
		ft_del_stack(&a);
		ft_del_stack(&b);
		ft_putendl("Error");
		return (1);
	}
	while (++i < ac)
	{
		if (pop(&a, &num) < 1)
		{
			ft_del_stack(&a);
			ft_del_stack(&b);
			ft_putendl("Error");
			return (1);
		}
	}
	ft_del_stack(&a);
	ft_del_stack(&b);
	return (0);
}
