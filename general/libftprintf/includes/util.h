/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:33:29 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/21 22:40:45 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTIL_H
# define PRINTF_UTIL_H

# include "libft.h"

size_t			print_buf(const char *buf);

int				ft_arr_find(const char **str_arr, size_t size, const char *s);

void			put_or_copy(char *dest, const char *prefix);

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

#endif
