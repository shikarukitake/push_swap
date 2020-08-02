/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <ayellin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:35:49 by ayellin           #+#    #+#             */
/*   Updated: 2019/09/23 15:41:27 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strchri(const char *s, char c)
{
	ssize_t i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		if (s[i] == c)
			return (i);
		else
			i++;
	return (-1);
}
