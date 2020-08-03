/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:25:21 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/22 18:28:35 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	is_precision(char ch)
{
	return (ft_isdigit(ch));
}

int			parse_precision(const char *format, t_spec *spec)
{
	int		i;
	char	*tmp;
	int		end;

	i = 0;
	if (format[i] == '.')
	{
		spec->precision.is_dot = TRUE;
		if (format[1] == '*')
		{
			spec->precision.is_asterisk = TRUE;
			return (2);
		}
		else
		{
			if ((end = ft_str_func_not_find(format + 1, is_precision)) <= 0)
				return (1);
			tmp = ft_strsub(format, 1, end);
			spec->precision.value = ft_atoi(tmp);
			i += ft_strlen(tmp);
			free(tmp);
			return (i + 1);
		}
	}
	return (0);
}
