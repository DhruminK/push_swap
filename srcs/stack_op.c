/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:55:57 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/17 18:56:40 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			push(t_list **alst, int data)
{
	t_list		*ele;

	if (!alst)
		return (-1);
	if (!(ele = ft_lstnew(&data, sizeof(int))))
		return (-1);
	ft_lstadd(alst, ele);
	return (1);
}

void		pop_del(void *content, size_t size)
{
	int		*d;

	d = (int*)content;
	(void)size;
	free(d);
}

int			top(t_list **alst, int *data)
{
	t_list		*ele;

	if (!alst)
		return (-1);
	if (!*alst)
		return (0);
	ele = *alst;
	if (data)
		*data = *((int*)ele->content);
	return (1);
}

int			pop(t_list **alst, int *data)
{
	t_list			*ele;

	if (!alst)
		return (-1);
	if (!*alst)
		return (0);
	ele = *alst;
	*alst = ele->next;
	if (data)
		*data = *((int*)ele->content);
	ft_lstdelone(&ele, &pop_del);
	return (1);
}
