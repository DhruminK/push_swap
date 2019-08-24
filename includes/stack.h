/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:47:32 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/24 19:11:41 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "get_next_line.h"

int					push(t_list **alst, int data);
int					pop(t_list **alst, int *data);
void				pop_del(void *content, size_t size);
int					top(t_list **alst, int *data);

#endif
