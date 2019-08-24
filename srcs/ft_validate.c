/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:57:54 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/24 18:10:05 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static int	ft_isint(char *str)
{
	int			i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (!ft_isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

static int	ft_finddup(char **av)
{
	int			i;
	int			j;

	i = 0;
	while (av[++i + 1] && (j = i))
	{
		if (!ft_isint(av[i]))
			return (0);
		while (av[++j])
			if (!ft_strcmp(av[i], av[j]))
				return (0);
	}
	if (!ft_isint(av[i]))
		return (0);
	return (1);
}

int			ft_validate(t_list **a, int ac, char **av)
{
	int		i;

	if (!a || ac == 1 || !ft_finddup(av))
		return (0);
	i = ac;
	while (--i > 0)
	{
		if (push(a, ft_atoi(av[i])) < 1)
			return (0);
	}
	return (1);
}
