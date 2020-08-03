/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:58:39 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 16:58:41 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_w_count(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != 0)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

static size_t	ft_c_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		i++;
	}
	return (i);
}

static char		**ft_split_free(char **buf, int j)
{
	while (j >= 0)
	{
		free(buf[j]);
		j--;
	}
	free(buf);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**buf;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	buf = (char **)malloc(sizeof(char *) * (ft_w_count(s, c) + 1));
	if (buf == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			buf[j] = ft_strsub(s, i, ft_c_count(&s[i], c));
			if (buf[j] == NULL)
				return (ft_split_free(buf, j));
			j++;
		}
		i++;
	}
	buf[j] = NULL;
	return (buf);
}
