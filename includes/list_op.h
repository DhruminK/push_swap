/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:15:42 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/24 17:01:22 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_OP_H

# define LIST_OP_H
# include "libft.h"

int				ft_lstlen(t_list *a);
int				ft_lstcmp(t_list *a, t_list *b);
int				ft_lstmax(t_list *a, int *max, int *min);

#endif