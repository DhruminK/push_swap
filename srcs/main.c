/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:58:52 by dkhatri           #+#    #+#             */
/*   Updated: 2019/09/17 15:43:11 by dkhatri          ###   ########.fr       */
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

	init_stack(&a, &b);
	if (ac == 1)
		return (0);
	if (!ft_validate(&a, ac, av))
	{
		ft_del_stack(&a);
		ft_putendl("Error");
		return (1);
	}
	if (ft_is_sorted(a, &i) == 0 || (i == 0 && ft_sort(&a, &b) < 1))
	{
		ft_del_stack(&a);
		ft_del_stack(&b);
		ft_putendl("Error");
		return (1);
	}
	ft_del_stack(&a);
	ft_del_stack(&b);
	return (0);
}
