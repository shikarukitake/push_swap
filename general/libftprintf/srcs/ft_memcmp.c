/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:26:56 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s11, const void *s22, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)s11;
	s2 = (unsigned char*)s22;
	if (!s11 && !s22)
		return (0);
	while (n-- > 0)
	{
		if (*s1 != *s2)
		{
			if (*s1 && !(*s2))
				return (*s1 - *s2);
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
