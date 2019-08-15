/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:47:32 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/15 18:14:38 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

#include "get_next_line.h"

typedef struct		s_stack
{
	int			*data;
	int			head;
}					t_stack;

void				init_stack(t_stack *stack, int *data);
int					push(t_stack *stack, int data);
int					pop(t_stack *stack, int *data);

#endif
