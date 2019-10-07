/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:57:54 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/07 15:58:13 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "list_op.h"
#include <stdio.h>

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
	if (i == 1 && !ft_isdigit(str[0]))
		return (0);
	return (1);
}

static int	ft_finddup(char *str, t_list **a)
{
	int			i;
	int			num;
	t_list		*ele;

	if (!str || !a)
		return (0);
	i = -1;
	if (!ft_isint(str))
		return (0);
	num = ft_atoi(str);
	ele = *a;
	while (ele)
	{
		if (num == ft_lstdata(ele))
			return (0);
		ele = ele->next;
	}
	return (1);
}

static int	ft_validate_one(t_list **a, char **av)
{
	int			i;

	if (!a)
		return (0);
	i = 0;
	while (av[i])
		i = i + 1;
	while (--i > -1)
	{
		if (!ft_finddup(av[i], a))
			return (0);
		if (push(a, ft_atoi(av[i])) < 1)
			return (0);
	}
	return (1);
}

static void	ft_strarrdel(char ***str)
{
	int			i;
	char		**s;

	if (!str)
		return ;
	i = -1;
	s = *str;
	while (s[++i])
		ft_strdel(s + i);
	free(s);
	*str = 0;
}

int			ft_validate(t_list **a, int ac, char **av)
{
	int			i;
	char		**str;

	if (!a || ac == 1)
		return (0);
	i = ac;
	while (--i > 0)
	{
		if (!(str = ft_strsplit(av[i], ' ')))
			return (0);
		if (!ft_validate_one(a, str))
			return (0);
		ft_strarrdel(&str);
	}
	return (1);
}
