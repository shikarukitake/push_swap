/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:43:22 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 16:45:19 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size_parser.h"

extern const char * g_size_specs[MAX_SPECS];

int		is_size(char ch, int n)
{
	int	i;

	i = 0;
	while (i < MAX_SPECS)
	{
		if (n < (int)ft_strlen(g_size_specs[i]))
		{
			if (ch == g_size_specs[i][n])
				return (1);
		}
		i++;
	}
	return (0);
}

int		parse_size(const char *format, t_spec *spec)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = spec->size.value;
	if (format[0] == '%')
		return (0);
	while (format[i] && is_size(format[i], i))
	{
		tmp[j++] = format[i];
		i++;
	}
	tmp[j] = '\0';
	spec->size.id = ft_arr_find(g_size_specs, MAX_SPECS, tmp);
	if (spec->size.id != -1)
		return (ft_strlen(tmp));
	return (0);
}
