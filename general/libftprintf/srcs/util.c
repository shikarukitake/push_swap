/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:31:48 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 16:29:48 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void		put_or_copy(char *dest, const char *prefix)
{
	if (dest)
		ft_strcpy(dest, prefix);
	else
		ft_putstr(prefix);
}

size_t		print_buf(const char *buf)
{
	if (buf)
		ft_putstr(buf);
	return (ft_strlen(buf));
}

int			ft_arr_find(const char **str_arr, size_t size, const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while ((size_t)i < size)
	{
		if (ft_strcmp(str_arr[i], s) == 0)
			return (i);
		i++;
	}
	return (-1);
}
