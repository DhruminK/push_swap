/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:50:36 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/15 19:13:00 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OP_H

#include "stack.h"

void		swap(t_stack *a, t_stack *b);
int			push_stack(t_stack *a, t_stack *b);
int			rotate(t_stack *a);
int			rrotate(t_stack *a);

#endif
