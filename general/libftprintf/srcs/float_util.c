/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:55:00 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:55:03 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_util.h"

int			get_float_precision(t_spec *spec)
{
	return (spec->precision.value == -1 ? 6 : spec->precision.value);
}

char		get_float_fill_ch(t_spec *spec)
{
	if (spec->flags['0'] == TRUE && spec->flags['-'] == FALSE)
		return ('0');
	else
		return (' ');
}

int			is_special_value(char *buf)
{
	return (ft_strcmp(buf, "inf") == 0 || ft_strcmp(buf, "-inf") == 0 ||
			ft_strcmp(buf, "nan") == 0);
}

int			is_float_null_case(char *f, t_spec *spec)
{
	if (ft_strcmp(f, "0.0") == 0 &&
		spec->precision.value <= 0 &&
		spec->precision.is_dot == TRUE)
	{
		ft_putchar('0');
		return (1);
	}
	return (0);
}
