/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:25:15 by sdagger           #+#    #+#             */
/*   Updated: 2019/09/15 15:58:31 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	unsigned const char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned const char*)src;
	while (n-- > 0)
	{
		*dest = *source;
		if (*source == (unsigned char)c)
			return ((void*)dest + 1);
		dest++;
		source++;
	}
	return (NULL);
}
