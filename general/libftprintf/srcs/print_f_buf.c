/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayellin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:47:48 by ayellin           #+#    #+#             */
/*   Updated: 2020/01/23 16:17:27 by ayellin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_f_buf.h"

void		add_sing_and_sp(char *f, t_spec *spec)
{
	if (ft_strcmp(f, "inf") == 0 && spec->flags['+'] == TRUE)
	{
		ft_strcpy(f, "+inf");
		if (spec->flags[' '] == TRUE)
			ft_strcpy(f, " +inf");
		return ;
	}
	else if (ft_strcmp(f, "inf") == 0 && spec->flags[' '] == TRUE)
		ft_strcpy(f, " inf");
}

void		add_zeros(char *buf, t_spec *spec)
{
	int i;
	int f_num;
	int precision;

	if (spec->type == 'g' || spec->type == 'G')
		return ;
	precision = get_float_precision(spec);
	f_num = 0;
	i = (int)ft_strchri(buf, '.') + 1;
	while (buf[i])
	{
		f_num++;
		i++;
	}
	while (f_num < precision)
	{
		buf[i++] = '0';
		f_num++;
	}
	buf[i] = '\0';
}

int			print_float_buf(char *f, t_spec *spec)
{
	int i;

	i = 0;
	while (f[i] && f[i] != '.')
		ft_putchar(f[i++]);
	if (spec->precision.value != 0)
	{
		ft_putstr(f + i);
		i = ft_strlen(f);
	}
	if (spec->precision.value == 0 && spec->flags['#'] == TRUE)
	{
		ft_putchar('.');
		i++;
	}
	return (i);
}

int			print_f_buf(char *f, t_spec *spec, char sign, int is_dot)
{
	int i;

	i = 0;
	if (spec->flags['-'] == TRUE)
	{
		i += print_sign(sign);
		i += print_float_buf(f, spec);
		i += fill_w_field(i, spec, '\0', 0);
	}
	else
	{
		if (get_float_fill_ch(spec) == ' ')
		{
			i += fill_w_field((int)ft_strlen(f) - is_dot, spec, sign, 0);
			i += print_sign(sign);
		}
		else
		{
			i += print_sign(sign);
			i += fill_w_field((int)ft_strlen(f) - is_dot, spec, sign, 0);
		}
		i += print_float_buf(f, spec);
	}
	return ((is_need_wh(f, spec) && (sign <= 0)) ? i + 1 : i);
}

int			print_f(char *f, t_spec *spec, t_ld *ld)
{
	char	sign;
	int		is_dot;

	if (is_special_value(f))
	{
		add_sing_and_sp(f, spec);
		return (print_str(f, spec));
	}
	if (is_float_null_case(f, spec))
		return (1);
	round_float(f, get_float_precision(spec), ld->round);
	add_zeros(f, spec);
	if (is_need_wh(f, spec))
	{
		ft_putchar(' ');
		spec->width.value--;
	}
	sign = get_sign(f, spec);
	is_dot = (f[ft_strlen(f) - 1] == '.');
	modify_g_buf(f, spec);
	return (print_f_buf(f, spec, sign, is_dot));
}
