/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:08:05 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/07 16:22:18 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_op.h"
#include "validate.h"
#include "sort.h"
#include "instruction.h"

void			ft_del_stack(t_list **alst)
{
	if (!alst)
		return ;
	ft_lstdel(alst, &pop_del);
}

void			init_stack(t_list **a, t_list **b)
{
	if (a)
		*a = 0;
	if (b)
		*b = 0;
}

int				main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;

	init_stack(&a, &b);
	if (ac == 1)
		return (0);
	if (!ft_validate(&a, ac, av))
	{
		ft_del_stack(&a);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (!ft_get_ins(&a, &b))
	{
		ft_del_stack(&a);
		ft_del_stack(&b);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	if (b || ft_is_sorted(a, &i, 1) < 1 || i != 1)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	ft_del_stack(&a);
	ft_del_stack(&b);
	return (0);
}
