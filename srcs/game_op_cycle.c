/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_op_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:24:55 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/17 17:33:21 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_op.h"

void			rrotate(t_list		**alst)
{
	t_list		*ele;
	t_list		*ele1;

	if (!alst || !*alst)
		return ;
	ele = *alst;
	ele1 = ele->next;
	while (ele1->next)
	{
		ele = ele->next;
		ele1 = ele1->next;
	}
	ele->next = 0;
	ele1->next = *alst;
	*alst = ele1;
}

void			rotate(t_list		**alst)
{
	t_list			*ele;
	t_list			*fe;
	t_list			*le;

	if (!alst || !*alst)
		return ;
	ele = *alst;
	le = ele->next;
	fe = ele->next;
	while (le->next)
		le = le->next;
	le->next = ele;
	ele->next = 0;
	*alst = fe;
}
