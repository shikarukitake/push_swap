/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:31:38 by sdagger           #+#    #+#             */
/*   Updated: 2019/09/06 20:40:32 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *sw;

	sw = NULL;
	if (c == '\0')
		return ((char*)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == c)
			sw = (char*)(s);
		s++;
	}
	if (sw)
		return (sw);
	return (NULL);
}
