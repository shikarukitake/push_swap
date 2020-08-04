/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:04:46 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_tab(char c, char q)
{
	return (c == q);
}

int			word_counter(char const *str, char c)
{
	size_t	i;
	int		q;

	i = 0;
	q = 0;
	if (!str)
		return (0);
	while (i < ft_strlen(str))
	{
		if (!check_tab(str[i], c) &&
				(i == ft_strlen(str) - 1 || check_tab(str[i + 1], c)))
		{
			q++;
		}
		i++;
	}
	return (q);
}

static int	w(char const *c, int j, char q)
{
	if (!c)
		return (0);
	while (c[j] != '\0' && !check_tab(c[j], q))
	{
		j++;
	}
	return (j);
}

void		to_free_dstr(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char		**ft_strsplit(char const *str, char c)
{
	int		j;
	int		i;
	int		k;
	char	**spl;

	if (!(spl = (char**)malloc(sizeof(char*) * (word_counter(str, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (i < word_counter(str, c))
	{
		while (check_tab(str[j], c))
			j++;
		if (!(spl[i] = (char*)malloc(sizeof(char*) * (w(str, j, c) - j + 1))))
		{
			to_free_dstr(spl);
			return (NULL);
		}
		k = 0;
		while (j < w(str, j, c))
			spl[i][k++] = str[j++];
		spl[i++][k] = '\0';
	}
	spl[i] = NULL;
	return (spl);
}
