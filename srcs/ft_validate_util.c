/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:14:11 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/15 15:57:53 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int			ft_isint(char *str)
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

int			ft_isbound(char *str)
{
	int			len_str;
	int			len_s;
	char		*s;

	if ((len_str = ft_strlen(str)) < 9)
		return (1);
	s = ft_itoa(ft_atoi(str));
	if (*str == '+')
		str = str + 1;
	len_str = ft_strlen(str);
	len_s = ft_strlen(s);
	ft_strdel(&s);
	if (len_s == len_str)
		return (1);
	return (0);
}
