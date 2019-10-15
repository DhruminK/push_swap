/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:09:50 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/15 15:17:36 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "stack.h"

int				ft_isint(char *str);
int				ft_isbound(char *str);

int				ft_validate(t_list **a, int ac, char **av);

#endif
