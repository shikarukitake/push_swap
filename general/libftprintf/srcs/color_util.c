/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:54:46 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:54:47 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_util.h"

const t_str_pair	g_colors[] = {{"nrm", KNRM},
	{"red", KRED},
	{"grn", KGRN},
	{"yel", KYEL},
	{"blu", KBLU},
	{"eoc", KNRM}};

int					find_color_id(char color[3])
{
	int i;

	i = 0;
	while (i < MAX_COLORS)
	{
		if (ft_strcmp(color, g_colors[i].key) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int					parse_color(const char *format, t_spec *spec)
{
	int		i;
	char	color[4];
	int		id;

	i = 0;
	if (format[0] == '{')
	{
		format++;
		while (i != 3)
		{
			color[i] = format[i];
			i++;
		}
		color[3] = '\0';
		id = find_color_id(color);
		if (id != -1)
			ft_putstr(g_colors[id].value);
		spec->type = -1;
		return (5);
	}
	return (0);
}
