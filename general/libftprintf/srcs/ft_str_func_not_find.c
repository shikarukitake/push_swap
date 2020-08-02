/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_func_not_find.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:18:53 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/27 19:19:09 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Returns the position of the character
 ** in the string for which the function returned 0
*/

ssize_t		ft_str_func_not_find(const char *s, int (*f)(char ch))
{
	ssize_t i;

	i = 0;
	while (s[i])
	{
		if (!f(s[i]))
			return (i);
		i++;
	}
	return (-1);
}
