/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:19:37 by sdagger           #+#    #+#             */
/*   Updated: 2019/09/20 21:19:38 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_str(char const *s1, char const *s2, int n)
{
	if (n == 0)
	{
		free((void*)s1);
		free((void*)s2);
	}
	else if (n == 1)
		free((void*)s1);
	else if (n == 2)
		free((void*)s2);
}

char			*ft_strjoin_free(char const *s1, char const *s2, int n)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free_str(s1, s2, n);
	return (dest);
}
