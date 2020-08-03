/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:42:04 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 16:43:00 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spec_util.h"

int		get_diff(int buf_len, t_spec *spec)
{
	if (spec->precision.value == -1 || spec->precision.value < buf_len)
		return (0);
	return (spec->precision.value - buf_len);
}

char	get_fill_ch(int len, t_spec *spec)
{
	if (spec->flags['0'] == TRUE &&
			spec->precision.value < spec->width.value &&
			spec->precision.value != -1)
		return (' ');
	if (spec->flags['0'] == TRUE &&
			spec->precision.value < len &&
			spec->precision.value != -1)
		return (' ');
	if (spec->flags['0'] == TRUE && spec->flags['-'] == FALSE)
		return ('0');
	else
		return (' ');
}

int		is_null_case(const char *digit, t_spec *spec)
{
	int b;

	b = (digit[0] == '0' && spec->precision.is_dot == TRUE
			&& (spec->precision.value <= 0));
	if (spec->type == 'x' || spec->type == 'X' || spec->type == 'p')
		return (b);
	else
		return (b && spec->flags['#'] == FALSE);
}
