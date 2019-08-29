/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:50:36 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/29 20:38:07 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OP_H
# define GAME_OP_H

# include "stack.h"

void		swap(t_list **a);
int			push_stack(t_list **a, t_list **b);
void		rotate(t_list **a);
void		rrotate(t_list **a);

#endif
