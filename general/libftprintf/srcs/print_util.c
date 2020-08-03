/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:47:22 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 17:23:36 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_util.h"

char	get_sign(char *digit, t_spec *spec)
{
	if (digit[0] == '-')
	{
		ft_strcpy(digit, digit + 1);
		return ('-');
	}
	else if (spec->flags['+'] == TRUE)
		return ('+');
	return ('\0');
}

int		print_sign(char sign)
{
	if (sign)
	{
		ft_putchar(sign);
		return (1);
	}
	return (0);
}

int		fill_w_field(int i, t_spec *spec, char sign, int prefix)
{
	char	ch;
	int		len;
	int		diff;

	len = i;
	if (spec->type == 'f')
	{
		ch = get_float_fill_ch(spec);
		diff = 0;
	}
	else
	{
		diff = get_diff(i, spec);
		ch = get_fill_ch(i + (sign > 0) + prefix, spec);
	}
	if (is_oct_prefix(spec) && diff != 0)
		prefix = 0;
	while (i + diff + prefix + (sign > 0) < spec->width.value)
	{
		ft_putchar(ch);
		i++;
	}
	return (i - len);
}

int		fill_precision_field(char *buf, t_spec *spec)
{
	int diff;
	int i;
	int len;

	i = 0;
	len = ft_strlen(buf);
	diff = get_diff(len, spec);
	while (diff > 0)
	{
		ft_putchar('0');
		diff--;
		i++;
	}
	return (i);
}
